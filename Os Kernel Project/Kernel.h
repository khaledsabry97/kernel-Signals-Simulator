#pragma once
#include "stdafx.h"
#include <vector>
class Disk;
class Process;
class ProcessStructure;
class Kernel: public MotherProcess
{
	int clk;
	int processesSize;
	int currentProcessIndex;

	string tempMessage;

	Disk* disk;
	vector<Process*> processes;
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
	void addProcess(Process* process);
	void addDisk(Disk* disk);
	void sendToAllProcesses(Signals signals, string msg);
};

