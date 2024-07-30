#ifndef COLORS_H
#define COLORS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Utils.h>

#define ESC "\x1b"
#define CSI "\x1b["

#define STRLEN_ESC 2
#define STRLEN_CSI 3

// dest = CSI + prefixFormat + text + CSI + sufixFormat
void createEscapeSequence(char *dest, const char* prefixFormat, char *text, const char* sufixFormat);

char *reset(char *text);

char *bold(char *text);

char *dim(char *text);

char *italic(char *text);

char *underline(char *text);

char *inverse(char *text);

char *hidden(char *text);

char *strikethrough(char *text);

char *black(char *text);

char *red(char *text);

char *green(char *text);

char *yellow(char *text);

char *blue(char *text);

char *magenta(char *text);

char *cyan(char *text);

char *white(char *text);

char *bgBlack(char *text);

char *bgRed(char *text);

char *bgGreen(char *text);

char *bgYellow(char *text);

char *bgBlue(char *text);

char *bgMagenta(char *text);

char *bgCyan(char *text);

char *bgWhite(char *text);

void test_colors();

#endif // COLORS_H