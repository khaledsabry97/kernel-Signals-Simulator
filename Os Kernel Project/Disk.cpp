#include "stdafx.h"
#include "Disk.h"

Disk* Disk::instance = NULL;//initailize
Disk::Disk()
{
	size = 10;
	state = DiskStates::free;
	kernel = Kernel::getInstance();
}


Disk * Disk::getInstance()
{

	if (instance == NULL)
		instance = new Disk();

	return instance;
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
	if (isFreeSlots() && state == DiskStates::free)
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
				state = DiskStates::free;
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
			state = DiskStates::free;
		}
	}
}

void Disk::up(Signals signal, string data)
{
}

//return true if you want the kernel to recieve on the up message on the up signal
void Disk::down(Signals signal, string data)
{
	if (signal == SIGUSR2)
	{
		clk++;
	}
}