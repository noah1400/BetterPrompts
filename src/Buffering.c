#include <Buffering.h>

static BufferStream_t *allocBufferStream()
{
    BufferStream_t *buf = (BufferStream_t *)malloc(sizeof(BufferStream_t));
    return buf;
}

BufferStream_t *openBufferStream(char **buffer, size_t *size)
{
    BufferStream_t *buf = allocBufferStream();
    buf->buffer = buffer;
    buf->size = size;
    return buf;
}

void closeBufferStream(BufferStream_t *stream)
{
    free(*(stream->buffer));
    *(stream->buffer) = NULL;
    *(stream->size) = 0;
    free(stream);
}

void writeBufferStream(BufferStream_t *stream, char *data, size_t size)
{
    char *newBuffer = NULL;
    if (*(stream->size) == 0)
    {
        newBuffer = (char *)malloc(size);
    }else {
        newBuffer = (char *)realloc(*(stream->buffer), *(stream->size) + size);
    }
    allocateFailCheck(newBuffer, "newBuffer");
    *(stream->buffer) = newBuffer;
    memcpy(*(stream->buffer) + *(stream->size), data, size);
    *(stream->size) += size;
}

void printBufferStream(BufferStream_t *stream)
{
    // write byte for byte since buffer can contain newLines
    for (size_t i = 0; i < *(stream->size); i++) {
        putchar(*(*(stream->buffer) + i));
    }
}

char* readBufferStreamAsString(BufferStream_t *stream) {
    // Ensure there's data in the stream
    if (*(stream->size) == 0) {
        return NULL; // or return an empty string if preferred
    }

    // Allocate memory for the string (including null terminator)
    char *result = (char *)malloc(*(stream->size) + 1); 
    if (result == NULL) {
        // Handle allocation failure (log, return error, etc.)
        return NULL;
    }

    // Copy data from the buffer to the string
    memcpy(result, *(stream->buffer), *(stream->size));

    // Add the null terminator
    result[*(stream->size)] = '\0'; 

    return result;
}