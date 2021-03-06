#include <algorithm>
#include "kth.h"
using std::min;

int Query_lastans(int m, int a, int b, int c, int x, int y, int z)
{
  if (m == a) {
    return min(get_a(x + 1), min(b, c));
  } else if (m == b) {
    return min(get_b(y + 1), min(a, c));
  } else if (m == c) {
    return min(get_c(z + 1), min(a, b));
  }
  return -1;
}
int Query(int x, int y, int z, int k) {
  int l = k / 3;
  int a = get_a(x + l), b = get_b(y + l), c = get_c(z + l),
      m = min(a, min(b, c));
  if (l == 0) {
    if (k == 0) {
      return m;
    } else if (k == 1) {
      return Query_lastans(m, a, b, c, x, y, z);
    } else if (k == 2) {
      if (m == a) {
        x++, a = get_a(x);
      } else if (m == b) {
        y++, b = get_b(y);
      } else {
        z++, c = get_c(z);
      }
      m = min(a, min(b, c));
      return Query_lastans(m, a, b, c, x, y, z);
    }
  }
  if (m == a) x += l;
  else if (m == b) y += l;
  else z += l;
  return Query(x, y, z, k - l);
}

int query_kth(int n_a, int n_b, int n_c, int k) { return Query(0, 0, 0, k - 1); }
