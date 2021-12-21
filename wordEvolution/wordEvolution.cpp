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
    cout << "Start of Genetic Algorithm!\n";
	string optima = "whitchurch";
	
	//Step 1:
	//Create a population of Person/Candidate.
	//Each Person/Candidate has Genome of Length 10, and Fitness score = 0, initially.
	Population* generation = new Population();


	//Step 2: Calculate the fitness of each Person/Candidate in the population.
	Helper_functions::fitnessRank(generation,optima);

	//Step 3: Sort the population based on fitness rank.
	//int sample[4] = { 10,9,8,7};
	
	for (int start = 0; start < populationSize ; start++)
	{
		//Key to hold the candidate, that is compared against the rest,as the key
		Candidate key = generation->candidate[start+1];
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

