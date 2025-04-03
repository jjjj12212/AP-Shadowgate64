#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "sg.h"
#include "inventory.h"
#include "shop.h"
#include "ap.h"

bool player_accident = false;
bool slipper_set = false;
bool moat_drained = false;
bool ctimer = false;
bool candle_requirement_flagged = false;
bool agaar_complete = false;

bool dpad_upressed = false;
bool dpad_rpressed = false;
bool dpad_dpressed = false;
bool dpad_lpressed = false;

void skip_intro()
{
  if(sg_player_event == EVENT_INTRO)
  {
    sg_scene_handler = SH_CUTSCENE_TRANSITION;
  }
}

void obtain_ingame_check(u8 _knownu8, u32 _unkown_addr, u8 item)
{
  if(item == AP_ITEM_WATER) // Real check is from function obtain_ingame_npc_check
  {
    ap_memory_ptrs.n64_saves_fake[item-1] = 1;
  }
  else
  {
    ap_memory_ptrs.n64_saves_fake[item] = 1;
  }
}

extern void obtain_ingame_npc_check_displaced(u8 _knownu8, u8 _knownu82, u8 item);
void obtain_ingame_npc_check(u8 _knownu8, u8 _knownu82, u8 item)
{
  ap_memory_ptrs.n64_saves_fake[item] = 1;
}

void show_ap_text()
{
  if(ap_memory_ptrs.n64_queue < ap_memory.pc.text_queue && ap_memory_ptrs.text_ready == true)
  {
    show_dialog(ap_memory.pc.message_item);
    ap_memory_ptrs.n64_queue++;
  }
}

void cheat_death()
{
  if(!player_accident && (sg_player_event == EVENT_FALL || sg_player_event == EVENT_DROWN || sg_player_event == EVENT_SLICED))
  {
    player_accident = true;
  }
  if(sg_game_state == GS_GAME_OVER && player_accident)
  {
    sg_game_state = GS_NORMAL;
    sg_death = 0x0;
    sg_scene_handler = SH_MAP_TRANSITION;
  }
  if(player_accident && sg_scene_handler != SH_NORMAL)
  {
    if(sg_current_map == MAP_CHAPEL_ROOF)
    {
      sg_player_xpos = 321; // 43A08
      sg_player_ypos = -256; // C3800
      sg_player_zpos = -458; // C3E50
    }
    if(sg_current_map == MAP_TRIAL_TOWER_DEATH_MAZE)
    {
      sg_player_xpos = 1728; //44D80000
      sg_player_ypos = -64; //C2800000
      sg_player_zpos = -1856; //C4E80000
    }
  }
  else if(player_accident && sg_scene_handler == SH_NORMAL)
  {
    player_accident = false;
  }
}

void inject_loop(u32* _unkownptr1, u32* _unkownptr2, u8 rand)
{
  sg_fn_main_loop(_unkownptr1, _unkownptr2, 1);
}

void open_main_door()
{
  if(ap_memory.pc.setting_open_door == true)
  {
    if(sg_current_map == MAP_TOWER1_ENTRANCE && have_item(AP_ITEM_RING_OF_THE_DEAD) == false)
    {
      sg_item_flags.ring_of_the_dead = 0x03;
    }
    else if(sg_current_map != MAP_TOWER1_ENTRANCE && have_item(AP_ITEM_RING_OF_THE_DEAD) == false)
    {
      sg_item_flags.ring_of_the_dead = 0x0;
    }
  }
}

void post_game_inn()
{
  if(sg_current_map == MAP_INN && have_item(AP_ITEM_STAFF_OF_AGES) == true && have_item(AP_ITEM_JEZIBEL_PENDANT) == false)
  {
    sg_item_flags.jezibel_pendant = 0x23;
  }
  else if(sg_current_map != MAP_INN && have_item(AP_ITEM_STAFF_OF_AGES) == true && have_item(AP_ITEM_JEZIBEL_PENDANT) == false)
  {
    sg_item_flags.jezibel_pendant = 0x0;
  }
}

void complete_slippers()
{
  if(slipper_set == true)
  {
    sg_item_flags.slipper = 0x4;
    sg_item_flags.dirty_slipper = 0x4;
    slipper_set = false;
    obtain_ingame_check(0, 0, AP_ITEM_PAIR_OF_SLIPPERS);
    obtain_item(AP_ITEM_PAIR_OF_SLIPPERS);
  }
  else if(ap_memory.pc.items[AP_ITEM_PAIR_OF_SLIPPERS] == false)
  {
    sg_item_flags.pair_of_slippers = 0x0;
  }
}

