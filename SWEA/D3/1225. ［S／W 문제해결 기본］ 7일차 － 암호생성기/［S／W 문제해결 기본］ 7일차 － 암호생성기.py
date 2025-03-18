import queue
T = 10
for tc in range(1, T+1):
    tmp = input()
    data = list(map(int, input().split()))
    q = queue.Queue()
    for i in data:
        q.put(i)

    while(q.queue[-1] != 0):
        for i in range(1, 6):
            cur = q.get()
            if cur - i <= 0:
                q.put(0)
                break
            q.put(cur - i)

    print(f'#{tc}', ' '.join(map(str, list(q.queue)[:9])))