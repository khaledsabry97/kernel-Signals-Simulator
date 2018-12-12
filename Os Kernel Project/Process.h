#pragma once
#include "MotherProcess.h"
class Process :
	public MotherProcess
{
	int time;
	char operation;
	string data;
public:
	Process();
	~Process();

	// Inherited via MotherProcess
	virtual void up(string key, string data) override;
	virtual void down(string key, string data) override;
	virtual void run() override;
};

