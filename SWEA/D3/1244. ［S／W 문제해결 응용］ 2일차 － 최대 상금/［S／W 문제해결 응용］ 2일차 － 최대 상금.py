from itertools import combinations as comb
def dfs(swap):
    global ans
    if swap == n:
        ans = max(ans, int(''.join(card)))
        return

    for i, j in comb(range(l), 2):
        card[i], card[j] = card[j], card[i]
        if (swap, ''.join(card)) not in s:
            dfs(swap+1)
            s.add((swap, ''.join(card)))
        card[i], card[j] = card[j], card[i]

T = int(input())
for tc in range(1, T+1):
    card, n = map(int, input().split())
    card = list(str(card))
    l = len(card)

    s = set()
    ans = 0
    dfs(0)
    s.clear()

    print(f'#{tc} {ans}')