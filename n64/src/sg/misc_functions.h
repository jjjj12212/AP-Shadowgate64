#ifndef SG_FN_INJECTED_H
#define SG_FN_INJECTED_H

typedef void (*sg_fnt_main_init)(u32);
#define sg_fn_main_init ((sg_fnt_main_init)0x80098A10)

typedef u8 (*sg_fnt_main_loop)(u32*, u32*, u8);
#define sg_fn_main_loop ((sg_fnt_main_loop)0x800976E0)

typedef bool (*sg_fnt_unknown_start_loop)();
#define sg_fn_unknown_start_loop ((sg_fnt_unknown_start_loop)0x8009CC80)

typedef u16 (*sg_fnt_ap_ingame_item)(u8, u32*, u8);
#define sg_fn_obtain_ap_item ((sg_fnt_ap_ingame_item)0x800320EC)

// typedef void (*sg_fnt_ap_item_end)();
// #define sg_fn_ap_item_end ((sg_fnt_ap_item_end)0x80032140)

#define sg_scene_handler (*(u8*)0x800A1BCF)

enum {
    SH_NORMAL = 0x05,
    SH_CUTSCENE_TRANSITION = 0x11,
    SH_MAP_TRANSITION = 0x0B,
    SH_CUTSCENE = 0x0D
};

#define sg_game_state (*(u16*)0x800E7988)
#define sg_current_game_state (*(u16*)0x800E798A)

enum {
    GS_GAME_OVER = 0x000C,
    GS_NORMAL = 0x0003,
    GS_TRANSITION = 0x000A,
    GS_DIALOG = 0x0005
};

#define sg_moat_removed (*(u8*)0x800EC460)
#define sg_ghost_girl_completed (*(u8*)0x800EA760)
#define sg_candle_requirement (*(u8*)0x800EC47E)
#define sg_candle_timer (*(u8*)0x800EC457)
#define sg_starcrest_inplace (*(u8*)0x800EC45B)
#define sg_statues_solved (*(u8*)0x800EA786)
#define sg_used_sthurst (*(u8*)0x800EC461)
#define sg_lever (*(u8*)0x800EC086)
#define sg_flower (*(u8*)0x800EC478)
#define sg_fang1 (*(u8*)0x800EA7DA)
#define sg_fang2 (*(u8*)0x800EA7DC)
#define sg_hair (*(u8*)0x800EC472)
#define sg_ancient_coin (*(u8*)0x800EC499)
#define sg_chipped_violin (*(u8*)0x800EC492)
#define sg_crest_fragment (*(u8*)0x800EA7D4)
#define sg_candle (*(u8*)0x800EC452)
#define sg_eye (*(u8*)0x800E7A43)
#define sg_staff (*(u8*)0x800C45F4)



//Aangar fix
//#define aangar_sister (*(u8*)0x800EC452) //00 = still in Inn, 05 = gone
//#define aangar_barkeep (*(u8*)0x800EC493) //00 = clean table, 01 = bar
#define sg_agaar_door (*(u8*)0x800EC48C) //05 = open 00 = agaar sister at location
#define sg_dungeon_door (*(u8*)0x800EC495) //01 = opened, 02 = sister gone
#define sg_sister_accepted (*(u8*)0x800EC48D) //02 = accepted




#define sg_map_rope_element (*(u8*)0x800E9165)
// #define sg_endgame_big_doors (*(u8*)0x800EA762)
// #define sg_endgame_farm (*(u8*)0x800EA763)
// #define sg_endgame_barn (*(u8*)0x800EA764)
// #define sg_endgame_pit (*(u8*)0x800EA765)
#endif