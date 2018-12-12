#pragma once
#include "MotherProcess.h"
#include "Kernel.h"
#include "ProcessStates.h"
#include "ProcessStructure.h"
class Process :
	public MotherProcess
{
	vector<ProcessStructure*> processes;
	ProcessStructure* currentProcess;
	Kernel* kernel;
	static Process* instance;
	Process();
public:
	static Process* getInstance();
	~Process();
	virtual void run() override;

	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;
};

