#include "stdafx.h"
#include "Kernel.h"

Kernel* Kernel::instance = NULL;
Kernel::Kernel()
{
	process = Process::getInstance();
	disk = Disk::getInstance();
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

void Kernel::up(Signals signal, string data)
{
	if (signal == checkDiskStatus)
	{
		disk->down(signal, "");
	}
	else if (signal == kernelResponse)
	{
		process->down(signal, data);
	}
	else if (signal == deleteSlot || signal == add)
	{
		disk->down(signal, data);
	}
	else if (signal == SIGUSR2)
	{
		process->down(signal, "");
		disk->down(signal, "");
	}
}

void Kernel::down(Signals signal, string data)
{
	if (signal == add)
	{
		if (data.size() > 64)
			//send not able to add/delete
			up(kernelResponse, "2");
		else
			up(checkDiskStatus, "0"); // zero mean add which will increment if you can add
		tempMessage = data;


	}

	else if (signal == checkDiskStatus)
	{
		//data number refer to hash table of my own
		//0 can't add
		//1 can add
		//2 can't delete
		//3 can delete
		if(data == "0")
			up(kernelResponse, "2");
		else if (data == "1")
		{
			up(kernelResponse, "0");
			up(add, tempMessage);
		}
		else if (data == "2")
			up(kernelResponse, "3");
		else if (data == "1")
		{
			up(kernelResponse, "1");
			up(deleteSlot, tempMessage);
		}
	}
	else if (signal == SIGUSR1)
	{
		int freeSlots = stoi(data);
	}

}

void Kernel::run()
{

	clk++;
	up(SIGUSR2, "");
}
