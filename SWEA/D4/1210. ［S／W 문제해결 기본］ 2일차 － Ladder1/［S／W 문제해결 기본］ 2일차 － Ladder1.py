def bf(i, j):
    x = i
    y = j

    while x < 99:
        if y > 0 and data[x][y-1] == 1: # left
            while y > 0 and data[x][y-1] == 1:
                y -= 1
            x += 1
        elif 99 > y and data[x][y+1] == 1: # right
            while y < 99 and data[x][y+1] == 1:
                y += 1
            x += 1
        else: # down
            x += 1

    return data[x][y]

for tc in range(10):
    T = int(input())
    data = [list(map(int, input().split())) for _ in range(100)]

    for start in range(100):
        if data[0][start] == 0:
            continue

        x = 0
        y = start
        while x < 99:
            if y > 0 and data[x][y - 1] == 1:  # left
                while y > 0 and data[x][y - 1] == 1:
                    y -= 1
                x += 1
            elif 99 > y and data[x][y + 1] == 1:  # right
                while y < 99 and data[x][y + 1] == 1:
                    y += 1
                x += 1
            else:  # down
                x += 1

        if data[x][y] == 2:
            print(f'#{tc+1} {start}')
            break