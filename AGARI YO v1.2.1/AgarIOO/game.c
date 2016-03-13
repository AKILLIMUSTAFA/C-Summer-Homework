#include "agar.h"

void game(double still_run,BITMAP *bmp,BITMAP *arka_fon,BITMAP *sprite_game,int choose_control, color_feature_t yem_color, color_feature_t player_color)
{
    FONT *font1 = load_font ("big_font.pcx", NULL, NULL);

    BITMAP *duraklatma_menusu_pic = load_bitmap("duraklatma_menusu_pic.bmp",NULL);
    BITMAP *green_things_pic = load_bitmap("green_things_pic.bmp",NULL);
    BITMAP *black_screen = load_bitmap("black_screen.bmp",NULL);
    SAMPLE *game_fon_music = load_sample("game_fon_music.wav");
    SAMPLE *stop_game = load_sample("stop_game.wav");
    BITMAP *stop_game_sprite = load_bitmap("mouse_icon_purple.bmp",NULL);

    int sayac_split;
    int again_game;

    //PLAYER
    player_feature_t player;//player

    bots_feature_t bots[SIZE_ARRAY];//botlar

    division_t splits[SIZE_ARRAY];//split (playerdan kopan parcalar)

    location_t yem[SIZE_ARRAY];//yem

    circle_t green_things[SIZE_ARRAY];//yesýl seyler

    location_t background; //arkaplan
    location_t camera; //kamera

    location_t sprite; //mouse iconu

    int sayac=0;
    int check=1;
    int game_continuation; // eger player olurse oyun devam etmez


    //SPLIT PLAYER
    int number_of_split; // split sayisi

    //SAYACLAR
    sayac=0;
    check=1;
    sayac_split=0;

    //OYUNCUNUN OLMESI
    game_continuation=0;


    //SPLIT PLAYER
    number_of_split=0;

    //OYUNU YENIDEN BASLATMA
    again_game=0;

    //OYUN BASI PLAYER RASTGELE LOCATION VE HIZI
    player.location_x=rand()%MAP_W;
    player.location_y=rand()%MAP_H;
    player.radius=RADIUS_PLAYER;
    player.live_or_dead=1;

    //OYUN BASI BOTLARIN YARICAPLARI
    while(sayac<BOT_NUMBER)
    {
        bots[sayac].radius=RADIUS_BOT;
        ++sayac;
    }

    if(still_run)
    {
        play_sample(game_fon_music,255,128,1000,1);
    }

    // Random yem, bot and color for bot
    random_yem_location(yem);
    random_bot_location(bots, -1);
    random_color_bot(bots);

    //OYUN BASI RASTGELE HEDEF (BOTLAR ICIN)
    random_bot_target_location(bots, -1);

    ////OYUN BASI YESIL SEYLER ICIN RASTGELE LOCATION
    random_green_things_location(green_things,-1);

    set_mouse_range(0,0,MAP_W-30, MAP_H-30);


    while(still_run)
    {
        //OYUN YENIDEN BASLATILIRSA DEGERLER SIFIRLANIR
        if(again_game)
        {
            //SAYACLAR
            sayac=0;
            check=1;
            sayac_split=0;

            //OYUNCUNUN OLMESI
            game_continuation=0;

            //SPLIT PLAYER
            number_of_split=0;

            //OYUNU YENIDEN BASLATMA
            again_game=0;

            //OYUN BASI PLAYER rastgele LOCATION VE HIZI
            player.location_x=rand()%MAP_W;
            player.location_y=rand()%MAP_H;
            player.radius=RADIUS_PLAYER;
            player.live_or_dead=1;

            //OYUN BASI BOTLARIN YARICAPLARI
            while(sayac<BOT_NUMBER)
            {
                bots[sayac].radius=RADIUS_BOT;
                ++sayac;
            }

            // Random yem, bot and color for bot
            random_yem_location(yem);
            random_bot_location(bots, -1);
            random_color_bot(bots);

            //OYUN BASI RASTGELE HEDEF (BOTLAR ICIN)
            random_bot_target_location(bots, -1);

            ////OYUN BASI YESIL SEYLER ICIN RASTGELE LOCATION
            random_green_things_location(green_things,-1);
        }


        //PLAYER AND BOT SPEED UPDATE
        speed_update(&player, bots, splits, number_of_split);

        //YEMELERIN DIGERLERI TARAFINDAN YENMESI
        eat_yem(&player, yem, splits, number_of_split,bots);

        //SPLITIN DIGERLERI TARAFINDAN YENMESI
        eat_split(&player, bots, splits, number_of_split);

        //GREEN THINGS TARAFINDAN BOLUNME
        division_green_things(&player, bots, splits,&number_of_split, green_things);

        //OYUN ADI
        textout_ex(bmp, font1, "AgorI YO! v1.2.1-beta", 20, 20, makecol(0, 0, 50), -1);

        //BOTLARIN DIGERLERI TARAFINDAN YENMESI
        eat_bot(&player, bots, splits, number_of_split);

        //PLAYERIN DIGERLERI TARAFINDAN YENMESI
        eat_player(&player, bots, splits, number_of_split);

        //BLUE MOUSE ICON
        if(choose_control==2)
        {
            blue_mouse_icon(&sprite, player);
            draw_sprite(bmp, sprite_game, (sprite.location_x), (sprite.location_y));
        }

        //PLAYER HAREKET YONU
        (player.location_x_last)=(player.location_x);
        (player.location_y_last)=(player.location_y);

        //PLAYER HAREKETI
        move_player(&player, choose_control, splits, number_of_split);

        //SPLITS HAREKET YONU
        while(sayac_split<number_of_split)
        {
            (splits[sayac_split].location_x_last)=(splits[sayac_split].location_x);
            (splits[sayac_split].location_y_last)=(splits[sayac_split].location_y);
            ++sayac_split;
        }
        sayac_split=0;


        //SPLITS HAREKETI
        move_splits(&player, choose_control, splits, number_of_split);


        //DIVISION
        division_space(&player, choose_control, splits, &number_of_split);


        //BOT HAREKETI
        move_bot(bots, player, splits, number_of_split);


        //KAMERA HAREKETI
        camera_move (player, splits, &camera, number_of_split);

        //BUFFER
        blit(bmp,screen,camera.location_x,camera.location_y,0,0,MAP_W,MAP_H);
        clear_bitmap(bmp);


        //ARKAPLAN KAPLAMASI
        background.location_x=0;

        while(background.location_x<5)
        {
            while(background.location_y<5)
            {
                blit(arka_fon,bmp,0,0,SCREEN_WW*(background.location_x),SCREEN_HH*(background.location_y),SCREEN_WW,SCREEN_HH);
                ++background.location_y;
            }
            (background.location_y)=0;
            ++(background.location_x);
        }

        draw_circles(bmp, player, bots, splits, number_of_split, yem_color, player_color, yem, green_things, green_things_pic, font1);


        //SPLITLERIN YENILIP YENILMEDIGI KONTROL EDILIR
        while(sayac_split<number_of_split)
        {
            if(splits[sayac_split].defeated==1)
                game_continuation=1;

            ++sayac_split;
        }

        //PLAYER IN YENILIP YENILMEDIGI KONTROL EDILIR
        if(player.live_or_dead)
            game_continuation=1;

        sayac_split=0;

        //DURAKLATMA MENUSU
        //ESC YE BASILIR YA DA PLAYER OLURSE OYUN DURUR
        if(key[KEY_ESC] || game_continuation==0)
        {
            //STOP FON MUSIC
            stop_sample(game_fon_music);

            set_mouse_range(0,0,SCREEN_WW, SCREEN_HH);
            play_sample(stop_game,255,128,1000,1);

            while(check)
            {
                //background
                blit(duraklatma_menusu_pic,bmp,0,0,0,0,duraklatma_menusu_pic->w,duraklatma_menusu_pic->h);

                if(mouse_x>390 && mouse_x<870 && mouse_y>90  && mouse_y<255)
                {
                    if(game_continuation)
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(255, 255, 0), -1);

                    else
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(192, 192, 192), -1);

                    textout_ex(bmp, font1, "YENIDEN BASLAT", 460, 410, makecol(0, 0, 0), -1);
                    textout_ex(bmp, font1, "CIKIS", 570, 680, makecol(0,0, 0), -1);
                }

                else if (mouse_x>390 && mouse_x<870 && mouse_y>350  && mouse_y<510)
                {
                    if(game_continuation)
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(0, 0, 0), -1);

                    else
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(192, 192, 192), -1);

                    textout_ex(bmp, font1, "YENIDEN BASLAT", 460, 410, makecol(255, 255, 0), -1);
                    textout_ex(bmp, font1, "CIKIS", 570, 680, makecol(0, 0, 0), -1);
                }

                else if (mouse_x>390 && mouse_x<870 && mouse_y>610  && mouse_y<780)
                {
                    if(game_continuation)
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(0, 0, 0), -1);

                    else
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(192, 192, 192), -1);

                    textout_ex(bmp, font1, "YENIDEN BASLAT", 460, 410, makecol(0, 0, 0), -1);
                    textout_ex(bmp, font1, "CIKIS", 570, 680, makecol(255, 255, 0), -1);
                }

                else
                {
                    if(game_continuation)
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(0, 0, 0), -1);

                    else
                        textout_ex(bmp, font1, "DEVAM", 550, 150, makecol(192, 192, 192), -1);

                    textout_ex(bmp, font1, "YENIDEN BASLAT", 460, 410, makecol(0, 0, 0), -1);
                    textout_ex(bmp, font1, "CIKIS", 570, 680, makecol(0, 0, 0), -1);
                }

                draw_sprite(bmp, stop_game_sprite, mouse_x, mouse_y);

                if(mouse_x>390 && mouse_x<870 && mouse_y>90  && mouse_y<255 && (mouse_b & 1) && game_continuation==1)
                    check=0;

                if(mouse_x>390 && mouse_x<870 && mouse_y>350  && mouse_y<510 && (mouse_b & 1))
                {
                    check=0;
                    again_game=1;
                }

                if(mouse_x>390 && mouse_x<870 && mouse_y>610  && mouse_y<780 && (mouse_b & 1))
                {
                    check=0;
                    still_run=0;
                }

                blit(bmp,screen,0,0,0,0,bmp->w,bmp->h);
                clear_bitmap(bmp);
            }

            check=1;
            stop_sample(stop_game);


            if(still_run)
            {
                //DEVAM EDILIYORSA START FON MUSIC
                play_sample(game_fon_music,255,128,1000,1);
            }
        }

        game_continuation=0;
    }
    destroy_sample (game_fon_music);
    destroy_bitmap (sprite_game);
    destroy_bitmap (green_things_pic);
    destroy_bitmap (duraklatma_menusu_pic);
    destroy_bitmap (black_screen);
    destroy_bitmap (stop_game_sprite);
}
