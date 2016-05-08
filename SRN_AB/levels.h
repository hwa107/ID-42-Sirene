#ifndef LEVELS_H
#define LEVELS_H

#include <Arduino.h>
#include "globals.h"
#include "enemies.h"

#define TOTAL_AMOUNT_OF_LEVELS  2
#define TOTAL_AMOUNT_OF_WAVES   20

boolean checkStartWave()
{
  if (currentWave != previousWave)
  {
    previousWave = currentWave;
    return true;
  }
  return false;
}


boolean checkEndWave()
{
  byte test = 0;
  for (byte i = 0; i < ARRAY_MAX_AMOUNT; i++)
  {
    test = test + enemy[i].isActive;
  }
  if (test < 1) currentWave++;
}

boolean checkEndLevel()
{
  if (currentWave > TOTAL_AMOUNT_OF_WAVES)
  {
    return true;
  }
  return false;
}

void enemySetInLine(byte firstEnemy, byte lastEnemy, byte x, byte y, int spacingX, int spacingY)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].isActive = true;
    enemy[i].x = x + (spacingX * (i - firstEnemy));
    enemy[i].y = y + (spacingY * (i - firstEnemy));
    enemy[i].HP = 2;
  }
}

void enemySwimRightLeft(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
  }
}

void enemySwimToMiddle(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
    if (enemy[i].x < 64)
    {
      if (enemy[i].y < 31) enemy[i].y++;
      if (enemy[i].y > 32) enemy[i].y--;
    }
  }
}

void enemySwimSine(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    enemy[i].x = enemy[i].x - speedEnemy;
    if ((enemy[i].x < 120 ) && (enemy[i].x > 104) && (enemy[i].y > 16)) enemy[i].y--;
    if ((enemy[i].x < 105) && (enemy[i].x > 73) && (enemy[i].y < 48)) enemy[i].y++;
    if ((enemy[i].x < 74 ) && (enemy[i].x > 42) && (enemy[i].y > 16)) enemy[i].y--;
    if ((enemy[i].x < 43) && (enemy[i].x > 10) && (enemy[i].y < 48)) enemy[i].y++;
    if ((enemy[i].x < 11) && (enemy[i].y > 16)) enemy[i].y--;
  }
}

void enemySwimDownUp(byte firstEnemy, byte lastEnemy, byte speedEnemy)
{
  for (byte i = firstEnemy; i < lastEnemy; i++)
  {
    if (enemy[i].frame > 4 && enemy[i].frame < 7 )enemy[i].y = enemy[i].y - speedEnemy - 1;
    if (enemy[i].frame > 6 )enemy[i].y = enemy[i].y - speedEnemy;
  }
}

void wave000()
{
}

void wave001()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 12, 20, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave002()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 32, 20, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave003()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 56, 20, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave004()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 12, 20, 0);
  enemySwimToMiddle(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave005()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 56, 20, 0);
  enemySwimToMiddle(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave006()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 128, 32, 20, 0);
  enemySwimSine(ARRAY_START_FISHY, MAX_ONSCREEN_FISHY, 1);
  checkEndWave();
}

void wave007()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 12, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 1);
  checkEndWave();
}

void wave008()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 32, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 1);
  checkEndWave();
}

void wave009()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 56, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 1);
  checkEndWave();
}

void wave010()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 12, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 2);
  checkEndWave();
}

void wave011()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 32, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 2);
  checkEndWave();
}

void wave012()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 128, 56, 0, 0);
  enemySwimRightLeft(ARRAY_START_FISHY, ARRAY_START_FISHY + 1, 2);
  checkEndWave();
}

void wave013()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 96, 64, -40, 16);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave014()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 16, 64, 40, 16);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave015()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 16, 64, 40, 0);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS, 1);
  checkEndWave();
}

void wave016()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS - 1, 32, 64, 48, 0);
  enemySwimDownUp(ARRAY_START_JELLYFISH, ARRAY_START_OCTOPUS - 1, 1);
  checkEndWave();
}

void wave017()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_EEL, ARRAY_START_EEL + 1, 128, 12, 0, 0);
  enemySwimRightLeft(ARRAY_START_EEL, ARRAY_START_EEL + 1, 1);
  checkEndWave();
}

void wave018()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_OCTOPUS, ARRAY_START_OCTOPUS + 1, 128, 12, 0, 0);
  enemySwimRightLeft(ARRAY_START_OCTOPUS, ARRAY_START_OCTOPUS + 1, 1);
  checkEndWave();
}

void wave019()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISH, ARRAY_START_EEL, 128, 12, 24, 0);
  enemySwimRightLeft(ARRAY_START_FISH, ARRAY_START_EEL, 1);
  checkEndWave();
}

void wave020()
{
  if (checkStartWave())enemySetInLine(ARRAY_START_FISH, ARRAY_START_EEL, 128, 48, 24, 0);
  enemySwimRightLeft(ARRAY_START_FISH, ARRAY_START_EEL, 1);
  checkEndWave();
}



typedef void (*FunctionPointer) ();

FunctionPointer Levels[TOTAL_AMOUNT_OF_LEVELS][TOTAL_AMOUNT_OF_WAVES] =
{
  { //LEVEL 01
    wave020,
    wave019,
    wave018,
    wave017,
    wave016,
    wave015,
    wave014,
    wave013,
    wave012,
    wave011,
    wave010,
    wave009,
    wave008,
    wave007,
    wave006,
    wave005,
    wave004,
    wave003,
    wave002,
    wave001,
    //wave000,
  },
  { //LEVEL 02
    wave001,
    wave002,
    wave003,
    wave004,
    wave005,
    wave006,
    wave007,
    wave008,
    wave009,
    wave010,
    wave011,
    wave012,
    wave013,
    wave014,
    wave015,
    wave016,
    wave017,
    wave018,
    wave019,
    wave020,
    //wave000,
  }
};

#endif
