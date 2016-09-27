#include "interval.h"
#include <assert.h>

using namespace std;

void test1() {
 interval a(0, 1);
 interval b(-16, -15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test2() {
 interval a(0, 1);
 interval b(0, 1);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-1, 1));
}

void test3() {
 interval a(-16, 15);
 interval b(-16, 15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test4() {
 interval a(-16, 15);
 interval b(0, 1);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test5() {
 interval a(-5, 1);
 interval b(-15, -10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test6() {
 interval a(0, 0);
 interval b(-16, -15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test7() {
 interval a(-4, -3);
 interval b(13, 15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test8() {
 interval a(-16, 0);
 interval b(-15, 3);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}


void test9() {
 interval a(-16, -15);
 interval b(3, 4);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "subtract result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(12, 14));
}

void test10() {
 interval a(-16, 15);
 interval b(0, 1);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(0, 15));
}

void test11() {
 interval a(-5, 1);
 interval b(-15, -10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.hi << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test12() {
 interval a(-5, -1);
 interval b(-15, -10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 0));
}

void test13() {
 interval a(-5, -1);
 interval b(10, 15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(0, 15));
}

void test14() {
 interval a(-5, 1);
 interval b(-15, 10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
}

void test15() {
 interval a(1, 5);
 interval b(10, 15);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(0, 15));
}

void test16() {
 interval a(0, 10);
 interval b(-15, -10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(0, 15));
}

void test17() {
 interval a(0, 0);
 interval b(-15, -10);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a & b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(0, 0));
}

void test18() {
 interval a(-16, -16);
 interval b(-16, 2);
 cout << "a:lo, a:hi :: " << a.lo << " " << a.hi << endl;
 cout << "b:lo, b:hi :: " << b.lo << " " << b.hi << endl;
 interval result = a - b;
 cout << "bitwise_and result:lo, result:hi :: " << result.lo << " " << result.hi << endl;
 assert(result == interval(-16, 15));
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
  test12();
  test13();
  test14();
  test15();
  test16();
  test17();
  test18();
  return 0;
}
