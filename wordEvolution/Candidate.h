
#pragma once
#include<string>

using namespace std;


class Candidate
{
public: 
	int fitness;
	string genome;
	Candidate();

	static string genomeValue(int length);


};

