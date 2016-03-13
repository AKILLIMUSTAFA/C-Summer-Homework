#include "agar.h"

void eat_yem(player_feature_t *player, location_t yem[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split, bots_feature_t bots[SIZE_ARRAY])
{
    int sayac=YEM_NUMBER-1;
    int sayac_split=number_of_split-1;
    int sayac_bot=BOT_NUMBER-1;

    while(sayac>-1)
    {
        //PLAYERIN YEMI YEMESI
        if ((yem[sayac].location_x)>((player->location_x)-(player->radius)) && (yem[sayac].location_x)<((player->location_x)+(player->radius)) &&
            (yem[sayac].location_y)>((player->location_y)-(player->radius)) && (yem[sayac].location_y)<((player->location_y)+(player->radius)) &&
            (player->live_or_dead)==1 )
        {
            (player->radius)+=(RADIUS_YEM/GROWTH_RATE);
            (yem[sayac].location_x)=rand()%MAP_W;
            (yem[sayac].location_y)=rand()%MAP_H;
        }

        //SPLITIN YEMI YEMESI
        while(sayac_split>-1)
        {
            if ((yem[sayac].location_x)>((splits[sayac_split].location_x)-(splits[sayac_split].radius)) &&
                (yem[sayac].location_x)<((splits[sayac_split].location_x)+(splits[sayac_split].radius)) &&
                (yem[sayac].location_y)>((splits[sayac_split].location_y)-(splits[sayac_split].radius)) &&
                (yem[sayac].location_y)<((splits[sayac_split].location_y)+(splits[sayac_split].radius)))
            {
                (splits[sayac_split].radius)+=(RADIUS_YEM/GROWTH_RATE);
                (yem[sayac].location_x)=rand()%MAP_W;
                (yem[sayac].location_y)=rand()%MAP_H;
            }

             --sayac_split;
        }

         //BOTLARIN YEMI YEMESI
        while(sayac_bot>-1)
        {
            if ((yem[sayac].location_x)>((bots[sayac_bot].location_x)-(bots[sayac_bot].radius)) &&
                (yem[sayac].location_x)<((bots[sayac_bot].location_x)+(bots[sayac_bot].radius)) &&
                (yem[sayac].location_y)>((bots[sayac_bot].location_y)-(bots[sayac_bot].radius)) &&
                (yem[sayac].location_y)<((bots[sayac_bot].location_y)+(bots[sayac_bot].radius)))
            {
                (bots[sayac_bot].radius)+=(RADIUS_YEM/GROWTH_RATE);
                (yem[sayac].location_x)=rand()%MAP_W;
                (yem[sayac].location_y)=rand()%MAP_H;
            }

            --sayac_bot;
        }

        sayac_bot=BOT_NUMBER-1;
        sayac_split=number_of_split-1;
        --sayac;
    }
}
