
#include <Utils.h>


#define UNKNOWN_ERROR -1
#define MEMORY_ALLOC_ERROR -2
#define UNKNOWN_COLOR -3

void allocateFailCheck(void *allocatedPointer, const char* allocationTarget)
{
    if (allocatedPointer == NULL) {
        printf("Unable to allocate memory for %s.", allocationTarget);
        exit(MEMORY_ALLOC_ERROR);
    }
}

int longestLine(const char **lines, int n)
{
    int longest = 0;
    for (int i = 0; i < n; i++) {
        int length = strlen(lines[i]);
        if (length > longest) {
            longest = length;
        }
    }
    return longest;
}

int splitLines(const char *text, char *lines[], int maxLines) {
    int numLines = 0;
    char *textCopy = strdup(text); // Create a mutable copy of the string
    allocateFailCheck(textCopy, "textCopy");
    
    char *token = strtok(textCopy, "\n");
    while (token != NULL && numLines < maxLines) {
        lines[numLines] = strdup(token); // Still need to duplicate for each line
        if (!lines[numLines]) {
            fprintf(stderr, "Memory allocation error in splitLines\n");
            free(textCopy); // Free the copy before returning
            return -1; // Indicate an error
        }
        numLines++;
        token = strtok(NULL, "\n");
    }
    free(textCopy); // Free the copy after use
    return numLines;
}

char* strrepeat(const char* str, int times) {
    if (times <= 0) { 
        return strdup(""); // Handle zero or negative repetitions
    }

    size_t str_len = strlen(str);
    size_t new_len = str_len * times;
    char* result = (char*)malloc(new_len + 1); // +1 for the null terminator

    allocateFailCheck(result, "strrepeat");

    for (int i = 0; i < times; i++) {
        strcpy(result + i * str_len, str); // Copy the string at the appropriate offset
    }
    result[new_len] = '\0'; // Null-terminate the resulting string

    return result; // Caller responsible for freeing the result
}

char* callColor(char *text, const char *color)
{
    // check color strings and switch over them
    // call the appropriate function with the text
    // return the result
    if (strcmp(color, "reset") == 0) {
        return reset(text);
    } else if (strcmp(color, "bold") == 0) {
        return bold(text);
    } else if (strcmp(color, "dim") == 0) {
        return dim(text);
    } else if (strcmp(color, "italic") == 0) {
        return italic(text);
    } else if (strcmp(color, "underline") == 0) {
        return underline(text);
    } else if (strcmp(color, "inverse") == 0) {
        return inverse(text);
    } else if (strcmp(color, "black") == 0) {
        return black(text);
    } else if (strcmp(color, "red") == 0) {
        return red(text);
    } else if (strcmp(color, "green") == 0) {
        return green(text);
    } else if (strcmp(color, "yellow") == 0) {
        return yellow(text);
    } else if (strcmp(color, "blue") == 0) {
        return blue(text);
    } else if (strcmp(color, "magenta") == 0) {
        return magenta(text);
    } else if (strcmp(color, "cyan") == 0) {
        return cyan(text);
    } else if (strcmp(color, "white") == 0) {
        return white(text);
    } else {
        printf("Unknown color: %s\n", color);
        exit(UNKNOWN_COLOR);
    }
}