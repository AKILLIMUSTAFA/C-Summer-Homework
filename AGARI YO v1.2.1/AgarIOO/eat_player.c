#include "agar.h"

void eat_player(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split)

{
    int sayac_split=number_of_split-1;
    int sayac_bot;

    //SPLITIN PLAYERI YEMESI
    while(sayac_split>-1)
    {
        if ((player->location_x)>((splits[sayac_split].location_x)-(splits[sayac_split].radius)) &&
            (player->location_x)<((splits[sayac_split].location_x)+(splits[sayac_split].radius)) &&
            (player->location_y)>((splits[sayac_split].location_y)-(splits[sayac_split].radius)) &&
            (player->location_y)<((splits[sayac_split].location_y)+(splits[sayac_split].radius)) &&
            (splits[sayac_split].radius)>=((player->radius)) && player->live_or_dead==1)
        {
            (splits[sayac_split].radius)+=((player->radius));
            (player->radius)=0;
            player->live_or_dead=0;
            player->location_x=0;
            player->location_y=0;
        }
        --sayac_split;
    }

    sayac_bot=BOT_NUMBER-1;

    //BOTUN PLAYERI YEMESI
    while(sayac_bot>-1)
    {
        if ((player->location_x)>((bots[sayac_bot].location_x)-(bots[sayac_bot].radius)) &&
            (player->location_x)<((bots[sayac_bot].location_x)+(bots[sayac_bot].radius)) &&
            (player->location_y)>((bots[sayac_bot].location_y)-(bots[sayac_bot].radius)) &&
            (player->location_y)<((bots[sayac_bot].location_y)+(bots[sayac_bot].radius)) &&
            (bots[sayac_bot].radius)>=((player->radius)+YEME_SINIRI) && player->live_or_dead==1)
        {
            (splits[sayac_split].radius)+=((player->radius));
            (player->radius)=0;
            player->live_or_dead=0;
            player->location_x=0;
            player->location_y=0;
        }

        --sayac_bot;
    }

}
