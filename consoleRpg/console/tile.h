#pragma once

#if defined(_WIN32)
#define FOREGROUND_BLACK        ((color)0x0000)
#define FOREGROUND_BLUE_DARK    ((color)0x0001)
#define FOREGROUND_GREEN_DARK   ((color)0x0002)
#define FOREGROUND_CYAN_DARK    ((color)0x0003)
#define FOREGROUND_RED_DARK     ((color)0x0004)
#define FOREGROUND_VIOLET_DARK  ((color)0x0005)
#define FOREGROUND_YELLOW_DARK  ((color)0x0006)
#define FOREGROUND_WHITE_DARK   ((color)0x0007)
#define FOREGROUND_GRAY         ((color)0x0008)
#define FOREGROUND_BLUE         ((color)0x0009)
#define FOREGROUND_GREEN        ((color)0x000A)
#define FOREGROUND_CYAN         ((color)0x000B)
#define FOREGROUND_RED          ((color)0x000C)
#define FOREGROUND_VIOLET       ((color)0x000D)
#define FOREGROUND_YELLOW       ((color)0x000E)
#define FOREGROUND_WHITE        ((color)0x000F)
#define BACKGROUND_BLACK        ((color)0x0000)
#define BACKGROUND_BLUE_DARK    ((color)0x0010)
#define BACKGROUND_GREEN_DARK   ((color)0x0020)
#define BACKGROUND_CYAN_DARK    ((color)0x0030)
#define BACKGROUND_RED_DARK     ((color)0x0040)
#define BACKGROUND_VIOLET_DARK  ((color)0x0050)
#define BACKGROUND_YELLOW_DARK  ((color)0x0060)
#define BACKGROUND_WHITE_DARK   ((color)0x0070)
#define BACKGROUND_GRAY         ((color)0x0080)
#define BACKGROUND_BLUE         ((color)0x0090)
#define BACKGROUND_GREEN        ((color)0x00A0)
#define BACKGROUND_CYAN         ((color)0x00B0)
#define BACKGROUND_RED          ((color)0x00C0)
#define BACKGROUND_VIOLET       ((color)0x00D0)
#define BACKGROUND_YELLOW       ((color)0x00E0)
#define BACKGROUND_WHITE        ((color)0x00F0)
#else
#error NO IMP
#endif


typedef int color;
typedef char icon;

typedef struct
{
	icon icon;
	color color;
} tile;



#define G_LIST_NAME tilelist
#define G_LIST_INNERTYPE tile

#include "../generic/g_list.h.txt"

#undef G_LIST_NAME
#undef G_LIST_INNERTYPE
