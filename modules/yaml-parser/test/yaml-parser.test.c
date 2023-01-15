#include "gclados.h"
#include "yaml-parser.h"

// Test for 'int countDigits(int value);'
TEST(countDigits_ensure_valid_output) {
    ensure(countDigits(1), gclados.toEqualInt(1));
    ensure(countDigits(10), gclados.toEqualInt(2));
    ensure(countDigits(100), gclados.toEqualInt(3));
    ensure(countDigits(1000), gclados.toEqualInt(4));
    ensure(countDigits(10000), gclados.toEqualInt(5));

    ensure(countDigits(9), gclados.toEqualInt(1));
    ensure(countDigits(12), gclados.toEqualInt(2));
    ensure(countDigits(193), gclados.toEqualInt(3));
    ensure(countDigits(9871), gclados.toEqualInt(4));
    ensure(countDigits(99999), gclados.toEqualInt(5));
}

// Test for 'char* yamlStrCat(char *a, char *b);'
TEST(yamlStrCat_ensure_valid_output) {
    char* string1 = yamlStrCat("Hello", "World");
    ensure(strlen(string1), gclados.toEqualInt(10));

    char* string2 = yamlStrCat("Hi", "");
    ensure(strlen(string2), gclados.toEqualInt(2));

    char* string3 = yamlStrCat("", "Za warudo");
    ensure(strlen(string3), gclados.toEqualInt(9));
}

// Test for 'bool isArrayElement(char* string);'
TEST(isArrayElement_ensure_valid_output) {
    ensure(isArrayElement("    - randomValue"), gclados.toBeTruthy());
    ensure(isArrayElement("    randomKey:randomValue"), gclados.toBeFalsy());
}

// Test for 'int countTabs(char* string);'
TEST(countTabs_ensure_valid_output) {
    ensure(countTabs("    Poggers:Key"), gclados.toEqualInt(1));
    ensure(countTabs("        Poggers:Key"), gclados.toEqualInt(2));
    ensure(countTabs("            Poggers:Key"), gclados.toEqualInt(3));
}

// Test for 'char* getKeyFromYamlString(char* string);'
TEST(getKeyFromYamlString_ensure_valid_output) {
    char* string1 = getKeyFromYamlString("    key1:value1");
    ensure(strlen(string1), gclados.toEqualInt(4));

    char* string2 = getKeyFromYamlString("    anotherkey:value2");
    ensure(strlen(string2), gclados.toEqualInt(10));

    char* string3 = getKeyFromYamlString("    anotheranotherkey:value2");
    ensure(strlen(string3), gclados.toEqualInt(17));
}

// Test for 'char* getValueFromYamlString(char* string);'
TEST(getValueFromYamlString_ensure_valid_output) {
    char* string1 = getValueFromYamlString("    key1:value1");
    ensure(strlen(string1), gclados.toEqualInt(6));

    char* string2 = getValueFromYamlString("    anotherkey:value1butnotvalue1");
    ensure(strlen(string2), gclados.toEqualInt(18));

    char* string3 = getValueFromYamlString("    anotheranotherkey:anotheranothervalue");
    ensure(strlen(string3), gclados.toEqualInt(19));
}
