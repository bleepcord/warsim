#include <stdio.h>
#include "battle.h"
#include "units.h"

int battle(enemy (*faction)[10][1000], int factionOneUnitCount, int factionTwoUnitCount)
{
    const int factionOne = 0;
    const int factionTwo = 1;
    //int unitNum = 0;
    int member = 0;
    int lastMember;

    for (int unitNum = 0; unitNum < factionOneUnitCount; unitNum++) {
        do {
            printf("%d", faction[factionOne][unitNum][member].strength);
            lastMember = faction[factionOne][unitNum][member].isLastMember;
        } while (!lastMember);
    }
}
