#include "agar.h"

void division_space_player(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split)

{
    int target=(number_of_split-1);

    //BOLUNME AKTIF HALE GELIYOR.
    splits[target].defeated=1;
    splits[target].aktif=1;
    splits[target].move_way_counter=1;

    //AYRILAN PARCANIN GIDECEGI YONUN BELIRLENMESI
    //1 YONU BATI, 3 YONU KUZEY, 5 YONU DOGU, 7 YONU GUNEY
    //2 YONU KUZEYBATI, 4 YONU KUZEYDOGU, 6 YONU GUNEYDOGU, 8 YONU GUNEYBATI

    //MOVE WAY 5 (EGER PLAYER HAREKET ETMIYORSA)
    if((player->location_x_last)==(player->location_x) && (player->location_y_last)==(player->location_y))
    {
        splits[target].move_way=5;
        (splits[target].location_x)=(player->location_x)+(player->radius);
        (splits[target].location_y)=(player->location_y);
    }

    else
    {
        //MOVE WAY 1
        if((player->location_x_last)>(player->location_x) && (player->location_y_last)==(player->location_y))
        {
            splits[target].move_way=1;
            (splits[target].location_x)=(player->location_x)-(player->radius);
            (splits[target].location_y)=(player->location_y);
        }

        //MOVE WAY 2
        else if((player->location_x_last)>(player->location_x) && (player->location_y_last)>(player->location_y))
        {
            splits[target].move_way=2;
            (splits[target].location_x)=(player->location_x)-(player->radius);
            (splits[target].location_y)=(player->location_y)-(player->radius);
        }

        //MOVE WAY 3
        else if((player->location_x_last)==(player->location_x) && (player->location_y_last)>(player->location_y))
        {
            splits[target].move_way=3;
            (splits[target].location_x)=(player->location_x);
            (splits[target].location_y)=(player->location_y)-(player->radius);
        }

        //MOVE WAY 4
        else if((player->location_x_last)<(player->location_x) && (player->location_y_last)>(player->location_y))
        {
            splits[target].move_way=4;
            (splits[target].location_x)=(player->location_x)+(player->radius);
            (splits[target].location_y)=(player->location_y)-(player->radius);
        }

        //MOVE WAY 5
        else if((player->location_x_last)<(player->location_x) && (player->location_y_last)==(player->location_y))
        {
            splits[target].move_way=5;
            (splits[target].location_x)=(player->location_x)+(player->radius);
            (splits[target].location_y)=(player->location_y);
        }

        //MOVE WAY 6
       else if((player->location_x_last)<(player->location_x) && (player->location_y_last)<(player->location_y))
        {
            splits[target].move_way=6;
            (splits[target].location_x)=(player->location_x)+(player->radius);
            (splits[target].location_y)=(player->location_y)+(player->radius);
        }

        //MOVE WAY 7
        else if((player->location_x_last)==(player->location_x) && (player->location_y_last)<(player->location_y))
        {
            splits[target].move_way=7;
            (splits[target].location_x)=(player->location_x);
            (splits[target].location_y)=(player->location_y)+(player->radius);
        }

        //MOVE WAY 8
        else
        {
            splits[target].move_way=8;
            (splits[target].location_x)=(player->location_x)-(player->radius);
            (splits[target].location_y)=(player->location_y)+(player->radius);
        }
    }

    // YARICAP YARIYA INIYOR.
    (player->radius)=((player->radius)/2);
    (splits[target].radius)=(player->radius);

}
