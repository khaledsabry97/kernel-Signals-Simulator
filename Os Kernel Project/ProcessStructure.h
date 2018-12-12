#pragma once
#include <iostream>
#include "ProcessStates.h"
#include <string>
using namespace std;
struct ProcessStructure
{
	int time;
	char operation;
	string data;
	int clk = 0;
	ProcessStates state = away;

};