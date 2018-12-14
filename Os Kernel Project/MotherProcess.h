#pragma once
#include <iostream>
//#include "Signals.h"
#include <string>
#include "stdafx.h"
using namespace std;
class MotherProcess
{

protected: int clk;
		   vector<MotherProcess*> processes;
public:
	MotherProcess();
	virtual void up(Signals signal, string data) = 0;
	virtual void down(Signals signal, string data) = 0;
	virtual void run() = 0;
	~MotherProcess();
};

