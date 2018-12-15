#include "stdafx.h"
#include "Disk.h"

Disk::Disk(int channel)
{
	size = 10;
	sizeFree = 10;
	this->channel = channel;
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

void Disk::run()
{
	if (state == DiskStatus::adding)
	{
		if (clk - processClk == 3)
		{
			//add has finished
			state = DiskStatus::available;
		}
	}

	if (state == DiskStatus::deleting)
	{
		if (clk - processClk == 1)
		{
			//add has finished
			state = DiskStatus::available;
		}
	}
}

void Disk::up(int channel, string msg)
{
	send(channel, msg);
}

void Disk::down(int channel, string msg)
{
	if (this->channel != channel && state == DiskStatus::available)
		return;
	if (state == DiskStatus::adding)
	{
		add(msg);
		sizeFree--;
		processClk = clk;
	}
	else//deleting
	{
		deleteSlot(stoi(msg));
		sizeFree++;
		processClk = clk;
	}
}

