#pragma once
#include "MotherProcess.h"
#include <vector>
#include "DiskStates.h"

class Disk :
	public MotherProcess
{
	int size;
	vector<string> slots;
	DiskStates state;
	static Disk* instance;
	//to store the coming value through the downlink
	string tempAdd;
	int tempIndex;
	//to differentiate between the normal clk and the processing clk
	int processClk;
	Disk();
public:
	static Disk* getInstance();
	~Disk();
	void add(string data);
	void deleteSlot(int index);
	bool isFreeSlots();
	// Inherited via MotherProcess
	virtual void up(string key, string data) override; // to the kernel
	virtual void down(string key, string data) override; // from the kernel
	// Inherited via MotherProcess
	virtual void run() override;
	// get from kernel
};

