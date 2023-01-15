/*

MIT License

Copyright (c) 2022 Nikita Gainulin, Georgij Kazimianec, Lukash Patrik Magalinski

IN COLLABORATION WITH TEAM "UFO enjoyers" (Aleksandras Sukelovic, Maksimas
Jaroslavcevas, Oskaras Vistorskis, Kamile Balzekaite)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.



This library creates a custom CSS stylesheet file.

Example usage:

CSS styles;
initCSS(&styles);

Style bodyStyles;
initStyle(&bodyStyles, "h1");


addCSSProperty(&bodyStyles, "display", "flex");
addCSSProperty(&bodyStyles, "justify-content", "center");

pushStyle(&styles, &bodyStyles);

Style bodyStylesB;
initStyle(&bodyStylesB, "h2");

addCSSProperty(&bodyStylesB, "background-color", "red");
addCSSProperty(&bodyStylesB, "outline-color", "green");

pushStyle(&styles, &bodyStylesB);

FILE *fp;
fp = fopen("testing.txt", "w+");
renderCSS(&styles, fp);
fclose(fp);

freeCSS(&styles);

*/

#include "css-generator.h"
#include <stdio.h>
#include <stdlib.h>

#define EXTRA_CAPACITY 8
/*
typedef struct {
    // "div > span\0"
    char *selector;

    // ["display", "justify-content"]
    char **keys;
    // ["flex", "center"]
    char **values;

    // 2
    size_t size;
    size_t capacity;
} Style;

typedef struct {
    Style **styles;
    size_t size;
    size_t capacity;
} CSS;*/

// The function below creates the CSS stylesheet file.
void renderCSS(CSS *css, FILE *stream) {
    for (int i = 0; i < css->size; ++i) {
        fprintf(stream, "%s {\n", css->styles[i]->selector);
        for (int j = 0; j < css->styles[i]->size; ++j) {
            fprintf(stream, "    %s: %s;\n", css->styles[i]->keys[j],
                    css->styles[i]->values[j]);
        }
        fprintf(stream, "}\n\n");
    }
}

// The function below initializes an empty CSS array.
void initCSS(CSS *css) {
    css->capacity = 0;
    css->size = 0;
    css->styles = NULL;
}

// The function below initializes developer's chosen style.
void initStyle(Style *style, char *selector) {
    // Here the developer must indicate, how many properties will the current
    // style contain.
    style->size = 0;
    style->capacity = 0;
    style->keys = NULL;
    style->values = NULL;
    style->selector = selector;
}

// The function below adds the style to the entire CSS array, return 0 if
// success or 1 if error is encountered.
int pushStyle(CSS *css, Style *style) {
    if (css == NULL || style == NULL)
        return 1;

    if (css->size == css->capacity) {
        css->styles = realloc(css->styles, css->size * sizeof(Style) +
                                               EXTRA_CAPACITY * sizeof(Style));
        css->capacity += EXTRA_CAPACITY;
    }

    css->styles[css->size] = style;
    ++css->size;

    return 0;
}

// The function below adds a CSS property to the selector, also returns 0 if
// success or 1 if error is encountered.
int addCSSProperty(Style *style, char *property, char *value) {
    if (property == NULL || value == NULL || style == NULL)
        return 1;

    if (style->size == style->capacity) {

        style->keys = realloc(style->keys, style->size * sizeof(char *) +
                                               EXTRA_CAPACITY * sizeof(char *));
        style->values =
            realloc(style->values, style->size * sizeof(char *) +
                                       EXTRA_CAPACITY * sizeof(char *));
        if (style == NULL)
            return 1;
        style->capacity += EXTRA_CAPACITY;
    }

    style->keys[style->size] = property;
    style->values[style->size] = value;
    ++style->size;

    return 0;
}

// The function below frees all CSS nodes and clears the memory.
void freeCSS(CSS *css) {
    for (int i = 0; i < css->size; ++i) {
        free(css->styles[i]->keys);
        free(css->styles[i]->values);
    }
    free(css->styles);
}
