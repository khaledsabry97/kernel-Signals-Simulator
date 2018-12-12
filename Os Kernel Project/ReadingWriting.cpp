#include "stdafx.h"
#include "ReadingWriting.h"


ReadingWriting::ReadingWriting()
{
}

bool ReadingWriting::readInput(string inputFileName)
{
	ifstream inputfile;
	inputfile.open("process.txt");
	if (!inputfile.is_open()) 
	{ 
		cout << "failed to open file" << endl;
		return false;
	}
	Process* process = Process::getInstance();
	try
	{
		while (!inputfile.eof())
		{
			ProcessStructure structure;
			inputfile >> structure.time;
			inputfile >> structure.operation;
			getline(inputfile, structure.data);
			structure.data = structure.data.substr(1, structure.data.size() + 1);
			process->addProcess(structure);
		}

	}
	catch (exception e)
	{
		cout << "failed in something while reading the text file " << endl;
		inputfile.close();
		return false;
	}
	inputfile.close();

	return true;
}

bool ReadingWriting::writeOutputArray(int time, string log)
{
	ofstream myfile;
	myfile.open("log.txt", ios::app);
	if (!myfile.is_open())
	{
		cout << "file doesn't open" << endl;
		return false;
	}
	myfile << time << " : " << log << endl;
	myfile.close();
	return true;
}


ReadingWriting::~ReadingWriting()
{
}
