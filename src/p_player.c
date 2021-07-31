#include "i_input.h"
#include "p_player.h"

pos2d_t player_position = { 4, 4 };
pos2d_t player_direction = { -1, 0 };
pos2d_t camera_plane = { 0, 0.5 };

const float move_speed = 0.005;
const float rotate_speed = 0.002;

void P_UpdatePlayer()
{
    // move the player
    if (I_IsKeyPressed(SDLK_w))
    {
        player_position.x += player_direction.x * move_speed;
        player_position.y += player_direction.y * move_speed;
    }
    if (I_IsKeyPressed(SDLK_s))
    {
        player_position.x -= player_direction.x * move_speed;
        player_position.y -= player_direction.y * move_speed;
    }
    
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