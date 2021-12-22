
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
	for (int start = 0; start < (populationSize-1); start++)
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

void Helper_functions::displayGeneration(Population * generation)
{

	Candidate *next = generation->candidate;
	for (int i = 0; i < (populationSize-1); i++)
	{
		cout << next[i].fitness << "\t" << next[i].genome << endl;

	}

}

void Helper_functions::createNewGeneration(Population * generation)
{
	for (int i = 0; i < (populationSize-1); i++)
	{
		//Elitisim: Candidate 1 & 2 pass unchanged to New Generation:

		//Replace 3rd candidate with pure cross over in New Generation:
		if (i == 2)
		{
			//We reset the fitness to 0, since we need to re-assess fitness after crossover.
			generation->candidate[i].fitness = 0;

			//We add in the new crossedover genome.
			generation->candidate[i].genome = Helper_functions::crossover(&generation->candidate[0], &generation->candidate[1]);

		}

		//Replace 4 - 10 with Alpha Candidate (top-most fitness) Crossover + Mutation:
		if (i > 2)
		{
			//We reset the fitness to 0, since we need to re-assess fitness after crossover.
			generation->candidate[i].fitness = 0;

			//We add in the new crossedover genome.
			generation->candidate[i].genome = Helper_functions::crossover(&generation->candidate[0], &generation->candidate[i]);

			//Try introducting mutations into the newly created genome:
			generation->candidate[i].genome = Helper_functions::mutation(generation->candidate[i].genome);

		}
	}

}

string Helper_functions::crossover(Candidate * c1, Candidate * c2)
{
	string c1Temp;
	c1Temp = c1->genome.substr(0, 5) + c2->genome.substr(5, 9);
	return c1Temp;
}

string Helper_functions::mutation(string genenomeToMutate)
{
	
	char table[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	for (int i = 0; i < genenomeToMutate.length(); i++)
	{
		if ((float)rand() / RAND_MAX < 0.12)
		{
			int randomNumber = rand() % (sizeof(table) - 1);
			genenomeToMutate[i] = table[randomNumber];
		}

	}	
	return genenomeToMutate;
}
