#include <algorithm>
#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ta = a, tb = b, tc = c;
  set<int> ans;
  ans.insert(c);
  while (b > 0 && c > 0) // c->a,a->b
  {
    c -= a;
    if (b >= a) {
      b -= a;
      ans.insert(c);
    }
  }
  c = tc, b = tb, a = ta;
  if (c >= b) // c->b
  {
    c -= b;
  } else {
    b = c;
    c = 0;
  }
  ans.insert(c);
  while (b > 0 && c <= tc) // b->a,a->c
  {
    b -= a;
    c += a;
    if (c <= tc)
      ans.insert(c);
  }
  int p = ans.size();
  int cnt = 0;
  for (set<int>::iterator it = ans.begin(); it != ans.end(); it++, cnt++) {
    printf("%d%c", *it, cnt == p - 1 ? '\n' : ' ');
  }
  return 0;
}
