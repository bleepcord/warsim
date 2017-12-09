#ifndef MEMBERS_HEADER
#define MEMBERS_HEADER

typedef enum unitType {KNIGHT, PIRATE} UnitType;

typedef struct memberNode {
    UnitType type;
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
    struct memberNode* mark;
    struct memberNode* nextMember;
} memberNode;

/* Head of unit lists. Contains pointer to first member of unit
 * and pointer to next unitNode.
 */
typedef struct unitNode {
    memberNode* firstMember;
    struct unitNode* nextUnit;
} unitNode;

memberNode* insNode(memberNode*);
memberNode* remNode(memberNode*, memberNode*);
void walkAndPrint(unitNode*);

#endif
