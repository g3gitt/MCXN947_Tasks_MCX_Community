#include "chess_pieces.h"

#include <stdint.h>
#include <stdbool.h>

#include "mcu-max.h"
#include "c_board.h"
#include "lcd_drv.h"
#include "chess_piece_images.h"


/* One complete LCD square: 60 x 40 pixels */
static uint16_t square_buffer[BOARD_SIZE * 0 + SQUARE_WIDTH * SQUARE_HEIGHT];


/*
 * Select the image corresponding to an engine piece.
 */
static const uint16_t *Chess_GetPieceImage(uint8_t piece)
{
    bool black = (piece & MCUMAX_BLACK) != 0U;
    uint8_t type = piece & 0x07U;

    if (black)
    {
        switch (type)
        {
            case MCUMAX_PAWN_UPSTREAM:
            case MCUMAX_PAWN_DOWNSTREAM:
                return chess_bP_rgb565;

            case MCUMAX_KNIGHT:
                return chess_bN_rgb565;

            case MCUMAX_KING:
                return chess_bK_rgb565;

            case MCUMAX_BISHOP:
                return chess_bB_rgb565;

            case MCUMAX_ROOK:
                return chess_bR_rgb565;

            case MCUMAX_QUEEN:
                return chess_bQ_rgb565;

            default:
                return NULL;
        }
    }
    else
    {
        switch (type)
        {
            case MCUMAX_PAWN_UPSTREAM:
            case MCUMAX_PAWN_DOWNSTREAM:
                return chess_wP_rgb565;

            case MCUMAX_KNIGHT:
                return chess_wN_rgb565;

            case MCUMAX_KING:
                return chess_wK_rgb565;

            case MCUMAX_BISHOP:
                return chess_wB_rgb565;

            case MCUMAX_ROOK:
                return chess_wR_rgb565;

            case MCUMAX_QUEEN:
                return chess_wQ_rgb565;

            default:
                return NULL;
        }
    }
}


/*
 * Get the transparency mask corresponding to the piece.
 */
static const uint8_t *Chess_GetPieceMask(uint8_t piece)
{
    bool black = (piece & MCUMAX_BLACK) != 0U;
    uint8_t type = piece & 0x07U;

    if (black)
    {
        switch (type)
        {
            case MCUMAX_PAWN_UPSTREAM:
            case MCUMAX_PAWN_DOWNSTREAM:
                return chess_bP_mask;

            case MCUMAX_KNIGHT:
                return chess_bN_mask;

            case MCUMAX_KING:
                return chess_bK_mask;

            case MCUMAX_BISHOP:
                return chess_bB_mask;

            case MCUMAX_ROOK:
                return chess_bR_mask;

            case MCUMAX_QUEEN:
                return chess_bQ_mask;

            default:
                return NULL;
        }
    }
    else
    {
        switch (type)
        {
            case MCUMAX_PAWN_UPSTREAM:
            case MCUMAX_PAWN_DOWNSTREAM:
                return chess_wP_mask;

            case MCUMAX_KNIGHT:
                return chess_wN_mask;

            case MCUMAX_KING:
                return chess_wK_mask;

            case MCUMAX_BISHOP:
                return chess_wB_mask;

            case MCUMAX_ROOK:
                return chess_wR_mask;

            case MCUMAX_QUEEN:
                return chess_wQ_mask;

            default:
                return NULL;
        }
    }
}


/*
 * Draw one chess piece on one square.
 *
 * The piece image is 48 x 40.
 * The chess square is 60 x 40.
 *
 * We create a 60 x 40 temporary image containing:
 *     checkerboard background
 *     + transparent piece image
 *
 * Then send the complete square to the LCD.
 */
