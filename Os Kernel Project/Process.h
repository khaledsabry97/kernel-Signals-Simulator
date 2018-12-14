#pragma once
//#include "Kernel.h"
//#include "ProcessStructure.h"

#include "stdafx.h"
#include <vector>

using namespace std;
class kernel;
class ProcessStructure;
class Process :public MotherProcess
{
	vector<ProcessStructure*> processes;
	ProcessStructure* current;
	Kernel* kernel;


public:
	Process();
	~Process();
	virtual void run() override;
	void addProcess(ProcessStructure structure);
	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;
};

