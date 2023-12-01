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

char* CAT_TEXTURES[] = {
    "    =|'W'|=    \n",
    "    =|-W-|=    \n",
    " =|   'W'   |= \n",
    " =|   -W-   |= \n",
    "   <-Boris->   \n",
    "     Boris     \n",
};

char* MONKE_TEXTURES[] = {
    "    @('_')@    \n",
    "    @(-_-)@    \n",
    " @(   '_'   )@ \n",
    " @(   -_-   )@ \n",
    "   <-Diego->   \n",
    "     Diego     \n",
    
};

char* FROG_TEXTURES[] = {
    "     c(o )     \n",
    "     -(- )     \n",
    "   c(o     )   \n",
    "   -(-     )   \n",
    "   <-Klava->   \n",
    "     Klava     \n",
};

enum ActivityIndex
{
    PLAYING = 0,
    EATING = 1,
    SLEEPING = 2,
    WASHING = 3,
} ActivityIndex;

char* ACTIVITIES[] = {
    "   IS PLAYING  \n",
    "   IS EATING   \n",
    "   IS SLEEPING \n",
    "   IS WASHING  \n",
};
