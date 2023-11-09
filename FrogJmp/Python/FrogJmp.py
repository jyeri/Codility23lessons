# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

import math

def solution(X, Y, D):
    res = 0
    distanceleft = 0

    # check if we are already at destionation
    if X == Y:
        return res
    
    # distanceleft is Y - X / D, because Y - X = overall distance to travel
    # And it divided by how many jumps it need to reach it
    distanceleft = Y - X
    distanceleft = distanceleft / D
    # then we round up the number to next full jump
    res = math.ceil(distanceleft)
    return res
