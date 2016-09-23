#include "interval.h"

using namespace std;

static int getIntervalValue(int value) {
 if(value > interval::MAX) {
   int remainder = value % interval::MAX;
   if(remainder != 0) {
     return interval::MIN + remainder - 1;
   } else {
     return 0;
   }
 } else if (value < interval::MIN) {
   int remainder = value % interval::MIN;
   if(remainder != 0) {
     return interval::MAX + remainder + 1;
   } else {
     return 0;
   }
 }
 return value;
}

interval interval::operator&(const interval &b) {
  if((lo == 0 && hi == 0) || (b.lo == 0 && b.hi == 0)) 
    return interval(0, 0);
  if(lo == hi && b.lo == b.hi)
    return interval(lo & b.lo, hi & b.hi);
  bool negative = false;
  bool positive = false;
  if((lo < 0 || hi < 0) && (b.lo < 0 || b.hi < 0))
    negative = true;
  if(lo > 0 || hi > 0 || b.lo > 0 || b.hi > 0)
    positive = true;     
  if(negative && positive)
    return top();
  else if (negative)
    return interval(interval::MIN, 0);
  else if(positive)
    return interval(0, interval::MAX);
  else
    return top();
}

