
#include "Candidate.h"
#include "GlobalParameters.h"
using namespace std;
Candidate::Candidate()
{
	
	this->fitness = 0;
	this->genome = genomeValue(Genomelength);

}

string Candidate::genomeValue(int length)
{
	string newGenome;
	char table[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	for (int i = 0; i < length; i++)
	{
		int randomNumber = rand() % (sizeof(table) - 1);
		newGenome += table[randomNumber];
	}
	
	return newGenome;
}



