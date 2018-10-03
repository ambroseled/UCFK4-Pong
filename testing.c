#include "system.h"
#include <avr/io.h>
#include "ledmat.h"





int main(void)
{
    system_init();
    ledmat_init();

    while(1)
    {
        ledmat_display_column(28,4);
    }

}
