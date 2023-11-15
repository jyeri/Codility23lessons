# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

# sorting isnt most efficient method but well in this range
# second improvement would be skipping complityely values < 0
# because is triangular if 0 ≤ P < Q < R < N

def solution(A):
    # Implement your solution here
    A.sort()
    for i in range(len(A) - 2):
        if A[i]+A[i+1] > A[i+2] and A[i] > 0 and A[i + 1] > 0 and A[i +2 ] > 0:
            return 1
    return 0