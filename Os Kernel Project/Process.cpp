#include "stdafx.h"
#include "Process.h"



Process::Process(int channel)
{
	this->channel = channel;
	running = true;
	addProcess(this);

}

Process::~Process()
{
}

void Process::run()
{
	if (current == NULL)
	{
		kill(channel);
		return;
	}
	if (running == false)
		return;
	if (clk == current->time)
		up(channel, current->data);

}

void Process::addRequest(Request structure)
{
	requests.push(new Request(structure));
	current = requests.front();
}

void Process::up(int channel, string msg)
{
	send(channel, msg);
	running = false;
}

void Process::down(int channel, string msg)
{
	if (this->channel != channel)
		return;

		int i = stoi(msg);
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
		requests.pop();
		current = requests.front();
		running = true;
	}

	

/*else if (signal == SIGUSR2)
	{
		clk++;
	}

	*/
