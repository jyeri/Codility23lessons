# probably not the safest method

def solution(X, A):
    # make empty set
    position = set()
    
    # iterate for whole array
    for i in range(len(A)):
        # if visiting first time in this leaf, add it to set
        if A[i] not in position:
            position.add(A[i])
        #if the set length is X we have found the goal
        if len(position) == X:
            return i
    # no path found so ret -1
    return -1

