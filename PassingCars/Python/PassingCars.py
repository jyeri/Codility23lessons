# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    x = 0
    westheads = 0
    total = 0
    # iterate the array
    for x in range(len(A)):
        #count cars goin 0 direction
        if A[x] == 0:
            westheads += 1
        #else we add em to the total
        else:
            total = total + westheads
        if total > 1000000000:
            return -1
    return total