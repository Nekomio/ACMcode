#include <bits/stdc++.h>
using namespace std;
struct F{
  int a, b;
  F(int _a = 0, int _b = 1): a(_a), b(_b) {}
  void operator = (int c) {
    a = c, b = 1;
  }
  F operator + (const F &c) {
    int _b = b * c.b;
    int _a = a * c.b + c.a * b;
    if (_a != 0) {
      int gcd = __gcd(abs(_a), abs(_b));
      _a /= gcd, _b /= gcd;
    } else {
      _b = 1;
    }
    return F(_a, _b);
  }
  F operator * (const F &c) {
    int _a = a * c.a, _b = b * c.b;
    if (_a != 0) {
      int gcd = __gcd(abs(_a), abs(_b));
      _a /= gcd, _b /= gcd;
    } else {
      _b = 1;
    }
    return F(_a, _b);
  }
  F operator - (const F &c) {
    int _b = b * c.b;
    int _a = a * c.b - c.a * b;
    if (_a != 0) {
      int gcd = __gcd(abs(_a), abs(_b));
      _a /= gcd, _b /= gcd;
    } else {
      _b = 1;
    }
    return F(_a, _b);
  }
}a[100][100], b;
char s[10];
int main() {
  int n, m, t;
  scanf ("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf ("%d", &t);
      a[i][j] = t;
    }
    a[i][i + m] = 1;
  }
  int x, y;
  while (1) {
    scanf ("%s", s);
    if (s[0] == '+') {
      scanf ("%d%d%d%d", &x, &y, &b.a, &b.b);
      for (int i = 1; i <= 2 * m; i++) {
        a[x][i] = a[x][i] + a[y][i] * b;
      }
    } else if (s[0] == '-') {
      scanf ("%d%d%d%d", &x, &y, &b.a, &b.b);
      for (int i = 1; i <= 2 * m; i++) {
        a[x][i] = a[x][i] - a[y][i] * b;
      }
    } else if (s[0] == '*') {
      scanf ("%d%d%d", &x, &b.a, &b.b);
      for (int i = 1; i <= 2 * m; i++) {
        a[x][i] = a[x][i] * b;
      }
    } else if (s[0] == 'p') {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          printf ("%d/%d ", a[i][j].a, a[i][j].b);
        }
        printf ("\n");
      }
      printf ("\n");
      // for (int i = 1; i <= n; i++) {
      //   for (int j = m + 1; j <= 2 * m; j++) {
      //     printf ("%d/%d ", a[i][j].a, a[i][j].b);
      //   }
      //   printf ("\n");
      // }
    } else if (s[0] == 's') {
      scanf("%d%d", &x, &y);
      for (int i = 1; i <= m; i++)
        swap(a[x][i], a[y][i]);
    }
  }
}