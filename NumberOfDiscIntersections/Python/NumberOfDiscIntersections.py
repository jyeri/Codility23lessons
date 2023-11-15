# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")
# https://codesays.com/2014/solution-to-beta2010-number-of-disc-intersections-by-codility/


def solution(A):
    M = len(A)
    dRight = [0] * M
    dLeft = [0] * M
    
    # we make two additional arrays to hold left point and right point of the discs
    # then we sort them
    for ind in range(0, M):
        dRight[ind] = ind + A[ind]
        dLeft[ind] = ind - A[ind]
    dRight.sort()
    dLeft.sort()
    left_ind = 0
    intersects = 0
    for right_ind in range(0, M):
        # every disc that center - radius is smaller or equal to our current disc center + radius
        # we have to exclude discs that are complitely omitted by current disc
        while left_ind < M and dRight[right_ind] >= dLeft[left_ind]:
            left_ind += 1
        # subract to get amount of intersections (minus one is current disc itself)
        intersects += left_ind - right_ind - 1
        if intersects > 10000000:
            return -1
    return intersects

