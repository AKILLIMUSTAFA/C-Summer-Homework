#include "agar.h"
#include "xbox.h"

void move_player(player_feature_t *player, double choose_control,division_t splits[SIZE_ARRAY], int number_of_split)
{
    int sayac_split=0;
    int player_move=0;

    //EGER PLAYER ONUNDE ENGEL VARSA HAREKET EDEMEZ
    //EGER PLAYER ONUNDE ENGEL YOKSA HAREKET EDEBILIR

    //KLAVYE ICIN
    if(choose_control==1)
    {
        //PLAYER MOVE
        if (key[KEY_LEFT] && (player->location_x)>(player->radius) && player->live_or_dead==1)
        {

            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<(splits[sayac_split].location_x))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (key[KEY_RIGHT] && (player->location_x)<(MAP_W-(player->radius)) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>(splits[sayac_split].location_x))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (key[KEY_UP] && (player->location_y)>(player->radius) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (key[KEY_DOWN] && (player->location_y)<(MAP_H-(player->radius)) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

    }

    //MOUSE ICIN
    if(choose_control==2)
    {
        //PLAYER MOVE
        if(mouse_x<(player->location_x) && (player->location_x)>(player->radius) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<(splits[sayac_split].location_x))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if(mouse_x>(player->location_x) && (player->location_x)<(MAP_W-(player->radius)) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>(splits[sayac_split].location_x))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if(mouse_y<(player->location_y) && (player->location_y)>(player->radius) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if(mouse_y>(player->location_y) && (player->location_y)<(MAP_H-(player->radius)) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

    }

    //GAMEPAD ICIN
    if(choose_control==3)
    {
        //PLAYER MOVE
        if (xbox[LSTICK_LEFT] && (player->location_x)>(player->radius) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<(splits[sayac_split].location_x))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (xbox[LSTICK_RIGHT] && (player->location_x)<(MAP_W-(player->radius)) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>(splits[sayac_split].location_x))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_x)=((player->location_x)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (xbox[LSTICK_UP] && (player->location_y)>(player->radius) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>((splits[sayac_split].location_y)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)-(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

        if (xbox[LSTICK_DOWN] && (player->location_y)<((MAP_H-(player->radius))) && player->live_or_dead==1)
        {
            while(sayac_split<number_of_split)
            {
                if(splits[sayac_split].aktif==1)
                {
                    //y koordinatinda split yukaridaysa
                    if((player->location_y)<((splits[sayac_split].location_y)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split asagidaysa
                    else if((player->location_y)>(splits[sayac_split].location_y))
                            ++player_move;

                    //y koordinatinda split esitse, sag taraftaysa,
                    else if((player->location_x)>((splits[sayac_split].location_x)+((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;

                    //y koordinatinda split esitse, sol taraftaysa
                    else if((player->location_x)<((splits[sayac_split].location_x)-((3*((splits[sayac_split].radius)+(player->radius)))/4)))
                            ++player_move;
                }

                else
                {
                    ++player_move;
                }
                ++sayac_split;
            }

            //PLAYERIN ONUNDE ENGEL OLUP OLMADIGINA BAKILIR
            if(player_move==number_of_split)
            {
                (player->location_y)=((player->location_y)+(player->speed));
            }

            player_move=0;
            sayac_split=0;
        }

    }
}
