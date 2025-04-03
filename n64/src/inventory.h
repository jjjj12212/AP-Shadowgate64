
#ifndef INVENTORY
#define INVENTORY
#include <stdint.h>
#include <string.h>
#include "util.h"
#include "sg/inventory.h"
#include "dialog.h"


void update_inventory(u8 item);
void obtain_item(u8 item);
bool have_item(u8 item);
u8 check_ingame_check(u8 item, u8 amt);
bool already_received(u8 item);
bool item_equipped(u8 item);
#endif