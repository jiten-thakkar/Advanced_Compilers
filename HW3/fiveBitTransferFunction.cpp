#include "fiveBitTransferFunction.h"
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define bits 5

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
 int x = a.lo - b.lo;
 int y = a.lo - b.hi;
 int z = a.hi - b.lo;
 int w = a.hi - b.hi;
 if((x < minimum && y < minimum && z < minimum && w < minimum) || 
    (x > maximum && y > maximum && z > maximum && w > maximum)) {
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
   int newLow = getIntervalValue(minimumMax); 
   for(int i=0; i<4; i++)
     if(values[i] >= minimum && values[i] < newLow)
       newLow = values[i];
   return interval(newLow, maximum, bits);
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
   int newMax = getIntervalValue(maximumMin);
   for(int i=0; i<4; i++) 
     if(values[i] <= maximum && values[i] > newMax)
       newMax = values[i];
   return interval(minimum, newMax, bits);
 }  
}

interval interval::bitwise_and(interval a, interval b) {
     
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



void test8() {
 interval a(-16, 0, bits);
 interval b(-15, 3, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 assert(result == interval(-16, 15, bits));
}


void test9() {
 interval a(-16, -15, bits);
 interval b(3, 4, bits);
 cout << "a:lo, a:hi :: " << a.getLo() << " " << a.getHi() << endl;
 cout << "b:lo, b:hi :: " << b.getLo() << " " << b.getHi() << endl;
 interval result = a.subtract(a, b);
 cout << "result:lo, result:hi :: " << result.getLo() << " " << result.getHi() << endl;
 //assert(result == interval(-16, 15, bits));
}

/*------------------------------------------bitwie_and cases--------------------------------*/

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
