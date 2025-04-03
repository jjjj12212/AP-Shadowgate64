#ifndef ARCHIPELAGO_H
#define ARCHIPELAGO_H

#define AP_VERSION_MAJOR 4
#define AP_VERSION_MINOR 0
#define AP_VERSION_PATCH 0

#include <stdint.h>
#include <stdbool.h>
#include "ap_memory/pc.h"

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
  ap_memory_pc_t pc; // only the pc program should write data here
} ap_memory_t;

typedef union {
  struct {
    u16 major;
    u8  minor;
    u8  patch;
  };
  u32 as_int;
} ap_version_t;
static const ap_version_t AP_VERSION = {AP_VERSION_MAJOR, AP_VERSION_MINOR, AP_VERSION_PATCH};

#endif // ARCHIPELAGO_H
