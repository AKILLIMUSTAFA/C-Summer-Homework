#include "agar.h"

double screen_first(double first_screen,BITMAP *bmp,BITMAP *sprite)
{
    double still_run=1;

    BITMAP *first_screen_pic = load_bitmap("first_screen_pic.bmp",NULL);
    FONT *font1 = load_font ("big_font.pcx", NULL, NULL);

    SAMPLE *menu_music = load_sample("music_menu.wav");

    play_sample(menu_music,255,128,1000,1);

    while(first_screen)
    {
        //background
        blit(first_screen_pic,bmp,0,0,0,0,first_screen_pic->w,first_screen_pic->h);

        //BASLAT USTUNE GELINIRSE
        if(mouse_x>108 && mouse_x<234 && mouse_y>159  && mouse_y<275)
        {
            textout_ex(bmp, font1, "BASLAT", 100, 190, makecol(255, 255, 0), -1);
            textout_ex(bmp, font1, "CIKIS", 410, 190, makecol(0, 0, 0), -1);
        }

        //CIKIS USTUNE GELINIRSE
        else if (mouse_x>407 && mouse_x<521 && mouse_y>166  && mouse_y<266)
        {
            textout_ex(bmp, font1, "BASLAT", 100, 190, makecol(0, 0, 0), -1);
            textout_ex(bmp, font1, "CIKIS", 410, 190, makecol(255, 255, 0), -1);
        }

        //FARE DIGER YERLERDEYSE
        else
        {
            textout_ex(bmp, font1, "BASLAT", 100, 190, makecol(0, 0, 0), -1);
            textout_ex(bmp, font1, "CIKIS", 410, 190, makecol(0, 0, 0), -1);
        }

        //mouse icon
        draw_sprite(bmp, sprite, mouse_x, mouse_y);

        //BASLAT SECILIRSE
        if(mouse_x>108 && mouse_x<234 && mouse_y>159  && mouse_y<275 && (mouse_b & 1))
            first_screen=0;

        //CIKIS SECILIRSE
        if(mouse_x>407 && mouse_x<521 && mouse_y>166  && mouse_y<266 && (mouse_b & 1))
        {
            first_screen=0;
            still_run=0;
        }

        blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
        clear_bitmap(bmp);
    }
    destroy_sample (menu_music);
    destroy_bitmap (first_screen_pic);

    return still_run;
}
