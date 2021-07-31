#ifndef __P_MAP_H_
#define __P_MAP_H_

#define MAPWIDTH 8
#define MAPHEIGHT 8

#define TILEWIDTH 64
#define TILEHEIGHT 64

extern int map[MAPWIDTH * MAPHEIGHT];

int P_GetTileAtPos(int x, int y);
int P_IsSolidVertLine(float x, float y);
int P_IsSolidHorzLine(float x, float y);

#endif /* __P_MAP_H_ */