#include "agar.h"

void choose_thema(BITMAP *bmp,BITMAP *sprite,double still_run, int *choose_tema, color_feature_t *yem_color, color_feature_t *player_color)
{
    //KARAKTER VE TEMA SECIMI

    //DEFAULT
    BITMAP *tema_pic = load_bitmap("tema_pic.bmp",NULL);

    //CHOOSE
    BITMAP *selected = load_bitmap("selected.bmp",NULL);
    BITMAP *locked = load_bitmap("locked.bmp",NULL);
    BITMAP *selected_big = load_bitmap("selected_big.bmp",NULL);
    BITMAP *locked_big = load_bitmap("locked_big.bmp",NULL);

    //SOUND
    SAMPLE *thema_sound = load_sample("tema.wav");

    int choose_karakter=0;
    int check=1;


    if(still_run)
    {
        play_sample(thema_sound,255,128,1000,0);

        while(check)
        {
            //background
            blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);

            //DEFTERIN USTUNE GELINIRSE
            if(mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450)
            {
                draw_sprite(bmp, selected, 80, 170);
            }

            //SU DAMLASININ USTUNE GELINIRSE
            else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450)
            {
                draw_sprite(bmp, selected, 480, 170);
            }

            //KARATAHTANIN USTUNE GELINIRSE
            else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450)
            {
                draw_sprite(bmp, selected, 870, 170);
            }

            //ANGRY IN USTUNE GELINIRSE
            else if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920)
            {
                draw_sprite(bmp, selected_big, 160, 650);
            }

            //HAPPY IN USTUNE GELINIRSE
            else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920)
            {
                draw_sprite(bmp, selected_big, 660, 650);
            }

            draw_sprite(bmp, sprite, mouse_x, mouse_y);

            //DEFTER SECILIRSE
            if(mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
            {
                (*choose_tema)=1;
                choose_karakter=0;
                check=0;
                yem_color->red=0;
                yem_color->green=255;
                yem_color->blue=0;
            }

            //SU DAMLASI SECILIRSE
            else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
            {
                (*choose_tema)=2;
                choose_karakter=0;
                check=0;
                yem_color->red=255;
                yem_color->green=128;
                yem_color->blue=0;
            }

            //KARATAHTA SECILIRSE
            else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
            {
                (*choose_tema)=3;
                choose_karakter=0;
                check=0;
                yem_color->red=0;
                yem_color->green=255;
                yem_color->blue=0;
            }

            //ANGRY SECILIRSE
            else if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
            {
                (*choose_tema)=0;
                choose_karakter=1;
                check=0;
                player_color->red=255;
                player_color->green=0;
                player_color->blue=0;
            }

            //HAPPY SECILIRSE
            else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
            {
                (*choose_tema)=0;
                choose_karakter=2;
                check=0;
                player_color->red=0;
                player_color->green=0;
                player_color->blue=255;
            }

            blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
            clear_bitmap(bmp);
        }

        check=1;

        //ONCE TEMA SECILIRSE
        if(*choose_tema>0)
        {
                //EGER 1. TEMA SECILIRSE
                if((*choose_tema)==1)
                {
                    while(check)
                    {
                        //background
                        blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);
                        blit(locked,bmp,0,0,490,180,locked->w,locked->h);
                        blit(locked,bmp,0,0,880,180,locked->w,locked->h);

                        //ANGRYNIN USTUNE GELINIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 160, 650);
                        }

                        //HAPPYIN USTUNE GELINIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 660, 650);
                        }

                        //ANGRY SECILIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=255;
                            player_color->green=0;
                            player_color->blue=0;
                            check=0;
                        }

                        //HAPPY SECILIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=0;
                            player_color->green=0;
                            player_color->blue=255;
                            check=0;
                        }

                        draw_sprite(bmp, sprite, mouse_x, mouse_y);
                        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                        clear_bitmap(bmp);
                    }
                }

                //EGER 2. TEMA SECILIRSE
                if((*choose_tema)==2)
                {
                    while(check)
                    {
                        //background
                        blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);
                        blit(locked,bmp,0,0,60,180,locked->w,locked->h);
                        blit(locked,bmp,0,0,860,180,locked->w,locked->h);

                        //ANGRYNIN USTUNE GELINIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 160, 650);
                        }

                        //HAPPYIN USTUNE GELINIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 660, 650);
                        }

                        //ANGRY SECILIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=255;
                            player_color->green=0;
                            player_color->blue=0;
                            check=0;
                        }

                        //HAPPY SECILIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=0;
                            player_color->green=0;
                            player_color->blue=255;
                            check=0;
                        }

                        draw_sprite(bmp, sprite, mouse_x, mouse_y);
                        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                        clear_bitmap(bmp);
                    }
                }

                //EGER 3. TEMA SECILIRSE
                else
                {
                    while(check)
                    {
                        //background
                        blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);
                        blit(locked,bmp,0,0,470,180,locked->w,locked->h);
                        blit(locked,bmp,0,0,70,180,locked->w,locked->h);

                        //ANGRYNIN USTUNE GELINIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 160, 650);
                        }

                        //HAPPYNIN USTUNE GELINIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920)
                        {
                            draw_sprite(bmp, selected_big, 660, 650);
                        }

                        //ANGRY SECILIRSE
                        if (mouse_x>225 && mouse_x<540 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=255;
                            player_color->green=0;
                            player_color->blue=0;
                            check=0;
                        }

                        //HAPPY SECILIRSE
                        else if (mouse_x>720 && mouse_x<1010 && mouse_y>650  && mouse_y<920 && (mouse_b & 1))
                        {
                            player_color->red=0;
                            player_color->green=0;
                            player_color->blue=255;
                            check=0;
                        }

                        draw_sprite(bmp, sprite, mouse_x, mouse_y);
                        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                        clear_bitmap(bmp);
                    }
                }
        }

        //ONCE KARAKTER SECILIRSE
        else
        {
                //EGER 1. KARAKTER SECILIRSE
                if(choose_karakter==1)
                {
                    while(check)
                    {
                        //background
                        blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);
                        blit(locked_big,bmp,0,0,670,650,locked_big->w,locked_big->h);

                        //DEFTER IN USTUNE GELINIRSE
                        if (mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 90, 180);
                        }

                        //SU DAMLASI NIN USTUNE GELINIRSE
                        else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 490, 180);
                        }

                        //KARATAHTA NIN USTUNE GELINIRSE
                        else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 880, 180);
                        }

                        //DEFTER SECILIRSE
                        if (mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=1;
                            check=0;
                            yem_color->red=0;
                            yem_color->green=255;
                            yem_color->blue=0;
                        }

                        //SU DAMLASI SECILIRSE
                        else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=2;
                            check=0;
                            yem_color->red=255;
                            yem_color->green=128;
                            yem_color->blue=0;
                        }

                        //KARATAHTA SECILIRSE
                        else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=3;
                            check=0;
                            yem_color->red=0;
                            yem_color->green=255;
                            yem_color->blue=0;
                        }

                        draw_sprite(bmp, sprite, mouse_x, mouse_y);
                        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                        clear_bitmap(bmp);
                    }
                }

                //EGER 2. KARAKTER SECILIRSE
                else
                {
                    while(check)
                    {
                        //background
                        blit(tema_pic,bmp,0,0,0,0,tema_pic->w,tema_pic->h);
                        blit(locked_big,bmp,0,0,160,650,locked_big->w,locked_big->h);

                        //DEFTER IN USTUNE GELINIRSE
                        if (mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 90, 180);
                        }

                        //SU DAMLASI IN USTUNE GELINIRSE
                        else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 490, 180);
                        }

                        //KARATAHTA NIN USTUNE GELINIRSE
                        else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450)
                        {
                            draw_sprite(bmp, selected, 880, 180);
                        }

                        //DEFTER SECILIRSE
                        if (mouse_x>100 && mouse_x<370 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=1;
                            check=0;
                            yem_color->red=0;
                            yem_color->green=255;
                            yem_color->blue=0;
                        }

                        //SU DAMLASI SECILIRSE
                        else if (mouse_x>500 && mouse_x<780 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=2;
                            check=0;
                            yem_color->red=255;
                            yem_color->green=128;
                            yem_color->blue=0;
                        }

                        //KARATAHTA SECILIRSE
                        else if (mouse_x>890 && mouse_x<1160 && mouse_y>180  && mouse_y<450 && (mouse_b & 1))
                        {
                            (*choose_tema)=3;
                            check=0;
                            yem_color->red=0;
                            yem_color->green=255;
                            yem_color->blue=0;
                        }

                        draw_sprite(bmp, sprite, mouse_x, mouse_y);
                        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                        clear_bitmap(bmp);
                    }
                }
        }
    }

    destroy_bitmap (tema_pic);
    destroy_bitmap (selected);
    destroy_bitmap (locked);
    destroy_bitmap (selected_big);
    destroy_bitmap (locked_big);
    destroy_sample (thema_sound);
    destroy_bitmap (sprite);
}
