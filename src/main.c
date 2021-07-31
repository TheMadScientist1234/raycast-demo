#include "i_video.h"
#include "p_player.h"
#include "r_buffer.h"
#include "r_ray.h"

int main()
{
    I_InitVideo();
    R_InitRays();

    while (!I_VideoShouldClose())
    {
        I_UpdateVideo();
        P_UpdatePlayer();

        R_CastRays();
        R_DrawAll();

        I_VideoFrame();
    }

    I_ShutdownVideo();
    return 0;
}