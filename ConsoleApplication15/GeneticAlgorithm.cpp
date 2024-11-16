#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "GeneticAlgorithm.h"
#define MUTATION_PROBABILITY 40
#define INACCURACY 10e-6

bool CompareEntities(GeneticEntity entityA, GeneticEntity entityB);

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
			return -1 * abs((entity.GetX() - 1) * cos(entity.GetY())) - 1 * abs((entity.GetY() + 1) * cos(entity.GetX()));
		case 3:
			return sin(entity.GetX() + sqrt(2) * 0.5) + cos(entity.GetX() + sqrt(2) * 0.5) + sin(entity.GetY() + 0.5) + cos(entity.GetY() + sqrt(3) * 0.5);
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
	int curentDepth = 0;

	while (_population[0].GetResult() < (epsilon - INACCURACY))
	{
		if (curentDepth >= _maxDepth)
		{
			break;
		}
		
		curentDepth++;

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
		cout << setw(10) <<x.GetX() << setw(10) << x.GetY() << setw(10) << x.GetResult() << endl;
	}
}

bool CompareEntities(GeneticEntity entityA, GeneticEntity entityB)
{
	return entityA.GetResult() > entityB.GetResult();
}