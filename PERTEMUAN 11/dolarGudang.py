def solve_knapsnack(n, w, berat, values):
    dp = [0] * (w + 1)

    for i in range(n):
        for j in range(w, berat[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - berat[i]] + values[i])

    return dp[w]


n, w = map(int, input().split())
berat = list(map(int, input().split()))
values = list(map(int, input().split()))

print(solve_knapsnack(n, w, berat, values))