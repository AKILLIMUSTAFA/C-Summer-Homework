#ifndef XBOX_H_INCLUDED
#define XBOX_H_INCLUDED

#include <allegro.h>

enum
{
  BUTTON_A,
  BUTTON_B,
  BUTTON_X,
  BUTTON_Y,
  BUTTON_LB,
  BUTTON_RB,
  BUTTON_LS,
  BUTTON_RS,
  BUTTON_BACK,
  BUTTON_START,

  DPAD_UP,
  DPAD_DOWN,
  DPAD_LEFT,
  DPAD_RIGHT,

  LSTICK_UP,
  LSTICK_DOWN,
  LSTICK_LEFT,
  LSTICK_RIGHT,

  TAM_MAX
};

int xbox_prev_state[TAM_MAX];
int xbox[TAM_MAX];

void xbox_input();
int xbox_soltou(int botao);
int xbox_segurou(int botao);
int xbox_apertou(int botao);


#endif // XBOX_H_INCLUDED

