#include <math.h>
#include <iostream>
#include <algorithm>
#include "GeneticAlgorithm.h"
#define MUTATION_PROBABILITY 40
#define INACCURACY 10e-5

void GeneticAlgorithm::Assess(GeneticEntity& entity)
{
	entity.SetResult(ComparatorFunction(entity));
}

double GeneticAlgorithm::ComparatorFunction(GeneticEntity entity)
{
	switch (_functionType)
	{
		case 1 :
			return sin(entity.GetX()) * cos(entity.GetY());
		case 2 :
			return 0;
		default :
			return 0;
	}
}

void GeneticAlgorithm::RunFor(int generationNumber)
{
	for (int i = 0; i < generationNumber; i++)
	{
		NextGeneration();
	}
}

void GeneticAlgorithm::RunUntil(double epsilon)
{
	while (abs(_population[0].GetResult() - epsilon) > INACCURACY);
	{
		NextGeneration();
	}
}

void GeneticAlgorithm::NextGeneration()
{
	Mix();

	sort(_population.begin(), _population.end(), CompareEntities);

	_generationCount++;

	Display();
}

void GeneticAlgorithm::Mix()
{
	vector<GeneticEntity> newPopulation = vector<GeneticEntity> (_population.size());

	vector<vector<short>> crossRatio = { {0,0},{0,1},{1,0},{0,2},{2,0},{1,3},{3,1},{2,4},{4,2} };

	int x_num, y_num;
	double x,y;

	for (int i = 0; i < crossRatio.size(); i++)
	{
		x_num = crossRatio[i][0];
		y_num = crossRatio[i][1];

		x = _population[x_num].GetX();
		y = _population[y_num].GetY();

		newPopulation[i] = GeneticEntity(x, y);

		if (i != 0)
		{
			newPopulation[i].Mutate(MUTATION_PROBABILITY);
		}

		Assess(newPopulation[i]);
	}

	for (int i = crossRatio.size(); i < _population.size(); i++)
	{
		newPopulation[i] = GeneticEntity(-10, 10, -10, 10);

		Assess(newPopulation[i]);
	}

	_population = newPopulation;
}

void GeneticAlgorithm::Display()
{
	system("cls");

	cout << "ganeration count: " << _generationCount<<endl;

	for (GeneticEntity x : _population)
	{
		cout << x.GetX() << x.GetY() << x.GetResult()<<endl;
	}
}

bool GeneticAlgorithm::CompareEntities(GeneticEntity entityA, GeneticEntity entityB)
{
	return entityA.GetResult() < entityB.GetResult();
}
