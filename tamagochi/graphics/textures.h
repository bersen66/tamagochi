#pragma once

/* c(o ") -- frog */
/* =|'W'|= -- cat */
/* @('_')@ -- monkey */


enum TextureIndex
{
    SLIM_BASIC = 0,
    SLIM_SLEEP = 1,
    FAT_BASIC = 2,
    FAT_SLEEP = 3,
    MENU_NAME = 4,
    GAME_NAME = 5,
} TextureIndex;

const char* CAT_TEXTURES[] = {
    "    =|'W'|=    ",
    "    =|-W-|=    ",
    " =|   'W'   |= ",
    " =|   -W-   |= ",
    "   <-Boris->   ",
    "     Boris     ",
};

const char* MONKE_TEXTURES[] = {
    "    @('_')@    ",
    "    @(-_-)@    ",
    " @(   '_'   )@ ",
    " @(   -_-   )@ ",
    "   <-Diego->   ",
    "     Diego     ",
};

const char* FROG_TEXTURES[] = {
    "     c(o )     ",
    "     -(- )     ",
    "   c(o     )   ",
    "   -(-     )   ",
    "   <-Klava->   ",
    "     Klava     ",
};

enum ActivityIndex
{
    PLAYING = 0,
    EATING = 1,
    SLEEPING = 2,
    WASHING = 3,
} ActivityIndex;

const char* ACTIVITIES[] = {
    "   IS PLAYING  ",
    "   IS EATING   ",
    "   IS SLEEPING ",
    "   IS WASHING  ",
};
