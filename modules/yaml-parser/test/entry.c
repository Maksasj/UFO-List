#include "gclados.h"
#include <stdbool.h>
extern GcladosTest __gcladosTest_countDigits_ensure_valid_output(char *description);
extern GcladosTest __gcladosTest_yamlStrCat_ensure_valid_output(char *description);
extern GcladosTest __gcladosTest_isArrayElement_ensure_valid_output(char *description);
extern GcladosTest __gcladosTest_countTabs_ensure_valid_output(char *description);
extern GcladosTest __gcladosTest_getKeyFromYamlString_ensure_valid_output(char *description);
extern GcladosTest __gcladosTest_getValueFromYamlString_ensure_valid_output(char *description);

int main() {
    gcladosColors.setColorsSupported(true);
    gcladosSetUpdateSnapshots(false);
    GcladosTest gcladosTests0[] = {
        __gcladosTest_countDigits_ensure_valid_output("Test for 'int countDigits(int value);'"),
        __gcladosTest_yamlStrCat_ensure_valid_output("Test for 'char* yamlStrCat(char *a, char *b);'"),
        __gcladosTest_isArrayElement_ensure_valid_output("Test for 'bool isArrayElement(char* string);'"),
        __gcladosTest_countTabs_ensure_valid_output("Test for 'int countTabs(char* string);'"),
        __gcladosTest_getKeyFromYamlString_ensure_valid_output("Test for 'char* getKeyFromYamlString(char* string);'"),
        __gcladosTest_getValueFromYamlString_ensure_valid_output("Test for 'char* getValueFromYamlString(char* string);'"),
    };
    GcladosTestSuite gcladosTestSuite0 = gcladosCreateTestSuite("/cygdrive/c/Programming/c/Ufo-list/modules/yaml-parser/test/yaml-parser.test.c", gcladosTests0, 6);
    GcladosTestSuite gcladosTestSuites[] = {
        gcladosTestSuite0,
    };
    return gcladosRunTestSuites(gcladosTestSuites, 1);
}
