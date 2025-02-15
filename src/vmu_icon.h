// https://github.com/darcagn/vmuicontool

static const unsigned short vmu_icon_pal[16] = {
    0xFFFF, 0xF888, 0xF880, 0xFCCC, 0xF800, 0xF000, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};

static const unsigned char vmu_icon_data[512] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x00, 0x00,
    0x00, 0x00, 0x33, 0x11, 0x11, 0x11, 0x33, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x44, 0x44, 0x22, 0x00,
    0x00, 0x00, 0x33, 0x11, 0x11, 0x11, 0x33, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x44, 0x44, 0x22, 0x00,
    0x00, 0x00, 0x11, 0x33, 0x33, 0x33, 0x11, 0x22,
    0x22, 0x22, 0x44, 0x44, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x11, 0x33, 0x33, 0x33, 0x11, 0x22,
    0x22, 0x22, 0x44, 0x44, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x11, 0x11, 0x33, 0x55, 0x33, 0x11, 0x11,
    0x22, 0x44, 0x33, 0x33, 0x33, 0x55, 0x00, 0x00,
    0x00, 0x11, 0x11, 0x33, 0x55, 0x33, 0x11, 0x11,
    0x22, 0x44, 0x33, 0x33, 0x33, 0x55, 0x00, 0x00,
    0x00, 0x00, 0x11, 0x33, 0x33, 0x33, 0x11, 0x22,
    0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x00,
    0x00, 0x00, 0x11, 0x33, 0x33, 0x33, 0x11, 0x22,
    0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x00,
    0x00, 0x00, 0x33, 0x11, 0x11, 0x11, 0x33, 0x22,
    0x44, 0x11, 0x11, 0x33, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x33, 0x11, 0x11, 0x11, 0x33, 0x22,
    0x44, 0x11, 0x11, 0x33, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x33, 0x33, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11,
    0x11, 0x11, 0x33, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11,
    0x11, 0x11, 0x33, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x11, 0x33, 0x55,
    0x55, 0x33, 0x11, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x11, 0x33, 0x55,
    0x55, 0x33, 0x11, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x11, 0x33, 0x55,
    0x55, 0x33, 0x11, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x33, 0x11, 0x33, 0x55,
    0x55, 0x33, 0x11, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x33,
    0x33, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11,
    0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11,
    0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x33,
    0x33, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x33,
    0x33, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};