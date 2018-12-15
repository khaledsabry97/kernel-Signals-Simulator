#pragma once
#include "stdafx.h"
class Kernel: public MotherProcess
{
	int channel = 0;
	int diskChannel;
	int tempIndex = -1;
	string tempMsg = "";
	int tempChannel;

	static Kernel* instance;
	Kernel();
public:
	static Kernel* getInstance();
	~Kernel();
	void log();

	void addDiskChannel(int channel);
	virtual void run() override;
	

	// Inherited via MotherProcess
	virtual void up(int channel, string msg) override;
	virtual void down(int channel, string msg) override;
};

