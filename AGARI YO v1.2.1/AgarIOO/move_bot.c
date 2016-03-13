#include "agar.h"

void move_bot(bots_feature_t bots[SIZE_ARRAY], player_feature_t player, division_t splits[SIZE_ARRAY], int number_of_split)
{
    int number_bot=0;
    int target_found=0;
    double bot_distance_to_player_x;
    double bot_distance_to_player_y;
    double bot_distance_to_split_x;
    double bot_distance_to_split_y;
    double bot_distance_to_other_bot_x;
    double bot_distance_to_other_bot_y;
    int sayac_split;
    int bot_sayac;

    while(number_bot<BOT_NUMBER)
    {
        //BOT ICIN HEDEF CONTROL (BOT STRATEGIES)
        //ONCELIKLI HEDEF PLAYER
        //SONRAKI HEDEF SPLIT
        //SONRAKI HEDEF DIGER BOTLAR
        //SON HEDEF ISE RASTGELE LOCATION

        //PLAYER CONTROL SAVUNMA
        if(!target_found)
        {
            //PLAYER'A OLAN X VE Y KOORDINATLARINDAKI UZAKLIK KONTROL EDILIR.
            if(((bots[number_bot].location_x)-(player.location_x))>0)
            {
                bot_distance_to_player_x=((bots[number_bot].location_x)-(player.location_x));
            }

            else
            {
                bot_distance_to_player_x=((player.location_x)-(bots[number_bot].location_x));
            }

             if(((bots[number_bot].location_y)-(player.location_y))>0)
            {
                bot_distance_to_player_y=((bots[number_bot].location_y)-(player.location_y));
            }

            else
            {
                bot_distance_to_player_y=((player.location_y)-(bots[number_bot].location_y));
            }

            //EGER KUCUKSE KACAR DUSER
            if(bot_distance_to_player_x<(SCREEN_WW/3) && bot_distance_to_player_y<(SCREEN_HH/3) &&
                player.live_or_dead==1 && (player.radius>(bots[number_bot].radius)+YEME_SINIRI))
            {
                //HARITANIN YUKARISINDAYSA
                if((bots[number_bot].location_x)<(MAP_W/2))
                {
                    //PLAYER IN SAGINDA VE ASAGI DAHA YAKINSA
                    if((bots[number_bot].location_x)>(player.location_x)+(player.radius) &&
                       (bots[number_bot].location_y)>(player.location_y)+(player.radius))
                    {
                        (bots[number_bot].target_location_x)=(MAP_W);
                        (bots[number_bot].target_location_y)=(MAP_H);
                        target_found=1;
                    }

                    //PLAYER IN SAGINDA VE YUKARI DAHA YAKINSA
                    else if((bots[number_bot].location_x)>(player.location_x)+(player.radius) &&
                            (bots[number_bot].location_y)<(player.location_y)-(player.radius))
                    {
                        //SAG ALT TARAF
                        if(bot_distance_to_player_x>bot_distance_to_player_y)
                        {
                            (bots[number_bot].target_location_x)=MAP_W;
                            (bots[number_bot].target_location_y)=MAP_H;
                            target_found=1;
                        }

                        //SOL UST TARAF
                        else
                        {
                            (bots[number_bot].target_location_x)=0;
                            (bots[number_bot].target_location_y)=0;
                            target_found=1;
                        }
                    }

                    //PLAYER IN SOLUNDA VE ASAGI DAHA YAKINSA
                    else if((bots[number_bot].location_x)<(player.location_x)-(player.radius) &&
                            (bots[number_bot].location_y)>(player.location_y)+(player.radius))
                    {
                        (bots[number_bot].target_location_x)=0;
                        (bots[number_bot].target_location_y)=MAP_H;
                        target_found=1;
                    }

                    //PLAYER IN SOLUNDA VE YUKARI DAHA YAKINSA
                    else if((bots[number_bot].location_x)<(player.location_x)-(player.radius) &&
                            (bots[number_bot].location_y)<(player.location_y)-(player.radius))
                    {
                        //SAG ALT TARAF
                        if(bot_distance_to_player_x>bot_distance_to_player_y)
                        {
                            (bots[number_bot].target_location_x)=0;
                            (bots[number_bot].target_location_y)=MAP_H;
                            target_found=1;
                        }

                        //SOL UST TARAF
                        else
                        {
                            (bots[number_bot].target_location_x)=MAP_W;
                            (bots[number_bot].target_location_y)=0;
                            target_found=1;
                        }
                    }

                }

                //HARITANIN ASAGISINDAYSA
                else
                {
                    //PLAYER IN SAGINDA VE ASAGI DAHA YAKINSA
                    if((bots[number_bot].location_x)>(player.location_x)+(player.radius)  &&
                       (bots[number_bot].location_y)>(player.location_y)+(player.radius) )
                    {
                        //SAG ALT TARAF
                        if(bot_distance_to_player_x>bot_distance_to_player_y)
                        {
                            (bots[number_bot].target_location_x)=0;
                            (bots[number_bot].target_location_y)=MAP_H;
                            target_found=1;
                        }

                        //SOL UST TARAF
                        else
                        {
                            (bots[number_bot].target_location_x)=MAP_W;
                            (bots[number_bot].target_location_y)=0;
                            target_found=1;
                        }
                    }

                    //PLAYER IN SAGINDA VE YUKARI DAHA YAKINSA
                    else if((bots[number_bot].location_x)>(player.location_x)+(player.radius)  &&
                            (bots[number_bot].location_y)<(player.location_y)-(player.radius) )
                    {
                        (bots[number_bot].target_location_x)=MAP_W;
                        (bots[number_bot].target_location_y)=0;
                        target_found=1;
                    }

                    //PLAYER IN SOLUNDA VE ASAGI DAHA YAKINSA
                    else if((bots[number_bot].location_x)<(player.location_x)-(player.radius)  &&
                            (bots[number_bot].location_y)>(player.location_y)+(player.radius) )
                    {
                        //SAG ALT TARAF
                        if(bot_distance_to_player_x>bot_distance_to_player_y)
                        {
                            (bots[number_bot].target_location_x)=0;
                            (bots[number_bot].target_location_y)=0;
                            target_found=1;
                        }

                        //SOL UST TARAF
                        else
                        {
                            (bots[number_bot].target_location_x)=MAP_W;
                            (bots[number_bot].target_location_y)=MAP_H;
                            target_found=1;
                        }
                    }

                    //PLAYER IN SOLUNDA VE YUKARI DAHA YAKINSA
                    else if((bots[number_bot].location_x)<(player.location_x)-(player.radius)  &&
                            (bots[number_bot].location_y)<(player.location_y)-(player.radius) )
                    {
                        (bots[number_bot].target_location_x)=0;
                        (bots[number_bot].target_location_y)=0;
                        target_found=1;
                    }

                }
            }
        }

        sayac_split=0;

        //SPLITS CONTROL SAVUNMA
        if(!target_found)
        {
            while(sayac_split<number_of_split)
            {
                if(!target_found)
                {
                    //SPLITS'A OLAN X VE Y KOORDINATLARINDAKI UZAKLIK KONTROL EDILIR.
                    if(((bots[number_bot].location_x)-(splits[sayac_split].location_x))>0)
                    {
                        bot_distance_to_split_x=((bots[number_bot].location_x)-(splits[sayac_split].location_x));
                    }

                    else
                    {
                        bot_distance_to_split_x=((splits[sayac_split].location_x)-(bots[number_bot].location_x));
                    }

                     if(((bots[number_bot].location_y)-(splits[sayac_split].location_y))>0)
                    {
                        bot_distance_to_split_y=((bots[number_bot].location_y)-(splits[sayac_split].location_y));
                    }

                    else
                    {
                        bot_distance_to_split_y=((splits[sayac_split].location_y)-(bots[number_bot].location_y));
                    }

                    //EGER BUYUKSE PESINE DUSER
                    if(bot_distance_to_split_x<(SCREEN_WW/3) && bot_distance_to_split_y<(SCREEN_HH/3) &&
                        splits[sayac_split].defeated==1 && (bots[number_bot].radius)>(splits[sayac_split].radius+YEME_SINIRI))
                    {
                        (bots[number_bot].target_location_x)=(splits[sayac_split].location_x);
                        (bots[number_bot].target_location_y)=(splits[sayac_split].location_y);
                        target_found=1;
                    }

                    //EGER KUCUKSE KACAR DUSER
                    if(bot_distance_to_split_x<(SCREEN_WW/3) && bot_distance_to_split_y<(SCREEN_HH/3) &&
                        splits[sayac_split].defeated==1 && (splits[sayac_split].radius)>(bots[number_bot].radius+YEME_SINIRI))
                    {
                        //HARITANIN YUKARISINDAYSA
                        if((bots[number_bot].location_x)<(MAP_W/2))
                        {
                            //PLAYER IN SAGINDA VE ASAGI DAHA YAKINSA
                            if((bots[number_bot].location_x)>(splits[sayac_split].location_x)+(splits[sayac_split].radius) &&
                               (bots[number_bot].location_y)>(splits[sayac_split].location_y)+(splits[sayac_split].radius))
                            {
                                (bots[number_bot].target_location_x)=(MAP_W);
                                (bots[number_bot].target_location_y)=(MAP_H);
                                target_found=1;
                            }

                            //PLAYER IN SAGINDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)>(splits[sayac_split].location_x)+(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)<(splits[sayac_split].location_y)-(splits[sayac_split].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_split_x>bot_distance_to_split_y)
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                            //PLAYER IN SOLUNDA VE ASAGI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(splits[sayac_split].location_x)-(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)>(splits[sayac_split].location_y)+(splits[sayac_split].radius))
                            {
                                (bots[number_bot].target_location_x)=0;
                                (bots[number_bot].target_location_y)=MAP_H;
                                target_found=1;
                            }

                            //PLAYER IN SOLUNDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(splits[sayac_split].location_x)-(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)<(splits[sayac_split].location_y)-(splits[sayac_split].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_split_x>bot_distance_to_split_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                        }

                        //HARITANIN ASAGISINDAYSA
                        else
                        {
                            //PLAYER IN SAGINDA VE ASAGI DAHA YAKINSA
                            if((bots[number_bot].location_x)>(splits[sayac_split].location_x)+(splits[sayac_split].radius) &&
                               (bots[number_bot].location_y)>(splits[sayac_split].location_y)+(splits[sayac_split].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_split_x>bot_distance_to_split_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                            //PLAYER IN SAGINDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)>(splits[sayac_split].location_x)+(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)<(splits[sayac_split].location_y)-(splits[sayac_split].radius))
                            {
                                (bots[number_bot].target_location_x)=MAP_W;
                                (bots[number_bot].target_location_y)=0;
                                target_found=1;
                            }

                            //PLAYER IN SOLUNDA VE ASAGI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(splits[sayac_split].location_x)-(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)>(splits[sayac_split].location_y)+(splits[sayac_split].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_split_x>bot_distance_to_split_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }
                            }

                            //PLAYER IN SOLUNDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(splits[sayac_split].location_x)-(splits[sayac_split].radius) &&
                                    (bots[number_bot].location_y)<(splits[sayac_split].location_y)-(splits[sayac_split].radius))
                            {
                                (bots[number_bot].target_location_x)=0;
                                (bots[number_bot].target_location_y)=0;
                                target_found=1;
                            }

                        }
                    }
                }
                ++sayac_split;
            }
        }

        bot_sayac=0;

        //OTHER BOTS CONTROL SAVUNMA
        if(!target_found)
        {
            while(bot_sayac<BOT_NUMBER)
            {
                if(!target_found)
                {
                    //DIGER BOTA OLAN X VE Y KOORDINATLARINDAKI UZAKLIK KONTROL EDILIR.
                    if(((bots[number_bot].location_x)-(bots[bot_sayac].location_x))>0)
                    {
                        bot_distance_to_other_bot_x=((bots[number_bot].location_x)-(bots[bot_sayac].location_x));
                    }

                    else
                    {
                        bot_distance_to_other_bot_x=((bots[bot_sayac].location_x)-(bots[number_bot].location_x));
                    }

                     if(((bots[number_bot].location_y)-(bots[bot_sayac].location_y))>0)
                    {
                        bot_distance_to_other_bot_y=((bots[number_bot].location_y)-(bots[bot_sayac].location_y));
                    }

                    else
                    {
                        bot_distance_to_other_bot_y=((bots[bot_sayac].location_y)-(bots[number_bot].location_y));
                    }

                    //EGER BUYUKSE PESINE DUSER
                    if(bot_distance_to_other_bot_x<(SCREEN_WW/2) && bot_distance_to_other_bot_y<(SCREEN_HH/2) &&
                        (bots[number_bot].radius)>(bots[bot_sayac].radius+YEME_SINIRI))
                    {
                        (bots[number_bot].target_location_x)=(bots[bot_sayac].location_x);
                        (bots[number_bot].target_location_y)=(bots[bot_sayac].location_y);
                        target_found=1;
                    }

                    //EGER KUCUKSE KACAR DUSER
                    if(bot_distance_to_other_bot_x<(SCREEN_WW/3) && bot_distance_to_other_bot_y<(SCREEN_HH/3) &&
                        (bots[bot_sayac].radius)>(bots[number_bot].radius+YEME_SINIRI))
                    {
                        //HARITANIN YUKARISINDAYSA
                        if((bots[number_bot].location_x)<(MAP_W/2))
                        {
                            //OTHER BOTS UN SAGINDA VE ASAGI DAHA YAKINSA
                            if((bots[number_bot].location_x)>(bots[bot_sayac].location_x)+(bots[bot_sayac].radius) &&
                               (bots[number_bot].location_y)>(bots[bot_sayac].location_y)+(bots[bot_sayac].radius))
                            {
                                (bots[number_bot].target_location_x)=(MAP_W);
                                (bots[number_bot].target_location_y)=(MAP_H);
                                target_found=1;
                            }

                            //OTHER BOTS IN SAGINDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)>(bots[bot_sayac].location_x)+(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)<(bots[bot_sayac].location_y)-(bots[bot_sayac].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_other_bot_x>bot_distance_to_other_bot_y)
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                            //OTHER BOTS IN SOLUNDA VE ASAGI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(bots[bot_sayac].location_x)-(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)>(bots[bot_sayac].location_y)+(bots[bot_sayac].radius))
                            {
                                (bots[number_bot].target_location_x)=0;
                                (bots[number_bot].target_location_y)=MAP_H;
                                target_found=1;
                            }

                            //OTHER BOTS IN SOLUNDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(bots[bot_sayac].location_x)-(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)<(bots[bot_sayac].location_y)-(bots[bot_sayac].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_other_bot_x>bot_distance_to_other_bot_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                        }

                        //HARITANIN ASAGISINDAYSA
                        else
                        {
                            //OTHER BOTS IN SAGINDA VE ASAGI DAHA YAKINSA
                            if((bots[number_bot].location_x)>(bots[bot_sayac].location_x)+(bots[bot_sayac].radius) &&
                               (bots[number_bot].location_y)>(bots[bot_sayac].location_y)+(bots[bot_sayac].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_other_bot_x>bot_distance_to_other_bot_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }
                            }

                            //OTHER BOTS IN SAGINDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)>(bots[bot_sayac].location_x)+(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)<(bots[bot_sayac].location_y)-(bots[bot_sayac].radius))
                            {
                                (bots[number_bot].target_location_x)=MAP_W;
                                (bots[number_bot].target_location_y)=0;
                                target_found=1;
                            }

                            //OTHER BOTS IN SOLUNDA VE ASAGI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(bots[bot_sayac].location_x)-(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)>(bots[bot_sayac].location_y)+(bots[bot_sayac].radius))
                            {
                                //SAG ALT TARAF
                                if(bot_distance_to_other_bot_x>bot_distance_to_other_bot_y)
                                {
                                    (bots[number_bot].target_location_x)=0;
                                    (bots[number_bot].target_location_y)=0;
                                    target_found=1;
                                }

                                //SOL UST TARAF
                                else
                                {
                                    (bots[number_bot].target_location_x)=MAP_W;
                                    (bots[number_bot].target_location_y)=MAP_H;
                                    target_found=1;
                                }
                            }

                            //OTHER BOTS IN SOLUNDA VE YUKARI DAHA YAKINSA
                            else if((bots[number_bot].location_x)<(bots[bot_sayac].location_x)-(bots[bot_sayac].radius) &&
                                    (bots[number_bot].location_y)<(bots[bot_sayac].location_y)-(bots[bot_sayac].radius))
                            {
                                (bots[number_bot].target_location_x)=0;
                                (bots[number_bot].target_location_y)=0;
                                target_found=1;
                            }

                        }
                    }


                }

                ++bot_sayac;
            }
        }

        //PLAYER CONTROL SALDIRI
        if(!target_found)
        {
            //EGER BUYUKSE PESINE DUSER
            if(bot_distance_to_player_x<(SCREEN_WW/3) && bot_distance_to_player_y<(SCREEN_HH/3) &&
                player.live_or_dead==1 && (bots[number_bot].radius)>(player.radius+YEME_SINIRI))
            {
                (bots[number_bot].target_location_x)=(player.location_x);
                (bots[number_bot].target_location_y)=(player.location_y);
                target_found=1;
            }
        }

        sayac_split=0;

        //SPLITS CONTROL SALDIRI
        if(!target_found)
        {
            while(sayac_split<number_of_split)
            {
                if(!target_found)
                {
                    //EGER BUYUKSE PESINE DUSER
                    if(bot_distance_to_split_x<(SCREEN_WW/3) && bot_distance_to_split_y<(SCREEN_HH/3) &&
                        splits[sayac_split].defeated==1 && (bots[number_bot].radius)>(splits[sayac_split].radius+YEME_SINIRI))
                    {
                        (bots[number_bot].target_location_x)=(splits[sayac_split].location_x);
                        (bots[number_bot].target_location_y)=(splits[sayac_split].location_y);
                        target_found=1;
                    }
                }
                ++sayac_split;
            }
        }

        bot_sayac=0;

        //OTHER BOTS CONTROL SALDIRI
        if(!target_found)
        {
            while(bot_sayac<BOT_NUMBER)
            {
                if(!target_found)
                {
                    //EGER BUYUKSE PESINE DUSER
                    if(bot_distance_to_other_bot_x<(SCREEN_WW/2) && bot_distance_to_other_bot_y<(SCREEN_HH/2) &&
                        (bots[number_bot].radius)>(bots[bot_sayac].radius+YEME_SINIRI))
                    {
                        (bots[number_bot].target_location_x)=(bots[bot_sayac].location_x);
                        (bots[number_bot].target_location_y)=(bots[bot_sayac].location_y);
                        target_found=1;
                    }
                }
                ++bot_sayac;
            }
        }


        //HEDEFE OLAN UZAKLIK HESAP EDILIR
        (bots[number_bot].distance_target_location_x)=((bots[number_bot].target_location_x)-(bots[number_bot].location_x));
        (bots[number_bot].distance_target_location_y)=((bots[number_bot].target_location_y)-(bots[number_bot].location_y));

        //EGER HEDEF ULASILIRSA YA DA HEDEF BULUNUMAZSA RASTGELE HEDEF BELIRLENIR
         if(!target_found)
        {
            //YENI RASTGELE HEDEF
            if((bots[number_bot].distance_target_location_x)<16 && (bots[number_bot].distance_target_location_x)>(-16))
            {
                random_bot_target_location(bots, number_bot);
            }

            if((bots[number_bot].distance_target_location_y)<16 && (bots[number_bot].distance_target_location_y)>(-16))
            {
                random_bot_target_location(bots, number_bot);
            }
        }

        //HEDEFE DOGRU HAREKET EDILIR
        if((bots[number_bot].distance_target_location_x)>0)
        {
            (bots[number_bot].location_x)=((bots[number_bot].location_x)+(bots[number_bot].speed));
        }
        else
        {
            (bots[number_bot].location_x)=((bots[number_bot].location_x)-(bots[number_bot].speed));
        }

        if((bots[number_bot].distance_target_location_y)>0)
        {
            (bots[number_bot].location_y)=((bots[number_bot].location_y)+(bots[number_bot].speed));
        }
        else
        {
            (bots[number_bot].location_y)=((bots[number_bot].location_y)-(bots[number_bot].speed));
        }

        //DIGER BOTA GECILIR
        target_found=0;
        ++number_bot;
    }
}
