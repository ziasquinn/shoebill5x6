
#include "shoebill5x6.h"

#ifdef BONGO_ENABLE
#include "bongo.h"
#endif


bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
    if (!oled_task_needs_to_repaint()) {
        return false;
    }
    oled_clear();
    if (clock_set_mode) {
        draw_clock();
        return false;;
    }
    switch (oled_mode) {
        default:
        case OLED_DEFAULT:
            draw_default();
            break;
        case OLED_TIME:
            draw_clock();
            break;
        case OLED_BONGO:
            draw_bongo(false);
            break;
        case OLED_BONGO_MIN:
            draw_bongo(true);
            break;
    }
    return false;
}
