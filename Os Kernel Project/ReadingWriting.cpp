#include "stdafx.h"
#include "ReadingWriting.h"


ReadingWriting::ReadingWriting()
{
}

vector<Process*> ReadingWriting::readInput(int noOfFiles, string inputFileName)
{

	ifstream inputfile;
	vector<Process*> processes;
	try
	{
		int i = 0;
		while (i < noOfFiles)
		{

			i++;
			Process* process = new Process();

			inputfile.open("process" + to_string(i) + ".txt");
			if (!inputfile.is_open())
			{
				cout << "failed to open file" << endl;
				return processes;
			}
			int j = 0;
			while (!inputfile.eof())
			{
				ProcessStructure structure;
				inputfile >> structure.time;
				inputfile >> structure.operation;
				getline(inputfile, structure.data);
				structure.data = structure.data.substr(1, structure.data.size() + 1);
				structure.id = i * 10 + j;
				process->addProcess(structure);
				j++;
			}
			processes.push_back(process);
			inputfile.close();
		}
	}
	catch (exception e)
	{
		cout << "failed in something while reading the text file " << endl;
		inputfile.close();
		return processes;
	}
	inputfile.close();
	return processes;
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
