/* This file declares a linked list implementation to track and store members of units.
 */
#include <stdio.h>

#include "units.h"

/* Inserts a new member (initialized from unitBuilder) into the front
 * of the list.
 */
memberNode* insNode(memberNode* head) {
    memberNode* newMember = malloc(sizeof(memberNode));
    newMember->nextMember = head;
    head = newMember;
    return head;
}

/* Removes a node from anywhere in the list. Called when a unit member is killed.
 */
memberNode* remNode(memberNode* head, memberNode* deadMember) {
    memberNode* toDelete = NULL;
    memberNode* cursor = head;
    while (cursor != NULL) {
        if (cursor == deadMember) {
            toDelete = cursor;
            cursor = cursor->nextMember;
            free(toDelete);
            break;
        }
        cursor = cursor->nextMember;
    }
    return head;
}

/* deallocate memory from each member in the unit
 */
int destroyMembers(memberNode* head) {
    memberNode* cursor = head;
    memberNode* toDelete = NULL;
    while (cursor != NULL) {
        toDelete = cursor;
        cursor = cursor->nextMember;
        free(toDelete);
    }
    return 0;
}

void walkAndPrint(unitNode* head) {
    unitNode* unit = head;
    memberNode* cursor = NULL;
    while (unit != NULL) {
        cursor = unit->firstMember;
        for (int i = 0; cursor != NULL; i++) {
            printf("%d: %d\n", i, cursor->type);
            cursor = cursor->nextMember;
        }
        unit = unit->nextUnit;
    }
}
