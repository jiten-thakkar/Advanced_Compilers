#include "fiveBitTransferFunction.h"
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define bits 5
/*#define maxPossible (pow(2, bits) - 1)
#define maximum maxPossible/2
#define minimum (maximum + 1) * -1*/


using namespace std;

int interval::getIntervalValue(int value) {
 if(value > maximum) {
   int remainder = value % maximum;
   if(remainder != 0) {
     return minimum + remainder - 1;
   } else {
     return 0;
   }
 } else if (value < minimum) {
   int remainder = value % minimum;
   if(remainder != 0) {
     return maximum + remainder + 1;
   } else {
     return 0;
   }
 }
 return value;
}

interval interval::subtract(interval a, interval b) {
 vector<int> values;
 values.push_back(a.lo - b.lo);
 values.push_back(a.lo - b.hi);
 values.push_back(a.hi - b.lo);
 values.push_back(a.hi - b.hi);
 std::sort(values.begin(), values.end());
 if(values[0] < minimum && values[3] > maximum) 
   return interval(minimum, maximum, bits);
 else if(values[0] >= minimum && values[3] <= maximum)
   return interval(values[0], values[3], bits);
 if(values[0] >= minimum) {
   int minimumMax;
   if(values[0] > maximum)
     minimumMax = values[0];
   else if(values[1] > maximum)
     minimumMax = values[1];
   else if(values[2] > maximum)
     minimumMax = values[2];
   else
     minimumMax = values[3];
   return interval(getIntervalValue(minimumMax), maximum, bits);
 } else if(values[3] <= maximum) {
   int maximumMin;
   if(values[3] < minimum)
     maximumMin = values[3];
   else if(values[2] < minimum)
     maximumMin = values[2];
   else if(values[1] < minimum)
     maximumMin = values[1];
   else
     maximumMin = values[0];
   return interval(minimum, getIntervalValue(maximumMin), bits);
 }  
}

interval interval::bitwise_and(interval a, interval b) {
 int x = getIntervalValue(a.lo & b.lo);
 int y = getIntervalValue(a.lo & b.hi);
 int z = getIntervalValue(a.hi & b.lo);
 int w = getIntervalValue(a.hi & b.hi);
 int min=x, max=x;
 if(y > max) max = y;
 else if(y < min) min = y;  
 if(z > max) max = z;
 else if(z < min) min = z;  
 if(w > max) max = w;
 else if(w < min) min = w;
 interval finalInterval(min, max, bits);
 return finalInterval;  
}

/*---------------------------------subtract cases------------------------------------------------*/

void test1() {
 interval a(0, 1, bits);
 interval b(-16, -15, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

void test2() {
 interval a(0, 1, bits);
 interval b(0, 1, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-1, 1, bits));
}

void test3() {
 interval a(-16, 15, bits);
 interval b(-16, 15, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

void test4() {
 interval a(-16, 15, bits);
 interval b(0, 1, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

void test5() {
 interval a(-5, 1, bits);
 interval b(-15, -10, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

void test6() {
 interval a(0, 0, bits);
 interval b(-16, -15, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

void test7() {
 interval a(-4, -3, bits);
 interval b(13, 15, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}

/*------------------------------------------bitwie_and cases--------------------------------*/

void test8() {
 interval a(0, 1, bits);
 interval b(0, 1, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.bitwise_and(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 //assert(result == interval(-1, 1, bits));
}

void test9() {
 interval a(-16, 15, bits);
 interval b(-16, 15, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.bitwise_and(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 //assert(result == interval(-16, 15, bits));
}

void test10() {
 interval a(-16, 15, bits);
 interval b(0, 1, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.bitwise_and(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 //assert(result == interval(-16, 15, bits));
}

void test11() {
 interval a(-5, 1, bits);
 interval b(-15, -10, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.bitwise_and(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 //assert(result == interval(-16, 11, bits));
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  test11();
  return 0;
}
