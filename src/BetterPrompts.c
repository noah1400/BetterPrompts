#include <windows.h>

#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <Colors.h>
#include <Shapes.h>
#include <Prompts.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

#define ESC "\x1b"
#define CSI "\x1b["

bool EnableVTMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode)) {
        return false;
    }
    return true;
}

int main(int argc, WCHAR* argv[]) {
    (void)argc;
    (void)argv;

    bool fSuccess = EnableVTMode();
    if (!fSuccess) {
        printf("Unable to enter VT processing mode. Exiting.\n");
        return -1;
    }
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        printf("Unable to get stdout handle. Exiting.\n");
        return -1;
    }

    CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
    GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
    COORD Size;
    Size.X = ScreenBufferInfo.srWindow.Right - ScreenBufferInfo.srWindow.Left + 1;
    Size.Y = ScreenBufferInfo.srWindow.Bottom - ScreenBufferInfo.srWindow.Top + 1;

    printf(CSI "?1049h");
    printf(CSI "1;1H");
    printf(CSI "102;30m");
    printf("Answer the prompts below:");
    printf(CSI "0m");

    printf(CSI "2;1H");

    char *input = textPrompt("What is your name?", "We need your name to know how we should call you.", Size);
    printf(CSI "?1049l");

    printf("Your name is: %s\n", input);


    free(input);

    unsigned char wc = readChar();

    printf("%d\n", wc);
}