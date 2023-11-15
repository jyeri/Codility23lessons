# https://codesays.com/2014/solution-to-genomic-range-query-by-codility/

# there was so much to learn about effiency. i hope everything is now imprinted on my brain :D

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

# okay so this approach divided:
# we have Cost func to return numeric value for genome in hand
# we have arra[] that stores when the nuc was last found
# and we have lastFound[] that has values for found nuc's (if its over -1, there is nuc of that value)
# arra[i][j] = k
# -> i: type of nucleoid, [0] = A, [1] = C, [2] = G and [3] = T
# -> j: this nucleoid
# -> K: appears in this position (including j)
# so if k == -1, it means there are no this type of nucs


# small helper to return cost of the current "genome"
def cost(S):
    if S == 'A':
        return 1
    elif S == 'C':
        return 2
    elif S == 'G':
        return 3
    else:
        return 4

def solution(S, P, Q):
    # init empty array, and last found array for A, C, G and T, defaulted to -1
    # also make empty array for upcoming result
    arra = []
    result = []
    lastFound = [-1, -1, -1, -1]
    for i in range(0, len(S)) :
        lastFound[cost(S[i]) - 1] = i
        arra.append(list(lastFound))
    # loop arrays from 0 -> len(P)
    # then check by slices of 4 (since there is 4 different genomes in array), if there is bigger genomes on our made array and we add them on our result
    for i in range(0, len(P)) :
        for j in range(0, 4) :
            if arra[Q[i]][j] >= P[i] :
                result.append(j + 1)
                break
    return result