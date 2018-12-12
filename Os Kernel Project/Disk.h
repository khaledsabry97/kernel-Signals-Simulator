#pragma once
#include "MotherProcess.h"
#include <vector>
#include "DiskStates.h"
#include "Kernel.h"
#include "Signals.h"
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
	Kernel* kernel;
	Disk();
public:
	static Disk* getInstance();
	~Disk();
	void add(string data);
	void deleteSlot(int index);
	bool isFreeSlots();
	bool isAvailable();
	// Inherited via MotherProcess
	
	// Inherited via MotherProcess
	virtual void run() override;

	// Inherited via MotherProcess
	virtual void up(Signals signal, string data) override;
	virtual void down(Signals signal, string data) override;


	Signals up();
	// get from kernel
};

