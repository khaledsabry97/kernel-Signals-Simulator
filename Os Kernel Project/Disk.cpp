#include "stdafx.h"
#include "Disk.h"

Disk* Disk::instance = NULL;//initailize
Disk::Disk()
{
	size = 10;
	state = DiskStates::free;
}


Disk * Disk::getInstance()
{
	return nullptr;
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

void Disk::up(string key, string data)
{
}

void Disk::down(string key, string data)
{
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
