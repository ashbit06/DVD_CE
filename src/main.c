#include <tice.h>
#include <graphx.h>
#include <gfx/gfx.h>

#define rand_disc DISCS[rand() % 21]
#define DISC_SIZE 48
gfx_sprite_t *DISCS[] = {
    music_disc_11,
    music_disc_13,
    music_disc_5,
    music_disc_blocks,
    music_disc_cat,
    music_disc_chirp,
    music_disc_creator,
    music_disc_creator_music_box,
    music_disc_far,
    music_disc_lava_chicken,
    music_disc_mall,
    music_disc_mellohi,
    music_disc_otherside,
    music_disc_pigstep,
    music_disc_precipice,
    music_disc_relic,
    music_disc_stal,
    music_disc_strad,
    music_disc_tears,
    music_disc_wait,
    music_disc_ward
};

// LCD width = 320
// LCD height = 240

int main() {
    srand(rtc_Time());
    gfx_Begin();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0x00);

    gfx_sprite_t *disc = rand_disc;
    int x = (rand() % (320 - 16));
    int y = (rand() % (240 - 16));
    int dx = 1;
    int dy = 1;
    
    gfx_SetDrawBuffer();
    gfx_FillScreen(0x00);
    
    while (!os_GetCSC()) {
        gfx_FillScreen(0x00);
        gfx_ScaledTransparentSprite_NoClip(disc, x, y, 3, 3);
        gfx_SwapDraw();
        
        x += dx;
        y += dy;

        if (x < 0) {
            dx = -dx;
            x = 0;
            disc = rand_disc;

        }
        if (y < 0) {
            dy = -dy;
            y = 0;
            disc = rand_disc;

        }
        if (x > (320 - DISC_SIZE)) {
            dx = -dx;
            x = 320 - DISC_SIZE;
            disc = rand_disc;

        }
        if (y > (240 - DISC_SIZE)) {
            dy = -dy;
            y = 240 - DISC_SIZE;
            disc = rand_disc;

        }
    }

    gfx_End();
    return 0;
}