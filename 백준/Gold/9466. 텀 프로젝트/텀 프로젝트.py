import sys
input = sys.stdin.readline

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        # 1-indexed 배열을 위해 앞에 더미 값 0을 추가
        arr = [0] + list(map(int, input().split()))
        state = [0] * (n + 1)
        
        # 각 정점을 순회하며 사이클 여부 판별
        for i in range(1, n + 1):
            if state[i] == 0:
                cur = i
                while True:
                    state[cur] = i
                    cur = arr[cur]
                    
                    # 현재 탐색에서 다시 i가 나오면 사이클 형성
                    if state[cur] == i:
                        while state[cur] != -1:
                            state[cur] = -1
                            cur = arr[cur]
                        break
                    # 이미 방문 기록이 있다면 사이클이 아님
                    elif state[cur] != 0:
                        break
        
        # 사이클에 속하지 않는 노드 개수를 세기
        count = sum(1 for i in range(1, n + 1) if state[i] != -1)
        print(count)

if __name__ == '__main__':
    main()
