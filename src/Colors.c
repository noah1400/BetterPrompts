#include <Colors.h>

void createEscapeSequence(char *dest, const char* prefixFormat, char *text, const char* sufixFormat)
{
    strcpy(dest, CSI);
    strcat(dest, prefixFormat);
    strcat(dest, text);
    strcat(dest, CSI);
    strcat(dest, sufixFormat);
}

char *reset(char *text) {
    // CSI + 0m + text + CSI + 0m
    char *resetText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 4 + 1);
    allocateFailCheck(resetText, "resetText");
    createEscapeSequence(resetText, "0m", text, "0m");

    return resetText;
}

char *bold(char *text) {
    // CSI + 1m + text + CSI + 22m
    char *boldText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(boldText, "boldText");
    createEscapeSequence(boldText, "1m", text, "22m");

    return boldText;
}


char *dim(char *text) {
    // CSI + 2m + text + CSI + 22m
    char *dimText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(dimText, "dimText");
    createEscapeSequence(dimText, "2m", text, "22m");

    return dimText;
}

char *italic(char *text) {
    // CSI + 3m + text + CSI + 23m
    char *italicText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(italicText, "italicText");
    createEscapeSequence(italicText, "3m", text, "23m");

    return italicText;
}

char *underline(char *text) {
    // CSI + 4m + text + CSI + 24m
    char *underlineText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(underlineText, "underlineText");
    createEscapeSequence(underlineText, "4m", text, "24m");

    return underlineText;
}

char *inverse(char *text) {
    // CSI + 7m + text + CSI + 27m
    char *inverseText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(inverseText, "inverseText");
    createEscapeSequence(inverseText, "7m", text, "27m");

    return inverseText;
}

char *hidden(char *text) {
    // CSI + 8m + text + CSI + 28m
    char *hiddenText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(hiddenText, "hiddenText");
    createEscapeSequence(hiddenText, "8m", text, "28m");

    return hiddenText;
}

char *strikethrough(char *text) {
    // CSI + 9m + text + CSI + 29m
    char *strikethroughText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 5 + 1);
    allocateFailCheck(strikethroughText, "strikethroughText");
    createEscapeSequence(strikethroughText, "9m", text, "29m");

    return strikethroughText;
}

char *black(char *text) {
    // CSI + 30m + text + CSI + 39m
    char *blackText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(blackText, "blackText");
    createEscapeSequence(blackText, "30m", text, "39m");
}

char *red(char *text) {
    // CSI + 31m + text + CSI + 39m
    char *redText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(redText, "redText");
    createEscapeSequence(redText, "31m", text, "39m");
}

char *green(char *text) {
    // CSI + 32m + text + CSI + 39m
    char *greenText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(greenText, "greenText");
    createEscapeSequence(greenText, "32m", text, "39m");
}

char *yellow(char *text) {
    // CSI + 33m + text + CSI + 39m
    char *yellowText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(yellowText, "yellowText");
    createEscapeSequence(yellowText, "33m", text, "39m");
}

char *blue(char *text) {
    // CSI + 34m + text + CSI + 39m
    char *blueText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(blueText, "blueText");
    createEscapeSequence(blueText, "34m", text, "39m");
}

char *magenta(char *text) {
    // CSI + 35m + text + CSI + 39m
    char *magentaText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(magentaText, "magentaText");
    createEscapeSequence(magentaText, "35m", text, "39m");
}

char *cyan(char *text) {
    // CSI + 36m + text + CSI + 39m
    char *cyanText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(cyanText, "cyanText");
    createEscapeSequence(cyanText, "36m", text, "39m");
}

char *white(char *text) {
    // CSI + 37m + text + CSI + 39m
    char *whiteText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(whiteText, "whiteText");
    createEscapeSequence(whiteText, "37m", text, "39m");
}

char *bgBlack(char *text) {
    // CSI + 40m + text + CSI + 49m
    char *bgBlackText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgBlackText, "bgBlackText");
    createEscapeSequence(bgBlackText, "40m", text, "49m");
}

char *bgRed(char *text) {
    // CSI + 41m + text + CSI + 49m
    char *bgRedText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgRedText, "bgRedText");
    createEscapeSequence(bgRedText, "41m", text, "49m");
}

char *bgGreen(char *text) {
    // CSI + 42m + text + CSI + 49m
    char *bgGreenText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgGreenText, "bgGreenText");
    createEscapeSequence(bgGreenText, "42m", text, "49m");
}

char *bgYellow(char *text) {
    // CSI + 43m + text + CSI + 49m
    char *bgYellowText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgYellowText, "bgYellowText");
    createEscapeSequence(bgYellowText, "43m", text, "49m");
}

char *bgBlue(char *text) {
    // CSI + 44m + text + CSI + 49m
    char *bgBlueText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgBlueText, "bgBlueText");
    createEscapeSequence(bgBlueText, "44m", text, "49m");
}

char *bgMagenta(char *text) {
    // CSI + 45m + text + CSI + 49m
    char *bgMagentaText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgMagentaText, "bgMagentaText");
    createEscapeSequence(bgMagentaText, "45m", text, "49m");
}

char *bgCyan(char *text) {
    // CSI + 46m + text + CSI + 49m
    char *bgCyanText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgCyanText, "bgCyanText");
    createEscapeSequence(bgCyanText, "46m", text, "49m");
}

char *bgWhite(char *text) {
    // CSI + 47m + text + CSI + 49m
    char *bgWhiteText = (char *)malloc(strlen(text) + STRLEN_CSI*2 + 6 + 1);
    allocateFailCheck(bgWhiteText, "bgWhiteText");
    createEscapeSequence(bgWhiteText, "47m", text, "49m");
}

void test_colors() {
    char *text = "Hello, World!";
    char *resetText = reset(text);
    char *boldText = bold(text);
    char *dimText = dim(text);
    char *italicText = italic(text);
    char *underlineText = underline(text);
    char *inverseText = inverse(text);
    char *hiddenText = hidden(text);
    char *strikethroughText = strikethrough(text);

    printf("Reset: %s\n", resetText);
    printf("Bold: %s\n", boldText);
    printf("Dim: %s\n", dimText);
    printf("Italic: %s\n", italicText);
    printf("Underline: %s\n", underlineText);
    printf("Inverse: %s\n", inverseText);
    printf("Hidden: %s\n", hiddenText);
    printf("Strikethrough: %s\n", strikethroughText);

    free(resetText);
    free(boldText);
    free(dimText);
    free(italicText);
    free(underlineText);
    free(inverseText);
    free(hiddenText);
    free(strikethroughText);
}