static void Chess_DrawPiece(uint8_t row, uint8_t col, uint8_t piece)
{
    const uint16_t *image;
    const uint8_t *mask;

    image = Chess_GetPieceImage(piece);
    mask = Chess_GetPieceMask(piece);

    if ((image == NULL) || (mask == NULL))
    {
        return;
    }

    /*
     * Determine checkerboard background.
     */
    uint16_t background;

    if (((row + col) % 2U) == 0U)
    {
        background = White;
    }
    else
    {
        background = Black;
    }

    /*
     * Start with the checkerboard square.
     */
    for (uint32_t i = 0U;
         i < (SQUARE_WIDTH * SQUARE_HEIGHT);
         i++)
    {
        square_buffer[i] = background;
    }

    /*
     * Center the 48-pixel-wide piece inside
     * the 60-pixel-wide chess square.
     *
     * 60 - 48 = 12
     * 12 / 2 = 6 pixels on each side.
     */
    const uint32_t x_offset = 6U;

    for (uint32_t y = 0U; y < CHESS_PIECE_H; y++)
    {
        for (uint32_t x = 0U; x < CHESS_PIECE_W; x++)
        {
            uint32_t piece_index =
                (y * CHESS_PIECE_W) + x;

            uint32_t mask_byte =
                piece_index >> 3;

            uint8_t mask_bit =
                (uint8_t)(1U << (piece_index & 7U));

            if ((mask[mask_byte] & mask_bit) != 0U)
            {
                uint32_t lcd_index =
                    (y * SQUARE_WIDTH) + x + x_offset;

                square_buffer[lcd_index] =
                    image[piece_index];
            }
        }
    }

    /*
     * LCD coordinates for this chess square.
     */
    AreaPoints_t area;

    area.x1 = col * SQUARE_WIDTH;
    area.y1 = row * SQUARE_HEIGHT;

    area.x2 = area.x1 + SQUARE_WIDTH - 1U;
    area.y2 = area.y1 + SQUARE_HEIGHT - 1U;

    LCD_FillPicPolling(&area, square_buffer);
}


/*
 * Draw every piece currently stored in mcu-max.
 */
void Chess_Pieces_Draw(void)
{
    for (uint8_t row = 0U; row < BOARD_SIZE; row++)
    {
        for (uint8_t col = 0U; col < BOARD_SIZE; col++)
        {
            uint8_t square =
                (uint8_t)((row << 4) | col);

            uint8_t piece =
                mcumax_get_piece(square);

            if (piece != MCUMAX_EMPTY)
            {
                Chess_DrawPiece(row, col, piece);
            }
        }
    }
}
void Chess_HighlightSquare(uint8_t square)
{
    uint8_t row = (square >> 4) & 0x0FU;
    uint8_t col = square & 0x0FU;

    if ((row >= BOARD_SIZE) || (col >= BOARD_SIZE))
    {
        return;
    }

    AreaPoints_t area;

    uint16_t x = col * SQUARE_WIDTH;
    uint16_t y = row * SQUARE_HEIGHT;

    /*
     * Red border thickness = 2 pixels
     */
    const uint16_t border = 2U;
    const uint16_t red = 0xF800U;   // RGB565 red

    /*
     * Top border
     */
    area.x1 = x;
    area.y1 = y;
    area.x2 = x + SQUARE_WIDTH - 1U;
    area.y2 = y + border - 1U;

    LCD_FillColorPolling(&area, red);

    /*
     * Bottom border
     */
    area.x1 = x;
    area.y1 = y + SQUARE_HEIGHT - border;
    area.x2 = x + SQUARE_WIDTH - 1U;
    area.y2 = y + SQUARE_HEIGHT - 1U;

    LCD_FillColorPolling(&area, red);

    /*
     * Left border
     */
    area.x1 = x;
    area.y1 = y + border;
    area.x2 = x + border - 1U;
    area.y2 = y + SQUARE_HEIGHT - border - 1U;

    LCD_FillColorPolling(&area, red);

    /*
     * Right border
     */
    area.x1 = x + SQUARE_WIDTH - border;
    area.y1 = y + border;
    area.x2 = x + SQUARE_WIDTH - 1U;
    area.y2 = y + SQUARE_HEIGHT - border - 1U;

    LCD_FillColorPolling(&area, red);
}
