#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "members.h"
#include "unitBuilder.h"
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

    char* unitToBuild;
    int numberOfFactions = NULL;
    int arg = NULL;
    int factionNum = NULL;
    int members;
    int unitNum;
    int factionOneUnitCount = -1;
    int factionTwoUnitCount = -1;

    // two factions max
    memberNode* faction[1];

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
            faction[factionNum] = buildUnit(faction[0], unitToBuild, members);
            if (faction[factionNum] == NULL) {
                printf("Unit \"%s\" is not a valid unit.\n", unitToBuild);
                return EXIT_FAILURE;
            }
            unitNum++;
            break;
        }
    }

    return EXIT_SUCCESS;
}
