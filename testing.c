#include "system.h"
#include <avr/io.h>
#include "ledmat.h"
#include "navswitch.h"





int main(void)
{
    system_init();
    ledmat_init();
    navswitch_init();
    int pattern = 28;
    ledmat_display_column(pattern, 4);

    while(1)
    {
        navswitch_update();
        if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
          pattern = pattern >> 1;
          ledmat_display_column(pattern, 4);
        } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
          pattern = pattern << 1;
          ledmat_display_column(pattern, 4);
        }
    }

}
