#include "gclados.h"
#include "chashmap.h"

// Hello poggers
TEST(test_zero_values_1) {
    ensure(0, gclados.toBeFalsy());
    ensure(1, gclados.toBeTruthy());
}
