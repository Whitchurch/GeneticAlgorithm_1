#pragma once
#include "Population.h"
#include<string>
using namespace std;
class Helper_functions
{

public:
	static void fitnessRank(Population *p, string optima);
	static void sortByBestRankFirst(Population *generation);
	static void displayGeneration(Population *generation);

};

