ans = 1;
n = input();
for i in range(1, n + 1):
	ans = ans * (4 * i - 2) / (i + 1)
print ans