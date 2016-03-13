#include "agar.h"

void random_bot_target_location(bots_feature_t bots[SIZE_ARRAY], int target)
{
    int sayac=BOT_NUMBER-1;

    //target bot icin hedef koordinatlar
    //hedefe ulasmis icin rastgele yeni hedef
    if(target!=(-1))
    {
        bots[target].target_location_x=rand()%MAP_W;
        bots[target].target_location_y=rand()%MAP_H;
    }

    else
    {
        //Target -1 ise oyun basi ilk hedef botlar icin
        while(sayac>-1)
        {
            bots[sayac].target_location_x=rand()%MAP_W;
            bots[sayac].target_location_y=rand()%MAP_H;
            --sayac;
        }
    }
}
