#include "Random.h"
#include <math.h>
#include <random>

double Random::GetDouble(double min,double max)
{
    int t = 3;
    int n = pow(10, t) * abs(min - max);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, n);

    int a = dist(rng);

    double b = (a * 1.0) / n;

    b *= (max - min);

    b += min;

    return b;
}

bool Random::Probability(double threshold)
{
    if (threshold >= 100) 
        return true;

    if (threshold <= 0)
        return false;

    return GetDouble(0, 100) <= threshold;
}
