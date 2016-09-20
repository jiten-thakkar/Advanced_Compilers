#include <iostream>
#include <math.h>

class interval {
  // 5-bit signed intervals: valid values for lo and hi are -16..15 and it is
  // required that hi >= lo. the bounds are inclusive.
  int lo, hi;
  int bits;
  int maximum, minimum, maxPossible;

public:
  interval(int low, int high, int bits):lo(low), hi(high), bits(bits) {
   maxPossible = pow(2, bits) - 1;
   maximum = maxPossible/2;
   minimum = (maximum + 1) * -1;
  };
  // these functions must trigger an assertion violation when presented with any
  // invalid interval, and must never return an invalid interval

  // requirement: be sound and fully precise
  // the second argument is to be subtracted from the first
  interval subtract(interval, interval);

  // requirement: be sound and don't always return top
  interval bitwise_and(interval, interval);

  int getIntervalValue(int);
   
  int getLo() {return lo;}
  int getHi() {return hi;}
  
  bool operator==(interval i) {
    return lo == i.getLo() && hi == i.getHi();
  }
};
