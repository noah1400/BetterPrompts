#include <Shapes.h>

#define MAX_LINES 100


void Box(char *title,
            char *body,
            char *footer,
            char *color,
            char *info,
            COORD size)
{
    hideCursor();
    int minWidth = min(size.X, 60);

    char *bodyLines[MAX_LINES];
    char *footerLines[MAX_LINES];

    int numBodyLines = splitLines(body, bodyLines, MAX_LINES);
    int numFooterLines = splitLines(footer, footerLines, MAX_LINES);

    const char *allLines[MAX_LINES*2];
    int numAllLines = 0;

    for (int i = 0; i < numBodyLines; i++) {
        allLines[numAllLines] = bodyLines[i];
        numAllLines++;
    }

    for (int i = 0; i < numFooterLines; i++) {
        allLines[numAllLines] = footerLines[i];
        numAllLines++;
    }

    allLines[numAllLines] = title;
    numAllLines++;
    int width = longestLine(allLines, numAllLines);

    
    int titleLength = strlen(title);
    char *titleLabel = NULL;
    titleLabel = (char *)malloc(titleLength + 2 /* space left and right */ + 1 /* null terminator */);
    allocateFailCheck(titleLabel, "titleLabel");
    sprintf(titleLabel, " %s ", title);



    int times = width - titleLength + (titleLength > 0 ? 0 : 2);
    char *topBorder = strrepeat("q", times);
    char *coloredTopBorder = callColor(topBorder, color);
    free(topBorder);
    char *bottomBorder = strrepeat("q", width+(titleLength > 0 ? 2 : 0));
    char *coloredBottomBorder = callColor(bottomBorder, color);
    free(bottomBorder);
    char *coloredTopRight = callColor("k", color);
    char *coloredTopLeft = callColor(" l", color);
    char *coloredBottomLeft = callColor("m", color);
    char *coloredBottomRight = callColor("j", color);
    char *verticalLine = callColor("x", color);

    printf(ESC "(0"); // Enter line drawing mode
    printf("%s", coloredTopLeft);
    printf(ESC "(B"); // Exit line drawing mode
    printf("%s", titleLabel);
    printf(ESC "(0"); // Enter line drawing mode
    printf("%s", coloredTopBorder);
    printf("%s", coloredTopRight);
    printf(ESC "(B"); // Exit line drawing mode
    printf("\n");

    for (int i = 0; i < numBodyLines; i++) {
        printf(ESC "(0"); // Enter line drawing mode
        printf(" %s ", verticalLine); // Left border
        printf(ESC "(B"); // Exit line drawing mode
        printf("%s ", bodyLines[i]);
        printf(ESC "(0"); // Enter line drawing mode
        printf("%*s", width - strlen(bodyLines[i]) + strlen(verticalLine), verticalLine); // Right border
        printf(ESC "(B"); // Exit line drawing mode
        printf("\n");
    }

    printf(ESC "(0"); // Enter line drawing mode
    printf(" %s", coloredBottomLeft);
    printf("%s", coloredBottomBorder);
    printf("%s", coloredBottomRight);
    printf(ESC "(B"); // Exit line drawing mode


    for (int i = 0; i < numBodyLines; i++) {
        free(bodyLines[i]);
    }

    for (int i = 0; i < numFooterLines; i++) {
        free(footerLines[i]);
    }
    free(coloredTopLeft);
    if (titleLength > 0) {
        free(titleLabel);
    }
    free(coloredTopBorder);
    free(coloredBottomBorder);
    free(coloredTopRight);
    free(verticalLine);

}