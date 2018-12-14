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
	vector<Process*> readInput(int noOfFiles, string inputFileName);
	bool writeOutputArray(int time,string log);

	~ReadingWriting();
};

