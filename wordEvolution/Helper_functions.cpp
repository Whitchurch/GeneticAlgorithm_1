
#include "Helper_functions.h"
#include "GlobalParameters.h"
#include<iostream>
using namespace std;
void Helper_functions::fitnessRank(Population* p, string optima)
{
	
	
	//Cycle through the list of Candidates in the Population
	for (int candidate = 0; candidate < populationSize; candidate++)
	{
		int fitnessRankValue = 0;

		//Cycle through the Chromosome/Genome of the Candidate
		for (int genomePosition = 0; genomePosition < Genomelength; genomePosition++)
		{
			//Calculate the fitness value
			if (p->candidate[candidate].genome[genomePosition] == optima[genomePosition])
			{
				fitnessRankValue += 1;
			}
		}

		// Assign the fitness value to the Candidate.
		p->candidate[candidate].fitness = fitnessRankValue;
	}

}

void Helper_functions::sortByBestRankFirst(Population * generation)
{
	for (int start = 0; start < populationSize; start++)
	{
		//Key to hold the candidate, that is compared against the rest,as the key
		Candidate key = generation->candidate[start + 1];
		int j = start;
		while (key.fitness > generation->candidate[j].fitness && j >= 0)
		{
			//Slide the bigger candidates to the right, of the Key Candidate
			generation->candidate[j + 1] = generation->candidate[j];
			j--;

		}

		generation->candidate[j + 1] = key;

	}

}
