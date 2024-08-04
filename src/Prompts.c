#include <Prompts.h>

char *textPrompt(
    char *title,
    char *footer,
    COORD size)
{
    hideCursor();
    char *buf;
    size_t bufSize = 0;
    BufferStream_t *stream = openBufferStream(&buf, &bufSize);
    Box(title, NULL, footer, "cyan", "...YourName...", size, stream);
    printBufferStream(stream);
    closeBufferStream(stream);

    unsigned char wc = readChar();
    char *inputBuf;
    size_t inputBufSize = 0;
    BufferStream_t *inputStream = openBufferStream(&inputBuf, &inputBufSize);

    while (wc != 13)
    {
        if (wc == 8)
        {
            removeLastChar(inputStream);
        }
        else
        {
            writeBufferStream(inputStream, &wc, 1);
        }

        buf = NULL;
        bufSize = 0;
        stream = openBufferStream(&buf, &bufSize);
        Box(title, readBufferStreamAsString(inputStream), footer, "cyan", "...YourName...", size, stream);
        moveCursor(1, 2);
        eraseDown();
        printBufferStream(stream);
        closeBufferStream(stream);
        wc = readChar();
    }

    char *input = readBufferStreamAsString(inputStream);
    closeBufferStream(inputStream);
    showCursor();
    printf("\n");
    return input;
}