#ifndef SHAPES_H
#define SHAPES_H

#include <stdio.h>
#include <windows.h>
#include <Colors.h>
#include <Utils.h>
#include <Cursor.h>
#include <Buffering.h>

void Box(char *title,
            char *body,
            char *footer,
            char *color,
            char *info,
            COORD size);

#endif // SHAPES_H