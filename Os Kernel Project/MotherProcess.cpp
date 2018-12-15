#include "stdafx.h"
#include "MotherProcess.h"


MotherProcess::MotherProcess()
{
	clk = 0;
}


void MotherProcess::addProcess(MotherProcess * process)
{
	processes.push_back(process);
}

void MotherProcess::send(int channel, string msg)
{
	for (int i = 0; i < processes.size(); i++)
	{
		if(processes[i]->channel != channel)
			processes[i]->down(channel, msg);
	}
}

void MotherProcess::kill(int channel)
{
	for (int i = 0; i < processes.size(); i++)
	{
		processes[i]->channel == channel;
		processes.erase(processes.begin() + i);
	}
}

MotherProcess::~MotherProcess()
{
}
