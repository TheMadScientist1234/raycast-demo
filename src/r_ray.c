#include "d_math.h"
#include "p_map.h"
#include "p_player.h"
#include "r_ray.h"
#include "r_buffer.h"

void R_CastRays()
{
    for (int x = 0; x < window_width; x++)
    {
        // x position in camera space (-1 to 1)
        float camera_x = 2 * ((float) x / (float) window_width) - 1;
        // direction of the current ray in camera space
        pos2d_t ray_dir = {
            player_direction.x + camera_plane.x * camera_x,
            player_direction.y + camera_plane.y * camera_x
        };

        int map_x = player_position.x;
        int map_y = player_position.y;

        float side_distance_x;
        float side_distance_y;

        float delta_distance_x = fabs(1 / ray_dir.x);
        float delta_distance_y = fabs(1 / ray_dir.y);
        float perp_wall_distance;

        int step_x = ray_dir.x < 0 ? -1 : 1;
        int step_y = ray_dir.y < 0 ? -1 : 1;

        if (ray_dir.x < 0)
            side_distance_x = (player_position.x - map_x) * delta_distance_x;
        else
            side_distance_x = (map_x+1.0 - player_position.x) * delta_distance_x;
        if (ray_dir.y < 0)
            side_distance_y = (player_position.y - map_y) * delta_distance_y;
        else
            side_distance_y = (map_y+1.0 - player_position.y) * delta_distance_y;

        // wall collision information
        int hit = 0;
        int side; // used for lighting

        // actual algorithm
        while (!hit)
        {
            if (side_distance_x < side_distance_y)
            {
                side_distance_x += delta_distance_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_distance_y += delta_distance_y;
                map_y += step_y;
                side = 1;
            }

            if (P_GetTileAtPos(map_x, map_y) > 0) hit = 1;
        }

        if (side == 0) perp_wall_distance = (map_x - player_position.x + (float)(1 - step_x)/2) / ray_dir.x;
        else           perp_wall_distance = (map_y - player_position.y + (float)(1 - step_y)/2) / ray_dir.y;

        // determine lighting
        lineColor_t line_color = WHITE;
        if (step_x < 0 && side == 0)
            line_color = GRAY;
        if (step_y >= 0 && side == 1)
            line_color = GRAY;

        // draw ray line
        int line_height = (int)(window_height / perp_wall_distance);
        int draw_start = -line_height / 2 + window_height / 2;
        if (draw_start < 0) draw_start = 0;
        R_AddLine(x, draw_start, line_height / 2 + window_height / 2, line_color);
    }
}

void R_InitRays()
{
}