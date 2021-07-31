#include "i_input.h"

int keys[1000000];

void I_ProcessEvent(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        keys[event.key.keysym.sym] = 1;
    }
    else if (event.type == SDL_KEYUP)
    {
        keys[event.key.keysym.sym] = 0;
    }
}

int I_IsKeyPressed(SDL_KeyCode code)
{
    return keys[code];
}