// wordEvolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Candidate.h"
#include "Population.h"
#include "Helper_functions.h"
#include "GlobalParameters.h"
using namespace std;
int main()
{
	//Step 0:
    cout << "Start of Genetic Algorithm!!!\n";
	string optima = "whitchurch";
	
	//Step 1:
	//Create a population of Person/Candidate.
	//Each Person/Candidate has Genome of Length 10, and Fitness score = 0, initially.
	Population *generation = new Population();

	bool repeatGeneration = true;

	while (repeatGeneration)
	{
		//Step 2: Calculate the fitness of each Person/Candidate in the population.
		Helper_functions::fitnessRank(generation, optima);

		//Step 3: Sort the population based on fitness rank.
		Helper_functions::sortByBestRankFirst(generation);

		//Step 4: Display the sorted Population by fitness:
		//Helper_functions::displayTopMostFitCandidate(generation);

		//Step 5: Create the new population:
		Helper_functions::createNewGeneration(generation);

		//Step 6: Check if fitness has been achieved by the Alpha Candidate in the population.
		repeatGeneration = Helper_functions::fitnessAchieved(generation, optima);

		
	}
	//Step 7: Recalculate fitness
	Helper_functions::fitnessRank(generation, optima);

	//Step 8: Sort them from highest to lowest fitness
	Helper_functions::sortByBestRankFirst(generation);

	//Step 9: Display all the Candidates in the Generation that hit the fitness value:
	Helper_functions::displayGeneration(generation);

	//Final Step: Remove all memory allocations.
	delete[] generation->candidate;
	delete generation;

	cout << "End of Genetic Algorithm !!!" << endl;
}

