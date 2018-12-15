// Os Kernel Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int main()
{
	Kernel* kernel = Kernel::getInstance();
	kernel->addDiskChannel(777);
	Disk* disk = new Disk(777);
	ReadingWriting* readingAndWriting = new ReadingWriting();
	vector<Process*> processes = readingAndWriting->readInput(1,"dsf");
    return 0;
}

