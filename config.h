#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// required because lower/raise modifiers are redefined
#define PREVENT_STUCK_MODIFIERS

// tap dance key press termination interval
#define TAPPING_TERM   250

// thumb key tap-shift() double tap: one shot shift (0) off (1) on
#define DT_SHIFT 1

#endif
