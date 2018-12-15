#include "stdafx.h"
#include "Kernel.h"

Kernel* Kernel::instance = NULL;
Kernel::Kernel()
{
}


Kernel * Kernel::getInstance()
{
	if (instance == NULL)
		instance = new Kernel();

	return instance;
}

Kernel::~Kernel()
{
}

void Kernel::log()
{
}

void Kernel::run()
{
	clk++;
}

void Kernel::addDiskChannel(int channel)
{
	diskChannel = channel;
}

void Kernel::up(int channel, string msg)
{
	send(channel, msg);
}

void Kernel::down(int channel, string msg)
{
	if (channel == diskChannel)
	{
		if (stoi(msg) != 0)
		{
			//send to process that you are able to add/delete
			//the message
			if (tempIndex == -1)//add
			{
				up(diskChannel, tempMsg);
				up(tempChannel, "successful ADD");
			}
			else
			{
				up(diskChannel, to_string(tempIndex));
				up(tempChannel, "successful DEL");
			}
		}
		else
		{
			//send to process that you are not able to add/delete
			//the message
			if (tempIndex == -1)//add
			{
				up(tempChannel, "unable to ADD");
			}
			else
			{
				up(tempChannel, "unable to DEL");
			}
		}
		tempIndex = -1; //something to use it later like check if other process has sent the signal first
		return;
	}
	//else then it's a process sending a request
	char ad = msg[0];
	msg = msg.substr(2, msg.length() -2);
	int msgSize = msg.size();
	tempChannel = channel;
	if (msgSize > 64)
	{
		if (ad = 'A')
			up(channel, "unable to ADD Because of the size");
		return;
	}
	if (ad = 'A')
	{
		tempMsg = msg;
		tempIndex = -1;
		//send signal to disk to check the size
	}
	else if (ad = 'D')
	{
		tempIndex = -1;
		tempMsg = "";
		//send signal to disk to check the size
	}

}
