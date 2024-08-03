#include <Terminal.h>

unsigned char readChar() {
    unsigned char ch;
    ch = _getch();
    return ch;
}