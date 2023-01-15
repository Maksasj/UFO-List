#include "outputFiles.h"
#include "utils.h"
#include <string.h>

char *getFilePath(char *outputDir, char *filename) {
    if (outputDir == NULL) {
        char *filePath = malloc(strlen(filename) + 1);

        if (filePath == NULL) {
            return NULL;
        }

        strcpy(filePath, filename);
        return filePath;
    }

    int outputDirLen = strlen(outputDir);
    int filePathLen = outputDirLen + 1 + strlen(filename) + 1;
    char *filePath = malloc(filePathLen);

    if (filePath == NULL) {
        return NULL;
    }

    strcpy(filePath, outputDir);

    filePath[outputDirLen] = '/';
    filePath[outputDirLen + 1] = '\0';

    strcat(filePath, filename);

    return filePath;
}

void writeHTMLFile(Node *htmlNode, char *outputDir) {
    char *filePath = getFilePath(outputDir, "index.html");

    if (filePath == NULL) {
        throwAllocationFailure();
    }

    FILE *htmlFile = fopen(filePath, "w");

    if (htmlFile != NULL) {
        renderToStream(htmlNode, htmlFile);

        freeNode(htmlNode);
        fclose(htmlFile);
    }

    free(filePath);
}

void writeCSSFile(CSS *css, char *outputDir) {
    char *filePath = getFilePath(outputDir, "styles.css");

    if (filePath == NULL) {
        throwAllocationFailure();
    }

    FILE *cssFile = fopen(filePath, "w");

    if (cssFile != NULL) {
        renderCSS(css, cssFile);

        freeCSS(css);
        fclose(cssFile);
    }

    free(filePath);
}

void writeJSFile(char *outputDir) {
    char *filePath = getFilePath(outputDir, "index.js");

    if (filePath == NULL) {
        throwAllocationFailure();
    }

    FILE *jsFile = fopen(filePath, "w");

    if (jsFile != NULL) {
        char jsText[] =
            "function registerShowListeners(triggerId, contentId) {\n"
            "	const triggers = document.querySelectorAll(`#${triggerId}`);\n"
            "	const contents = document.querySelectorAll(`#${contentId}`);\n"
            "	function trigger(element) {\n"
            "		if (element.classList.contains(\"show\")) {\n"
            "			element.classList.remove(\"show\");\n"
            "		} else {\n"
            "			element.classList.add(\"show\");\n"
            "		}\n"
            "	}\n"
            "	for (let i = 0; i < triggers.length; ++i) {\n"
            "		triggers[i].addEventListener(\"click\", () => {\n"
            "			trigger(contents[i]);\n"
            "		});\n"
            "	}\n"
            "}\n"

            "registerShowListeners(\"traits-trigger\", \"traits-content\");\n"
            "registerShowListeners(\"situation-trigger\", "
            "\"situation-content\");\n";

        fprintf(jsFile, "%s", jsText);

        fclose(jsFile);
        free(filePath);
    }
}
