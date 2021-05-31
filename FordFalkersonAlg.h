#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "Rib.h"
using namespace std;


class FordFalkerson
{
public:
	RibList Ribs;
	void ReadFromFile(string);//read from file
	int alg(string, string);//algoritmh FordFalkerson
};