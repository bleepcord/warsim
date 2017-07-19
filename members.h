#ifndef MEMBERS_HEADER
#define MEMBERS_HEADER

#include "unitBuilder.h"

typedef struct unitMember
{
    char* name;
    int meleeDamageLow;
    int meleeDamageHigh;
    int rangeDamageLow;
    int rangeDamageHigh;
    int strength;
    int constitution;
    int skill;
    int dexterity;
    int hasRangedAttack;
    int health;
    struct unitMember* mark;
} unitMember;

typedef struct memberNode {
    unitMember* member;
    struct memberNode* nextMember;
} memberNode;

extern int isEmpty(memberNode*);
memberNode* createNode(unitMember*, memberNode*);
extern memberNode* prependMember(memberNode*, unitMember*);
extern memberNode* appendMember(memberNode*, unitMember*);
memberNode* removeFront(memberNode*);
memberNode* removeBack(memberNode*);
extern memberNode* removeMember(memberNode*, memberNode*);
extern memberNode* dispose(memberNode*);

#endif
