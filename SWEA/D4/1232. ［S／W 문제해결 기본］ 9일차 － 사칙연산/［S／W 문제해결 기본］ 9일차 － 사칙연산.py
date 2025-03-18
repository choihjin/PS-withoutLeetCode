def postorder(n):
    if n:
        postorder(left[n])
        postorder(right[n])
        if tree[n] == '+':
            tree[n] = int(tree[left[n]]) + int(tree[right[n]])
        elif tree[n] == '-':
            tree[n] = int(tree[left[n]]) - int(tree[right[n]])
        elif tree[n] == '*':
            tree[n] = int(tree[left[n]]) * int(tree[right[n]])
        elif tree[n] == '/':
            tree[n] = int(tree[left[n]]) // int(tree[right[n]])

for tc in range(1, 11):
    n = int(input())
    tree = [0] * (n+1)
    left = [0] * (n+1)
    right = [0] * (n+1)

    for i in range(n):
        tmp = input().split()
        tree[int(tmp[0])] = tmp[1]
        if len(tmp) == 4:
            left[int(tmp[0])] = int(tmp[2])
            right[int(tmp[0])] = int(tmp[3])

    postorder(1)
    print(f'#{tc} {tree[1]}')