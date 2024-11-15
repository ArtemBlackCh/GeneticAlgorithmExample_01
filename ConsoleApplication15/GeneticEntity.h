#pragma once
#include "Random.h"
#include "GeneticAlgorithm.h"
class GeneticEntity
{
private:
	double _x = 0;
	double _y = 0;
	double _result = 0;
	
public:
	double GetX();
	double GetY();
	double GetResult();

	GeneticEntity(){}

	GeneticEntity(double X, double Y)
	{
		_x = X;
		_y = Y;
	}

	GeneticEntity(double MinX, double MaxX, double MinY, double MaxY)
	{
		_x = Random::GetDouble(MinX, MaxX);
		_y = Random::GetDouble(MinY, MaxY);
	}

	void Mutate(double probability);

	void SetResult(double value);

};

