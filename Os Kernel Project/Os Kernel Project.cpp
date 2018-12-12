// Os Kernel Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
int main()
{
	Kernel* kernel = Kernel::getInstance();
	Process* process = Process::getInstance();
	Disk* disk = Disk::getInstance();
	process->addKernel();
	disk->addKernel();
	ReadingWriting* readingAndWriting = new ReadingWriting();
	readingAndWriting->readInput("dsf");
    return 0;
}

