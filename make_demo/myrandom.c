#include <stdlib.h>
#include "myrandom.h"

float myrandomf(float x) {
  return x*(float) rand()/(float)RAND_MAX;
}
