#ifndef __I_VIDEO_H_
#define __I_VIDEO_H_

#include <SDL2/SDL.h>

#define WINDOWWIDTH 640
#define WINDOWHEIGHT 480

extern int window_width;
extern int window_height;

extern SDL_Renderer* i_renderer;
extern SDL_Texture* i_framebuffer;

void I_InitVideo();
void I_ShutdownVideo();

void I_UpdateVideo();
int  I_VideoShouldClose();

void I_VideoFrame();

#endif /* __I_VIDEO_H_ */