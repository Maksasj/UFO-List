#include "gclados.h"
#include "yaml-parser.h"

// chashmapHash generates same output with same input 
TEST(chashmapHash_ensure_valid_output) {
    ensure(0, gclados.toBeFalsy());
    ensure(1, gclados.toBeTruthy());
}
