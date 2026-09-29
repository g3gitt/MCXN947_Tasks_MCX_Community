
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include "flexio_8080_drv.h"
#include "lcd_drv.h"

volatile static bool g_enable_to_update = false;
int main(void)
{
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    Demo_FLEXIO_8080_Init();

    LCD_ST7796S_IPS_Init();

    while (1)
    {
    }
}
