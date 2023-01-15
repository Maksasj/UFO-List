#include "outputFiles.h"
#include "utils.h"
#include <string.h>

char *getFilePath(char *filename) {
    char outputDir[] = "docs";

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

void writeHTMLFile(Node *htmlNode) {
    char *filePath = getFilePath("index.html");

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

void writeCSSFile(CSS *css) {
    char *filePath = getFilePath("styles.css");

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

void writeJSFile() {
    char *filePath = getFilePath("index.js");

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
