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
    Box(title, NULL, footer, "blue", "123", size, stream);
    printBufferStream(stream);
    closeBufferStream(stream);

    unsigned char wc = readChar();
    char *inputBuf;
    size_t inputBufSize = 0;
    BufferStream_t *inputStream = openBufferStream(&inputBuf, &inputBufSize);

    while(wc != 13){
        char *c = (char *)malloc(2);
        c[0] = wc;
        c[1] = '\0';
        writeBufferStream(inputStream, c, 1);
        free(c);
        moveCursor(1,2);
        eraseDown();

        buf = NULL;
        bufSize = 0;
        stream = openBufferStream(&buf, &bufSize);
        Box(title, readBufferStreamAsString(inputStream), footer, "blue", "123", size, stream);
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