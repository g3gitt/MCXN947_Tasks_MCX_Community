#include "c_board.h"
#include "lcd_drv.h"

void Board_Draw(void)
{
    AreaPoints_t area;

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            area.x1 = col * SQUARE_WIDTH;
            area.y1 = row * SQUARE_HEIGHT;

            area.x2 = area.x1 + SQUARE_WIDTH - 1;
            area.y2 = area.y1 + SQUARE_HEIGHT - 1;

            if ((row + col) % 2 == 0)
            {
                LCD_FillColorPolling(&area, White);
            }
            else
            {
                LCD_FillColorPolling(&area, Black);
            }
        }
    }
}
