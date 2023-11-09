# took a bit nudge to right direction from stack overflow

def solution(A):
    # Compare two sets, A and set from values from 1 len of A +1. If the are equal there are no permutations
    if set(A) == set(range(1, 1+len(A))):
        return 1
    else:
        return 0
