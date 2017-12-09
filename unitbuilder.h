#ifndef UNIT_BUILDER_HEADER
#define UNIT_BUILDER_HEADER

#include "units.h"
/* unit structure */

extern struct unitNode* buildKnightUnit(unitNode*, int);
extern struct unitNode* buildPirateUnit(unitNode*, int);
extern struct unitNode* buildUnit(unitNode*, char*, int);

#endif
