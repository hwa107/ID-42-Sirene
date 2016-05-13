#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"

void checkInputs()
{
  if (buttons.pressed(DOWN_BUTTON) && (mermaid.y < GAME_BOTTOM - 16))
  {
    mermaid.y++;
  }
  if (buttons.pressed(LEFT_BUTTON) && (mermaid.x > GAME_LEFT))
  {
    mermaid.x--;
  }
  if (buttons.pressed(UP_BUTTON) && (mermaid.y > GAME_TOP))
  {
    mermaid.y--;
  }
  if (buttons.pressed(RIGHT_BUTTON) && (mermaid.x < GAME_RIGHT - 16))
  {
    mermaid.x++;
  }

  if (buttons.justPressed(A_BUTTON))
  {
    mermaid.weaponType++;
    if (mermaid.weaponType > 3) mermaid.weaponType = 0;
  }

  if (buttons.justPressed(B_BUTTON) && (coolDown[mermaid.weaponType] == coolDownMax[mermaid.weaponType]))
  {

    if (mermaid.weaponType == WEAPON_TYPE_TRIDENT)
    {
      coolDown[mermaid.weaponType]--;
      shootWeapon();
    }
    if ((mermaid.weaponType == WEAPON_TYPE_SEASHELL))
    {
      {
        coolDown[mermaid.weaponType]--;
        for (byte i = 0; i < 3; i++)
        {
          shootWeapon();
        }
      }
    }
  }
  if (buttons.pressed(B_BUTTON))
  {
    if ((mermaid.weaponType == WEAPON_TYPE_BUBBLES) && (coolDown[WEAPON_TYPE_BUBBLES] == coolDownMax[WEAPON_TYPE_BUBBLES]))
    {
      coolDown[mermaid.weaponType]--;
      shootWeapon();
    }
    if (mermaid.weaponType == WEAPON_TYPE_MAGIC)
    {
      mermaid.magicCharging = true;
      if (arduboy.everyXFrames(30)) mermaid.chargeBarFrame ++;
      if (mermaid.chargeBarFrame > 4) mermaid.chargeBarFrame = 4;
    }
  }
  if (buttons.notPressed(B_BUTTON) && (mermaid.weaponType == WEAPON_TYPE_MAGIC) && (mermaid.magicCharging == true))
  {
    mermaid.magicCharging = false;
    coolDown[mermaid.weaponType]--;
    shootWeapon();
    mermaid.chargeBarFrame = 0;
  }
}


#endif
