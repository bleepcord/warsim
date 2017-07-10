#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "units.h"
#include "battle.h"

/* opts
   -F NUM_FACTIONS
   -f NEW_TEAM
   -u UNIT_NAME as string
   -m NUMBER_MEMBERS_IN_UNIT as int
*/
int main(int argc, char* argv[])
{
    const char* shortopts = "F:fu:m";
    const struct option longopts[] = {
        {"factions", required_argument, NULL, 'F'},
        {"faction", no_argument, NULL, 'f'},
        {"unit", required_argument, NULL, 'u'},
        {"members", optional_argument, NULL, 'm'}
    };

    // TODO: limit unit sizes to 1000 for now, also work on passing faction array to battle function
    int maxMembers = 1000;
    char* unitToBuild;
    int numberOfFactions = NULL;
    int arg = NULL;
    int factionNum = NULL;
    int unitNum = 0;
    int members;
    int factionOneUnitCount = -1;
    int factionTwoUnitCount = -1;
    enemy* faction[1][10];

    while((arg = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
        switch(arg) {
        case 'F':
            if (!numberOfFactions) {
                numberOfFactions = optarg;
            }
            break;
        case 'f':
            if (!factionNum) {
                factionNum = 0;
            } else {
                factionNum++;
                unitNum = 0;
            }
            break;
        case 'u':
            unitToBuild = optarg;
            if (factionNum == 0) {
                factionOneUnitCount++;
            } else if (factionNum = 1) {
                factionTwoUnitCount++;
            }
            break;
        case 'm':
            members = optarg;
            if (members > maxMembers) {
                printf("Please keep unit sizes under %d\n", maxMembers);
                return EXIT_FAILURE;
            }
            faction[factionNum][unitNum] = buildUnit(unitToBuild, members);
            if (faction[factionNum][unitNum] == NULL) {
                printf("Unit \"%s\" is not a valid unit.\n", unitToBuild);
                return EXIT_FAILURE;
            }
            unitNum++;
            break;
        }
    }

    battle(faction, factionOneUnitCount, factionTwoUnitCount);

    for (int factionToFree = 0; factionToFree <= factionNum; factionToFree++) {
        for (int unitToFree = 0; unitToFree < unitNum; unitToFree++) {
            free(faction[factionToFree][unitToFree]);
        }
    }

    return EXIT_SUCCESS;
}
