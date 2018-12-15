#pragma once
#include <iostream>
#include "ProcessStates.h"
#include <string>
using namespace std;
struct Request
{
	int time;
	char operation;
	string data;
};