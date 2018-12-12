#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ProcessStructure.h"
#include "Process.h"
using namespace std;
class Process;
class ReadingWriting
{
public:
	ReadingWriting();
	bool readInput(string inputFileName);
	bool writeOutputArray(int time,string log);

	~ReadingWriting();
};

