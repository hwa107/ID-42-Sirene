#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "Arglib.h"
#include "bitmaps.h"

//define menu states (on main menu)
#define STATE_MENU_INTRO             0
#define STATE_MENU_MAIN              1
#define STATE_MENU_HELP              2
#define STATE_MENU_PLAY              3
#define STATE_MENU_INFO              4
#define STATE_MENU_SOUNDFX           5

//define game states (on main menu)
#define STATE_GAME_PREPARE_LEVEL     6
#define STATE_GAME_NEXT_LEVEL        7
#define STATE_GAME_PLAYING           8
#define STATE_GAME_PAUSE             9
#define STATE_GAME_OVER              10

#define GAME_TOP                     0
#define GAME_BOTTOM                  64
#define GAME_LEFT                    0
#define GAME_RIGHT                   128

#define WEAPON_TYPE_TRIDENT          0
#define WEAPON_TYPE_BUBBLES          1
#define WEAPON_TYPE_SEASHELL         2
#define WEAPON_TYPE_MAGIC            3

#define WEAPON_COOLDOWN_TRIDENT      24
#define WEAPON_COOLDOWN_BUBBLES      16
#define WEAPON_COOLDOWN_SEASHELL     24
#define WEAPON_COOLDOWN_MAGIC        24


Arduboy arduboy;
Sprites sprites(arduboy);
SimpleButtons buttons (arduboy);

unsigned char gameState;
boolean soundYesNo;
int menuSelection;
byte counter = 0;
byte level;
byte currentWave;
byte previousWave;
unsigned long scorePlayer; 

#endif
