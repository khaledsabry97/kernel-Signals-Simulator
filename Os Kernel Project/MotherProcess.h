#pragma once
#include "stdafx.h"
using namespace std;
class MotherProcess
{

protected:
	int clk;
	vector<MotherProcess*> processes;
	int channel;
public:
	MotherProcess();
	virtual void up(int channel, string msg) = 0;
	virtual void down(int channel, string msg) = 0;
	virtual void run() = 0;
	void addProcess(MotherProcess* process);
	void send(int channel, string msg);
	void kill(int channel);
	~MotherProcess();
};

