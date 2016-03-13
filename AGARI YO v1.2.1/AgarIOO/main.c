#include <allegro.h>

#include "agar.h"
#include "xbox.h"

volatile long speed_counter = 0;

void increment_speed_counter(){
speed_counter++;
}END_OF_FUNCTION(increment_speed_counter);

int main()
{
    Baslat();

    double first_screen=1;
    double still_run;
    int choose_control;
    int choose_tema;

    LOCK_VARIABLE(speed_counter);
    LOCK_FUNCTION(increment_speed_counter);
    install_int_ex(increment_speed_counter,BPS_TO_TIMER(60));

    BITMAP *bmp_first_screen = create_bitmap(SCREEN_WW,SCREEN_HH);
    BITMAP *bmp = create_bitmap(MAP_W,MAP_H);
    BITMAP *arka_fon_defter = load_bitmap("defter.bmp",NULL);
    BITMAP *arka_fon_su_damlasi = load_bitmap("su_damlasi.bmp",NULL);
    BITMAP *arka_fon_karatahta = load_bitmap("karatahta.bmp",NULL);
    BITMAP *sprite = load_bitmap("mouse_icon_purple.bmp",NULL);
    BITMAP *sprite_game = load_bitmap("mouse_icon_blue.bmp",NULL);
    color_feature_t yem_color;
    color_feature_t player_color;

    int depth;
    depth=desktop_color_depth();
    set_color_depth(depth);

    //ILK EKRAN
    still_run=screen_first(first_screen,bmp_first_screen,sprite);

    //PLAYER KONTROLU SECILIR
    choose_control=player_control(bmp_first_screen,sprite,still_run);

    //TEMA VE KARAKTER SECILIR
    choose_thema(bmp,sprite,still_run, &choose_tema, &yem_color, &player_color);

    //ARKA FON SECIMI
    if(choose_tema==1)
    {
        //OYUN
        game(still_run,bmp,arka_fon_defter,sprite_game,choose_control, yem_color, player_color);
    }

    else if(choose_tema==2)
    {
        //OYUN
        game(still_run,bmp,arka_fon_su_damlasi,sprite_game,choose_control, yem_color, player_color);
    }

    else
    {
        //OYUN
        game(still_run,bmp,arka_fon_karatahta,sprite_game,choose_control, yem_color, player_color);
    }

    destroy_bitmap (bmp);
    destroy_bitmap (arka_fon_defter);
    destroy_bitmap (arka_fon_su_damlasi);
    destroy_bitmap (arka_fon_karatahta);


    Bitir();
    return 0;
}
END_OF_MAIN()

