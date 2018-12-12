#include "stdafx.h"
#include "Process.h"

Process* Process::instance = NULL;
Process::Process()
{
	kernel = Kernel::getInstance();
}


Process * Process::getInstance()
{
	if (instance == NULL)
		instance = new Process();

	return instance;
}

Process::~Process()
{
}

void Process::run()
{
	if (currentProcess == NULL)
		currentProcess = processes.at(0);


}

void Process::up(Signals signal, string data)
{
	kernel->down(signal, data);
	currentProcess->state = blocked;
}

void Process::down(Signals signal, string data)
{
	if (signal == kernelResponse)
	{
		int i = stoi(data);
		switch (i)
		{
		case 0:
			cout << "Successful Add" << endl;
			break;
		case 1:
			cout << "Successful Del" << endl;
			break;
		case 2:
			cout << "Unable to Add" << endl;
			break;
		case 3:
			cout << "Unable to Del" << endl;
			break;
		default:
			break;
		}
	}
	else if (signal == SIGUSR2)
	{
		clk++;
	}
}
