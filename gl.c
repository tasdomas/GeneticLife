#include "lib_life.h"

int main()
{
	gl_world_t world;
	int i;

	for (i = 0; i < 1000; i++)
	{
		gl_evolve(world);
	}
	return 0;
}
