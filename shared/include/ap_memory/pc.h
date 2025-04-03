#ifndef PC_H
#define PC_H

#include <stdint.h>
#include <archipelago.h>
#include "util.h"

#include "items.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef struct {
    u8 items[AP_NOTE_MAX];
    u8 message[256];
    u8 message_item;
    u8 text_queue;
    u8 setting_open_door;

} ap_memory_pc_t;

#endif