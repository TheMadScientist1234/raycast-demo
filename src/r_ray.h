#ifndef __R_RAY_H_
#define __R_RAY_H_

#include "i_video.h"

#define NUMRAYS ((int)window_width/(int)2)
#define FOV 60

void R_CastRays();

void R_InitRays();

#endif /* __R_RAY_H_ */