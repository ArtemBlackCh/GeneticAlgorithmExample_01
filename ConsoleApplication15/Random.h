#pragma once
class Random
{
private:
    Random()
    {

    }

public:
    static double GetDouble(double min, double max);
    static bool Probability(double threshold);
};