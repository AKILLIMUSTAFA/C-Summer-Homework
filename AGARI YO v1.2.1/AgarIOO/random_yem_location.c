#include "agar.h"

void random_yem_location(location_t yem[SIZE_ARRAY])
{
    int sayac=YEM_NUMBER-1;

    //YEMLER ICIN RASTGELE KOORDINATLAR
    while(sayac>(-1))
    {
        yem[sayac].location_x=rand()%MAP_W;
        yem[sayac].location_y=rand()%MAP_H;
        --sayac;
    }
}
