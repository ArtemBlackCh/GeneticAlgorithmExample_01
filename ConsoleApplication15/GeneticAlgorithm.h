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
	int _mutationProbability = 40;

	double _minDoubleNum = -10;
	double _maxDoubleNum = 10;

	vector<GeneticEntity> _population;

	void Assess(GeneticEntity& entity);
	double ComparatorFunction(GeneticEntity entity);

public:
	inline vector<GeneticEntity> GetPopulation() { return  _population; }
	inline int GetGenerationCount() { return _generationCount; }
	inline int GetPopulationSize() { return _populationSize; }
	inline int GetFunctionType() { return _functionType; }
	inline GeneticEntity GetBestEntity() { return _population[0]; }

	inline void SetMaxDepth(int value) { _maxDepth = value; }
	inline void SetPopulationSize(int value) { _populationSize = value; }
	inline void SetFunctionType(int value) { _functionType = value; }
	inline void SetMutationProbability(int value) { _mutationProbability = value; }

	GeneticAlgorithm()
	{
		_populationSize = 10;
		_functionType = 1;
		_generationCount = 0;
		_population = vector<GeneticEntity>(_populationSize, GeneticEntity(-10, 10, -10, 10));
	}

	/// <param name="FunctionType"> 
	/// <para> Sets genetic function to... </para>
	/// <para> 1) sin(x) * cos(y) </para>
	/// <para> 2) -|(x - 1 ) * cos(y)| - |(y + 1) * cos(x)|</para>
	/// <para> 3) sin(x + sqrt(2)/2) + cos(x + sqrt(2)/2) + sin(y + 1/2) + cos(y + sqrt(3)/2) </para>
	/// </param>
	GeneticAlgorithm(int functionType, int populationSize)
	{
		_populationSize = populationSize;
		_functionType = functionType;
		_generationCount = 0;
		_population = vector<GeneticEntity>(_populationSize, GeneticEntity(_minDoubleNum, _maxDoubleNum, _minDoubleNum, _maxDoubleNum));
	}

	GeneticAlgorithm(int functionType, int populationSize, double minDoubleNum, double maxDoubleNum)
	{
		_populationSize = populationSize;
		_functionType = functionType;
		_generationCount = 0;
		_minDoubleNum = minDoubleNum;
		_maxDoubleNum = maxDoubleNum;
		_population = vector<GeneticEntity>(_populationSize, GeneticEntity(_minDoubleNum, _maxDoubleNum, _minDoubleNum, _maxDoubleNum));
	}

	GeneticAlgorithm(int functionType, int populationSize, double minDoubleNum, double maxDoubleNum, vector<GeneticEntity> population)
	{
		_populationSize = populationSize;
		_functionType = functionType;
		_generationCount = 0;
		_minDoubleNum = minDoubleNum;
		_maxDoubleNum = maxDoubleNum;
		_population = population;
	}

	void RunFor(int generationNumber);
	void RunUntil(double epsilon);
	void NextGeneration();
	void Mix();
	void Display();
	void SetConsoleColor(int color);
};

