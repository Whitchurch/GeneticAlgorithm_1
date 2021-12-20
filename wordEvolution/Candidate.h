
#pragma once
#include<string>

using namespace std;

const int Genomelength = 10; // Change this to toggle length of the Genome. We can make this more general later, if needed.
class Candidate
{
public: 
	int fitness;
	string genome;
	Candidate();

	static string genomeValue(int length);


};

