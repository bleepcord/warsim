#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"units.h"

/* each function here builds a unit of size 'members', stores in a heap allocated array and returns the pointer */
enemy* buildKnightUnit(int members)
{
    enemy* knights = malloc(members * sizeof(enemy));
    for (int i = 0; i < members; i++) {
        knights[i].name = "knight";
        knights[i].health = 100;
        knights[i].meleeDamageLow = 5;
        knights[i].meleeDamageHigh = 9;
        knights[i].rangeDamageLow = 0;
        knights[i].rangeDamageHigh = 0;
        knights[i].strength = 20;
        knights[i].constitution = 20;
        knights[i].skill = 20;
        knights[i].dexterity = 20;
        if (i == (members - 1)) {
            knights[i].isLastMember = 1;
        }
        knights[i].hasRangedAttack = 0;
        knights[i].alive = 1;
    }
    return knights;
}

enemy* buildPirateUnit(int members)
{
    enemy* pirates = malloc(members * sizeof(enemy));
    for (int i = 0; i < members; i++) {
        pirates[i].name = "pirate";
        pirates[i].health = 100;
        pirates[i].meleeDamageLow = 5;
        pirates[i].meleeDamageHigh = 9;
        pirates[i].rangeDamageLow = 3;
        pirates[i].rangeDamageHigh = 20;
        pirates[i].strength = 20;
        pirates[i].constitution = 20;
        pirates[i].skill = 20;
        pirates[i].dexterity = 20;
        if (i == (members - 1)) {
            pirates[i].isLastMember = 1;
        }
        pirates[i].hasRangedAttack = 1;
        pirates[i].alive = 1;
    }
    return pirates;
}

enemy* buildUnit(char unitName[], int members)
{
    enemy* retUnit;
    if (!strcmp(unitName, "knight")){
        retUnit = buildKnightUnit(members);
        return retUnit;
    } else if (!strcmp(unitName, "pirate")) {
        retUnit = buildPirateUnit(members);
        return retUnit;
    }

    return NULL;
}
