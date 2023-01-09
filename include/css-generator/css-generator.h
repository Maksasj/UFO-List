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

#ifndef __CSSHEADER_H__
#define __CSSHEADER_H__

#define EXTRA_CAPACITY 8

#include <stddef.h>
#include <stdio.h>

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
} CSS;

void renderCSS(CSS *css, FILE *stream);
void initCSS(CSS *css);
void initStyle(Style *style, char *selector);
int pushStyle(CSS *css, Style *style);
int addCSSProperty(Style *style, char *property, char *value);
void freeCSS(CSS *css);

#endif // __CSSHEADER_H__
