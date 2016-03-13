#include "agar.h"
#include "xbox.h"

void move_splits(player_feature_t *player, double choose_control,division_t splits[SIZE_ARRAY], int number_of_split)
{
    int sayac_split=0;
    int target=number_of_split-1;
    move_feature_t split_move;

    //EGER SPLIT ONUNDE ENGEL VARSA HAREKET EDEMEZ
    //EGER SPLIT ONUNDE ENGEL YOKSA HAREKET EDEBILIR

    //KLAVYE ICIN
    if(choose_control==1)
    {
        while(sayac_split<number_of_split)
        {
            if(splits[sayac_split].defeated)
            {
                //SOL TUSA BASILIRSA
                if (key[KEY_LEFT] &&  (splits[sayac_split].location_x)>(splits[sayac_split].radius))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.left=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            else if((splits[sayac_split].location_x)<(player->location_x))
                                    split_move.left=1;
                        }

                        else
                        {
                           split_move.left=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.left)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.left;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<(splits[target].location_x))
                                                ++split_move.left;

                                }

                                else
                                {
                                    ++split_move.left;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.left==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                    }
                }

                //SAG TUSA BASILIRSA
                if (key[KEY_RIGHT] && (splits[sayac_split].location_x)<(MAP_W-((splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.right=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>(player->location_x))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;
                        }

                        else
                        {
                           split_move.right=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.right)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.right;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>(splits[target].location_x))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;
                                }

                                else
                                {
                                    ++split_move.right;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.right==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                    }
                }

                //YUKARI TUSUNA BASILIRSA
                if (key[KEY_UP] &&    (splits[sayac_split].location_y)>((splits[sayac_split].radius)))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<(player->location_y))
                                 split_move.up=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;
                        }

                        else
                        {
                           split_move.up=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.up)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<(splits[target].location_y))
                                            ++split_move.up;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;
                                }

                                else
                                {
                                    ++split_move.up;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.up==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                    }
                }

                //ASAGI TUSUNA BASILIRSA
                if (key[KEY_DOWN] &&  (splits[sayac_split].location_y)<((MAP_H-(splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.down=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>(player->location_y))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;
                        }

                        else
                        {
                           split_move.down=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.down)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.down;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>(splits[target].location_y))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;
                                }

                                else
                                {
                                    ++split_move.down;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.down==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                    }
                }
            }

            split_move.left=0;
            split_move.right=0;
            split_move.up=0;
            split_move.down=0;
            ++sayac_split;
        }
    }

    //MOUSE ICIN
    if(choose_control==2)
    {
        while(sayac_split<number_of_split)
        {
            if(splits[sayac_split].defeated)
            {
                //SOL TUSA BASILIRSA
                if (mouse_x<(splits[sayac_split].location_x) &&  (splits[sayac_split].location_x)>(splits[sayac_split].radius))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.left=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            else if((splits[sayac_split].location_x)<(player->location_x))
                                    split_move.left=1;
                        }

                        else
                        {
                           split_move.left=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.left)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.left;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<(splits[target].location_x))
                                                ++split_move.left;

                                }

                                else
                                {
                                    ++split_move.left;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.left==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                    }
                }

                //SAG TUSA BASILIRSA
                if (mouse_x>(splits[sayac_split].location_x) && (splits[sayac_split].location_x)<(MAP_W-((splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.right=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>(player->location_x))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;
                        }

                        else
                        {
                           split_move.right=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.right)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.right;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>(splits[target].location_x))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;
                                }

                                else
                                {
                                    ++split_move.right;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.right==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                    }
                }

                //YUKARI TUSUNA BASILIRSA
                if (mouse_y<(splits[sayac_split].location_y) &&    (splits[sayac_split].location_y)>((splits[sayac_split].radius)))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<(player->location_y))
                                 split_move.up=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;
                        }

                        else
                        {
                           split_move.up=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.up)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<(splits[target].location_y))
                                            ++split_move.up;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;
                                }

                                else
                                {
                                    ++split_move.up;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.up==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                    }
                }

                //ASAGI TUSUNA BASILIRSA
                if (mouse_y>(splits[sayac_split].location_y) &&  (splits[sayac_split].location_y)<((MAP_H-(splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.down=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>(player->location_y))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;
                        }

                        else
                        {
                           split_move.down=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.down)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.down;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>(splits[target].location_y))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;
                                }

                                else
                                {
                                    ++split_move.down;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.down==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                    }
                }
            }

            split_move.left=0;
            split_move.right=0;
            split_move.up=0;
            split_move.down=0;
            ++sayac_split;
        }
    }

    //GAMEPAD ICIN
    if(choose_control==3)
    {
        xbox_input();

        while(sayac_split<number_of_split)
        {
            if(splits[sayac_split].defeated)
            {
                //SOL TUSA BASILIRSA
                if (xbox[LSTICK_LEFT] &&  (splits[sayac_split].location_x)>(splits[sayac_split].radius))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.left=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.left=1;

                            else if((splits[sayac_split].location_x)<(player->location_x))
                                    split_move.left=1;
                        }

                        else
                        {
                           split_move.left=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.left)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.left;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.left;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<(splits[target].location_x))
                                                ++split_move.left;

                                }

                                else
                                {
                                    ++split_move.left;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.left==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)-(splits[sayac_split].speed));
                    }
                }

                //SAG TUSA BASILIRSA
                if (xbox[LSTICK_RIGHT] && (splits[sayac_split].location_x)<(MAP_W-((splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.right=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>(player->location_x))
                                    split_move.right=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.right=1;
                        }

                        else
                        {
                           split_move.right=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.right)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.right;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>(splits[target].location_x))
                                                ++split_move.right;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.right;
                                }

                                else
                                {
                                    ++split_move.right;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.right==(number_of_split+1))
                        {
                            (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_x)=((splits[sayac_split].location_x)+(splits[sayac_split].speed));
                    }
                }

                //YUKARI TUSUNA BASILIRSA
                if (xbox[LSTICK_UP] &&    (splits[sayac_split].location_y)>((splits[sayac_split].radius)))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<(player->location_y))
                                 split_move.up=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>((player->location_y)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.up=1;
                        }

                        else
                        {
                           split_move.up=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.up)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<(splits[target].location_y))
                                            ++split_move.up;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>((splits[target].location_y)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.up;
                                }

                                else
                                {
                                    ++split_move.up;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.up==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)-(splits[sayac_split].speed));
                    }
                }

                //ASAGI TUSUNA BASILIRSA
                if (xbox[LSTICK_DOWN] &&  (splits[sayac_split].location_y)<((MAP_H-(splits[sayac_split].radius))))
                {
                    if(splits[sayac_split].aktif)
                    {
                        //SPLITS vs PLAYER
                        if(player->live_or_dead)
                        {
                            //y koordinatinda split yukaridaysa
                            if((splits[sayac_split].location_y)<((player->location_y)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                 split_move.down=1;

                            //y koordinatinda split asagidaysa
                            else if((splits[sayac_split].location_y)>(player->location_y))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sag taraftaysa,
                            else if((splits[sayac_split].location_x)>((player->location_x)+((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;

                            //y koordinatinda split esitse, sol taraftaysa
                            else if((splits[sayac_split].location_x)<((player->location_x)-((3*((player->radius)+(splits[sayac_split].radius)))/4)))
                                    split_move.down=1;
                        }

                        else
                        {
                           split_move.down=1;
                        }

                        //SPLITS vs SPLITS
                        if(split_move.down)
                        {
                            while(target>-1)
                            {
                                if(target!=sayac_split)
                                {
                                    //y koordinatinda split yukaridaysa
                                    if((splits[sayac_split].location_y)<((splits[target].location_y)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                            ++split_move.down;

                                    //y koordinatinda split asagidaysa
                                    else if((splits[sayac_split].location_y)>(splits[target].location_y))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sag taraftaysa,
                                    else if((splits[sayac_split].location_x)>((splits[target].location_x)+((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;

                                    //y koordinatinda split esitse, sol taraftaysa
                                    else if((splits[sayac_split].location_x)<((splits[target].location_x)-((3*((splits[target].radius)+(splits[sayac_split].radius)))/4)))
                                                ++split_move.down;
                                }

                                else
                                {
                                    ++split_move.down;
                                }
                                --target;
                            }
                            target=number_of_split-1;
                        }

                        if(split_move.down==(number_of_split+1))
                        {
                            (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                        }
                    }

                    else if(splits[sayac_split].defeated==0)
                    {

                    }

                    else
                    {
                        (splits[sayac_split].location_y)=((splits[sayac_split].location_y)+(splits[sayac_split].speed));
                    }
                }
            }

            split_move.left=0;
            split_move.right=0;
            split_move.up=0;
            split_move.down=0;
            ++sayac_split;
        }
    }

}

