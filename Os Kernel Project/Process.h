#pragma once
//#include "Kernel.h"
//#include "ProcessStructure.h"

#include "stdafx.h"
#include <vector>

using namespace std;
class kernel;
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
	void addKernel();
	void addProcess(ProcessStructure structure);
	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;
};

