#include "gclados.h"
#include "chashmap.h"
#include "chashmapPrivate.h"

// chashmapHash generates same output with same input 
TEST(chashmapHash_ensure_valid_output) {
    ensure(0, gclados.toBeFalsy());
    ensure(1, gclados.toBeTruthy());
}
