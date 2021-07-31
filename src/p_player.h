#ifndef __P_PLAYER_H_
#define __P_PLAYER_H_

#include "d_math.h"

extern pos2d_t player_position;
extern pos2d_t player_direction;
extern pos2d_t camera_plane;

void P_UpdatePlayer();

#endif /* __P_PLAYER_H_ */