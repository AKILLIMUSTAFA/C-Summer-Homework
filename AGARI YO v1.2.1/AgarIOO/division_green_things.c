#include "agar.h"

void division_green_things(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY],
                           int *number_of_split, circle_t green_things[SIZE_ARRAY])
{

    int sayac=GREEN_THINGS_NUMBER-1;
    int sayac_split=0;
    int temp_player_radius;
    int temp_split_radius;
    int sayac_division=0;

    while(sayac>-1)
    {
        //SPLITSLERIN GREEN THINGS TARAFINDAN BOLUNMESI
        while(sayac_split<(*number_of_split))
        {
            //EGER AYNI KOORDINATLARDA VE
            //YETEREINCE BUYUKSE SPLIT PARCALANIR
            if ((green_things[sayac].location_x)>((splits[sayac_split].location_x)-(splits[sayac_split].radius)) &&
                (green_things[sayac].location_x)<((splits[sayac_split].location_x)+(splits[sayac_split].radius)) &&
                (green_things[sayac].location_y)>((splits[sayac_split].location_y)-(splits[sayac_split].radius)) &&
                (green_things[sayac].location_y)<((splits[sayac_split].location_y)+(splits[sayac_split].radius)) &&
                (splits[sayac_split].radius)>DIVISION_GREEN_THINGS_SINIRI)
            {
                temp_split_radius=(splits[sayac_split].radius);

                //EN FAZLA 10 PARCA AYRILABILIYOR
                while(temp_split_radius>(DIVISION_GREEN_THINGS_SINIRI/4) && sayac_division<10)
                {
                    temp_split_radius=temp_split_radius-(DIVISION_GREEN_THINGS_SINIRI/2);
                    ++sayac_division;
                }

                //PARCALAMA FONKSIYONU
                division_green_things_split(splits, number_of_split, green_things, sayac_division, sayac_split);

                if(sayac_division==10 && temp_split_radius>32)
                {
                    (splits[sayac_split].radius)=temp_split_radius;
                }
                else
                {
                    splits[(sayac_split)].aktif=0;
                    splits[(sayac_split)].aktif_counter=0;
                    (splits[sayac_split].radius)=0;
                    (splits[sayac_split].defeated)=0;
                }

                (green_things[sayac].location_x)=rand()%MAP_W;
                (green_things[sayac].location_y)=rand()%MAP_H;
            }

            ++sayac_split;
        }

         sayac_division=0;
         sayac_split=0;

        //PLAYERIN GREEN THINGS TARAFINDAN PARCALANMASI

        //EGER AYNI KOORDINATLARDA VE
        //YETEREINCE BUYUKSE PLAYER PARCALANIR
        if ((green_things[sayac].location_x)>((player->location_x)-(player->radius)) &&
            (green_things[sayac].location_x)<((player->location_x)+(player->radius)) &&
            (green_things[sayac].location_y)>((player->location_y)-(player->radius)) &&
            (green_things[sayac].location_y)<((player->location_y)+(player->radius)) &&
            player->live_or_dead==1 && player->radius>DIVISION_GREEN_THINGS_SINIRI)
        {
            temp_player_radius=player->radius;

            while(temp_player_radius>(DIVISION_GREEN_THINGS_SINIRI/4) && sayac_division<10)
            {
                temp_player_radius=temp_player_radius-(DIVISION_GREEN_THINGS_SINIRI/2);
                ++sayac_division;
            }

            //PARCALAMA FONKSIYONU
            division_green_things_player(player, splits, number_of_split, green_things, sayac_division);

            if(sayac_division==10)
            {
                (player->radius)=temp_player_radius;
            }
            else
            {
                (player->radius)=0;
                player->live_or_dead=0;
            }

            (green_things[sayac].location_x)=rand()%MAP_W;
            (green_things[sayac].location_y)=rand()%MAP_H;
        }

        --sayac;

    }

}
