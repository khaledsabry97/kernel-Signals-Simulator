#pragma once
#include <iostream>
#include "Signals.h"
#include <string>
using namespace std;
class MotherProcess
{

protected: int clk;
public:
	MotherProcess();
	virtual void up(Signals signal, string data) = 0;
	virtual void down(Signals signal, string data) = 0;
	virtual void run() = 0;
	~MotherProcess();
};

