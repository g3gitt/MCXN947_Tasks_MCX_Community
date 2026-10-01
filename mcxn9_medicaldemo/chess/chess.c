#include "chess.h"
#include "fsl_debug_console.h"
#include "c_board.h"

void Chess_Init(void)
{
    PRINTF("Chess initialized!\r\n");

    Board_Draw();
}
