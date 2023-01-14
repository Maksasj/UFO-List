#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_chashmapHash_ensure_valid_output(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_chashmapHash_ensure_valid_output("chashmapHash generates same output with same input"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite("/cygdrive/c/Users/balka/OneDrive - Vilnius University/propagas/UFO-List/modules/chashmap/test/chashmap.test.c", gcladosTests0, 1);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 1);
}
