#pragma once
#include "Population.h"
#include<string>
using namespace std;
class Helper_functions
{

public:
	static void fitnessRank(Population *p, string optima);
	static void sortByBestRankFirst(Population *generation);
	static void displayTopMostFitCandidate(Population *generation);
	static void displayGeneration(Population *generation);
	static void createNewGeneration(Population *generation);
	static string crossover(Candidate *c1, Candidate *c2);
	static string mutation(string genenomeToMutate);
	static bool fitnessAchieved(Population *p, string optima);

};

