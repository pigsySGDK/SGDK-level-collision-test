#include <genesis.h>
#include <resources.h>

//#define MAP_HEIGHT_INTILES 89
#define MAP_HEIGHT 432
#define MAP_WIDTH 496

int camPosX;
int camPosY;

#define SOLID_TILE 1
#define PLATFORM_TILE 2
#define STAIRS_TILE 3


//Note to self: don't forget to change array size!!!
int level[54][62] = {
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1}
};

u16 bgBaseTileIndex[1];

Map *bgb;
//Map *bga;

typedef struct 
{
	int x;
	fix16 y;
} Point;

fix16 jumpingVel = FIX16(-5);
fix16 gravity = FIX16(0.2);
fix16 velY = FIX16(0);
bool moveLeft;
bool moveRight;
bool jump = FALSE;

typedef struct
{
	Point pos;
	Point tilePos;
	u16 w;
	u16 h;
	Sprite* sprite;
} Character;

Character maria = {{464, FIX16(304)}, {0, 0}, 24, 48, NULL};

static void handleInput();
//int getPlayerTile(u16 x, u16 y);
static void textDisplay();
static void movementAndCollision();
static void setSpritePosition(Sprite* sprite, int x, int y);
static void setCameraPosition(int x, int y);
static void updateCameraPosition();


char mariaX[10];
int mariaXDivide = 0;
char mariaXDivideEightChar[10];
char mariaY[10];
int mariaYDivide;
char mariaYDivideEightChar[10];
int currentTile;
char currentTileChar[10];
char currentVel[10];

int main()
{

	
	VDP_setPalette(PAL0, bgb_map.palette->data);
	//VDP_setPalette(PAL1, bga_map.palette->data);
	VDP_setPalette(PAL1, maria_sprite.palette->data);

	u16 ind;

	ind = TILE_USERINDEX;
	bgBaseTileIndex[0] = ind;
	VDP_loadTileSet(&bgb_tileset, ind , DMA);
	ind += bgb_tileset.numTile;
	/*
	bgBaseTileIndex[1] = ind;
	VDP_loadTileSet(&bga_tileset, ind, DMA);
	ind += bga_tileset.numTile;
	*/

	bgb = MAP_create(&bgb_map, BG_B, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[0]));
	//bga = MAP_create(&bga_map, BG_A, TILE_ATTR_FULL(0, FALSE, FALSE, FALSE, bgBaseTileIndex[1]));
	SYS_doVBlankProcess();

	SPR_init(0, 0, 0);
	maria.sprite = SPR_addSprite(&maria_sprite, maria.pos.x, fix16ToInt(maria.pos.y), TILE_ATTR(PAL1, 0, FALSE, FALSE));
	SPR_setPosition(maria.sprite, maria.pos.x, fix16ToInt(maria.pos.y));

	MAP_scrollTo(bgb, 177, 208);
	//MAP_scrollTo(bga, 0, 0);
	
	

	while(1)
	{

		
		handleInput();



		movementAndCollision();

		

		

		//int loc = level[(maria.pos.x/8)][(maria.pos.y/8)];

		textDisplay();

		


		
		SPR_update();
		SYS_doVBlankProcess();
	}

	MEM_free(bgb);
	return(0);
}

static void handleInput()
{
	u16 value = JOY_readJoypad(JOY_1);


	if (value & BUTTON_LEFT)
	{
		moveLeft = TRUE;
		/*
		futureX = maria.pos.x; //no need for -1, as want sprite to move closer to wall
		futureXDivide = futureX>>3;
		futureYDivideUpper = (fix16ToInt(maria.pos.y)+4)>>3;
		futureYDivideLowerLeft = (fix16ToInt(maria.pos.y) +47)>>3;
		futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
		futureTileBottomLeft = level[futureYDivideLowerLeft][futureXDivide];
		if (futureTileTopLeft != 1 && futureTileBottomLeft != 1) maria.pos.x -= 1;
		*/
		
	}
	if (value & !BUTTON_LEFT)
	{
		moveLeft = FALSE;
	}
	if (value & BUTTON_RIGHT)
	{
		moveRight = TRUE;
		/*
		futureX = maria.pos.x + 1;
		futureXDivide = (futureX+22)/8;
		futureYDivideUpper = (fix16ToInt(maria.pos.y)+4)/8;
		futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
		if (futureTileTopLeft != 1) maria.pos.x += 1;
		*/
	
	}
	if (value & !BUTTON_RIGHT)
	{
		moveRight = FALSE;
	}

	if (value & BUTTON_C)
	{
		if (jump == FALSE && velY == 0)
		{
			velY = fix16Add(velY, jumpingVel);
			jump = TRUE;
		}
	}
/*
	
	if (value & BUTTON_UP)
	{
		futureY = fix16Sub(maria.pos.y, velY);
		futureXDivide = (maria.pos.x+12)/8;
		futureYDivideUpper = (fix16ToInt(futureY)+4)/8;
		futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
		if (futureTileTopLeft != 1) maria.pos.y = fix16Sub(maria.pos.y, velY);
		
	}
	if (value & BUTTON_DOWN)
	{
		futureY = fix16Add(maria.pos.y, velY);
		futureXDivide = maria.pos.x/8;
		futureYDivideUpper = (fix16ToInt(futureY)+47)/8;
		futureTileBottomLeft = level[futureYDivideUpper][futureXDivide];
		if (futureTileBottomLeft != 1) maria.pos.y = fix16Add(maria.pos.y, velY);
	}

	futureY = maria.pos.y + 1;
	futureYDivideUpper = (futureY+47)/8;
	futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
	if (futureTileTopLeft != 1) maria.pos.y += gravity;
*/


}



