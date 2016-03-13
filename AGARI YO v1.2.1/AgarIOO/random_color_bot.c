#include "agar.h"

void random_color_bot(bots_feature_t bots[SIZE_ARRAY])
{
    int sayac=BOT_NUMBER-1;

    //BOTLAR ICIN RASTGELE RENK
    while(sayac>-1)
    {
        bots[sayac].random_color_red=rand()%255;
        bots[sayac].random_color_green=rand()%255;
        bots[sayac].random_color_blue=rand()%255;
        --sayac;
    }
}
