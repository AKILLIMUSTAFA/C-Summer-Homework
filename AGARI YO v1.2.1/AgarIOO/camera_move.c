#include "agar.h"

void camera_move (player_feature_t player, division_t splits[SIZE_ARRAY], location_t *camera, int number_of_split)
{
    int camx;
    int camy;
    int i,j,temp;
    double circle_radius[number_of_split];
    int circle[number_of_split];
    int sayac_split=0;
    int number_circle=0;

    //SPLITLER ARRRAYA DIZILIR
    while(sayac_split<number_of_split)
    {
        circle_radius[number_circle]=splits[sayac_split].radius;
        circle[number_circle]=sayac_split;
        ++number_circle;
        ++sayac_split;
    }

    //SIRALAMA YAPILIR.
    for(i=0;i<number_circle;i++)
    {
        for(j=0;j<number_circle;j++)
        {
            if(circle_radius[i]<=circle_radius[j])
            {
                temp=circle_radius[i];
                circle_radius[i]=circle_radius[j];
                circle_radius[j]=temp;

                temp=circle[i];
                circle[i]=circle[j];
                circle[j]=temp;
            }
        }
    }

    //PLAYERDEN BUYUKSE TAKIBE ALINIR (EN BUYUK OLAN TAKIBE ALINIR)
    if(player.radius>=circle_radius[number_circle-1] && player.live_or_dead==1)
    {
        camx=(player.location_x)-(SCREEN_WW/2);
        camy=(player.location_y)-(SCREEN_HH/2);
    }

    else
    {
        camx=(splits[circle[number_circle-1]].location_x)-(SCREEN_WW/2);
        camy=(splits[circle[number_circle-1]].location_y)-(SCREEN_HH/2);
    }


    //CAMERANIN MAP SINIRLARI ICINDE KALMASI SAGLANIR

    if(camx<(MAP_W-SCREEN_WW))
        (camera->location_x)=camx;

    if(camy<(MAP_H-SCREEN_HH))
        (camera->location_y)=camy;

    if((camera->location_x)<0)
        (camera->location_x)=0;

     if((camera->location_y)<0)
        (camera->location_y)=0;

}
