#include "shop.h"


void shop_keeper_items_calc()
{
    if(sg_current_map == MAP_SHOP)
    {
        if(check_ingame_check(AP_ITEM_BROOCH, 1))
        {
        sg_item_flags.coin1 = 0x04;
        sg_item_flags.brooch = 0x03;
        }
        else if(have_item(AP_ITEM_BROOCH))
        {
            sg_item_flags.brooch = 0x4;
        }

        if(check_ingame_check(AP_ITEM_JEWELRY_BOX, 1))
        {
        sg_item_flags.coin2 = 0x04;
        sg_item_flags.jewelry_box = 0x03;
        }
        else if(have_item(AP_ITEM_JEWELRY_BOX))
        {
            sg_item_flags.jewelry_box = 0x4;
        }

        if(check_ingame_check(AP_ITEM_FRUIT, 1))
        {
        sg_item_flags.coin3 = 0x04;
        sg_item_flags.fruit = 0x03;
        }
        else if(have_item(AP_ITEM_FRUIT))
        {
            sg_item_flags.fruit = 0x4;
        }

        if(check_ingame_check(AP_ITEM_GAUNTLET, 1))
        {
        sg_item_flags.coin4 = 0x04;
        sg_item_flags.gauntlet = 0x03;
        }
        else if(have_item(AP_ITEM_GAUNTLET))
        {
            sg_item_flags.gauntlet = 0x4;
        }
    }

    if(sg_current_map != MAP_SHOP && ap_memory.pc.items[AP_ITEM_BROOCH] == 1 && sg_item_flags.brooch == 0x4)
    {
        sg_item_flags.brooch = 0x03;
    }
    if(sg_current_map != MAP_SHOP && ap_memory.pc.items[AP_ITEM_JEWELRY_BOX] == 1 && sg_item_flags.jewelry_box == 0x4)
    {
        sg_item_flags.jewelry_box = 0x03;
    }
    if(sg_current_map != MAP_SHOP && ap_memory.pc.items[AP_ITEM_FRUIT] == 1 && sg_item_flags.fruit == 0x4)
    {
        sg_item_flags.fruit = 0x03;
    }
    if(sg_current_map != MAP_SHOP && ap_memory.pc.items[AP_ITEM_GAUNTLET] == 1 && sg_item_flags.gauntlet == 0x4)
    {
        sg_item_flags.gauntlet = 0x03;
    }
}