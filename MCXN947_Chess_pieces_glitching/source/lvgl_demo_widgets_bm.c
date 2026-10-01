/*
 * MCXN947 + ST7796S LCD + LVGL
 *
 * Chess Board + Touch X/Y Test
 */

#include "pin_mux.h"
#include "lvgl_support.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_debug_console.h"
#include <stdlib.h>
#include "mcu-max.h"
#include "flexio_8080_drv.h"
#include "lcd_drv.h"
#include "lvgl.h"

/* Chess files */
#include "chess.h"
#include "c_board.h"
#include "chess_pieces.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LVGL_TICK_MS             1U
#define LVGL_TASK_PERIOD_TICK    5U


/*******************************************************************************
 * Variables
 ******************************************************************************/

static volatile uint32_t s_tick = 0U;
static volatile bool s_lvglTaskPending = false;


/*******************************************************************************
 * Function Prototypes
 ******************************************************************************/

static void DEMO_SetupTick(void);
static void Touch_Callback(lv_event_t *e);


/*******************************************************************************
 * Touch Callback
 ******************************************************************************/
static void Touch_Callback(lv_event_t *e)
{
    lv_indev_t *indev = lv_event_get_indev(e);
    lv_point_t point;

    lv_indev_get_point(indev, &point);

    uint8_t col = point.x / SQUARE_WIDTH;
    uint8_t row = point.y / SQUARE_HEIGHT;

    uint8_t square = (row << 4) | col;

    uint8_t piece = mcumax_get_piece(square);

    PRINTF("Chess square = 0x%02X\r\n", square);
    PRINTF("Piece = 0x%02X\r\n", piece);

    PRINTF("Touch X = %d, Y = %d\r\n",
           point.x,
           point.y);

    PRINTF("Chess square = 0x%02X\r\n",
           square);
}


/*******************************************************************************
 * Main
 ******************************************************************************/

int main(void)
{
    /***************************************************************************
     * 1. Initialize clocks
     **************************************************************************/

    /* Debug UART clock */
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom4Clk, 1u);
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    /*
     * I2C2 clock for GT911 touch controller
     */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM2);
    CLOCK_EnableClock(kCLOCK_LPFlexComm2);
    CLOCK_EnableClock(kCLOCK_LPI2c2);
    CLOCK_SetClkDiv(kCLOCK_DivFlexcom2Clk, 1u);


    /***************************************************************************
     * 2. Initialize board
     **************************************************************************/

    BOARD_InitPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    PRINTF("\r\n");
    PRINTF("MCXN947 CHESS + TOUCH\r\n");


    /***************************************************************************
     * 3. Initialize LCD
     **************************************************************************/

    Demo_FLEXIO_8080_Init();

#ifdef LCD_ST7796S_IPS
    LCD_ST7796S_IPS_Init();
#endif


    /***************************************************************************
     * 4. Initialize LVGL
     **************************************************************************/

    lv_init();

    /* Initialize LCD display driver */
    lv_port_disp_init();

    /* Initialize touch input driver */
    lv_port_indev_init();


    /***************************************************************************
     * 5. Draw chess board directly to LCD
     **************************************************************************/



    Chess_Init();
    mcumax_init();
    Board_Draw();
    Chess_Pieces_Draw();
    /***************************************************************************
     * 6. Create transparent LVGL touch area
     **************************************************************************/

    lv_obj_t *touch_area = lv_obj_create(lv_scr_act());

    lv_obj_set_size(touch_area,
                    LCD_WIDTH,
                    LCD_HEIGHT);

    lv_obj_set_pos(touch_area,
                   0,
                   0);

    /*
     * Make the touch object completely transparent.
     */
    lv_obj_set_style_bg_opa(touch_area,
                            LV_OPA_TRANSP,
                            0);

    lv_obj_set_style_border_width(touch_area,
                                  0,
                                  0);

    /*
     * Make the LVGL screen background transparent too.
     */
    lv_obj_set_style_bg_opa(lv_scr_act(),
                            LV_OPA_TRANSP,
                            0);

    /*
     * Receive touch events.
     */
    lv_obj_add_event_cb(touch_area,
                        Touch_Callback,
                        LV_EVENT_PRESSED,
                        NULL);


    /***************************************************************************
     * 7. Start LVGL timing
     **************************************************************************/

    DEMO_SetupTick();


    /***************************************************************************
     * 8. Main loop
     **************************************************************************/

    while (1)
    {
        while (!s_lvglTaskPending)
        {
        }

        s_lvglTaskPending = false;
        lv_task_handler();
        Board_Draw();
        Chess_Pieces_Draw();
    }
}


/*******************************************************************************
 * SysTick setup
 ******************************************************************************/

static void DEMO_SetupTick(void)
{
    if (0 != SysTick_Config(SystemCoreClock /
                            (LVGL_TICK_MS * 1000U)))
    {
        PRINTF("Tick initialization failed\r\n");

        while (1)
        {
        }
    }
}


/*******************************************************************************
 * SysTick interrupt
 ******************************************************************************/

void SysTick_Handler(void)
{
    s_tick++;

    /* Tell LVGL 1 ms has passed */
    lv_tick_inc(LVGL_TICK_MS);

    /* Run LVGL every 5 ms */
    if ((s_tick % LVGL_TASK_PERIOD_TICK) == 0U)
    {
        s_lvglTaskPending = true;
    }
}
