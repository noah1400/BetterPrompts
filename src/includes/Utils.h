#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Colors.h>

void allocateFailCheck(void *allocatedPointer, const char* allocationTarget);

int longestLine(const char **lines, int n);

int splitLines(const char *text, char *lines[], int n);

char* strrepeat(const char* str, int times);

char* callColor(char *text, const char *color);

#endif // UTILS_H