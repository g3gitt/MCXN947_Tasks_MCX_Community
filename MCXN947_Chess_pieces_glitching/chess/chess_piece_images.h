#ifndef CHESS_PIECE_IMAGES_H
#define CHESS_PIECE_IMAGES_H

#include <stdint.h>

#define CHESS_PIECE_W 48
#define CHESS_PIECE_H 40
#define CHESS_PIECE_PIXELS (CHESS_PIECE_W * CHESS_PIECE_H)
#define CHESS_PIECE_MASK_BYTES ((CHESS_PIECE_PIXELS + 7) / 8)

extern const uint16_t chess_wK_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wK_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_wQ_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wQ_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_wR_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wR_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_wB_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wB_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_wN_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wN_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_wP_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_wP_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bK_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bK_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bQ_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bQ_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bR_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bR_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bB_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bB_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bN_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bN_mask[CHESS_PIECE_MASK_BYTES];
extern const uint16_t chess_bP_rgb565[CHESS_PIECE_PIXELS];
extern const uint8_t chess_bP_mask[CHESS_PIECE_MASK_BYTES];

#endif
