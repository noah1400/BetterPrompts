#ifndef BUFFERING_H
#define BUFFERING_H

#include <stdio.h>
#include <stdlib.h>
#include <Utils.h>

typedef struct BufferStream {
    char **buffer;
    size_t *size;
} BufferStream_t;

BufferStream_t *openBufferStream(char **buffer, size_t *size);
void closeBufferStream(BufferStream_t *stream);
void writeBufferStream(BufferStream_t *stream, char *data, size_t size);
void printBufferStream(BufferStream_t *stream);

#endif // BUFFERING_H