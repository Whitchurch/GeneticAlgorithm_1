
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
