#include "lib_life.h"
#include <string.h>

static int
neighbour_count(gl_world_t w, int x, int y)
{
	int j, k, cnt;

	cnt = 0;

	for (j = -1; j <= 1; j++)
	{
		for (k =  -1; k <= 1; k++)
		{
			if ((j == 0) && (k == 0))
			{
				continue;
			}
			cnt += w[(x + j + WORLD_MAX_X) % WORLD_MAX_X]
				[(y + k + WORLD_MAX_Y) % WORLD_MAX_Y];
		}
	}
	return cnt;
}

int
gl_evolve(gl_world_t w)
{
	static gl_world_t temp;
	unsigned int x,y;
	int neighbours = 0;

	memset(temp, 0, sizeof(temp));

	for (x = 0; x < WORLD_MAX_X; x++)
	{
		for (y = 0; y < WORLD_MAX_Y; y++)
		{
			neighbours = neighbour_count(w, x, y);
			if (w[x][y] && (neighbours >= 2) && (neighbours <= 3))
			{
				temp[x][y] = 1;
			}
			else if (!w[x][y] && (neighbours == 3))
			{
				temp[x][y] = 1;
			}

		}
	}
	memcpy(w, temp, sizeof(w));
	return 0;
}
