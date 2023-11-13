# Using the same formula as C solution, bit more tidy.
# The math used is from stack overflow, couldn't get to the actual solution without bit of help :)

import math

 # explanation of the functionality:
 # we need number of divisors between A/K and B/K
 # so we calculate B/K to get bigger number of divisors.
 # we calculate A/K to get smaller number of divisors
 # then we substract small from big
def solution(A, B, K):
    return math.floor(B / K) - math.ceil(A / K) + 1