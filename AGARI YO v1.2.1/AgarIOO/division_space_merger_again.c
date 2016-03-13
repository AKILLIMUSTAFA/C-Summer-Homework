#include "agar.h"

void division_space_merger_again(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split)
{
    int sayac=(number_of_split-1);

    //BOLUNMEDEN SONRA DONGU BOYUNCA SAYAC ARTIRILIR
    //YAKLASIK 25 SANIYE SONRA 1000 SAYISININA ULASILIR
    //PLAYERIN PARCALARININ BIRLESMESINE IZIN VERILIR

    while(sayac>-1)
    {
        // aktif ve live ise
        if(splits[sayac].aktif==1)
        {
            ++(splits[sayac].aktif_counter);
        }

        if((splits[sayac].aktif_counter)==MERGER_AGAIN)
        {
            splits[sayac].aktif=0;
        }

        --sayac;
    }


}
