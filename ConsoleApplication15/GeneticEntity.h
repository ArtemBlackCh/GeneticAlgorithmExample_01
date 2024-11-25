#pragma once
#include "Random.h"

class GeneticEntity 
{
private:
	double _x = 0;
	double _y = 0;
	double _result = 0;
	
public:
	inline double GetX() { return _x; }
	inline double GetY() { return _y; }
	inline double GetResult() { return _result; }

	inline void SetX(double value) { _x = value; }
	inline void SetY(double value) { _y = value; }
	inline void SetResult(double value) { _result = value; }

	GeneticEntity()
	{
		_x = 0;
		_y = 0;
		_result = 0;
	}

	GeneticEntity(double X, double Y)
	{
		_x = X;
		_y = Y;
		_result = 0;
	}

	GeneticEntity(double MinX, double MaxX, double MinY, double MaxY)
	{
		_x = Random::GetDouble(MinX, MaxX);
		_y = Random::GetDouble(MinY, MaxY);
		_result = 0;
	}

	void Mutate(double probability);
};

