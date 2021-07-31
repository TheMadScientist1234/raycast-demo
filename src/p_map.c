#include "d_math.h"
#include "p_map.h"

int map[MAPWIDTH * MAPHEIGHT] = {
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1
};

int P_GetTileAtPos(int x, int y)
{
    // bounds checking
    if (x >= MAPWIDTH)
        return 1;
    else if (x < 0)
        return 1;
    if (y >= MAPHEIGHT)
        return 1;
    else if (y < 0)
        return 1;

    // otherwise return the value at pos
    return map[y*MAPWIDTH + x];
}

int P_IsSolidVertLine(float x, float y)
{
    int map_x = D_Floor(x / TILEWIDTH);
    int map_y = D_Floor(y / TILEHEIGHT);
    return P_GetTileAtPos(map_x, map_y) || P_GetTileAtPos(map_x-1, map_y);
}

int P_IsSolidHorzLine(float x, float y)
{
    int map_x = D_Floor(x / TILEWIDTH);
    int map_y = D_Floor(y / TILEHEIGHT);
    return P_GetTileAtPos(map_x, map_y) || P_GetTileAtPos(map_x, map_y-1);
}