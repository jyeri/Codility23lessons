def solution(A):
    M = len(A)
    # we use sort function (i know there is method to get even more efficient without using sort) to get array sorted, then we return which ever comes up higher
    A.sort()
    # in this case python fuckery, A[-1] == highest, my c brain aint ok with lists goin like this.
    return max(A[0]*A[1]*A[-1], A[-1]*A[-2]*A[-3])