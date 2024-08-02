#ifndef PROMPTS_H
#define PROMPTS_H

#include <stdio.h>
#include <windows.h>
#include <Shapes.h>
#include <Buffering.h>
#include <Terminal.h>
#include <Cursor.h>

void textPrompt(
            char *title,
            char *footer,
            COORD size);

#endif // PROMPTS_H