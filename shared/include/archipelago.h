#ifndef ARCHIPELAGO_H
#define ARCHIPELAGO_H

#include <stdint.h>
#include <stdbool.h>
#include "ap_memory/items.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef volatile uint8_t vu8;
typedef volatile uint16_t vu16;
typedef volatile uint32_t vu32;
typedef volatile uint64_t vu64;

typedef volatile int8_t vs8;
typedef volatile int16_t vs16;
typedef volatile int32_t vs32;
typedef volatile int64_t vs64;

typedef float f32;
typedef double f64;

typedef struct {
    u32 hook;
    u8 major;
    u8 minor;
    u8 patch;
    u8 n64_saves_fake[AP_NOTE_MAX];
    u8 real_items[AP_NOTE_MAX];
    u8 message[256];
    u8 message_item;
    u8 text_queue;
    u8 n64_queue;
    u8 text_ready;
    u8 setting_open_door;
} ap_memory_t;

#endif // ARCHIPELAGO_H
