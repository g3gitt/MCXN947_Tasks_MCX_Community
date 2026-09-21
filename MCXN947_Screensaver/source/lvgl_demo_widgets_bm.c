/*
 * MCXN947 + ST7796S LCD + LVGL
 *
 * Level 1:
 * Display "HI" on the LCD.
 */

#include "pin_mux.h"
#include "lvgl_support.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include <stdlib.h>
#include "flexio_8080_drv.h"
#include "lcd_drv.h"
#include "lvgl.h"

// variables
int box_width = 50;
int box_height = 40;
int x = 20;
int y = 20;
int speed = 10;
int y_speed = 10;
int direction = 1;

int border_x = 10;
int border_y = 10;
int border_width = 450;
int border_height = 300;

/****************************************************************************
 * Definitions
 ****************************************************************************/

/* LVGL needs a 1 ms time base */
#define LVGL_TICK_MS             1U

/* Run LVGL every 5 ms */
#define LVGL_TASK_PERIOD_TICK    5U

/****************************************************************************
 * Variables
 ****************************************************************************/

static volatile uint32_t s_tick = 0U;
static volatile bool s_lvglTaskPending = false;

/****************************************************************************
 * Function Prototypes
 ****************************************************************************/

static void DEMO_SetupTick(void);

/****************************************************************************
 * Main
 ****************************************************************************/

static void change_box_color(lv_obj_t *box)
{
    int color = rand() % 6;

    if (color == 0)
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0xFF0000), 0); // Red
    }
    else if (color == 1)
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0x00FF00), 0); // Green
    }
    else if (color == 2)
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0x0000FF), 0); // Blue
    }
    else if (color == 3)
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0xFFFF00), 0); // Yellow
    }
    else if (color == 4)
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0xFF00FF), 0); // Magenta
    }
    else
    {
        lv_obj_set_style_bg_color(box, lv_color_hex(0x00FFFF), 0); // Cyan
    }
}

static void move_box_timer(lv_timer_t *timer)
{
    x = x + (speed * direction);
    y = y + y_speed;

    if (x + box_width >= border_x + border_width)
    {
        direction = -1;
        change_box_color(timer->user_data);
    }

    if (x <= border_x)
    {
        direction = 1;
        change_box_color(timer->user_data);
    }

    if (y + box_height >= border_y + border_height)
    {
        y_speed = -10;
        change_box_color(timer->user_data);
    }

    if (y <= border_y)
    {
        y_speed = 10;
        change_box_color(timer->user_data);
    }

    lv_obj_set_pos(timer->user_data, x, y);
}

int main(void)
{
    /****************************************************************************
     * 1. Initialize clocks
     ****************************************************************************/

    /* Debug UART clock */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /*
     * I2C2 clock.
     *
     * Your LCD/touch project uses FLEXCOMM2 / LPI2C2.
     * We are not using touch yet, but keep the known-good clock setup.
     */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
    CLOCK_EnableClock(kCLOCK_LPFlexComm2);
    CLOCK_EnableClock(kCLOCK_LPI2c2);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);

    /****************************************************************************
     * 2. Initialize board
     ****************************************************************************/

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("\r\n");
    PRINTF("MCXN947 LVGL Level 1\r\n");

    /****************************************************************************
     * 3. Initialize LCD hardware
     ****************************************************************************/

    /*
     * Initialize FLEXIO 8080 interface.
     *
     * This is the low-level interface between the MCXN947
     * and the parallel LCD.
     */
    Demo_FLEXIO_8080_Init();

    /*
     * Initialize the ST7796S LCD controller.
     */
#ifdef LCD_ST7796S_IPS
    LCD_ST7796S_IPS_Init();
#endif

    /****************************************************************************
     * 4. Initialize LVGL
     ****************************************************************************/

    /*
     * Start LVGL.
     */
    lv_init();

    /*
     * Connect LVGL to our physical LCD.
     *
     * This initializes the LVGL display driver.
     */
    lv_port_disp_init();

    /* Make the screen black */
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), 0);

    /****************************************************************************
     * 5. Create BOX
     ****************************************************************************/

    lv_obj_t *border = lv_obj_create(lv_scr_act());

    lv_obj_set_size(border, border_width, border_height);
    lv_obj_set_pos(border, border_x, border_y);

    lv_obj_set_style_border_color(
        border,
        lv_color_black(),
        0
    );

    lv_obj_set_style_bg_opa(border, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(border, 3, 0);

    lv_obj_t *box = lv_obj_create(lv_scr_act());

    lv_obj_set_size(box, box_width, box_height);

    PRINTF("Box created\r\n");

    lv_obj_set_pos(box, x, y);

    /* Remove border from the moving DVD box */
    lv_obj_set_style_border_width(box, 0, 0);


    lv_timer_create(move_box_timer, 100, box);

    /****************************************************************************
     * 6. Start LVGL timing
     ****************************************************************************/

    DEMO_SetupTick();

    /****************************************************************************
     * 7. Main loop
     ****************************************************************************/

    while (1)
    {
        /*
         * Wait until our 5 ms LVGL period has elapsed.
         */
        while (!s_lvglTaskPending)
        {
        }

        s_lvglTaskPending = false;

        /*
         * Let LVGL process drawing, timers, animations, etc.
         */
        lv_task_handler();
    }
}

/****************************************************************************
 * SysTick setup
 ****************************************************************************/

static void DEMO_SetupTick(void)
{
    /*
     * Configure the Cortex-M33 SysTick to generate an interrupt
     * every 1 ms.
     */
    if (0 != SysTick_Config(SystemCoreClock / (LVGL_TICK_MS * 1000U)))
    {
        PRINTF("Tick initialization failed\r\n");

        while (1)
        {
        }
    }
}

/****************************************************************************
 * SysTick interrupt
 ****************************************************************************/

void SysTick_Handler(void)
{
    /*
     * Count milliseconds.
     */
    s_tick++;

    /*
     * Tell LVGL that 1 ms has passed.
     */
    lv_tick_inc(LVGL_TICK_MS);

    /*
     * Every 5 ms, tell main() to run lv_task_handler().
     */
    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }
}
