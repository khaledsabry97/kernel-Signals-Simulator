#pragma once
#include <iostream>

using namespace std;
class MotherProcess
{

	int clk;
public:
	MotherProcess();
	virtual void up(string key, string data) = 0;
	virtual void down(string key, string data) = 0;
	virtual void run() = 0;
	~MotherProcess();
};

