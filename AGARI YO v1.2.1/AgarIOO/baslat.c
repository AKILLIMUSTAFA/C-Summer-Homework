#include "agar.h"

void Baslat()
{
    //STANDART ALLEGRO 4.4 BASLANGI KODLARI
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if (depth == 0) depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, SCREEN_WW, SCREEN_HH, 0, 0);
    if (res != 0) {
    allegro_message(allegro_error);
    exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
    install_joystick(JOY_TYPE_AUTODETECT);
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,"A");
    set_window_title("AgorIOO v1.0.7-beta");
    srand(time(NULL));

}
