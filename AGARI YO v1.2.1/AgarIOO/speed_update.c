#include "agar.h"

void speed_update(player_feature_t *player, bots_feature_t bots[SIZE_ARRAY], division_t splits[SIZE_ARRAY], int number_of_split)
{
    int sayac;

    //PLAYER SPEED UPDATE
    (player->speed)=FIRST_MOVE_SPEED/(player->radius);

    //SPLITS SPEED UPDATE
    sayac=number_of_split-1;

    while(sayac>-1)
    {
        (splits[sayac].speed)=FIRST_MOVE_SPEED/(splits[sayac].radius);
        --sayac;
    }

    //BOT SPEED UPDATE
    sayac=BOT_NUMBER-1;

    while(sayac>-1)
    {
        (bots[sayac].speed)=FIRST_MOVE_SPEED/(bots[sayac].radius);
        --sayac;
    }

}
