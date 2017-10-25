#include "utils.h"
#include "term.h"

/* 4bpp 3x5 pixel font (texture size: 192 x 10, 480 16bit words) */
const uint16_t font[(192 * 10) / 4] = {
    0x0001, 0x0101, 0x1011, 0x1110, 0x1010, 0x0100, 0x1100, 0x0000,
    0x0000, 0x0000, 0x0000, 0x1000, 0x0111, 0x1101, 0x0110, 0x1101,
    0x1111, 0x1111, 0x1010, 0x0011, 0x0000, 0x0000, 0x0000, 0x1110,
    0x0111, 0x1101, 0x1100, 0x1110, 0x1111, 0x1101, 0x1101, 0x0011,
    0x1011, 0x1001, 0x1110, 0x0100, 0x1111, 0x1111, 0x1111, 0x1111,
    0x0110, 0x1011, 0x1101, 0x1110, 0x0111, 0x0001, 0x1011, 0x0000,
    0x0100, 0x0101, 0x1111, 0x0011, 0x0110, 0x0101, 0x0010, 0x0101,
    0x0101, 0x0000, 0x0000, 0x1000, 0x1101, 0x0001, 0x1001, 0x1101,
    0x0100, 0x1000, 0x1101, 0x1010, 0x0100, 0x1010, 0x1011, 0x1000,
    0x1101, 0x0110, 0x0011, 0x1101, 0x0100, 0x0010, 0x0101, 0x0001,
    0x1011, 0x1001, 0x0111, 0x1011, 0x1101, 0x0110, 0x0011, 0x1010,
    0x0110, 0x1011, 0x1101, 0x0010, 0x0011, 0x0001, 0x0110, 0x0001,
    0x0000, 0x0001, 0x1010, 0x0010, 0x1001, 0x0001, 0x0011, 0x1011,
    0x1110, 0x1000, 0x0011, 0x0100, 0x0101, 0x1001, 0x0110, 0x1111,
    0x1111, 0x0101, 0x1010, 0x0011, 0x0000, 0x0001, 0x0000, 0x1101,
    0x1100, 0x1111, 0x0010, 0x1101, 0x1101, 0x1010, 0x0111, 0x0001,
    0x0111, 0x1001, 0x0110, 0x1011, 0x1111, 0x1110, 0x1111, 0x1010,
    0x0110, 0x1011, 0x0010, 0x1001, 0x0010, 0x0010, 0x0010, 0x0000,
    0x0000, 0x0000, 0x1110, 0x1110, 0x1100, 0x0000, 0x0010, 0x0101,
    0x0101, 0x0010, 0x0000, 0x0010, 0x0101, 0x0101, 0x1000, 0x0100,
    0x0110, 0x0011, 0x0101, 0x1010, 0x0100, 0x1010, 0x1011, 0x0000,
    0x1111, 0x0110, 0x0011, 0x1101, 0x0100, 0x1010, 0x0101, 0x0101,
    0x1011, 0x1001, 0x0110, 0x1011, 0x1001, 0x1111, 0x1000, 0x1010,
    0x0110, 0x1111, 0x0101, 0x0101, 0x0010, 0x0100, 0x0010, 0x0000,
    0x0010, 0x0001, 0x1010, 0x1011, 0x1010, 0x0001, 0x1100, 0x0000,
    0x0000, 0x0001, 0x1000, 0x0010, 0x1111, 0x1111, 0x0111, 0x1100,
    0x1111, 0x0011, 0x1010, 0x0011, 0x0010, 0x0000, 0x0000, 0x0100,
    0x1111, 0x1010, 0x1101, 0x1011, 0x0111, 0x0100, 0x1101, 0x1111,
    0x1011, 0x1111, 0x0110, 0x0101, 0x0001, 0x0110, 0x1111, 0x1010,
    0x1011, 0x1010, 0x0101, 0x1101, 0x0111, 0x0100, 0x0011, 0x1110,
    0x0001, 0x0100, 0x0000, 0x0100, 0x1000, 0x0001, 0x0001, 0x0000,
    0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x1100, 0x1010, 0x0001, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0010, 0x0101, 0x1100, 0x0100, 0x1001, 0x0100, 0x0001, 0x0001,
    0x0010, 0x1010, 0x1111, 0x0100, 0x0011, 0x0111, 0x0100, 0x1010,
    0x0110, 0x1011, 0x1101, 0x1110, 0x0101, 0x0010, 0x0001, 0x0001,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x1000, 0x1110, 0x0010, 0x1110, 0x1110, 0x1011, 0x0011, 0x0000,
    0x1011, 0x1010, 0x0111, 0x1011, 0x1101, 0x1110, 0x0010, 0x1111,
    0x0110, 0x1011, 0x1010, 0x1010, 0x0111, 0x0010, 0x1111, 0x0001,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x1000, 0x0110, 0x0011, 0x1101, 0x1001, 0x1100, 0x0101, 0x0001,
    0x0111, 0x1010, 0x0110, 0x1011, 0x0011, 0x0111, 0x0100, 0x1010,
    0x0110, 0x1111, 0x0010, 0x1101, 0x0100, 0x0010, 0x0101, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x1111, 0x1100, 0x0110, 0x1011, 0x0010, 0x0101, 0x1001,
    0x1010, 0x1110, 0x0110, 0x0101, 0x0001, 0x0110, 0x0010, 0x1110,
    0x1011, 0x1110, 0x1101, 0x1101, 0x1101, 0x1010, 0x0001, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

/* Macro to convert 888 RGB into 555 BGR */
#define RGB(_r, _g, _b) ((_r >> 3) |         \
                         ((_g >> 3) << 5) |  \
                         ((_b >> 3) << 10))

/* 2 x 16 texture containing 2bit CLUTs for each of the 16 ANSI
   colors. The first entry (background color) is always fully
   transparent. */
const uint16_t clut[] = {
    /* 0x8000, 0xffff, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, */
    /* 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, */

    /* Black */
    0x0000, RGB(0, 0, 0),
    /* Red */
    0x0000, RGB(170, 0, 0),
    /* Green */
    0x0000, RGB(0, 170, 0),
    /* Yellow */
    0x0000, RGB(170, 85, 0),
    /* Blue */
    0x0000, RGB(0, 0, 170),
    /* Magenta */
    0x0000, RGB(170, 0, 170),
    /* Cyan */
    0x0000, RGB(0, 170, 170),
    /* White */
    0x0000, RGB(170, 170, 170),

    /* Bright black */
    0x0000, RGB(85, 85, 85),
    /* Bright Red */
    0x0000, RGB(255, 85, 85),
    /* Bright Green */
    0x0000, RGB(85, 255, 85),
    /* Bright Yellow */
    0x0000, RGB(255, 255, 85),
    /* Bright Blue */
    0x0000, RGB(85, 85, 255),
    /* Bright Magenta */
    0x0000, RGB(255, 85, 255),
    /* Bright Cyan */
    0x0000, RGB(85, 255, 255),
    /* Bright White */
    0x0000, RGB(255, 255, 255),
};

void term_init(unsigned long backbuffer_lines, enum gpu_vmode vmode) {
    gpu_reset();

    gpu_set_video_mode(vmode, GPU_XRES_256, GPU_INTERLACING_DISABLED);
    gpu_display_enable(true);

    /* Texpage = f */
    gpu_upload_texture(960, 0,
                       48, 10,
                       font);

    gpu_upload_texture(960, 0x20,
                       2, 16,
                       clut);
}
