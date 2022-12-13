#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_free_node_1(char *description);
extern GcladosTest __gcladosTest_init_node_1(char *description);
extern GcladosTest __gcladosTest_push_children_1(char *description);
extern GcladosTest __gcladosTest_string_literal_1(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_free_node_1("free_node_1"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite("/cygdrive/c/Users/balka/OneDrive - Vilnius University/propagas/UFO-List/UFO-List/modules/html-generator/test/freeNode.test.c", gcladosTests0, 1);
    GcladosTest gcladosTests1[] = {
        __gcladosTest_init_node_1("Should return Node pointer with correct values"),
    };
    GcladosTestSuite gcladosTestSuite1 = gcladosCreateTestSuite("/cygdrive/c/Users/balka/OneDrive - Vilnius University/propagas/UFO-List/UFO-List/modules/html-generator/test/initNode.test.c", gcladosTests1, 1);
    GcladosTest gcladosTests2[] = {
        __gcladosTest_push_children_1("push_children_1"),
    };
    GcladosTestSuite gcladosTestSuite2 = gcladosCreateTestSuite("/cygdrive/c/Users/balka/OneDrive - Vilnius University/propagas/UFO-List/UFO-List/modules/html-generator/test/pushChildrenNode.test.c", gcladosTests2, 1);
    GcladosTest gcladosTests3[] = {
        __gcladosTest_string_literal_1("string_literal_1"),
    };
    GcladosTestSuite gcladosTestSuite3 = gcladosCreateTestSuite("/cygdrive/c/Users/balka/OneDrive - Vilnius University/propagas/UFO-List/UFO-List/modules/html-generator/test/pushStringLiteral.test.c", gcladosTests3, 1);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
        gcladosTestSuite1,
        gcladosTestSuite2,
        gcladosTestSuite3,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 4);
}