void remove_inventory_items()
{
  if(sg_map_rope_element == true && sg_next_map == MAP_TOWER1_2FLR)
  {
    sg_item_flags.rope = 0x04;
  }
  if(sg_statues_solved == true)
  {
    sg_item_flags.fairy_sculpture = 0x04;
    sg_item_flags.elf_statue = 0x04;
  }
  if(sg_used_sthurst == true)
  {
    sg_item_flags.stone_of_thirst = 0x04;
  }
  if(sg_lever == true)
  {
    sg_item_flags.lever = 0x04;
  }
  if(sg_flower == true)
  {
    sg_item_flags.flower = 0x04;
  }
  if(sg_fang1 == true)
  {
    sg_item_flags.fang = 0x04;
  }
  if(sg_hair == true)
  {
    sg_item_flags.hair_of_giant = 0x04;
  }
  if(sg_ancient_coin == true)
  {
    sg_item_flags.ancient_coin = 0x04;
  }
  if(sg_chipped_violin == true)
  {
    sg_item_flags.chipped_violin = 0x04;
  }
  if(ap_memory_ptrs.n64_saves_fake[AP_ITEM_STONE_OF_THIRST] == 1)
  {
    sg_item_flags.pair_of_slippers = 0x04;
  }
  if(sg_crest_fragment == true)
  {
    sg_item_flags.fragments_of_crest = 0x04;
  }
  if(sg_candle == true)
  {
    sg_item_flags.burning_candle = 0x04;
  }
  if(have_item(AP_ITEM_WATER_DRAGON_TEARS))
  {
    sg_item_flags.mug = 0x4;
    sg_item_flags.water = 0x4;
  }
  if(have_item(AP_ITEM_WATER))
  {
    sg_item_flags.mug = 0x4;
  }
  if(sg_agaar_door == 0x04)
  {
    sg_item_flags.orb = 0x04;
  }
  if(sg_next_map == MAP_RUINS)
  {
    sg_item_flags.dragon_eye = 0x04;
  }
  if(sg_next_map == MAP_END && sg_staff == true)
  {
    sg_item_flags.staff_of_ages = 0x04;
  }
}

void agaar_quest_fix()
{
  if(sg_sister_accepted == 0x02)
  {
    return;
  }
  else
  {
    if(agaar_complete == false)
    {
      if(sg_current_map == MAP_TOWN && sg_dungeon_door == true)
      {
        show_dialog_text("Thank you for saving me Del.\nThe door to my house is unlocked.\nPlease see my sister at the Inn.");
        sg_agaar_door = 0x0;
        agaar_complete = true;
      }
    }
    else
    {
      if(sg_next_map == MAP_TOWN && (sg_agaar_door == 0x04 || sg_agaar_door == 0x05))
      {
        sg_agaar_door = 0x0;
      }
      if(sg_next_map == MAP_BROKEN_SIDE_OF_TOWN)
      {
        sg_agaar_door = 0x05;
      }
    }
  }

}

void check_slippers()
{
  if(have_item(AP_ITEM_DIRTY_SLIPPER) == true && have_item(AP_ITEM_SLIPPER) == true)
  {
    slipper_set = true;
    return;
  }
}

void check_moat()
{
  if(sg_moat_removed)
  {
    moat_drained = true;
  }
}

void spawn_ghost_girl()
{
  if(moat_drained == true && item_equipped(AP_ITEM_RING_OF_THE_DEAD) && check_ingame_check(AP_ITEM_STONE_OF_THIRST, 1) == false)
  {
    sg_moat_removed = 0x0;
    sg_ghost_girl_completed = 0x0;
  }
  else if(moat_drained)
  {
    sg_moat_removed = 0x1;
  }
}

void take_candle_check()
{
  if(sg_current_map == MAP_TRIAL_TOWER_BEFORE_MAZE && sg_candle_requirement == 0x0)
  {
    candle_requirement_flagged = true;
    sg_candle_requirement = 0x01;
  }
  else if (sg_current_map != MAP_TRIAL_TOWER_BEFORE_MAZE && candle_requirement_flagged == true)
  {
    candle_requirement_flagged = false;
    sg_candle_requirement = 0x00;
  }
}

void candle_timer_begin()
{
  if(sg_current_map == MAP_TRIAL_TOWER_BEFORE_MAZE && have_item(AP_ITEM_BURNING_CANDLE) == true)
  {
    ctimer = true;
    sg_candle_timer = 0xFF;
  }
  else if(have_item(AP_ITEM_BURNING_CANDLE) == false)
  {
    ctimer = false;
    sg_candle_timer = 0x00;
  }
}

void start_candle_timer()
{
  if(ctimer == true && (sg_candle_timer >= 0xD0 && sg_candle_timer <= 0xF0))
  {
    sg_candle_timer = 0xFF;
  }
}

void check_starcrest_inplace()
{
  if(sg_starcrest_inplace)
  {
    obtain_ingame_check(0, 0, AP_ITEM_STARCREST);
    sg_item_flags.starcrest = 0x4;
  }
}

void end_save()
{
  if(sg_next_map == MAP_END && have_item(AP_ITEM_RING_OF_THE_KINGDOM) && !item_equipped(AP_ITEM_RING_OF_THE_KINGDOM))
  {
    sg_item_flags.ring_of_the_kingdom = 0x23;
  }
}


