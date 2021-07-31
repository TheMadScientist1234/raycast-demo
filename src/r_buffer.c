#include "r_buffer.h"
#include "i_video.h"

#include <SDL2/SDL_render.h>
#include <stdlib.h>

typedef struct {
    int r;
    int g;
    int b;
    int a;
} color_t;

const color_t colors[] = {
    { 255, 255, 255, 255 },
    { 200, 200, 200, 255 }
};

int line_count = 0;
int line_capacity = 0;
line_t* lines = NULL;

// memory alignment from quake 2
int R_AlignMemory(int size)
{
    size = (size + 7) & ~(7);
    return size;
}

// add line to the drawing list
void R_AddLine(int col, int start_y, int end_y, lineColor_t color)
{
    line_t new_line = { col, start_y, end_y, color };

    if (line_count + 1 >= line_capacity)
    {
        line_capacity = R_AlignMemory(line_count + 1);
        lines = realloc(lines, sizeof(line_t) * line_capacity);
    }

    lines[line_count] = new_line;
    line_count++;
}

// draw all the lines
void R_DrawAll()
{
    SDL_SetRenderTarget(i_renderer, i_framebuffer);
    SDL_RenderClear(i_renderer);
    for (int i = 0; i < line_count; i++)
    {
        line_t cur_line = lines[i];
        color_t lineColor = colors[cur_line.color];
        SDL_SetRenderDrawColor(i_renderer, lineColor.r, lineColor.g, lineColor.b, lineColor.a);
        SDL_RenderDrawLine(i_renderer, cur_line.col, cur_line.start_y, cur_line.col, cur_line.end_y);
        SDL_SetRenderDrawColor(i_renderer, 0, 0, 0, 255);
    }
    SDL_SetRenderTarget(i_renderer, NULL);

    // clear the list of lines
    if (line_capacity > 0)
    {
        line_count = 0;
        line_capacity = 0;
        free(lines);
        lines = NULL;
    }
}