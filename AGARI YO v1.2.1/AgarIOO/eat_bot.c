#include "agar.h"

void eat_bot(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split)

{
    int sayac=BOT_NUMBER-1;
    int sayac_split=number_of_split-1;
    int sayac_bot=BOT_NUMBER-1;

    while(sayac>-1)
    {
        //PLAYERIN BOTU YEMESI
        if ((bots[sayac].location_x)>((player->location_x)-(player->radius)) && (bots[sayac].location_x)<((player->location_x)+(player->radius)) &&
            (bots[sayac].location_y)>((player->location_y)-(player->radius)) && (bots[sayac].location_y)<((player->location_y)+(player->radius)) &&
            (player->radius)>((bots[sayac].radius)+YEME_SINIRI) && player->live_or_dead==1)
        {
            (player->radius)+=((bots[sayac].radius)/GROWTH_RATE);
            (bots[sayac].location_x)=rand()%MAP_W;
            (bots[sayac].location_y)=rand()%MAP_H;
            (bots[sayac].radius)=RADIUS_BOT;
        }

        //SPLITIN BOTU YEMESI
        while(sayac_split>-1)
        {
            if ((bots[sayac].location_x)>((splits[sayac_split].location_x)-(splits[sayac_split].radius)) && (bots[sayac].location_x)<((splits[sayac_split].location_x)+(splits[sayac_split].radius)) &&
                (bots[sayac].location_y)>((splits[sayac_split].location_y)-(splits[sayac_split].radius)) && (bots[sayac].location_y)<((splits[sayac_split].location_y)+(splits[sayac_split].radius)) &&
                (splits[sayac_split].radius)>((bots[sayac].radius)+YEME_SINIRI))
            {
                (splits[sayac_split].radius)+=((bots[sayac].radius)/GROWTH_RATE);
                (bots[sayac].location_x)=rand()%MAP_W;
                (bots[sayac].location_y)=rand()%MAP_H;
                (bots[sayac].radius)=RADIUS_BOT;
            }

            --sayac_split;
        }

        //DIGER BOTLARIN BOTU YEMESI
        while(sayac_bot>-1)
        {
            if ((bots[sayac].location_x)>((bots[sayac_bot].location_x)-(bots[sayac_bot].radius)) &&
                (bots[sayac].location_x)<((bots[sayac_bot].location_x)+(bots[sayac_bot].radius)) &&
                (bots[sayac].location_y)>((bots[sayac_bot].location_y)-(bots[sayac_bot].radius)) &&
                (bots[sayac].location_y)<((bots[sayac_bot].location_y)+(bots[sayac_bot].radius)) &&
                (bots[sayac_bot].radius)>((bots[sayac].radius)+YEME_SINIRI))
            {
                (bots[sayac_bot].radius)+=((bots[sayac].radius)/GROWTH_RATE);
                (bots[sayac].location_x)=rand()%MAP_W;
                (bots[sayac].location_y)=rand()%MAP_H;
                (bots[sayac].radius)=RADIUS_BOT;
            }

            --sayac_bot;
        }

        sayac_bot=BOT_NUMBER-1;
        sayac_split=number_of_split-1;
        --sayac;
    }
}
