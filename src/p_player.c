#include "i_input.h"
#include "p_map.h"
#include "p_player.h"

pos2d_t player_position = { 4, 4 };
pos2d_t player_direction = { -1, 0 };
pos2d_t camera_plane = { 0, 0.5 };

const float move_speed = 0.005;
const float rotate_speed = 0.002;

// perform collision raycasting
int P_CollisionCast(int backwards)
{
    pos2d_t ray_dir = player_direction;
    if (backwards)
    {
        ray_dir.x *= -1;
        ray_dir.y *= -1;
    }

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

    int hit = 0;
    int side; // used for normal calculation
    
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

    // get distance from the wall
    if (side == 0) perp_wall_distance = (map_x - player_position.x + (float)(1 - step_x)/2) / ray_dir.x;
    else           perp_wall_distance = (map_y - player_position.y + (float)(1 - step_y)/2) / ray_dir.y;
    
    return perp_wall_distance < 1;
}

void P_UpdatePlayer()
{
    // move the player
    pos2d_t move_amount = {};
    int backwards = 0;
    if (I_IsKeyPressed(SDLK_w))
    {
        move_amount.x = player_direction.x * move_speed;
        move_amount.y = player_direction.y * move_speed;
        backwards = 0;
    }
    else if (I_IsKeyPressed(SDLK_s))
    {
        move_amount.x = -player_direction.x * move_speed;
        move_amount.y = -player_direction.y * move_speed;
        backwards = 1;
    }

    // check for collision
    pos2d_t new_pos = { player_position.x + move_amount.x, player_position.y + move_amount.y };
    if (!P_CollisionCast(backwards))
        player_position = new_pos;
    
    // rotate the player
    if (I_IsKeyPressed(SDLK_a))
    {
        float old_dir_x = player_direction.x;
        player_direction.x = player_direction.x * cos(rotate_speed) - player_direction.y * sin(rotate_speed);
        player_direction.y = old_dir_x * sin(rotate_speed) + player_direction.y * cos(rotate_speed);
        float old_plane_x = camera_plane.x;
        camera_plane.x = camera_plane.x * cos(rotate_speed) - camera_plane.y * sin(rotate_speed);
        camera_plane.y = old_plane_x * sin(rotate_speed) + camera_plane.y * cos(rotate_speed);
    }

    if (I_IsKeyPressed(SDLK_d))
    {
        float old_dir_x = player_direction.x;
        player_direction.x = player_direction.x * cos(-rotate_speed) - player_direction.y * sin(-rotate_speed);
        player_direction.y = old_dir_x * sin(-rotate_speed) + player_direction.y * cos(-rotate_speed);
        float old_plane_x = camera_plane.x;
        camera_plane.x = camera_plane.x * cos(-rotate_speed) - camera_plane.y * sin(-rotate_speed);
        camera_plane.y = old_plane_x * sin(-rotate_speed) + camera_plane.y * cos(-rotate_speed);
    }
}