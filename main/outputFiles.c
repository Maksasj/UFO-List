#include "outputFiles.h"
#include <string.h>

void throwAllocationFailure() {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(-1);
}

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
        char **jsText;
        jsText[0] = "function registerShowListeners(triggerId, contentId) {\n";
        jsText[1] =
            "	const triggers = document.querySelectorAll(`#${triggerId}`);\n";
        jsText[2] =
            "	const contents = document.querySelectorAll(`#${contentId}`);\n";
        jsText[3] = "	function trigger(element) {\n";
        jsText[4] = "		if (element.classList.contains(\"show\")) {\n";
        jsText[5] = "			element.classList.remove(\"show\");\n";
        jsText[6] = "		} else {\n";
        jsText[7] = "			element.classList.add(\"show\");\n";
        jsText[8] = "		}\n";
        jsText[9] = "	}\n";
        jsText[10] = "	for (let i = 0; i < triggers.length; ++i) {\n";
        jsText[11] =
            "		triggers[i].addEventListener(\"click\", () => {\n";
        jsText[12] = "			trigger(contents[i]);\n";
        jsText[13] = "		});\n";
        jsText[14] = "	}\n";
        jsText[15] = "}\n";
        jsText[16] =
            "registerShowListeners(\"traits-trigger\", \"traits-content\");\n";
        jsText[17] = "registerShowListeners(\"situation-trigger\", "
                     "\"situation-content\");\n";

        fprintf(jsFile, *jsText);

        free(filePath);
    }
}
