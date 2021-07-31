cmake_minimum_required(VERSION 3.10)

project(ForgeEngine)

add_executable(forge_engine
src/d_math.c
src/i_input.c
src/i_video.c
src/main.c
src/p_map.c
src/p_player.c
src/r_buffer.c
src/r_ray.c
)
target_link_libraries(forge_engine SDL2 m)