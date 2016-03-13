#include "agar.h"

void division_green_things_player(player_feature_t *player, division_t splits[SIZE_ARRAY], int *number_of_split, circle_t green_things[SIZE_ARRAY],
                       int sayac_division)
{
    int artis_locationx=(DIVISION_GREEN_THINGS_SINIRI/2);
    int artis_locationy=(DIVISION_GREEN_THINGS_SINIRI/2);
    int check=1;

    //PARCALANMA GERCEKLESIYOR.
    //YENI SPLITLER OLUSTURULUYOR
    while(sayac_division>0)
    {
        if(check)
        {
            (splits[(*number_of_split)].location_x)=(player->location_x)+artis_locationx;
            (splits[(*number_of_split)].location_y)=(player->location_y);
            check=0;
        }

        else
        {
            (splits[(*number_of_split)].location_x)=(player->location_x);
            (splits[(*number_of_split)].location_y)=(player->location_y)+artis_locationy;
            check=1;
        }


        splits[(*number_of_split)].defeated=1;
        splits[(*number_of_split)].radius=(DIVISION_GREEN_THINGS_SINIRI/2);
        splits[(*number_of_split)].aktif=1;
        splits[(*number_of_split)].aktif_counter=1;

        artis_locationx+=(DIVISION_GREEN_THINGS_SINIRI/2);
        artis_locationy+=(DIVISION_GREEN_THINGS_SINIRI/2);

        ++(*number_of_split);
        --sayac_division;
    }

}

