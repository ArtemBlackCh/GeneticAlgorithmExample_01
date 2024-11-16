#pragma once
#include <vector>
#include "GeneticEntity.h"

using namespace std;

class GeneticAlgorithm
{
private:
	int _functionType = 1;
	int _generationCount = 0;
	int _populationSize = 10;
	int _maxDepth = 10000;

	vector<GeneticEntity> _population;

	void Assess(GeneticEntity& entity);
	double ComparatorFunction(GeneticEntity entity);

public:
	inline void SetMaxDepth(int value) { _maxDepth = value; }
	inline void SetPopulationSize(int value) { _populationSize = value; }
	inline void SetFunctionType(int value) { _functionType = value; }

	/// <param name="FunctionType"> 
	/// <para> Sets genetic function to... </para>
	/// <para> 1 - sin </para>
	/// <para> 2 - cos </para>
	/// </param>
	GeneticAlgorithm(int functionType, int populationSize)
	{
		_populationSize = populationSize;
		_functionType = functionType;
		_generationCount = 0;
		_population = vector<GeneticEntity>(_populationSize, GeneticEntity(-10, 10, -10, 10));
	}

	void RunFor(int generationNumber);
	void RunUntil(double epsilon);
	void NextGeneration();
	void Mix();
	void Display();
};

