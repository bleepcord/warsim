#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unitbuilder.h"
#include "units.h"

/* Each function here builds a unit of size 'members' by calling
 * insNode passing the head of the unit it is building on
 */
unitNode* buildKnightUnit(unitNode* head, int members) {
    /* Allocate space for new unit and insert to front
     */
    unitNode* newUnit = malloc(sizeof(unitNode));
    newUnit->nextUnit = head;
    head = newUnit;

    memberNode* cursor = head->firstMember;
    //memberNode* newMember = NULL; this is unused

    for (int i = 0; i < members; i++) {
        cursor = insNode(cursor);
        cursor->type = KNIGHT;
        cursor->meleeDamageLow = 7;
        cursor->meleeDamageHigh = 11;
        cursor->rangeDamageLow = 0;
        cursor->rangeDamageHigh = 0;
        cursor->strength = 20;
        cursor->constitution = 20;
        cursor->skill = 20;
        cursor->dexterity = 20;
        cursor->hasRangedAttack = 0;
        cursor->mark = NULL;
    }
    head->firstMember = cursor;

    return head;
}

unitNode* buildPirateUnit(unitNode* head, int members) {
    /* Allocate space for new unit and insert to front
     */
    unitNode* newUnit = malloc(sizeof(newUnit));
    newUnit->nextUnit = head;
    head = newUnit;

    memberNode* cursor = head->firstMember;
    memberNode* newMember = NULL;

    for (int i = 0; i < members; i++) {
        cursor = insNode(cursor);
        cursor->type = PIRATE;
        cursor->meleeDamageLow = 3;
        cursor->meleeDamageHigh = 10;
        cursor->rangeDamageLow = 3;
        cursor->rangeDamageHigh = 10;
        cursor->strength = 20;
        cursor->constitution = 20;
        cursor->skill = 20;
        cursor->dexterity = 20;
        cursor->hasRangedAttack = 1;
    }
    head->firstMember = cursor;

    return head;
    return NULL;
}


/* Calls the proper build function based on unit name input
 * Returns pointer to unitNode.
 */
unitNode* buildUnit(unitNode* head, char* unitName, int members) {
    memberNode* retUnit;
    if (!strcmp(unitName, "knight")){
        retUnit = buildKnightUnit(head, members);
        return retUnit;
    } else if (!strcmp(unitName, "pirate")) {
        retUnit = buildPirateUnit(head, members);
        return retUnit;
    }

    return NULL;
}

/* Deallocates space for unit nodes and calls destroyMembers to deallocate
 * space from individual members of unit
 */
int destroyFaction(unitNode* head) {
    unitNode* cursor = head;
    unitNode* toDelete = NULL;

    while (cursor != NULL) {
        destroyMembers(cursor->firstMember);
        toDelete = cursor;
        cursor = cursor->nextUnit;
        free(toDelete);
    }
    return 0;
}
