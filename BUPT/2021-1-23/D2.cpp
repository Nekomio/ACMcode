#include <bits/stdc++.h>
using namespace std;
char c[205][205];
int sum[205][205];
int a[205], b[205];
int main() {
  int n, m, k;
  scanf ("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf ("%s", c[i] + 1);
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      sum[i][j] = c[i][j] - '0';
      sum[i][j] += sum[i - 1][j];
    }
  }
  int pre = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    bool flag = 0;
    int Sum = 0;
    for (int j = 1; j <= m; j++) {
      if (sum[i][j] - sum[pre][j] == 1) {
        Sum++;
      }
      if (sum[i][j] - sum[pre][j] >= 2) {
        flag = 1;
      }
    }
    if (Sum == k) {
      a[++cnt] = i;
      pre = i;
    }
    if (Sum != k && flag) {
      printf ("NO\n");
      exit(0);
    }
    if (cnt == k - 1) {
      flag = 0;
      for (int j = 1; j <= m; j++) {
        if (sum[n][j] - sum[i][j] >= 2) {
          flag = 1;
        }
      }
      if (flag) {
        printf ("NO\n");
        exit(0);
      }
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] = c[i][j] - '0';
      sum[i][j] += sum[i][j - 1];
    }
  }
  pre = 0, cnt = 0;
  for (int j = 1; j <= m; j++) {
    bool flag = 0;
    int Sum = 0;
    for (int i = 1; i <= n; i++) {
      if (sum[i][j] - sum[i][pre] == 1) {
        Sum++;
      }
      if (sum[i][j] - sum[i][pre] >= 2) {
        flag = 1;
      }
    }
    if (Sum == k) {
      b[++cnt] = j;
      pre = j;
    }
    if (Sum != k && flag) {
      printf ("NO\n");
      exit(0);
    }
    if (cnt == k - 1) {
      flag = 0;
      for (int i = 1; i <= n; i++) {
        if (sum[i][m] - sum[i][j] >= 2) {
          flag = 1;
        }
      }
      if (flag) {
        printf ("NO\n");
        exit(0);
      }
      break;
    }
  }
  printf ("YES\n");
  for (int i = 1; i <= k - 1; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
  for (int i = 1; i <= k - 1; i++) {
    printf ("%d ", b[i]);
  }
}