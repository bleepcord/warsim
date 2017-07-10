#ifndef UNIT_HEADER
#define UNIT_HEADER
/* unit structure */
typedef struct enemy
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
    int isLastMember;
    int health;
    int alive;
    struct enemy* mark;
} enemy;

extern enemy* buildKnightUnit(int);
extern enemy* buildPirateUnit(int);
extern enemy* buildUnit(char*, int);

#endif
