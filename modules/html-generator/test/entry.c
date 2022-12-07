#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_test_zero_values_1(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_test_zero_values_1("Hello"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite("./html-generator.test.c", gcladosTests0, 1);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 1);
}
