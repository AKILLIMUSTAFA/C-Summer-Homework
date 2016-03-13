#include "agar.h"

double player_control(BITMAP *bmp,BITMAP *sprite,double still_run)
{
    BITMAP *klavye = load_bitmap("klavye.bmp",NULL);
    BITMAP *mouse = load_bitmap("mouse.bmp",NULL);
    BITMAP *gamepad = load_bitmap("gamepad.bmp",NULL);
    BITMAP *control = load_bitmap("control_pic.bmp",NULL);
    FONT *font1 = load_font ("big_font.pcx", NULL, NULL);

    SAMPLE *control_sound = load_sample("control_sound.wav");

    double choose_control=0;
    double check=1;

    if(still_run)
    {
         play_sample(control_sound,255,128,1000,0);

        while(check)
        {
            //background
            blit(control,bmp,0,0,0,0,control->w,control->h);

            //KLAVYE USTUNE GELINIRSE
            if(mouse_x>65 && mouse_x<356 && mouse_y>126  && mouse_y<259)
            {
                textout_ex(bmp, font1, "KLAVYE", 120, 160, makecol(255, 255, 0), -1);
                textout_ex(bmp, font1, "MOUSE", 120, 410, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "GAMEPAD", 120, 659, makecol(0, 0, 0), -1);
                draw_sprite(bmp, klavye, 530, 160);
            }

            //MOUSE USTUNE GELINIRSE
            else if (mouse_x>65 && mouse_x<356 && mouse_y>378  && mouse_y<510)
            {
                textout_ex(bmp, font1, "KLAVYE", 120, 160, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "MOUSE", 120, 410, makecol(255, 255, 0), -1);
                textout_ex(bmp, font1, "GAMEPAD", 120, 659, makecol(0, 0, 0), -1);
                draw_sprite(bmp, mouse, 530, 160);
            }

            //GAMEPAD USTUNE GELINIRSE
            else if (mouse_x>65 && mouse_x<356 && mouse_y>621  && mouse_y<757)
            {
                textout_ex(bmp, font1, "KLAVYE", 120, 160, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "MOUSE", 120, 410, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "GAMEPAD", 120, 659, makecol(255, 255, 0), -1);
                draw_sprite(bmp, gamepad, 530, 160);
            }

            //HICBIRSEY SECILI DEGÝLSE
            else
            {
                textout_ex(bmp, font1, "KLAVYE", 120, 160, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "MOUSE", 120, 410, makecol(0, 0, 0), -1);
                textout_ex(bmp, font1, "GAMEPAD", 120, 659, makecol(0, 0, 0), -1);
            }

            draw_sprite(bmp, sprite, mouse_x, mouse_y);

            //KLAVYE SECILIRSE
            if(mouse_x>65 && mouse_x<356 && mouse_y>126  && mouse_y<259 && (mouse_b & 1))
            {
                choose_control=1;
                check=0;
            }

            //MOUSE SECILIRSE
            if(mouse_x>65 && mouse_x<356 && mouse_y>378  && mouse_y<510 && (mouse_b & 1))
            {
                choose_control=2;
                check=0;
            }

            //GAMEPAD SECILIRSE
            if(mouse_x>65 && mouse_x<356 && mouse_y>621  && mouse_y<757 && (mouse_b & 1))
            {
                choose_control=3;
                check=0;
            }

            blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
            clear_bitmap(bmp);
        }

        destroy_sample (control_sound);
        destroy_bitmap (control);
        destroy_bitmap (klavye);
        destroy_bitmap (mouse);
        destroy_bitmap (gamepad);

    }

    return choose_control;

}
