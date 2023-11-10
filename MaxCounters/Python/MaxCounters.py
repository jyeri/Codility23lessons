# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(N, A):
    res = [0] * N
    maxim = 0
    increase = 0
    M = len(A)
    # for every element in array size
    for x in range(M):
        # if its single incrementation
        if A[x] > 0 and A[x] <= N:
            # if there needs has been max command before not applied
            if res[A[x] - 1] < increase:
                res[A[x] - 1] = increase
            # increment
            res[A[x] - 1] += 1
            # if its biggest one on array
            if res[A[x] - 1] > maxim:
                maxim = res[A[x] - 1]
        # max command, save new value to increase
        if A[x] == N + 1:
            increase = maxim
    # loop to apply every non applied max increases
    for i in range(0, N):
        if res[i] < increase:
            res[i] = increase
    return res