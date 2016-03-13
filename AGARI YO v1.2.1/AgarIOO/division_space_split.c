#include "agar.h"

void division_space_split(division_t splits[SIZE_ARRAY], int number_of_split, int sayac_split)
{
    int target=(number_of_split-1);

    //BOLUNME AKTIF HALE GELIYOR.
    splits[target].defeated=1;
    splits[target].aktif=1;
    splits[target].move_way_counter=1;

    //AYRILAN PARCANIN GIDECEGI YONUN BELIRLENMESI
    //1 YONU BATI, 3 YONU KUZEY, 5 YONU DOGU, 7 YONU GUNEY
    //2 YONU KUZEYBATI, 4 YONU KUZEYDOGU, 6 YONU GUNEYDOGU, 8 YONU GUNEYBATI

    //MOVE WAY 5 (EGER SPLIT HAREKET ETMIYORSA)
    if((splits[sayac_split].location_x_last)==(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)==(splits[sayac_split].location_y))
    {
        splits[target].move_way=5;
        (splits[target].location_x)=(splits[sayac_split].location_x)+(splits[sayac_split].radius);
        (splits[target].location_y)=(splits[sayac_split].location_y);
    }

    else
    {
        //MOVE WAY 1
        if((splits[sayac_split].location_x_last)>(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)==(splits[sayac_split].location_y))
        {
            splits[target].move_way=1;
            (splits[target].location_x)=(splits[sayac_split].location_x)-(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y);
        }

        //MOVE WAY 2
        else if((splits[sayac_split].location_x_last)>(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)>(splits[sayac_split].location_y))
        {
            splits[target].move_way=2;
            (splits[target].location_x)=(splits[sayac_split].location_x)-(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y)-(splits[sayac_split].radius);
        }

        //MOVE WAY 3
        else if((splits[sayac_split].location_x_last)==(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)>(splits[sayac_split].location_y))
        {
            splits[target].move_way=3;
            (splits[target].location_x)=(splits[sayac_split].location_x);
            (splits[target].location_y)=(splits[sayac_split].location_y)-(splits[sayac_split].radius);
        }

        //MOVE WAY 4
        else if((splits[sayac_split].location_x_last)<(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)>(splits[sayac_split].location_y))
        {
            splits[target].move_way=4;
            (splits[target].location_x)=(splits[sayac_split].location_x)+(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y)-(splits[sayac_split].radius);
        }

        //MOVE WAY 5
        else if((splits[sayac_split].location_x_last)<(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)==(splits[sayac_split].location_y))
        {
            splits[target].move_way=5;
            (splits[target].location_x)=(splits[sayac_split].location_x)+(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y);
        }

        //MOVE WAY 6
       else if((splits[sayac_split].location_x_last)<(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)<(splits[sayac_split].location_y))
        {
            splits[target].move_way=6;
            (splits[target].location_x)=(splits[sayac_split].location_x)+(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y)+(splits[sayac_split].radius);
        }

        //MOVE WAY 7
        else if((splits[sayac_split].location_x_last)==(splits[sayac_split].location_x) && (splits[sayac_split].location_y_last)<(splits[sayac_split].location_y))
        {
            splits[target].move_way=7;
            (splits[target].location_x)=(splits[sayac_split].location_x);
            (splits[target].location_y)=(splits[sayac_split].location_y)+(splits[sayac_split].radius);
        }

        //MOVE WAY 8
        else
        {
            splits[target].move_way=8;
            (splits[target].location_x)=(splits[sayac_split].location_x)-(splits[sayac_split].radius);
            (splits[target].location_y)=(splits[sayac_split].location_y)+(splits[sayac_split].radius);
        }
    }

    // YARICAP YARIYA INIYOR.
    (splits[sayac_split].radius)=((splits[sayac_split].radius)/2);
    (splits[target].radius)=(splits[sayac_split].radius);

}
