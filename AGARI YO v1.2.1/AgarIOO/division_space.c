#include "agar.h"
#include "xbox.h"

void division_space(player_feature_t *player, double choose_control, division_t splits[SIZE_ARRAY], int *number_of_split)
{
    int bolunme_siniri=BOLUNME_SINIRI;
    int sayac_split=0;
    int temp;
    int temp_last_split=-1;

    //BOLUNME

//KLAVYE ICIN

        //PLAYER
        if(choose_control==1 && key[KEY_SPACE] && (player->radius)>(bolunme_siniri) && player->live_or_dead==1)
        {
            if((*number_of_split)>0)
            {
                //ONCEKI BOLUNME BITENE KADAR BOLUNME OLMAZ
                if(splits[(*number_of_split)-1].move_way_counter==0)
                {
                    temp_last_split=(*number_of_split);
                    ++(*number_of_split);
                    division_space_player(player, splits, *number_of_split);
                }
            }

            //ILK DEFA BOLUNMEDE
            else
            {
                temp_last_split=(*number_of_split);
                ++(*number_of_split);
                division_space_player(player, splits, *number_of_split);
            }
        }

        //SPLITS
        if(choose_control==1 && key[KEY_SPACE] && (*number_of_split)>0)
        {
            temp=(*number_of_split);

            while(sayac_split<(temp))
            {
                if((splits[sayac_split].radius)>(bolunme_siniri) && sayac_split!=temp_last_split &&
                   (splits[sayac_split].move_way)==0)
                {
                    ++(*number_of_split);
                    division_space_split(splits, *number_of_split, sayac_split);
                }

                ++sayac_split;
            }
            sayac_split=0;
        }

//MOUSE ICIN

        //PLAYER
        if(choose_control==2 && (mouse_b & 1) && (player->radius)>(bolunme_siniri) && player->live_or_dead==1)
        {
            if((*number_of_split)>0)
            {
                //ONCEKI BOLUNME BITENE KADAR BOLUNME OLMAZ
                if(splits[(*number_of_split)-1].move_way_counter==0)
                {
                    temp_last_split=(*number_of_split);
                    ++(*number_of_split);
                    division_space_player(player, splits, *number_of_split);
                }
            }

            //ILK DEFA BOLUNMEDE
            else
            {
                temp_last_split=(*number_of_split);
                ++(*number_of_split);
                division_space_player(player, splits, *number_of_split);
            }
        }

        //SPLITS
        if(choose_control==2 && (mouse_b & 1) && (*number_of_split)>0)
        {
            temp=(*number_of_split);

            while(sayac_split<(temp))
            {
                if((splits[sayac_split].radius)>(bolunme_siniri) && sayac_split!=temp_last_split)
                {
                    ++(*number_of_split);
                    division_space_split(splits, *number_of_split, sayac_split);
                }

                ++sayac_split;
            }
            sayac_split=0;
        }

//GAMEPAD ICIN

        //PLAYER
        if(choose_control==3 && xbox[BUTTON_A] && (player->radius)>(bolunme_siniri) && player->live_or_dead==1)
        {
            xbox_input();
            if((*number_of_split)>0)
            {
                //ONCEKI BOLUNME BITENE KADAR BOLUNME OLMAZ
                if(splits[(*number_of_split)-1].move_way_counter==0)
                {
                    temp_last_split=(*number_of_split);
                    ++(*number_of_split);
                    division_space_player(player, splits, *number_of_split);
                }
            }

            //ILK DEFA BOLUNMEDE
            else
            {
                temp_last_split=(*number_of_split);
                ++(*number_of_split);
                division_space_player(player, splits, *number_of_split);
            }
        }

        //SPLITS
        if(choose_control==3 && xbox[BUTTON_A] && (*number_of_split)>0)
        {
            temp=(*number_of_split);

            while(sayac_split<(temp))
            {
                if((splits[sayac_split].radius)>(bolunme_siniri) && sayac_split!=temp_last_split)
                {
                    ++(*number_of_split);
                    division_space_split(splits, *number_of_split, sayac_split);
                }

                ++sayac_split;
            }
            sayac_split=0;
        }

    //BOLUNDUKTEN SONRA YAPILAN HAREKET
    division_space_move_way(player, splits, *number_of_split);


    //TEKRAR BIRLESME ICIN YAPILAN GERI SAYIM(YAKLASIK 25 SANIYE)
    division_space_merger_again(player, splits, *number_of_split);

}
