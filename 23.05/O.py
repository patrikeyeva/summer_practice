def pprint(l):
    for i in range(len(l)):
        print(l[i])


n, m, k = input().split()
n = int(n)
m = int(m)
k = int(k)
begin = [int(_) for _ in input().split()]
dp = [[0 for _ in range(k + 1)] for _ in range(m + 1)]
path = [[(0, 0) for _ in range(k + 1)] for _ in range(m + 1)]
for i in range(0, m + 1):
    for j in range(0, k + 1):
        if i == 0 and j == 0:
            continue
        if j > 0 and i > 0:
            dp[i][j] += begin[i + j * 2 - 1]
            if dp[i][j - 1] >= dp[i - 1][j]:
                path[i][j] = (i, j - 1)
                dp[i][j] += dp[i][j - 1]
            else:
                path[i][j] = (i - 1, j)
                dp[i][j] += dp[i - 1][j]
        elif j > 0:
            dp[i][j] += dp[i][j - 1] + begin[i + j * 2 - 1]
            path[i][j] = (i, j - 1)
        elif i > 0:
            path[i][j] = (i - 1, j)
            dp[i][j] += dp[i - 1][j] + begin[i + j * 2 - 1]

print(dp[m][k])
res = []
cur = path[m][k]
res.append(n)
while cur != (0, 0):
    res.append(cur[0] + cur[1]*2)
    cur = path[cur[0]][cur[1]]
res.append(0)

for _ in reversed(res):
    print(_, end=' ')
print()
