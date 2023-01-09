#include "outputFiles.h"
#include <string.h>

void throwAllocationFailure() {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(-1);
}

char *getFilePath(char *outputDir, char *filename) {
    if (outputDir == NULL) {
        char *filePath = malloc(strlen(filename));

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
