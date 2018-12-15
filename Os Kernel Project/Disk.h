#pragma once
#include "stdafx.h"
using namespace std;

//still
// how to recevie the signals from kernel
// if you recieve the returning count signal then change the state to add and send the count
// if you recieve the clk increment increment the clock
class Disk :public MotherProcess
{
	int size;
	vector<string> slots;
	//to store the coming value through the downlink
	//string tempAdd;
	//int tempIndex;
	//to differentiate between the normal clk and the processing clk
	int processClk;
	int sizeFree;
	DiskStatus state;
public:
	Disk(int channel);
	~Disk();
	void add(string data);
	void deleteSlot(int index);
	// Inherited via MotherProcess
	
	// Inherited via MotherProcess
	virtual void run() override;

	// Inherited via MotherProcess
	virtual void up(int channel, string msg) override;
	virtual void down(int channel, string msg) override;
};

