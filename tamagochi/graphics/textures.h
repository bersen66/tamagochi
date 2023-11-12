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
} TextureIndex;

const char* CAT_TEXTURES[] = {
    "    =|'W'|=    ",
    "    =|-W-|=    ",
    " =|   'W'   |= ",
    " =|   -W-   |= ",
    "   <-Boris->   ",
};

const char* MONKE_TEXTURES[] = {
    "    @('_')@    ",
    "    @(-_-)@    ",
    " @(   '_'   )@ ",
    " @(   -_-   )@ ",
    "   <-Diego->   ",
};

const char* FROG_TEXTURES[] = {
    "     c(o )     ",
    "     -(- )     ",
    "   c(o     )   ",
    "   -(-     )   ",
    "   <-Klava->   ",
};