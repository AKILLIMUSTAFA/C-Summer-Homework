#include "agar.h"

void random_bot_location(bots_feature_t bots[SIZE_ARRAY], int target)
{
    int sayac=BOT_NUMBER-1;

    //target bot icin random location
    //yenilmis bot icin yeni hedef koordinatlar
    if(target!=(-1))
    {
        bots[target].location_x=rand()%MAP_W;
        bots[target].location_y=rand()%MAP_H;
    }

    else
    {
        //Target -1 ise oyun basi random locations botlar icin
        while(sayac>-1)
        {
            bots[sayac].location_x=rand()%MAP_W;
            bots[sayac].location_y=rand()%MAP_H;
            --sayac;
        }
    }
}
