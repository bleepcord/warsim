#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unitBuilder.h"
#include "members.h"

/* each function here builds a unit of size 'members', stores in a heap allocated array and returns the pointer */
memberNode* buildKnightUnit(memberNode* head, int members)
{
    unitMember* member;
    head = prependMember(head, member);
    memberNode* cursor = head;

    for (int i = 0; i < members; i++) {
        cursor->member->meleeDamageLow = 7;
        cursor->member->meleeDamageHigh = 11;
        cursor->member->rangeDamageLow = 0;
        cursor->member->rangeDamageHigh = 0;
        cursor->member->strength = 20;
        cursor->member->constitution = 20;
        cursor->member->skill = 20;
        cursor->member->dexterity = 20;
        cursor->member->hasRangedAttack = 0;
        cursor = prependMember(head, member);
    }

    return head;
}

memberNode* buildPirateUnit(memberNode* head, int members)
{
    return NULL;
}

memberNode* buildUnit(memberNode* head, char* unitName, int members)
{
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
