import bisect

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

da = dict().fromkeys([i for i in range(n + 1)], -1)
db = dict().fromkeys([i for i in range(n + 1)], -1)

for i in range(n):
    da[a[i]] = i
    db[b[i]] = i

arr = []
for i in range(n):
    arr.append(db[a[i]])

lis = []
for i in range(n):
    if not lis:
        lis.append(arr[i])
    else:
        if arr[i] > lis[-1]:
            lis.append(arr[i])
        else:
            idx = bisect.bisect_left(lis, arr[i])
            lis[idx] = arr[i]
            
print(len(lis))