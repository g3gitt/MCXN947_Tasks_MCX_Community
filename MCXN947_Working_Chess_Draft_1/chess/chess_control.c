#include "chess_control.h"
#include "mcu-max.h"
#include "fsl_debug_console.h"
#include "chess_pieces.h"
#include "c_board.h"

#define CHESS_MAX_VALID_MOVES    64U

static uint8_t selected_square = 0xFFU;

static mcumax_move valid_moves[CHESS_MAX_VALID_MOVES];
static uint32_t valid_move_count = 0U;

//static const char *Chess_PieceName(uint8_t piece)
//{
//    bool black = (piece & MCUMAX_BLACK) != 0U;
//    uint8_t type = piece & 0x07U;
//
//    if (black)
//    {
//        switch (type)
//        {
//            case MCUMAX_PAWN_UPSTREAM:
//            case MCUMAX_PAWN_DOWNSTREAM:
//                return "Black Pawn";
//
//            case MCUMAX_KNIGHT:
//                return "Black Knight";
//
//            case MCUMAX_BISHOP:
//                return "Black Bishop";
//
//            case MCUMAX_ROOK:
//                return "Black Rook";
//
//            case MCUMAX_QUEEN:
//                return "Black Queen";
//
//            case MCUMAX_KING:
//                return "Black King";
//
//            default:
//                return "Unknown Black";
//        }
//    }
//
//    switch (type)
//    {
//        case MCUMAX_PAWN_UPSTREAM:
//        case MCUMAX_PAWN_DOWNSTREAM:
//            return "White Pawn";
//
//        case MCUMAX_KNIGHT:
//            return "White Knight";
//
//        case MCUMAX_BISHOP:
//            return "White Bishop";
//
//        case MCUMAX_ROOK:
//            return "White Rook";
//
//        case MCUMAX_QUEEN:
//            return "White Queen";
//
//        case MCUMAX_KING:
//            return "White King";
//
//        default:
//            return "Unknown White";
//    }
//}

void Chess_Control_Init(void)
{
    selected_square = 0xFFU;
    valid_move_count = 0U;
}

void Chess_Control_Touch(uint8_t square)
{
    uint8_t piece = mcumax_get_piece(square);

    /*
     * --------------------------------------------------
     * CASE 1: No piece is currently selected
     * --------------------------------------------------
     */
    if (selected_square == 0xFFU)
    {
        if (piece == MCUMAX_EMPTY)
        {
            PRINTF("Empty square: 0x%02X\r\n", square);
            return;
        }

        selected_square = square;

        valid_move_count =
            mcumax_search_valid_moves(valid_moves,
                                      CHESS_MAX_VALID_MOVES);

        PRINTF("\r\nSelected: 0x%02X\r\n", selected_square);
        PRINTF("Piece: 0x%02X\r\n", piece);

        for (uint32_t i = 0U; i < valid_move_count; i++)
        {
            if (valid_moves[i].from == selected_square)
            {
                PRINTF("  %02X -> %02X\r\n",
                       valid_moves[i].from,
                       valid_moves[i].to);

                Chess_HighlightSquare(valid_moves[i].to);
            }
        }

        return;
    }

    /*
     * --------------------------------------------------
     * CASE 2: A piece is already selected
     * --------------------------------------------------
     */

    /*
     * Check whether the tapped square is one of the
     * legal destinations of the selected piece.
     */
    for (uint32_t i = 0U; i < valid_move_count; i++)
    {
        if ((valid_moves[i].from == selected_square) &&
            (valid_moves[i].to == square))
        {
            PRINTF("\r\nPlaying move: %02X -> %02X\r\n",
                   selected_square,
                   square);

            /*
             * Let the chess engine execute the move.
             */
            if (mcumax_play_move(valid_moves[i]))
            {
                PRINTF("Move successful!\r\n");

                /*
                 * Redraw the complete chess board.
                 */
                Board_Draw();
                Chess_Pieces_Draw();

                /*
                 * Clear selection.
                 */
                selected_square = 0xFFU;
                valid_move_count = 0U;

                return;
            }
            else
            {
                PRINTF("Move failed!\r\n");
            }

            return;
        }
    }

    /*
     * --------------------------------------------------
     * CASE 3: Tapped something that isn't a legal move
     * --------------------------------------------------
     */

    PRINTF("Not a legal move: %02X -> %02X\r\n",
           selected_square,
           square);
}
