#include <Shapes.h>

#define MAX_LINES 100

static void enterLineDrawingMode(BufferStream_t *stream)
{
    writeBufferStream(stream, ESC "(0", STRLEN_ESC + 2);
}

static void exitLineDrawingMode(BufferStream_t *stream)
{
    writeBufferStream(stream, ESC "(B", STRLEN_ESC + 2);
}

static void writeSpace(BufferStream_t *stream)
{
    writeBufferStream(stream, " ", 1);
}

static void writeNewLine(BufferStream_t *stream)
{
    writeBufferStream(stream, "\n", 1);
}

static void writeColoredText(BufferStream_t *stream, char *text, const char *color)
{
    char *coloredText = callColor(text, color);
    writeBufferStream(stream, coloredText, strlen(coloredText));
    free(coloredText);
}

static void writeLine(BufferStream_t *stream, char *line, char *verticalLine, int width)
{
    enterLineDrawingMode(stream);
    writeSpace(stream);
    writeBufferStream(stream, verticalLine, strlen(verticalLine));
    writeSpace(stream);
    exitLineDrawingMode(stream);
    writeBufferStream(stream, line, strlen(line));
    writeSpace(stream);
    int numSpaces = width - strlen(line);
    char *spaces = strrepeat(" ", numSpaces);
    writeBufferStream(stream, spaces, numSpaces);
    free(spaces);
    enterLineDrawingMode(stream);
    writeBufferStream(stream, verticalLine, strlen(verticalLine));
    exitLineDrawingMode(stream);
    writeNewLine(stream);
}

void Box(char *title, char *body, char *footer, char *color, char *info, COORD size, BufferStream_t *stream)
{
    int minWidth = min(size.X, 60);

    char *bodyLines[MAX_LINES];
    char *footerLines[MAX_LINES];

    int numBodyLines = splitLines(body, bodyLines, MAX_LINES);
    int numFooterLines = splitLines(footer, footerLines, MAX_LINES);

    const char *allLines[MAX_LINES * 2];
    int numAllLines = 0;

    for (int i = 0; i < numBodyLines; i++)
    {
        allLines[numAllLines++] = bodyLines[i];
    }

    for (int i = 0; i < numFooterLines; i++)
    {
        allLines[numAllLines++] = footerLines[i];
    }

    allLines[numAllLines++] = title;
    int width = longestLine(allLines, numAllLines);

    int titleLength = strlen(title);
    char *titleLabel = (char *)malloc(titleLength + 3); // space left and right + null terminator
    allocateFailCheck(titleLabel, "titleLabel");
    sprintf(titleLabel, " %s ", title);

    int times = width - titleLength + (titleLength > 0 ? 0 : 2);
    char *bottomBorder = strrepeat("q", width + (titleLength > 0 ? 2 : 0));
    char *verticalLine = callColor("x", color);

    enterLineDrawingMode(stream);
    writeColoredText(stream, " l", color);
    exitLineDrawingMode(stream);
    writeBufferStream(stream, titleLabel, strlen(titleLabel));
    enterLineDrawingMode(stream);
    writeColoredText(stream, strrepeat("q", times), color);
    writeColoredText(stream, "k", color);
    exitLineDrawingMode(stream);
    writeNewLine(stream);

    for (int i = 0; i < numBodyLines; i++)
    {
        writeLine(stream, bodyLines[i], verticalLine, width);
    }

    if (numFooterLines > 0)
    {
        enterLineDrawingMode(stream);
        writeSpace(stream);
        writeColoredText(stream, "t", color);
        writeColoredText(stream, bottomBorder, color);
        writeColoredText(stream, "u", color);
        exitLineDrawingMode(stream);
        writeNewLine(stream);

        for (int i = 0; i < numFooterLines; i++)
        {
            writeLine(stream, footerLines[i], verticalLine, width);
        }
    }

    enterLineDrawingMode(stream);
    writeSpace(stream);
    writeColoredText(stream, "m", color);
    writeColoredText(stream, bottomBorder, color);
    writeColoredText(stream, "j", color);
    exitLineDrawingMode(stream);

    for (int i = 0; i < numBodyLines; i++)
    {
        free(bodyLines[i]);
    }

    for (int i = 0; i < numFooterLines; i++)
    {
        free(footerLines[i]);
    }
    free(titleLabel);
    free(bottomBorder);
    free(verticalLine);
}
