/**
 * @author Aleksandras Sukelovic
 * @date 2023-01-09
 *
 * Module to write HTML and CSS code in files.
 */

#ifndef OUTPUT_FILES_H
#define OUTPUT_FILES_H

#include "css-generator.h"
#include "html-generator.h"

/**
 * Generates html file in docs directory.
 *
 * @param   htmlNode    Pointer to root html node.
 */
void writeHTMLFile(Node *htmlNode);

/**
 * Generates css files in docs directory.
 *
 * @param   css         Pointer to css root node.
 */
void writeCSSFile(CSS *css);

/**
 * Generates js file in docs directory.
 */
void writeJSFile();

#endif
