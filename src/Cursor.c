#include <Cursor.h>

void hideCursor() {
    printf(CSI "?25l");
}

void showCursor() {
    printf(CSI "?25h");
}

void moveCursor(char x, char y) {
    printf(CSI "%d;%dH", y, x);
}

void moveCursorUp(char n) {
    printf(CSI "%dA", n);
}

void moveCursorToColumn(char x) {
    printf(CSI "%dG", x);
}

void eraseDown() {
    printf(CSI "J");
}