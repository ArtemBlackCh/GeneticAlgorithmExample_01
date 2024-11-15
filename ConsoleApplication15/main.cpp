#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <list>
#include <iomanip>
#include "GeneticAlgorithm.h"

using namespace std;

int main() 
{
	cout << fixed;
	cout << setprecision(5);

	GeneticAlgorithm algorithm = GeneticAlgorithm(1,10);

	algorithm.RunUntil(1);

	//algorithm.RunFor(100);
}

