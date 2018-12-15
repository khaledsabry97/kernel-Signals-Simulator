#pragma once
#include "stdafx.h"

using namespace std;

class Request;
class Process :public MotherProcess
{
	queue<Request*> requests;
	Request* current;
	bool running;

public:
	Process(int channel);
	~Process();
	virtual void run() override;
	void addRequest(Request structure);

	// Inherited via MotherProcess
	virtual void up(int channel, string msg) override;
	virtual void down(int channel, string msg) override;
};

