#include "GeneticEntity.h"
#include "Random.h"
#define MUTATION_OFFSET 0
#define MUTATION_SHIFT 0.5

void GeneticEntity::Mutate(double probability)
{
	if (Random::Probability(probability))
	{
		_x += _x * Random::GetDouble(MUTATION_OFFSET - MUTATION_SHIFT, MUTATION_OFFSET + MUTATION_SHIFT);
	}

	if (Random::Probability(probability))
	{
		_y += _y * Random::GetDouble(MUTATION_OFFSET - MUTATION_SHIFT, MUTATION_OFFSET + MUTATION_SHIFT);
	}
}