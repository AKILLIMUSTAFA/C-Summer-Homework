#include "agar.h"

void blue_mouse_icon(location_t *sprite, player_feature_t player)
{

    //MAVI MOUSE ICONUNUN EKRAN CERCEVESINDE KALMASI SAGLANIR(X LOCATION)
    if((mouse_x)>(player.location_x)-(SCREEN_WW/2) && (mouse_x)<(player.location_x)+(SCREEN_WW/2))
    {
        (sprite->location_x)=(mouse_x);
    }

    else if((mouse_x)<=(player.location_x)-(SCREEN_WW/2))
    {
        (sprite->location_x)=(player.location_x)-(SCREEN_WW/2);
    }

    else
    {
        (sprite->location_x)=(player.location_x)+(SCREEN_WW/2)-20;
    }

    //MAVI MOUSE ICONUNUN EKRAN CERCEVESINDE KALMASI SAGLANIR(Y LOCATION)
    if((mouse_y)>(player.location_y)-(SCREEN_HH/2) && (mouse_y)<(player.location_y)+(SCREEN_HH/2))
    {
        (sprite->location_y)=(mouse_y);
    }

    else if((mouse_y)<=(player.location_y)-(SCREEN_HH/2))
    {
        (sprite->location_y)=(player.location_y)-(SCREEN_HH/2);
    }

    else
    {
        (sprite->location_y)=(player.location_y)+(SCREEN_HH/2)-20;
    }

}
