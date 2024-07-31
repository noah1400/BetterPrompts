#include <Terminal.h>

char readChar() {
    wchar_t wch;
    wch = _getwch();
    return (char)wch;
}