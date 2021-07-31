#include "i_input.h"
#include "p_player.h"

pos2d_t player_position = { 4, 4 };
pos2d_t player_direction = { -1, 0 };
pos2d_t camera_plane = { 0, 0.5 };

float rotate_speed = 0.001;

void P_UpdatePlayer()
{
    // move the player
    if (I_IsKeyPressed(SDLK_w))
        player_position.x += 0.01;
    if (I_IsKeyPressed(SDLK_s))
        player_position.x -= 0.01;
    
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