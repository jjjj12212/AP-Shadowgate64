#include <archipelago.h>
#ifndef SG_ITEM_FLAGS
#define SG_ITEM_FLAGS

typedef struct {
    u8 crest_key;
    u8 bottle_of_oil;
    u8 fragments_of_crest;
    u8 dragon_tears;
    u8 pixie_flute;
    u8 treasure;
    u8 rusty_key;
    u8 ornate_Key;
    u8 ring_of_the_kingdom;
    u8 orb;
    u8 golden_key;
    u8 liquid_sunset;
    u8 night_elixir;
    u8 forest_nectar;
    u8 primitive_man_statue;
    u8 apeman_sculpture;
    u8 fairy_sculpture;
    u8 elf_statue;
    u8 ancient_coin;
    u8 pick_axe;
    u8 ring_of_the_dead;
    u8 blue_ring;
    u8 green_ring;
    u8 lever;
    u8 slipper;
    u8 dirty_slipper;
    u8 pair_of_slippers;
    u8 jezibel_pendant;
    u8 staff_of_ages;
    u8 rope;
    u8 cemetery_key;
    u8 flower;
    u8 flint;
    u8 fang;
    u8 dragon_eye;
    u8 dragon_flute;
    u8 burning_candle;
    u8 chipped_violin;
    u8 stringless_violin;
    u8 broken_violin;
    u8 dungeon_key;
    u8 map;
    u8 bone;
    u8 starcrest;
    u8 iron_bar;
    u8 crowbar;
    u8 hair_of_giant;
    u8 mug;
    u8 water;
    u8 water_dragon_tears;
    u8 stone_of_thirst;
    u8 coin1;
    u8 coin2;
    u8 coin3;
    u8 coin4;
    u8 coin5;
    u8 nail;
    u8 brooch;
    u8 jewelry_box;
    u8 fruit;
    u8 gauntlet;
    u8 cup;
    u8 artwork;
    u8 poisonous_herb;
    u8 bracelet;
    u8 precious_stone;
    u8 broken_sword;
    u8 quill;
    u8 plate;
    u8 broken_lance;
    u8 unkown_item1; //71
    u8 unkown_item2;
    u8 unkown_item3;
    u8 unkown_item4; //74
    u8 dnarth_chronicles;
    u8 final_battle;
    u8 speeches_jair;
    u8 blank_book1;
    u8 blank_book2;
    u8 blank_book3;
    u8 student_diary;
    u8 acolyte_diary;
    u8 personal_journal;
    u8 memoirs;
    u8 novice_journal;
    u8 trials_kingdom;
    u8 brotherhood_report;
    u8 writings_konnor;
    u8 house_dreslin;
    u8 memorandum;
    u8 last_dragon;
    u8 riding_dragons;
    u8 research_log;
    u8 musings_lunatic;
    u8 orders;
    u8 laws_magic;
    u8 family_diary;
    u8 words_dnarth;
    u8 artifacts_power;
    u8 magical_elixirs;
    u8 unkown_book1; //101
    u8 unkown_book2;
    u8 unkown_book3; //103
    u8 journal;
    u8 watchman_memo;
    u8 report;
    u8 official_article;
    u8 lecture_notes;
    u8 personal_letter;
    u8 inner_chamber;
    u8 travelogue;
    u8 travel_guide;
    u8 petition;
    u8 receipt;
    u8 personal_note;
    u8 unkown_note1; //116
    u8 unkown_note2;
    u8 unkown_note3; //118
} sg_item_flags_t;

#define sg_item_flags (*(sg_item_flags_t*)0x800EC3D1)

#endif