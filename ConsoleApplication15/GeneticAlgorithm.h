#pragma once
#include <vector>
#include "GeneticEntity.h"

using namespace std;

class GeneticAlgorithm
{
private:
	int _functionType = 1;
	int _generationCount = 0;

	vector<GeneticEntity> _population;

	void Assess(GeneticEntity& entity);
	double ComparatorFunction(GeneticEntity entity);

public:
	/// <param name="FunctionType"> 
	/// <para> Sets genetic function to... </para>
	/// <para> 1 - sin </para>
	/// <para> 2 - cos </para>
	/// </param>
	GeneticAlgorithm(int functionType, int populationSize) : _population(populationSize, GeneticEntity(-10, 10, -10, 10))
	{
		_functionType = functionType;
		_generationCount = 0;
	}

	void RunFor(int generationNumber);
	void RunUntil(double epsilon);
	void NextGeneration();
	void Mix();
	void Display();

	bool CompareEntities(GeneticEntity entityA, GeneticEntity entityB);
};

