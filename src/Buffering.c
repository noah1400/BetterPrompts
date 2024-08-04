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
    buf->allocatedSize = 0;
    return buf;
}

void closeBufferStream(BufferStream_t *stream)
{
    free(*(stream->buffer));
    *(stream->buffer) = NULL;
    *(stream->size) = 0;
    free(stream);
}

void writeBufferStream(BufferStream_t *stream, char *data, size_t size) {
    if (stream->allocatedSize == 0) {
        // Initial allocation if the buffer is NULL
        stream->allocatedSize = size;
        *(stream->buffer) = (char *)malloc(stream->allocatedSize);
        allocateFailCheck(*(stream->buffer), "newBuffer");
    } else {
        // Check if we need to reallocate
        if (stream->allocatedSize < *(stream->size) + size) {
            // Reallocate to accommodate new data
            stream->allocatedSize = *(stream->size) + size;
            char *newBuffer = (char *)realloc(*(stream->buffer), stream->allocatedSize);
            allocateFailCheck(newBuffer, "newBuffer");
            *(stream->buffer) = newBuffer;
        }
    }

    // Write the data
    memcpy(*(stream->buffer) + *(stream->size), data, size);
    *(stream->size) += size;
}

void removeLastChar(BufferStream_t *stream) {
    if (*(stream->size) > 0) {
        *(stream->size) -= 1;
    }
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
        return "";
    }

    // Allocate memory for the string (including null terminator)
    char *result = (char *)malloc(*(stream->size) + 1); 
    allocateFailCheck(result, "result");

    // Copy data from the buffer to the string
    memcpy(result, *(stream->buffer), *(stream->size));

    // Add the null terminator
    result[*(stream->size)] = '\0'; 

    return result;
}