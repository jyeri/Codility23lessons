#straight up C solution, binary way
def solution(A):
    ret = 0

    #every number in A we bit shift, result is the one that does not get sifted back
    for i in range(len(A)):
        ret = ret ^ A[i]
    return ret