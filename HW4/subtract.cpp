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

interval interval::operator-(const interval &b) {
 int x = lo - b.lo;
 int y = lo - b.hi;
 int z = hi - b.lo;
 int w = hi - b.hi;
 if((x < interval::MIN && y < interval::MIN && z < interval::MIN && w < interval::MIN) || 
    (x > interval::MAX && y > interval::MAX && z > interval::MAX && w > interval::MAX)) {
   x = getIntervalValue(x);
   y = getIntervalValue(y);
   z = getIntervalValue(z);
   w = getIntervalValue(w);
 }
 int min=x, max=x;
 if(y < min) min = y;
 if(z < min) min = z;
 if(w < min) min = w;
 if(y > max) max = y;
 if(z > max) max = z;
 if(w > max) max = w;
 if(min >= interval::MIN && max <= interval::MAX)
   return interval(min, max);
 else
   return top();  
}
