// Author: Artiom Tretjakovas
// Description: File, which contains functions for colorizing output.

#ifndef GCLADOS_COLORS_H
#define GCLADOS_COLORS_H

#include <stdbool.h>

// Structure, which contains ANSI flags.
typedef struct {
    int *flags;
    int count;
} GcladosAnsiFlags;

typedef enum {
    GCLADOS_BLACK = 0,
    GCLADOS_RED,
    GCLADOS_GREEN,
    GCLADOS_YELLOW,
    GCLADOS_BLUE,
    GCLADOS_MAGENTA,
    GCLADOS_CYAN,
    GCLADOS_WHITE,
} GcladosColor;

// Structure containing function for colored output.
typedef struct {
    // Toggle color support.
    void (*setColorsSupported)(bool colorSupport);
    // Function, which is used to determine, if colors are enabled or not.
    bool (*colorsSupported)();
    // Function to create flags.
    // Parameters:
    //     count      - the count of flags.
    //     ... (rest) - ANSI flags.
    // Returns:
    //     GcladosAnsiFlags structure, that should be disposed after using by calling gcladosColors.freeFlags.
    GcladosAnsiFlags (*createFlags)(int count, ...);
    // Function, that utilizes GcladosAnsiFlags.
    void (*freeFlags)(GcladosAnsiFlags flags);
    // Function, that applies flags on given string.
    // Returns:
    //     String, that should be disposed after using it by calling free.
    char *(*applyFlags)(char *input, GcladosAnsiFlags flags);
    // Function, which returns flag for the text color.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*foregroundColor)(GcladosColor color);
    // Function, which returns flag for the background color.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*backgroundColor)(GcladosColor color);
    // Function, which returns flag for making text bold (or darker, depending on OS).
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*bold)();
    // Function, which returns flag for decreasing text intensity.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*dimmed)();
    // Function, which returns flag for making text italic.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*italic)();
    // Function, which returns flag for adding underline for text.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*underline)();
    // Function, which returns flag for inverting foreground and background colors.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*invert)();
    // Function, which returns flag for making text crossed out.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*strikethrough)();
    // Function, which returns flag for creating frame on text. Not widely supported.
    // Should be passed into gcladosColors.createFlags, and the applied on the string via gcladosColors.applyFlags.
    int (*framed)();
} GcladosColors;

// Variable, for accessing text coloring functions.
// Used as namespace alternative.
extern GcladosColors gcladosColors;

#endif