/*
int getPlayerTile(u16 x, u16 y)
{	
	

	
	return *(&level[0][0] + (y * MAP_HEIGHT_INTILES + x));
}
*/

static void textDisplay()
{
	sprintf(mariaX, "%4d", maria.pos.x);
	VDP_drawText(mariaX, 10, 10);

	mariaXDivide = maria.pos.x/8;
	sprintf(mariaXDivideEightChar, "%4d", mariaXDivide);
	VDP_drawText(mariaXDivideEightChar, 10, 12);

	sprintf(mariaY, "%4d", fix16ToInt(maria.pos.y));
	VDP_drawText(mariaY, 10, 14);

	mariaYDivide = fix16ToInt(maria.pos.y)/8;
	sprintf(mariaYDivideEightChar, "%4d", mariaYDivide);
	VDP_drawText(mariaYDivideEightChar, 10, 16);



	sprintf(currentVel, "%4d", velY);
	VDP_drawText(currentVel, 10, 22);
}

static void movementAndCollision()
{
	int futureTileTopLeft;
	int futureTileBottomLeft;
	int futureTileTopRight;
	int futureTileBottomRight;
	int futureTileBottomCentre;
	int futureTileCentre;

	int futureX;
	fix16 futureY;
	int futureXDivide;
	int futureYDivide;
	int futureXDivideR;

	int futureYDivideUpper;
	//int futureYDivideUpperRight;

	int futureYDivideCentre;

	int futureYDivideLower;
	//int futureYDivideLowerRight;
	int futureYDivideLowerPlusOne;
	

	int futureXDivideLeft;
	int futureXDivideRight;
	int futureXDivideCentre;

	fix16 velYWithGravity;

	if (moveLeft)
	{
		
		
		futureX = maria.pos.x -1 ; 
		futureXDivide = futureX>>3;
		futureYDivideUpper = (fix16ToInt(maria.pos.y)+4)>>3;
		futureYDivideLower = (fix16ToInt(maria.pos.y) +47)>>3;
		futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
		futureTileBottomLeft = level[futureYDivideLower][futureXDivide];

		futureYDivideCentre = (fix16ToInt(maria.pos.y) + 25) >> 3;
		futureTileCentre = level[futureYDivideCentre][futureXDivide];
		

		futureYDivideLowerPlusOne = (fix16ToInt(maria.pos.y) +55)>>3;
		futureXDivideR = (futureX+16)/8;
		futureTileBottomRight = level[futureYDivideLowerPlusOne][futureXDivide];

		if (futureTileBottomRight == STAIRS_TILE)
		{
			maria.pos.y = fix16Add(maria.pos.y, FIX16(1));
			maria.pos.x -= 1;
						
		}
		else if (futureTileTopLeft != SOLID_TILE && futureTileBottomLeft != SOLID_TILE && futureTileCentre != SOLID_TILE) maria.pos.x -= 1;


		

		moveLeft = FALSE;
		
	}
	else if (moveRight)
	{
		
		
		futureX = maria.pos.x + 1;
		futureXDivide = (futureX+22)/8;
		futureYDivideUpper = (fix16ToInt(maria.pos.y)+4)/8;
		futureYDivideLower = (fix16ToInt(maria.pos.y) +47)>>3;
		futureTileTopRight = level[futureYDivideUpper][futureXDivide];
		futureTileBottomRight = level[futureYDivideLower][futureXDivide];

		//currentTile = level[mariaYDivide][mariaXDivide];
		sprintf(currentTileChar, "%4d", futureTileBottomRight);
		//sprintf(currentTileChar, "%4d", currentTile);
		VDP_drawText(currentTileChar, 10, 20);

		if (futureTileBottomRight == 3)
		{
			maria.pos.x += 1;
			maria.pos.y = fix16Sub(maria.pos.y, FIX16(1));
		}
		else if (futureTileTopRight != 1 && futureTileBottomRight != 1) maria.pos.x += 1;
		

		moveRight = FALSE;
	}

	velYWithGravity = fix16Add(velY, gravity);
	futureY = fix16Add(velYWithGravity, maria.pos.y);
	futureYDivide = (fix16ToInt(futureY) + 47) / 8;
	futureYDivideUpper = (fix16ToInt(futureY) +4) / 8;

	futureXDivideLeft = (maria.pos.x + 4)/8;
	futureTileBottomLeft = level[futureYDivide][futureXDivideLeft];
	futureXDivideRight = (maria.pos.x + 21)/8;
	futureTileBottomRight = level[futureYDivide][futureXDivideRight];
	futureXDivideCentre = (maria.pos.x + 13)/8;
	futureTileBottomCentre = level[futureYDivide][futureXDivideCentre];

	futureTileTopLeft = level[futureYDivideUpper][futureXDivideLeft];
	futureTileTopRight = level[futureYDivideUpper][futureXDivideRight];


	


	//futureTileBottomRight = level[futureYDivideLowerRight][futureXDivide];


	/*
	if (futureTileBottomLeft == PLATFORM_TILE && velY > 0)
	{
		velY = FIX16(0); 
		jump = FALSE;
	}
	*/

	if (futureTileBottomRight == 3)
	{
		velY = FIX16(0);
		jump = FALSE;
	}

	else if (futureTileTopLeft == 1 || futureTileTopRight == 1)
	{
		velY = FIX16(0);
	}

	else if( (futureTileBottomLeft == 1 || futureTileBottomRight == 1) || ((futureTileBottomLeft == 2 || futureTileBottomRight == 2) && velY >= FIX16(0)) )
	{
		velY = FIX16(0);
		jump = FALSE;		
	}
	else
	{
		velY = fix16Add(velY, gravity);
		maria.pos.y = futureY;		
	}



	updateCameraPosition();
	setSpritePosition(maria.sprite, (maria.pos.x - camPosX), (fix16ToInt(maria.pos.y) - camPosY));

	/*
	else if ((futureTileBottomLeft == 0) || ((futureTileBottomLeft == 2) && velY < FIX16(0)))
	{
		velY = fix16Add(velY, gravity);
		maria.pos.y = futureY;
	} 
	else
	{
		velY = FIX16(0);
		jump = FALSE;
	}

	*/


/*
	if (value & BUTTON_UP)
	{
		futureY = fix16Sub(maria.pos.y, velY);
		futureXDivide = (maria.pos.x+12)/8;
		futureYDivideUpper = (fix16ToInt(futureY)+4)/8;
		futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
		if (futureTileTopLeft != 1) maria.pos.y = fix16Sub(maria.pos.y, velY);
		
	}
	if (value & BUTTON_DOWN)
	{
		futureY = fix16Add(maria.pos.y, velY);
		futureXDivide = maria.pos.x/8;
		futureYDivideUpper = (fix16ToInt(futureY)+47)/8;
		futureTileBottomLeft = level[futureYDivideUpper][futureXDivide];
		if (futureTileBottomLeft != 1) maria.pos.y = fix16Add(maria.pos.y, velY);
	}

	futureY = maria.pos.y + 1;
	futureYDivideUpper = (futureY+47)/8;
	futureTileTopLeft = level[futureYDivideUpper][futureXDivide];
	if (futureTileTopLeft != 1) maria.pos.y += gravity;
*/

}

