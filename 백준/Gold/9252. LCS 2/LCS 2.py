s1 = input()
s2 = input()
dp = [[[0, ""] for _ in range(len(s2) + 1)] for _ in range(len(s1) + 1)]
# dp[i][j] : s1 i번째와 s2 j 번째까지 LCS

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2)+1):
        if s1[i-1] == s2[j-1]:
            dp[i][j][0] = dp[i-1][j-1][0] + 1
            dp[i][j][1] = dp[i-1][j-1][1] + s1[i-1]
        else:
            if dp[i-1][j][0] < dp[i][j-1][0]:
                dp[i][j][0] = dp[i][j-1][0]
                dp[i][j][1] = dp[i][j-1][1]
            else:
                dp[i][j][0] = dp[i-1][j][0]
                dp[i][j][1] = dp[i-1][j][1]

print(dp[len(s1)][len(s2)][0])
print(dp[len(s1)][len(s2)][1])