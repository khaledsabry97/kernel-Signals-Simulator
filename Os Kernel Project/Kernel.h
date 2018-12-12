#pragma once
#include "MotherProcess.h"
#include "Process.h"
#include "Disk.h"
class Kernel: public MotherProcess
{
	int clk;
	int processesSize;
	vector<Process> processes;
	int currentProcessIndex;
	Disk* disk;
	Process* process;
	string tempMessage;
	static Kernel* instance;
	Kernel();
public:
	static Kernel* getInstance();
	~Kernel();
	void log();

	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;
	virtual void run() override;
};

