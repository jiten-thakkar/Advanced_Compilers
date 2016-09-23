#include "interval.h"
#include <vector>

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
 vector<int> values;
 values.push_back(x);
 values.push_back(y);
 values.push_back(z);
 values.push_back(w);
 std::sort(values.begin(), values.end());
 if(values[0] >= interval::MIN && values[3] <= interval::MAX)
   return interval(values[0], values[3]);
 else
   return top();  
}
