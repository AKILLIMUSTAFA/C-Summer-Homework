#ifndef AGAR_H_INCLUDED
#define AGAR_H_INCLUDED

#include <allegro.h>


#define SIZE_ARRAY 1000

#define SCREEN_WW 1280
#define SCREEN_HH 1024

#define MAP_W 6400
#define MAP_H 5120

#define YEM_NUMBER 200 //this number can't be bigger than SIZE_ARRAY
#define BOT_NUMBER 20  //this number can't be bigger than SIZE_ARRAY

#define RADIUS_PLAYER 32
#define RADIUS_BOT 32
#define RADIUS_YEM 8
#define RADIUS_GREEN_THING_rx 135
#define RADIUS_GREEN_THING_ry 95

#define GROWTH_RATE 8

#define MERGER_AGAIN 1000 // 25 saniye.

#define FIRST_MOVE_SPEED 640

#define YEME_SINIRI 5

#define GREEN_THINGS_NUMBER 10

#define BOLUNME_SINIRI 63

#define DIVISION_GREEN_THINGS_SINIRI 64

/*------------------------------------------------------------------------------*/
/*                              Structure                                       */

//PLAYER ICIN STRUCT
typedef struct{

    double location_x;//bulundugu x koordinati
    double location_y;//bulundugu y koordinati
    double location_x_last;// hareket etmeden onceki bulundugu x koordinatı (gidilen yonun bulunması)
    double location_y_last;// hareket etmeden onceki bulundugu y koordinatı (gidilen yonun bulunması)
    double radius; // yaricapi
    double speed;  //hizi
    int live_or_dead; // 1 ise yasiyor. 0 ise yenmis ve yokedilmis

}player_feature_t;


//HAREKET ICIN YONLER
typedef struct{

    int left;//SOL
    int right;//SAG
    int up;//YUKARI
    int down;//ASAGI

}move_feature_t;

//BOTLAR ICIN STRUCT
typedef struct{

    double location_x;//bulundugu x koordinati
    double location_y;//bulundugu y koordinati
    double radius;//yaricapi
    double speed;//hizi
    double target_location_x;//gidecegi hedefin x koordinati
    double target_location_y;//gidecegi hedefin y koordinati
    double distance_target_location_x; //x koordinatinda gidecegi hedefe  olan uzaklıgı
    double distance_target_location_y; //y koordinatinda gidecegi hedefe  olan uzaklıgı
    double random_color_red; // rastgele kırmızı tonu
    double random_color_green; // rastgele yesil tonu
    double random_color_blue; // rastgele mavi tonu

}bots_feature_t;

//KOORDINAT
typedef struct{

    double location_x; //x koordinati
    double location_y; //y koordinati

}location_t;

//PLAYERDAN KOPAN PARCALAR ICIN STRUCT
//BUNLARA SPLIT ADINI KOYDUM
typedef struct{

    double location_x;//bulundugu x koordinati
    double location_y;//bulundugu y koordinati
    double location_x_last;// hareket etmeden onceki bulundugu x koordinatı (gidilen yonun bulunması)
    double location_y_last;// hareket etmeden onceki bulundugu y koordinatı (gidilen yonun bulunması)
    double radius; //yaricapi
    double speed; //hizi
    int defeated; // 1 ise yasiyor. 0 ise yenmis ve yokedilmis
    int aktif;  //bolunmeden sonra 1 olur ve birlesme olmaz. 0 olduðu zaman birlesme gerceklesir.
    int aktif_counter; // sayac yaklasık 25 saniye sonra aktifi 0 yaparak birlesmeye izin verir.
    int move_way; // Bolunmede ilerleme yonu
    int move_way_counter; // Bolunmede ilerleme süresi (yaklasik 1 saniye)

}division_t;

//YUVARLAK SEKILLERI ICIN STRUCT
typedef struct{

    double location_x;//bulundugu x koordinati
    double location_y;//bulundugu y koordinati
    double radius;//yaricapi
    int red; //kirmizi tonu
    int green; //yesil tonu
    int blue; //mavi tonu

}circle_t;

//RENKLER ICIN STRUCT
typedef struct{

    int red; //KIRMIZI TONU
    int green; //YESIL TONU
    int blue; //MAVI TONU

}color_feature_t;

//ALLEGRO BASLATMA FONKSIYONLARI
void Baslat();

//ALLEGRO BITIRME FONKSIYONLARI
void Bitir();

//ALLEGRO BASLANGICI ICIN KOD
void increment_speed_counter();

//OYUN SIRASINDA GOZUKEN MAVI FARE SEMBOLU
void blue_mouse_icon(location_t *sprite, player_feature_t player);

//PLAYERI TAKIP EDEN ve GOZUKMESINI SAGLAYAN CAMERA FONKSIYONU
void camera_move (player_feature_t player, division_t splits[SIZE_ARRAY], location_t *camera, int number_of_split);

