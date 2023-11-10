# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    maxim = max(A) + 1
    # there is less than 1 positive integer in list
    if maxim < 2:
        return 1
    arr = [0] * maxim
    # loop and change values of existing to 1
    for i in range(len(A)):
        if A[i] > 0:
            arr[A[i]] = 1
    # loop to find if something is not changed to 0 == not existing in orginal array
    for i in range(1, len(arr)):
        if arr[i] == 0:
            return i
    # else missing value is array length
    return len(arr)