bool pre_loop()
{
  skip_intro();
  cheat_death();
  if(DIALOG_SET == true && sg_game_state == GS_NORMAL)
  {
    DIALOG_SET = false;
    ap_memory_ptrs.text_ready = true;
  }
  if(sg_scene_handler == SH_NORMAL && sg_player_locked != 0x01)
  {
    ap_check();
    show_ap_text();
    if(sg_player_button == BTN_DU && !dpad_upressed)
    {
      // ap_memory.pc.items[AP_ITEM_STAFF_OF_AGES] = 1;
      // dpad_upressed = true;
    }
    if(sg_player_button == BTN_DR && !dpad_rpressed)
    {
      // ap_memory.pc.items[AP_ITEM_BONE] = 1;
      // ap_memory.pc.items[AP_ITEM_IRON_BAR] = 1;
      // ap_memory.pc.items[AP_ITEM_RUSTY_KEY] = 1;
      // ap_memory.pc.items[AP_ITEM_CEMETERY_KEY] = 1;
      // ap_memory.pc.items[AP_ITEM_RING_OF_THE_DEAD] = 1;
      // ap_memory.pc.items[AP_ITEM_DRAGON_FLUTE] = 1;
      // ap_memory.pc.items[AP_ITEM_DRAGON_TEARS] = 1;
      // ap_memory.pc.items[AP_ITEM_JEZIBEL_PENDANT] = 1;
      // ap_memory.pc.items[AP_ITEM_FLINT] = 1;
      // ap_memory.pc.items[AP_ITEM_CROWBAR] = 1;
      // ap_memory.pc.items[AP_ITEM_STARCREST] = 1;
      // ap_memory.pc.items[AP_ITEM_BOTTLE_OF_OIL] = 1;
      // ap_memory.pc.items[AP_ITEM_LIQUID_SUNSET] = 1;
      // ap_memory.pc.items[AP_ITEM_NIGHT_ELIXIR] = 1;
      // dpad_rpressed = true;
    }
    if(sg_player_button == BTN_DL && !dpad_lpressed)
    {
      // ap_memory.pc.items[AP_ITEM_FRAGMENTS_OF_CREST] = 1;
      // ap_memory.pc.items[AP_ITEM_LEVER] = 1;
      // ap_memory.pc.items[AP_ITEM_PAIR_OF_SLIPPERS] = 1;
      // ap_memory.pc.items[AP_ITEM_STONE_OF_THIRST] = 1;
      // ap_memory.pc.items[AP_ITEM_BURNING_CANDLE] = 1;
      // ap_memory.pc.items[AP_ITEM_ANCIENT_COIN] = 1;
      // ap_memory.pc.items[AP_ITEM_WATER_DRAGON_TEARS] = 1;
      // ap_memory.pc.items[AP_ITEM_CREST_KEY] = 1;
      // ap_memory.pc.items[AP_ITEM_DRAGON_EYE] = 1;
      // ap_memory.pc.items[AP_ITEM_RING_OF_THE_KINGDOM] = 1;
      // ap_memory.pc.items[AP_ITEM_STAFF_OF_AGES] = 1;
      // dpad_lpressed = true;
    }
    if(sg_player_button == BTN_DD && !dpad_dpressed)
    {
      // ap_memory.pc.items[AP_ITEM_CEMETERY_KEY] = 1;
      // ap_memory.pc.items[AP_ITEM_DRAGON_EYE] = 1;
      // ap_memory.pc.items[AP_ITEM_STAFF_OF_AGES] = 1;
      // ap_memory.pc.items[AP_ITEM_JEZIBEL_PENDANT] = 1;
      // ap_memory.pc.items[AP_ITEM_RING_OF_THE_KINGDOM] = 1;
      // sg_moat_removed = true;
      // dpad_dpressed = true;
    }
  }
  check_starcrest_inplace();
  complete_slippers();
  remove_inventory_items();

  agaar_quest_fix();
  open_main_door();
  post_game_inn();
  check_slippers();
  check_moat();
  spawn_ghost_girl();
  take_candle_check();
  candle_timer_begin();
  start_candle_timer();
  shop_keeper_items_calc();
  return sg_fn_unknown_start_loop();
}

void dialog_override_check(u32* text_ptr)
{
  if(DIALOG_SET == false)
  {
    sg_fn_dialog_text(text_ptr);
  } else
  {
    sg_fn_dialog_text((u32*)ap_memory.pc.message);
  }
}


u32 inject_hooks() {
  util_inject(UTIL_INJECT_FUNCTION, 0x80098A24, (u32)pre_loop, 0);
  util_inject(UTIL_INJECT_FUNCTION, 0x800900E0, (u32)inject_loop, 0);
  util_inject(UTIL_INJECT_FUNCTION, 0x800320E8, (u32)obtain_ingame_check, 1);
  util_inject(UTIL_INJECT_RAW, 0x80053F30, 0, 0); // No guard in Excavating map
  util_inject(UTIL_INJECT_JUMP, 0x80030E7C, (u32)obtain_ingame_npc_check_displaced, 1);

  for(int addr = 0x800320F0; addr <= 0x80032138; addr += 4)
  {
      util_inject(UTIL_INJECT_RAW, addr, 0, 0);
  }
  util_inject(UTIL_INJECT_FUNCTION, 0x8002FD64, (u32)dialog_override_check, 0);
  ap_memory_ptrs.text_ready = true;
  ap_memory.pc.setting_open_door = false;
  return 0;
}

