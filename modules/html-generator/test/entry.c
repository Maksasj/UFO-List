#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_init_node_1(char *description);
extern GcladosTest __gcladosTest_init_node_2(char *description);
extern GcladosTest __gcladosTest_push_children_1(char *description);
extern GcladosTest __gcladosTest_push_children_2(char *description);
extern GcladosTest __gcladosTest_push_children_3(char *description);
extern GcladosTest __gcladosTest_string_literal_1(char *description);
extern GcladosTest __gcladosTest_string_literal_2(char *description);
extern GcladosTest __gcladosTest_string_literal_3(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_init_node_1(
            "Should return Node pointer with correct values"),
        __gcladosTest_init_node_2(
            "Should return NULL if tag or attributes are NULL"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite(
        "/cygdrive/c/Git/UFO-List/modules/html-generator/test/initNode.test.c",
        gcladosTests0, 2);
    GcladosTest gcladosTests1[] = {
        __gcladosTest_push_children_1(
            "Should push children node in parent correctly"),
        __gcladosTest_push_children_2(
            "Should return NULL if one of the arguments is NULL"),
        __gcladosTest_push_children_3(
            "Should return NULL if parentNode of type STRING_LITERAL"),
    };
    GcladosTestSuite gcladosTestSuite1 =
        gcladosCreateTestSuite("/cygdrive/c/Git/UFO-List/modules/"
                               "html-generator/test/pushChildrenNode.test.c",
                               gcladosTests1, 3);
    GcladosTest gcladosTests2[] = {
        __gcladosTest_string_literal_1(
            "Should set attributes in format value=..."),
        __gcladosTest_string_literal_2(
            "Should do nothing if one of the arguments is NULL"),
        __gcladosTest_string_literal_3("Should do nothing if trying to push "
                                       "string literal node in string literal"),
    };
    GcladosTestSuite gcladosTestSuite2 =
        gcladosCreateTestSuite("/cygdrive/c/Git/UFO-List/modules/"
                               "html-generator/test/pushStringLiteral.test.c",
                               gcladosTests2, 3);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
        gcladosTestSuite1,
        gcladosTestSuite2,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 3);
}
