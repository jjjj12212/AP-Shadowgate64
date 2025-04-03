#include "inventory.h"

bool already_received(u8 item)
{
    //Iterates the sg_item_flag struct
    //finds the right item in memory and see if the value is 0 or not (item received already)
    //We don't want to overwite the data here has it will determine if the item is used already

    u8 *p = (u8*)&sg_item_flags;
    if(*(p+item-1) == 0x0) //-1 is important here 
    {
        return false;
    }
    else
    {
        return true;
    }
}

void update_inventory(u8 item)
{
    switch(item){
        case AP_ITEM_CREST_KEY:
            sg_item_flags.crest_key = 0x03;
            break;
        case AP_ITEM_BOTTLE_OF_OIL:
            sg_item_flags.bottle_of_oil = 0x03;
            break;
        case AP_ITEM_FRAGMENTS_OF_CREST:
            sg_item_flags.fragments_of_crest = 0x03;
            break;
        case AP_ITEM_DRAGON_TEARS:
            sg_item_flags.dragon_tears = 0x03;
            break;
        case AP_ITEM_PIXIE_FLUTE:
            sg_item_flags.pixie_flute = 0x03;
            break;
        case AP_ITEM_TREASURE:
            sg_item_flags.treasure = 0x03;
            break;
        case AP_ITEM_RUSTY_KEY:
            sg_item_flags.rusty_key = 0x03;
            break;
        case AP_ITEM_ORNATE_KEY:
            sg_item_flags.ornate_Key = 0x03;
            break;
        case AP_ITEM_RING_OF_THE_KINGDOM:
            sg_item_flags.ring_of_the_kingdom = 0x03;
            break;
        case AP_ITEM_ORB:
            sg_item_flags.orb = 0x03;
            break;
        case AP_ITEM_GOLDEN_KEY:
            sg_item_flags.golden_key = 0x03;
            break;
        case AP_ITEM_LIQUID_SUNSET:
            sg_item_flags.liquid_sunset = 0x03;
            break;
        case AP_ITEM_NIGHT_ELIXIR:
            sg_item_flags.night_elixir = 0x03;
            break;
        case AP_ITEM_FOREST_NECTAR:
            sg_item_flags.forest_nectar = 0x03;
            break;
        case AP_ITEM_PRIMITIVE_MAN_STATUE:
            sg_item_flags.primitive_man_statue = 0x03;
            break;
        case AP_ITEM_APEMAN_SCULPTURE:
            sg_item_flags.apeman_sculpture = 0x03;
            break;
        case AP_ITEM_FAIRY_SCULPTURE:
            sg_item_flags.fairy_sculpture = 0x03;
            break;
        case AP_ITEM_ELF_STATUE:
            sg_item_flags.elf_statue = 0x03;
            break;
        case AP_ITEM_ANCIENT_COIN:
            sg_item_flags.ancient_coin = 0x03;
            break;
        case AP_ITEM_PICK_AXE:
            sg_item_flags.pick_axe = 0x03;
            break;
        case AP_ITEM_RING_OF_THE_DEAD:
            sg_item_flags.ring_of_the_dead = 0x03;
            break;
        case AP_ITEM_BLUE_RING:
            sg_item_flags.blue_ring = 0x03;
            break;
        case AP_ITEM_GREEN_RING:
            sg_item_flags.green_ring = 0x03;
            break;
        case AP_ITEM_LEVER:
            sg_item_flags.lever = 0x03;
            break;
        case AP_ITEM_SLIPPER:
            sg_item_flags.slipper = 0x03;
            break;
        case AP_ITEM_DIRTY_SLIPPER:
            sg_item_flags.dirty_slipper = 0x03;
            break;
        case AP_ITEM_PAIR_OF_SLIPPERS:
            sg_item_flags.pair_of_slippers = 0x03;
            break;
        case AP_ITEM_JEZIBEL_PENDANT:
            sg_item_flags.jezibel_pendant = 0x03;
            break;
        case AP_ITEM_STAFF_OF_AGES:
            sg_item_flags.staff_of_ages = 0x03;
            break;
        case AP_ITEM_ROPE:
            sg_item_flags.rope = 0x03;
            break;
        case AP_ITEM_CEMETERY_KEY:
            sg_item_flags.cemetery_key = 0x03;
            break;
        case AP_ITEM_FLOWER:
            sg_item_flags.flower = 0x03;
            break;
        case AP_ITEM_FLINT:
            sg_item_flags.flint = 0x03;
            break;
        case AP_ITEM_FANG:
            sg_item_flags.fang = 0x03;
            break;
        case AP_ITEM_DRAGON_EYE:
            sg_item_flags.dragon_eye = 0x03;
            break;
        case AP_ITEM_DRAGON_FLUTE:
            sg_item_flags.dragon_flute = 0x03;
            break;
        case AP_ITEM_BURNING_CANDLE:
            sg_item_flags.burning_candle = 0x03;
            break;
        case AP_ITEM_CHIPPED_VIOLIN:
            sg_item_flags.chipped_violin = 0x03;
            break;
        case AP_ITEM_STRINGLESS_VIOLIN:
            sg_item_flags.stringless_violin = 0x03;
            break;
        case AP_ITEM_BROKEN_VIOLIN:
            sg_item_flags.broken_violin = 0x03;
            break;
        case AP_ITEM_DUNGEON_KEY:
            sg_item_flags.dungeon_key = 0x03;
            break;
        case AP_ITEM_MAP:
            sg_item_flags.map = 0x03;
            break;
        case AP_ITEM_BONE:
            sg_item_flags.bone = 0x03;
            break;
        case AP_ITEM_STARCREST:
            sg_item_flags.starcrest = 0x03;
            break;
        case AP_ITEM_IRON_BAR:
            sg_item_flags.iron_bar = 0x03;
            break;
        case AP_ITEM_CROWBAR:
            sg_item_flags.crowbar = 0x03;
            break;
        case AP_ITEM_HAIR_OF_GIANT:
            sg_item_flags.hair_of_giant = 0x03;
            break;
        case AP_ITEM_MUG:
            sg_item_flags.mug = 0x03;
            break;
        case AP_ITEM_WATER:
            sg_item_flags.water = 0x03;
            break;
        case AP_ITEM_WATER_DRAGON_TEARS:
            sg_item_flags.water_dragon_tears = 0x03;
            break;
        case AP_ITEM_STONE_OF_THIRST:
            sg_item_flags.stone_of_thirst = 0x03;
            break;
        case AP_ITEM_COIN1:
            sg_item_flags.coin1 = 0x03;
            break;
        case AP_ITEM_COIN2:
            sg_item_flags.coin2 = 0x03;
            break;
        case AP_ITEM_COIN3:
            sg_item_flags.coin3 = 0x03;
            break;
        case AP_ITEM_COIN4:
            sg_item_flags.coin4 = 0x03;
            break;
        case AP_ITEM_COIN5:
            sg_item_flags.coin5 = 0x03;
            break;
        case AP_ITEM_NAIL:
            sg_item_flags.nail = 0x03;
            break;
        case AP_ITEM_BROOCH:
            sg_item_flags.brooch = 0x03;
            break;
        case AP_ITEM_JEWELRY_BOX:
            sg_item_flags.jewelry_box = 0x03;
            break;
        case AP_ITEM_FRUIT:
            sg_item_flags.fruit = 0x03;
            break;
        case AP_ITEM_GAUNTLET:
            sg_item_flags.gauntlet = 0x03;
            break;
        case AP_ITEM_CUP:
            sg_item_flags.cup = 0x03;
            break;
        case AP_ITEM_ARTWORK:
            sg_item_flags.artwork = 0x03;
            break;
        case AP_ITEM_POISONOUS_HERB:
            sg_item_flags.poisonous_herb = 0x03;
            break;
        case AP_ITEM_BRACELET:
            sg_item_flags.bracelet = 0x03;
            break;
        case AP_ITEM_PRECIOUS_STONE:
            sg_item_flags.precious_stone = 0x03;
            break;
        case AP_ITEM_BROKEN_SWORD:
            sg_item_flags.broken_sword = 0x03;
            break;
        case AP_ITEM_QUILL:
            sg_item_flags.quill = 0x03;
            break;
        case AP_ITEM_PLATE:
            sg_item_flags.plate = 0x03;
            break;
        case AP_ITEM_BROKEN_LANCE:
            sg_item_flags.broken_lance = 0x03;
            break;
        
        case AP_DNARTH_CHRONICLES:
            sg_item_flags.dnarth_chronicles = 0x03;
            break;
        case AP_FINAL_BATTLE:
            sg_item_flags.final_battle = 0x03;
            break;
        case AP_SPEECHES_JAIR:
            sg_item_flags.speeches_jair = 0x03;
            break;
        case AP_BLANK_BOOK1:
            sg_item_flags.blank_book1 = 0x03;
            break;
        case AP_BLANK_BOOK2:
            sg_item_flags.blank_book2 = 0x03;
            break;
        case AP_BLANK_BOOK3:
            sg_item_flags.blank_book3 = 0x03;
            break;
        case AP_STUDENT_DIARY:
            sg_item_flags.student_diary = 0x03;
            break;
        case AP_ACOLYTE_DIARY:
            sg_item_flags.acolyte_diary = 0x03;
            break;
        case AP_PERSONAL_JOURNAL:
            sg_item_flags.personal_journal = 0x03;
            break;
        case AP_MEMOIRS:
            sg_item_flags.memoirs = 0x03;
            break;
        case AP_NOVICE_JOURNAL:
            sg_item_flags.novice_journal = 0x03;
            break;
        case AP_TRIALS_KINGDOM:
            sg_item_flags.trials_kingdom = 0x03;
            break;
        case AP_BROTHERHOOD_REPORT:
            sg_item_flags.brotherhood_report = 0x03;
            break;
        case AP_WRITINGS_KONNOR:
            sg_item_flags.writings_konnor = 0x03;
            break;
        case AP_HOUSE_DRESLIN:
            sg_item_flags.house_dreslin = 0x03;
            break;
        case AP_MEMORANDUM:
            sg_item_flags.memorandum = 0x03;
            break;
        case AP_LAST_DRAGON:
            sg_item_flags.last_dragon = 0x03;
            break;
        case AP_RIDING_DRAGONS:
            sg_item_flags.riding_dragons = 0x03;
            break;
        case AP_RESEARCH_LOG:
            sg_item_flags.research_log = 0x03;
            break;
        case AP_MUSINGS_LUNATIC:
            sg_item_flags.musings_lunatic = 0x03;
            break;
        case AP_ORDERS:
            sg_item_flags.orders = 0x03;
            break;
        case AP_LAWS_MAGIC:
            sg_item_flags.laws_magic = 0x03;
            break;
        case AP_FAMILY_DIARY:
            sg_item_flags.family_diary = 0x03;
            break;
        case AP_WORDS_DNARTH:
            sg_item_flags.words_dnarth = 0x03;
            break;
        case AP_ARTIFACTS_POWER:
            sg_item_flags.artifacts_power = 0x03;
            break;
        case AP_MAGICAL_ELIXIRS:
            sg_item_flags.magical_elixirs = 0x03;
            break;

        case AP_JOURNAL:
            sg_item_flags.journal = 0x03;
            break;
        case AP_WATCHMAN_MEMO:
            sg_item_flags.watchman_memo = 0x03;
            break;
        case AP_REPORT:
            sg_item_flags.report = 0x03;
            break;
        case AP_OFFICIAL_ARTICLE:
            sg_item_flags.official_article = 0x03;
            break;
        case AP_LECTURE_NOTES:
            sg_item_flags.lecture_notes = 0x03;
            break;
        case AP_PERSONAL_LETTER:
            sg_item_flags.personal_letter = 0x03;
            break;
        case AP_INNER_CHAMBER:
            sg_item_flags.inner_chamber = 0x03;
            break;
        case AP_TRAVELOGUE:
            sg_item_flags.travelogue = 0x03;
            break;
        case AP_TRAVEL_GUIDE:
            sg_item_flags.travel_guide = 0x03;
            break;
        case AP_PETITION:
            sg_item_flags.petition = 0x03;
            break;
        case AP_RECEIPT:
            sg_item_flags.receipt = 0x03;
            break;
        case AP_PERSONAL_NOTE:
            sg_item_flags.personal_note = 0x03;
            break;
        
    }
}

