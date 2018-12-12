#pragma once
/*#include "MotherProcess.h"
#include "Process.h"
#include "Disk.h"*/
#include "stdafx.h"
class Disk;
class Process;
class Kernel: public MotherProcess
{
	int clk;
	int processesSize;
	int currentProcessIndex;

	string tempMessage;
	static Kernel* instance;
	Kernel();
	Disk* disk;
	Process* process;
public:
	static Kernel* getInstance();
	~Kernel();
	void log();

	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;
	virtual void run() override;
};

