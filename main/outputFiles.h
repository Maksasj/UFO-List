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
 * @param   htmlNode    Pointer to root html node.
 * @param   outputDir   Directory where to output "index.html" file. If this
 * parameter is NULL, file will be written to the current execution directory.
 */
void writeHTMLFile(Node *htmlNode, char *outputDir);

/**
 * @param   css         Pointer to css root node.
 * @param   outputDir   Directory where to output "styles.css" file. If this
 * parameter is NULL, file will be written to the current execution directory.
 */
void writeCSSFile(CSS *css, char *outputDir);

#endif