bool have_item(u8 item)
{
    u16 inventory_items = sg_items_collected;
    for(u16 inventory = 0; inventory <= inventory_items; inventory++)
    { 
        u32 address = 0x800EC350;
        address += inventory;
        u8 found_item = (*(u8*)address);
        if(found_item == 0x0) // No more items
        {
            break;
        }
        if(found_item == item)
        {
            u32 check_inv_flag = 0x800EC3D0 + item;
            if((*(u8*)check_inv_flag) == 0x03 || (*(u8*)check_inv_flag) == 0x23)
            {
                return true;
            }
        }
    }
    return false;
}

bool item_equipped(u8 item)
{
    u32 check_inv_flag = 0x800EC3D0 + item;
    if((*(u8*)check_inv_flag) == 0x23)
    {
        return true;
    }
    return false;
}

u8 check_ingame_check(u8 item, u8 amt)
{
  if(ap_memory_ptrs.n64_saves_fake[item] == amt){
    return true;
  }
  return false;
}


void obtain_item(u8 item)
{
    if(!already_received(item))
    {
        u16 inventory_items = sg_items_collected;
        u8 previous_item = 0x0;
        u8 current_item = item;
        update_inventory(item);
        for(u16 inventory = 0; inventory <= inventory_items; inventory++)
        {
            u32 address = 0x800EC350;
            address += inventory;
            if(inventory != 0x0)
            {
                current_item = previous_item;
            }
            previous_item = (*(u8*)address);
            (*(u8*)address) = current_item;
        }
        sg_items_collected = inventory_items+1;
    }
}

