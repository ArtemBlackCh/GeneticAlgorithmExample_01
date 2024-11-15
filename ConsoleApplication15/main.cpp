#include <iostream>
#include <math.h>
#include <random>
#include <vector>
#include <list>
#include <iomanip>
#include "random.h"
#include "GeneticAlgorithm.h"

using namespace std;

int main() 
{
	GeneticAlgorithm algorithm = GeneticAlgorithm(1,10);

	algorithm.RunUntil(0.95);

	algorithm.RunFor(100);


}

////class Object <<RIP>>

