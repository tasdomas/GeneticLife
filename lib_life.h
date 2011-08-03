#ifndef __LIB_LIFE__

#define __LIB_LIFE__

#define WORLD_MAX_X 100
#define WORLD_MAX_Y 100

typedef unsigned char gl_world_t[WORLD_MAX_X][WORLD_MAX_Y];

int gl_evolve(gl_world_t w);

#endif
