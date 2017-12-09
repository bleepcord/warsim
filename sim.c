#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "units.h"
#include "unitbuilder.h"
#include "battle.h"

/* opts
 * -f NEW_TEAM
 * -u UNIT_NAME as string
 * -m NUMBER_MEMBERS_IN_UNIT as int
 *
 * TODO: not building separate factions properly, error with unitialized
 *       values brought up by valgrind
 */
int main(int argc, char* argv[])
{
    const char* shortopts = "fu:m:";
    const struct option longopts[] = {
        {"faction", no_argument, NULL, 'f'},
        {"unit", required_argument, NULL, 'u'},
        {"members", required_argument, NULL, 'm'}
    };

    char* unitToBuild = NULL;
    char* memberOp = NULL;
    int numberOfFactions, members;
    int unitNum = -1;
    int factionNum = -1;
    int factionOneUnitCount = -1;
    int factionTwoUnitCount = -1;

    // two factions max
    unitNode* faction[1] = {NULL, NULL};

    int arg;
    while((arg = getopt_long(argc, argv, shortopts, longopts, NULL)) != -1) {
        switch(arg) {
        case 'f':
            factionNum++;
            unitNum++;
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
            memberOp = optarg;
            members = atoi(memberOp);
            faction[factionNum] = buildUnit(faction[factionNum], unitToBuild, members);
            if (faction[factionNum] == NULL) {
                printf("Unit \"%s\" is not a valid unit.\n", unitToBuild);
                return EXIT_FAILURE;
            }
            unitNum++;
            break;
        }
    }

    walkAndPrint(faction[0]);
    walkAndPrint(faction[1]);
    destroyFaction(faction[0]);

    return EXIT_SUCCESS;
}
