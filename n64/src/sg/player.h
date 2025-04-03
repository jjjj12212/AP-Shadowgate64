#ifndef SG_EVENTS
#define SG_EVENTS

#define sg_player_event (*(u16*)0x800E7A22) //last u8 also possibly contains hex to obtain item 

enum {
    EVENT_NORMAL = 0x0,
    EVENT_INTRO = 0x1300,
    EVENT_CELL = 0x1301,
    EVENT_DROWN = 0x0296,
    EVENT_FALL = 0x297,
    EVENT_SHRINK = 0x134C,
    EVENT_GROW = 0x134B,
    EVENT_BELZAR = 0x1313,
    EVENT_GUARD_CAUGHT = 0x1323,
    EVENT_SLICED = 0x506
};

#define sg_player_zpos (*(float*)0x800EA734)
#define sg_player_zpos_hex (*(u32*)0x800EA734)
#define sg_player_xpos (*(float*)0x800EA72C)
#define sg_player_xpos_hex (*(u32*)0x800EA72C)
#define sg_player_ypos (*(float*)0x800EA730)

#define sg_player_button (*(u16*)0x800B0C00)
enum {
    BTN_A = 0x8000,
    BTN_B = 0x4000,
    BTN_Z = 0x2000,
    BTN_L = 0x0020,
    BTN_R = 0x0010,
    BTN_CU = 0x0008,
    BTN_CR = 0x0001,
    BTN_CD = 0x0004,
    BTN_CL = 0x0002,
    BTN_DU = 0x0800,
    BTN_DR = 0x0100,
    BTN_DD = 0x0400,
    BTN_DL = 0x0200
};
#define sg_player_campos (*(float*)0x800EA73C)

#define sg_death (*(u8*)0x800EBB9C)

#define sg_player_locked (*(u8*)0x800E7B1D)

extern bool player_died;

#endif