#include "i_input.h"
#include "i_video.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

int window_width;
int window_height;

SDL_Window* window;
int window_should_close;

SDL_Renderer* i_renderer;
SDL_Texture* i_framebuffer;

void I_InitVideo()
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    window_width = WINDOWWIDTH;
    window_height = WINDOWHEIGHT;
    
    window = SDL_CreateWindow(
        "Forge Engine",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_SHOWN
    );

    window_should_close = 0;

    i_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    i_framebuffer = SDL_CreateTexture(
        i_renderer,
        SDL_PIXELFORMAT_RGB888,
        SDL_TEXTUREACCESS_TARGET,
        window_width,
        window_height
    );
}

void I_ShutdownVideo()
{
    SDL_DestroyTexture(i_framebuffer);
    SDL_DestroyRenderer(i_renderer);

    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void I_UpdateVideo()
{
    for (SDL_Event event; SDL_PollEvent(&event) != 0;)
    {
        I_ProcessEvent(event);
        if (event.type == SDL_QUIT)
            window_should_close = 1;
    }
}

int I_VideoShouldClose()
{
    return window_should_close;
}

void I_VideoFrame()
{
    SDL_RenderClear(i_renderer);
    SDL_RenderCopy(i_renderer, i_framebuffer, NULL, NULL);
    SDL_RenderPresent(i_renderer);
}