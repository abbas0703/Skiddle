#include <gb/gb.h>
#include <stdio.h>
#include "MazeSprites.h"
#include "MazeMap.h"
#include "Snail.h"

const char blankmap[1] = {0x00};

void performantdelay(uint8_t numloops) {
    for (uint8_t i = 0; i < numloops; i++) {
        wait_vbl_done();
    }     
}

UBYTE canplayermove(uint8_t newplayerx, uint8_t newplayery, UBYTE* haskey) {
    uint16_t indexTLx = (newplayerx - 8) / 8;
    uint16_t indexTLy = (newplayery - 16) / 8;
    uint16_t tileindexTL = 20 * indexTLy + indexTLx;

    UBYTE result = MazeMap[tileindexTL] == blankmap[0];

    switch(tileindexTL) {
        case 321:
            set_bkg_tiles(1, 16, 1, 1, blankmap);
            *haskey = 1;
            result = 1;
            break;
        case 263:
            if (*haskey) {
                set_bkg_tiles(3, 13, 1, 1, blankmap);
                result = 1;
            }
            break;
        case 340:
            HIDE_SPRITES;
            printf("\n \n \n \n \n \n \n \n \n      YOU WIN!");
            result = 1;
            break;
    }

    return result;
}

void animatesprite(uint8_t spriteindex, int8_t movex, int8_t movey) {
    while (movex != 0) {
        scroll_sprite(spriteindex, movex < 0 ? -1 : 1, 0);
        movex += (movex < 0 ? 1 : -1);
        wait_vbl_done();
    }
    while (movey != 0) {
        scroll_sprite(spriteindex, 0, movey < 0 ? -1 : 1);
        movey += movey < 0 ? 1 : -1;
        wait_vbl_done();
    }    
}

void main() {
    uint8_t playerlocation[2] = {16, 24};
    UBYTE haskey = 0;
    UBYTE gamerunning = 1;

    set_bkg_data(0, 4, MazeSprites);
    set_bkg_tiles(0, 0, 20, 18, MazeMap);

    set_sprite_data(0, 1, Snail);   
    set_sprite_tile(0, 0);           

    move_sprite(0, playerlocation[0], playerlocation[1]);

    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    while (gamerunning) {
        uint8_t joy = joypad();
        int8_t dx = 0, dy = 0;

        if (joy & J_LEFT) dx = -8;
        else if (joy & J_RIGHT) dx = 8;
        else if (joy & J_UP) dy = -8;
        else if (joy & J_DOWN) dy = 8;

        if (dx != 0 || dy != 0) {
            uint8_t newx = playerlocation[0] + dx;
            uint8_t newy = playerlocation[1] + dy;

            if (canplayermove(newx, newy, &haskey)) {
                playerlocation[0] = newx;
                playerlocation[1] = newy;
                animatesprite(0, dx, dy);
            }
        }

        performantdelay(6);
    }
}
