# 100% python
# same as C basically
# we iterate from end, and discard 0's tailing
# after that we again increment current until next 1 and compare to maxim value
# note to self: DO NOT NAME VARIABLES AS MAX

def solution(N):
    maxim = 0
    current = 0
    modulus = 0
    # Tail zeros
    while N > 0 and N % 2 == 0:
        N //= 2
    # After tail 0's
    while N > 0:
        modulus = N % 2
        if modulus == 0:
            current += 1
        else:
            if current != 0:
                if current > maxim:
                    maxim = current
                current = 0
        N //= 2

    return maxim