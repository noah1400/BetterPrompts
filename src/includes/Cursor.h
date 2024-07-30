#ifndef CURSOR_H
#define CURSOR_H

#include <stdio.h>

#define ESC "\x1b"
#define CSI "\x1b["

void hideCursor();
void showCursor();

void moveCursor(char x, char y);
void moveCursorUp(char n);
void moveCursorToColumn(char x);

#endif // CURSOR_H