#include "agar.h"

void random_green_things_location(circle_t green_things[SIZE_ARRAY], int target)
{
    int sayac=GREEN_THINGS_NUMBER-1;

    //target bot icin rastgele koordinatlar
    //parcalanmýs green area icin yeni koordinatlar
    if(target!=(-1))
    {
        green_things[target].location_x=rand()%(MAP_W-RADIUS_GREEN_THING_rx)+RADIUS_GREEN_THING_rx;
        green_things[target].location_y=rand()%(MAP_H-RADIUS_GREEN_THING_ry)+RADIUS_GREEN_THING_ry;
    }

    else
    {
        //Target -1 ise oyun basi rastgele koordinatlar yesil alanlar icin
        while(sayac>-1)
        {
            green_things[sayac].location_x=rand()%(MAP_W-RADIUS_GREEN_THING_rx)+RADIUS_GREEN_THING_rx;
            green_things[sayac].location_y=rand()%(MAP_H-RADIUS_GREEN_THING_ry)+RADIUS_GREEN_THING_ry;
            --sayac;
        }
    }
}
