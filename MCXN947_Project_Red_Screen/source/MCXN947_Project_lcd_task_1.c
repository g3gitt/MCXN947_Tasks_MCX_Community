/*
 * Copyright 2016-2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

#include "flexio_8080_drv.h"
#include "lcd_drv.h"

int main(void)
{
    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    BOARD_InitDebugConsole();
#endif

    PRINTF("LCD test\r\n");

    /*
     * Initialize FLEXIO 8080 LCD interface.
     */
    Demo_FLEXIO_8080_Init();

    /*
     * Initialize ST7796S IPS LCD controller.
     */
    LCD_ST7796S_IPS_Init();
    AreaPoints_t area = {
        .x1 = 0,
        .y1 = 0,
        .x2 = 479,
        .y2 = 319
    };

    LCD_FillColorPolling(&area, Red);
    while (1)
    {
    }

    return 0;
}
