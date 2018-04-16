#ifndef _GEVP_CONFIG_H
#define _GEVP_CONFIG_H

//if define, output step result
#undef OUTPUT_EIGENVALUE_DIRECTLY 
//if define, sorting eigenvalue for later calculating so that mode number matches
#define EIGENVALUE_SORTING
//if define, consider small Lt effect so that replace log by acosh (should be implemented by Chris's numerical inversion)
//#undef FINITE_LT_EFFECT

#endif
