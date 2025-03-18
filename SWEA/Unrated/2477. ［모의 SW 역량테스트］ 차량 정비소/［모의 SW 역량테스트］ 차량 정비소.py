import queue
T = int(input())
for tc in range(1, T+1):
    n, m, k, a, b = map(int, input().split())
    reception_time = list(map(int, input().split()))
    repair_time = list(map(int, input().split()))
    arrive_time = list(map(int, input().split()))

    reception_waiting = queue.Queue()
    reception_desk = [-1] * n
    repair_waiting = queue.Queue()
    repair_desk = [-1] * m

    t = 0 # current time
    reception_timer = [-1] * n
    repair_timer = [-1] * m
    ans = []
    cnt = 0
    while 1:
        # update timer
        for i in range(n):
            if reception_timer[i] > 0:
                reception_timer[i] -= 1
        for i in range(m):
            if repair_timer[i] > 0:
                repair_timer[i] -= 1

        # arrive customer
        for i in range(k):
            if arrive_time[i] > t:
                break
            if arrive_time[i] == t:
                reception_waiting.put(i+1)

        # out reception desk
        while 0 in reception_timer:
            idx = reception_timer.index(0)
            tmp = reception_desk[idx]
            repair_waiting.put(tmp)
            reception_timer[idx] = -1 # empty
            reception_desk[idx] = -1

        # in reception desk
        while -1 in reception_desk and not reception_waiting.empty():
            idx = reception_desk.index(-1)
            reception_desk[idx] = reception_waiting.get()
            reception_timer[idx] = reception_time[idx]
            if idx+1 == a:
                ans.append(reception_desk[idx])

        # out repair desk
        while 0 in repair_timer:
            idx = repair_timer.index(0)
            repair_timer[idx] = -1 # empty
            repair_desk[idx] = -1

        # in repair desk
        while -1 in repair_desk and not repair_waiting.empty():
            idx = repair_desk.index(-1)
            repair_desk[idx] = repair_waiting.get()
            repair_timer[idx] = repair_time[idx]
            if idx+1 != b and repair_desk[idx] in ans:
                ans.remove(repair_desk[idx])
            cnt += 1

        if cnt == k:
            break
        t += 1

    res = sum(ans)
    if res == 0:
        res = -1
    print(f'#{tc} {res}')