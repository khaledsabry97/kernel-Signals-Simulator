#include "stdafx.h"
#include "Disk.h"

Disk::Disk()
{
	size = 10;
	state = DiskStates::available;
	sizeFree = 10;
	kernel = Kernel::getInstance();
	kernel->addDisk(this);
}

Disk::~Disk()
{
}

void Disk::add(string data)
{
	slots.push_back(data);
}

void Disk::deleteSlot(int index)
{
	slots.erase(slots.begin() + index);
}

bool Disk::isFreeSlots()
{
	if (slots.size() == 10)
		return false;
	return true;
}

bool Disk::isAvailable()
{
	if (isFreeSlots() && state == DiskStates::available)
		return true;
	return false;
}

void Disk::run()
{

	if (state == DiskStates::adding)
	{
		processClk++;
		if (processClk == 3)
		{
			add(tempAdd);
			processClk = 0;
			if (isFreeSlots())
			{
				state = DiskStates::available;
			}
			else
			{
				state = DiskStates::sizeComplete;
			}
		}
	}

	if (state == DiskStates::deleting)
	{
		processClk++;
		if (processClk == 1)
		{
			deleteSlot(tempIndex);
			processClk = 0;
			state = DiskStates::available;
		}
	}
}

void Disk::up(Signals signal, string data)
{
		kernel->down(signal, data);
}

void Disk::down(Signals signal, string data)
{
	if (signal == SIGUSR1)
	{
		up(SIGUSR1, to_string(size - slots.size()));
	}
	else if (signal == SIGUSR2)
	{
		clk++;
	}
	else if (signal == Signals::add)
	{
		state = adding;
		tempAdd = data;
		sizeFree--;

	}
	else if (signal == Signals::deleteSlot)
	{
		state = deleting;
		tempIndex = stoi(data);
		sizeFree++;
	}
}