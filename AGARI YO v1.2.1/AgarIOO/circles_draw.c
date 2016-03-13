#include "agar.h"

void draw_circles(BITMAP *bmp, player_feature_t player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY],
                  int number_of_split, color_feature_t yem_color, color_feature_t player_color, location_t yem[SIZE_ARRAY],
                  circle_t green_things[SIZE_ARRAY], BITMAP *green_things_pic, FONT *font1)

{
    //KUCUKTEN BUYUGE DOGRU CIZIM YAPILIR (BUYUK OLAN KUCUK OLANIN USTUNDE CIZILIR)
    circle_t circles[SIZE_ARRAY];
    circle_t temp[SIZE_ARRAY];

    int sayac_split=0;
    int sayac=0;
    int number_circles=0;
    int i,j;

    //YEMLER CIZILIR
    while(sayac<YEM_NUMBER)
    {
        circlefill(bmp, (yem[sayac].location_x), (yem[sayac].location_y), RADIUS_YEM,
                   makecol(yem_color.red, yem_color.green, yem_color.blue));
        ++sayac;
    }
    sayac=0;

    //BOTS ARRAYA YERLESTIRILIR
    while(number_circles<BOT_NUMBER)
    {
        circles[number_circles].location_x=bots[number_circles].location_x;
        circles[number_circles].location_y=bots[number_circles].location_y;
        circles[number_circles].radius=bots[number_circles].radius;
        circles[number_circles].red=bots[number_circles].random_color_red;
        circles[number_circles].green=bots[number_circles].random_color_green;
        circles[number_circles].blue=bots[number_circles].random_color_blue;

        ++number_circles;
    }

    //PLAYER ARRAYA YERLESTIRILIR
    if(player.live_or_dead)
    {
        circles[number_circles].location_x=player.location_x;
        circles[number_circles].location_y=player.location_y;
        circles[number_circles].radius=player.radius;
        circles[number_circles].red=player_color.red;
        circles[number_circles].green=player_color.green;
        circles[number_circles].blue=player_color.blue;
        ++number_circles;
    }

    //SPLITS ARRAYA YERLESTIRILIR
    while(sayac_split< number_of_split)
    {
        circles[number_circles].location_x=splits[sayac_split].location_x;
        circles[number_circles].location_y=splits[sayac_split].location_y;
        circles[number_circles].radius=splits[sayac_split].radius;
        circles[number_circles].red=player_color.red;
        circles[number_circles].green=player_color.green;
        circles[number_circles].blue=player_color.blue;
        ++number_circles;
        ++sayac_split;
    }

    //KUCUKTEN BUYUGE SIRALAMA YAPILIR
    for(i=0;i<number_circles;i++)
    {
        for(j=0;j<number_circles;j++)
        {
            if((circles[i].radius)<=(circles[j].radius))
            {
                temp[0]=circles[i];
                circles[i]=circles[j];
                circles[j]=temp[0];
            }
        }
    }

    //KUCUKTEN BUYUGE DOGRU CIZIM YAPILIR
    while(sayac<number_circles)
    {
        circlefill(bmp, circles[sayac].location_x, circles[sayac].location_y, circles[sayac].radius,
                   makecol(circles[sayac].red, circles[sayac].green, circles[sayac].blue));
        ++sayac;
    }

    sayac=0;

    //GREEN THINGS CIZILIR
    while(sayac<GREEN_THINGS_NUMBER)
    {
        ellipsefill(bmp, green_things[sayac].location_x, green_things[sayac].location_y, RADIUS_GREEN_THING_rx, RADIUS_GREEN_THING_ry, makecol(0, 255, 0));
        textout_ex(bmp, font1, "GREEN", green_things[sayac].location_x-75, green_things[sayac].location_y-50, makecol(0, 0, 0), -1);
        textout_ex(bmp, font1, "AREA", green_things[sayac].location_x-75, green_things[sayac].location_y-20, makecol(0, 0, 0), -1);
        ++sayac;
    }
}
