import sys
from collections import defaultdict, deque

parents = defaultdict(list)
indegree = defaultdict(int)
childs = defaultdict(list)
answer = defaultdict(list)

# sys.stdin = open("input.txt", "r")

input = sys.stdin.readline

# 사람들의 수
n = int(input())

# 사람들의 이름
people = list(map(str, input().split()))

# 이름 순으로 정렬
people.sort()

# 관계의 수
m = int(input())

for _ in range(m):
    child, parent = tuple(map(str, input().split()))
    # 자식의 부모를 저장
    parents[child].append(parent)
    # 부모의 자식을 저장
    childs[parent].append(child)
    # child를 가르키고 있는 조상의 수
    indegree[child] += 1

roots = []

for p in people:
    # 부모가 없는 경우가 가문의 조상이다.
    if not parents[p]:
        roots.append(p)

# 조상의 수 출력
print(len(roots))
# 조상들 출력
print(*roots)

def topologicalSort(root):
    q = deque([root])

    while q:
        cur = q.popleft()
        for child in childs[cur]:
            indegree[child] -= 1
            # indegree가 0으로 만드는 부모가 직계 부모이다.
            if indegree[child] == 0:
                answer[cur].append(child)
                q.append(child)

for r in roots:
    topologicalSort(r)

for p in people:
    print(p, len(answer[p]), *sorted(answer[p]))