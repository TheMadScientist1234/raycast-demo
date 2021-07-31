#ifndef __I_INPUT_H_
#define __I_INPUT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>

void I_ProcessEvent(SDL_Event event);
int I_IsKeyPressed(SDL_KeyCode code);

#endif /* __I_INPUT_H_ */