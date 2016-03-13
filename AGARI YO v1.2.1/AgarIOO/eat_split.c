#include "agar.h"

void eat_split(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split)

{
    //int sayac=BOT_NUMBER-1;
    int sayac_split=0;
    int sayac;
    int sayac_bot;

    while(sayac_split<number_of_split)
    {
        //PLAYERIN SPLITI YEMESI
        if ((splits[sayac_split].location_x)>((player->location_x)-(player->radius)) &&
            (splits[sayac_split].location_x)<((player->location_x)+(player->radius)) &&
            (splits[sayac_split].location_y)>((player->location_y)-(player->radius)) &&
            (splits[sayac_split].location_y)<((player->location_y)+(player->radius)) &&
            (player->radius)>=(splits[sayac_split].radius) && splits[sayac_split].defeated==1 &&
            splits[sayac_split].aktif==0)
        {
            (player->radius)+=((splits[sayac_split].radius));
            splits[sayac_split].defeated=0;
            splits[sayac_split].aktif=0;
            splits[sayac_split].location_x=0;
            splits[sayac_split].location_y=0;
            splits[sayac_split].radius=1;
        }

        sayac=number_of_split-1;

        //SPLITIN SPLITI YEMESI
        while(sayac>-1)
        {
            if(sayac!=sayac_split)
            {
                if ((splits[sayac_split].location_x)>((splits[sayac].location_x)-(splits[sayac].radius)) &&
                    (splits[sayac_split].location_x)<((splits[sayac].location_x)+(splits[sayac].radius)) &&
                    (splits[sayac_split].location_y)>((splits[sayac].location_y)-(splits[sayac].radius)) &&
                    (splits[sayac_split].location_y)<((splits[sayac].location_y)+(splits[sayac].radius)) &&
                    (splits[sayac].radius)>=(splits[sayac_split].radius) && splits[sayac_split].defeated==1 &&
                    splits[sayac_split].aktif==0)
                {
                    (splits[sayac].radius)+=((splits[sayac_split].radius));
                    splits[sayac_split].defeated=0;
                    splits[sayac_split].aktif=0;
                    splits[sayac_split].location_x=0;
                    splits[sayac_split].location_y=0;
                    splits[sayac_split].radius=1;
                }
            }
            --sayac;
        }

        sayac_bot=BOT_NUMBER-1;

        //BOTUN SPLITI YEMESI
        while(sayac_bot>-1)
        {
            if ((splits[sayac_split].location_x)>((bots[sayac_bot].location_x)-(bots[sayac_bot].radius)) &&
                (splits[sayac_split].location_x)<((bots[sayac_bot].location_x)+(bots[sayac_bot].radius)) &&
                (splits[sayac_split].location_y)>((bots[sayac_bot].location_y)-(bots[sayac_bot].radius)) &&
                (splits[sayac_split].location_y)<((bots[sayac_bot].location_y)+(bots[sayac_bot].radius)) &&
                (bots[sayac_bot].radius)>=(splits[sayac_split].radius+YEME_SINIRI) && splits[sayac_split].defeated==1)
            {
                (bots[sayac_bot].radius)+=((splits[sayac_split].radius));
                splits[sayac_split].defeated=0;
                splits[sayac_split].aktif=0;
                splits[sayac_split].location_x=0;
                splits[sayac_split].location_y=0;
                splits[sayac_split].radius=1;
            }

            --sayac_bot;
        }

        ++sayac_split;
    }
}
