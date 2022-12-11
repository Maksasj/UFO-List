#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_init_node_1(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_init_node_1("Should return Node pointer with correct values"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite("/cygdrive/c/Programming/c/Ufo-list/modules/html-generator/test/initNode.test.c", gcladosTests0, 1);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 1);
}
