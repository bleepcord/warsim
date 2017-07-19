#ifndef UNIT_BUILDER_HEADER
#define UNIT_BUILDER_HEADER

#include "members.h"
/* unit structure */

extern struct memberNode* buildKnightUnit(struct memberNode*, int);
extern struct memberNode* buildPirateUnit(struct memberNode*, int);
extern struct memberNode* buildUnit(struct memberNode*, char*, int);

#endif