//TEMA VE KARAKTER SECIM EKRANI
void choose_thema(BITMAP *bmp,BITMAP *sprite,double still_run, int *choose_tema, color_feature_t *yem_color, color_feature_t *player_color);

//BASLANGIC EKRANI
double screen_first(double first_screen,BITMAP *bmp,BITMAP *sprite);

//KONTROL CIHAZI SECIM EKRANI
double player_control(BITMAP *bmp,BITMAP *sprite, double still_run);

//OYUN OYNANDIGI SIRADA CALISAN FONKSIYON
//BUTUN FONKSIYONLAR BU FONKSIYON ICERISINDE SIRAYLA CAGILIRIR
void game(double still_run,BITMAP *bmp,BITMAP *arka_fon,BITMAP *sprite_game,int choose_control, color_feature_t yem_color, color_feature_t player_color);

//PLAYERIN BOTLARIN VE SPLITLERI CIZEN FONKSIYON
//BUYUK OLAN USTTE CIZILIR ve KUCUK OLANI KAPLAR
void draw_circles(BITMAP *bmp, player_feature_t player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY],
                  int number_of_split, color_feature_t yem_color, color_feature_t player_color, location_t yem[SIZE_ARRAY],
                  circle_t green_things[SIZE_ARRAY], BITMAP *green_things_pic, FONT *font1);


//EAT

//BOTLARIN DIGERLERI TARAFINDAN YENMESI
void eat_bot(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split);

//PLAYERIN DIGERLERI TARAFINDAN YENMESI
void eat_player(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split);

//SPLITIN DIGERLERI TARAFINDAN YENMESI
void eat_split(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split);

//YEMELERIN DIGERLERI TARAFINDAN YENMESI
void eat_yem(player_feature_t *player, location_t yem[SIZE_ARRAY], division_t splits[SIZE_ARRAY],
             int number_of_split, bots_feature_t bots[SIZE_ARRAY]);


//RASTGELE KOORDINATLAR

//RASTGELE YEM KOORDINATLARI
void random_yem_location(location_t yem[SIZE_ARRAY]);

//RASTGELE BOT KOORDINATLARI
void random_bot_location(bots_feature_t bots[SIZE_ARRAY], int target);

//RASTGELE BOT ICIN HEDEF KOORDINATLARI
void random_bot_target_location(bots_feature_t bots[SIZE_ARRAY], int target);

//RASTGELE BOT RENGI
void random_color_bot(bots_feature_t bots[SIZE_ARRAY]);

//RASTGELE YESIL ALAN KOORDINATI
void random_green_things_location(circle_t green_things[SIZE_ARRAY], int target);


//HAREKET

//PLAYER HAREKETI
void move_player(player_feature_t *player, double choose_control,division_t splits[SIZE_ARRAY], int number_of_split);

//BOT HAREKETI
void move_bot(bots_feature_t bots[SIZE_ARRAY], player_feature_t player, division_t splits[SIZE_ARRAY], int number_of_split);

//SPLIT HAREKETI
void move_splits(player_feature_t *player, double choose_control,division_t splits[SIZE_ARRAY], int number_of_split);



//PLAYER BOT VE SPLITLERIN HIZ UPDATESI
void speed_update(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split);



//SPACE ILE BOLUNME

//SPACE ILE BOLUNME
void division_space(player_feature_t *player, double choose_control, division_t splits[SIZE_ARRAY], int *number_of_split);

//SPLITIN SPACE ILE BOLUNMESI
void division_space_split(division_t splits[SIZE_ARRAY], int number_of_split, int sayac_split);

//PLAYERIN SPACE ILE BOLUNMESI
void division_space_player(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split);

//BOLUNMENIN GERCEKLESTIGI YON
void division_space_move_way(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split);

//BOLUNMEDEN SONRA BIRLESME ICIN GECMESI GEREKEN SURE
void division_space_merger_again(player_feature_t *player, division_t splits[SIZE_ARRAY], int number_of_split);



//GREEN THINGS TARAFINDAN BOLUNME

//GREEN THINGS TARAFINDAN BOLUNME
void division_green_things(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY],
                           int *number_of_split, circle_t green_things[SIZE_ARRAY]);

//PLAYERIN GREEN THINGS TARAFINDAN BOLUNMESI
void division_green_things_player(player_feature_t *player, division_t splits[SIZE_ARRAY], int *number_of_split, circle_t green_things[SIZE_ARRAY],
                       int sayac_division);

//SPLITLERIN GREEN THINGS TARAFINDAN BOLUNMESI
void division_green_things_split(division_t splits[SIZE_ARRAY], int *number_of_split, circle_t green_things[SIZE_ARRAY],
                                 int sayac_division, int target_split);

#endif // AGAR_H_INCLUDED