static void updateCameraPosition()
{
    // Get player position (pixel)
    int px = maria.pos.x;
    int py = fix16ToInt(maria.pos.y);
    // Current sprite position on screen
    int px_scr = px - camPosX;
    int py_scr = py - camPosY;

    //s16 npx_cam, npy_cam;
	int npx_cam;
	int npy_cam;


    
    // Adjust new camera position
    if (px_scr > 170) npx_cam = px - 170;
    else if (px_scr < 120) npx_cam = px - 120;
    else npx_cam = camPosX;
    if (py_scr > 100) npy_cam = py - 100;
    else if (py_scr < 60) npy_cam = py - 60;
    else npy_cam = camPosY;

    
    // Clip camera position
    if (npx_cam < 0) npx_cam = 0;
    else if (npx_cam > (MAP_WIDTH - 320)) npx_cam = (MAP_WIDTH - 320);

	
    if (npy_cam < 0) npy_cam = 0;
    else if (npy_cam > (MAP_HEIGHT - 224)) npy_cam = (MAP_HEIGHT - 224);
	

    // Set new camera position
    setCameraPosition(npx_cam, npy_cam);
}

static void setCameraPosition(int x, int y)
{
    if ((x != camPosX) || (y != camPosY))
    {
        camPosX = x;
        camPosY = y;


        MAP_scrollTo(bgb, x, y); 
		//MAP_scrollTo(bga, x, y);    
        
    }
}


static void setSpritePosition(Sprite* sprite, int x, int y)
{
    // Clip out of screen sprites
    if ((x < -80) || (x > 320) || (y < -100) || (y > 240)) SPR_setVisibility(sprite, HIDDEN);
    else
    {
        SPR_setVisibility(sprite, VISIBLE);
        SPR_setPosition(sprite, x, y);
    }
}