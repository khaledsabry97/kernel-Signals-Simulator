#pragma once
#include <iostream>
#include "ProcessStates.h"
#include <string>
using namespace std;
struct ProcessStructure
{
	int id;
	int time;
	char operation;
	string data;
	ProcessStates state = away;

};