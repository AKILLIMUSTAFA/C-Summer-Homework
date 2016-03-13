#include "agar.h"

void division_space_move_way(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split)

{
    //BOLUNMENIN GERCEKLESTIGI YON
    //GIDILEN YONE DOGRU LOCATION X VE Y ARTIRILIR YA DA AZALTILIR

    int artis=12;
    int sayac=(number_of_split-1);


    while(sayac>-1)
    {

        if(splits[sayac].move_way!=0)
        {
            //MOVE WAY 1
            if(splits[sayac].move_way==1 && (splits[sayac].location_x)>(splits[sayac].radius))
            {
                (splits[sayac].location_x)=(splits[sayac].location_x)-artis;
            }

             //MOVE WAY 2
            else if(splits[sayac].move_way==2)
            {
                if((splits[sayac].location_x)>(splits[sayac].radius))
                {
                    (splits[sayac].location_x)=(splits[sayac].location_x)-artis;
                }

                if((splits[sayac].location_y)>(splits[sayac].radius))
                {
                    (splits[sayac].location_y)=(splits[sayac].location_y)-artis;
                }
            }

             //MOVE WAY 3
            else if(splits[sayac].move_way==3 && (splits[sayac].location_y)>(splits[sayac].radius))
            {
                (splits[sayac].location_y)=(splits[sayac].location_y)-artis;
            }

             //MOVE WAY 4
            else if(splits[sayac].move_way==4)
            {
                if((splits[sayac].location_x)<(MAP_W-(splits[sayac].radius)))
                {
                    (splits[sayac].location_x)=(splits[sayac].location_x)+artis;
                }


                if((splits[sayac].location_y)>(splits[sayac].radius))
                {
                    (splits[sayac].location_y)=(splits[sayac].location_y)-artis;
                }
            }

             //MOVE WAY 5
            else if(splits[sayac].move_way==5 && (splits[sayac].location_x)<(MAP_W-(splits[sayac].radius)))
            {
                (splits[sayac].location_x)=(splits[sayac].location_x)+artis;
            }

             //MOVE WAY 6
            else if(splits[sayac].move_way==6)
            {
                if((splits[sayac].location_x)<(MAP_W-(splits[sayac].radius)))
                {
                    (splits[sayac].location_x)=(splits[sayac].location_x)+artis;
                }

                if((splits[sayac].location_y)<(MAP_H-(splits[sayac].radius)))
                {
                    (splits[sayac].location_y)=(splits[sayac].location_y)+artis;
                }

            }

             //MOVE WAY 7
            else if(splits[sayac].move_way==7 && (splits[sayac].location_y)<(MAP_H-(splits[sayac].radius)))
            {
                (splits[sayac].location_y)=(splits[sayac].location_y)+artis;
            }

             //MOVE WAY 8
            else if(splits[sayac].move_way==8)
            {
                if((splits[sayac].location_x)>(splits[sayac].radius))
                {
                    (splits[sayac].location_x)=(splits[sayac].location_x)-artis;
                }

                if((splits[sayac].location_y)<(MAP_H-(splits[sayac].radius)))
                {
                    (splits[sayac].location_y)=(splits[sayac].location_y)+artis;
                }
            }

            ++splits[sayac].move_way_counter;
        }

        if((splits[sayac].move_way_counter)>((player->radius)/3))
        {
            splits[sayac].move_way_counter=0;
            splits[sayac].move_way=0;
        }

        --sayac;
    }

    //merger again
}
