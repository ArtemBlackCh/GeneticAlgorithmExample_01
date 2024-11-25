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

	GeneticAlgorithm algorithm = GeneticAlgorithm(1, 10, -20, 20);

	algorithm.RunFor(100);

	GeneticEntity bestEntity = algorithm.GetBestEntity();

	cout << "Result : x = " << bestEntity.GetX() << " y = " << bestEntity.GetY() << " z = " << bestEntity.GetResult();

}

