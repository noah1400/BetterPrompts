#include <Prompts.h>

void textPrompt(
            char *title,
            char *footer,
            COORD size)
{
    hideCursor();
    char *buf;
    size_t bufSize = 0;
    BufferStream_t *stream = openBufferStream(&buf, &bufSize);
    Box(title, " ", footer, "blue", "123", size, stream);
    printBufferStream(stream);
    closeBufferStream(stream);

    char wc = readChar();
    while(wc != 13){
        moveCursor(1,2);
        eraseDown();

        char str[2] = {wc, '\n'};

        buf = NULL;
        bufSize = 0;
        stream = openBufferStream(&buf, &bufSize);
        Box(title, str, footer, "blue", "123", size, stream);
        printBufferStream(stream);
        closeBufferStream(stream);
        wc = readChar();
    }

}