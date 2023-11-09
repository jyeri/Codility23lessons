def solution(A, K):
    N = len(A)
    i = 0
    if N < 2:
        return A
    newK = K % N
    for x in range(newK):
        # if array is empty check
        if A == []:
            return A
        # pop last element of A, insert it into 1st positin
        A.insert(0, A.pop())
        #do this K%N times

    return A