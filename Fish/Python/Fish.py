# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A, B):
    # very similar approach than to Brackets
    stack = []
    downs = 0
    alive = 0


    for i in range(len(A)):
        # we append dowstreamers to stack, and increment their count
        if B[i] == 1:
            stack.append(A[i])
            downs += 1
        else:
            # when upstream fish, we pop out of stack all smaller ones that gets eaten
            while downs > 0:
                # i will never get used to it, but stack[-1], the -1 stands for last element on the "array"
                if A[i] > stack[-1]:
                    stack.pop()
                    downs -= 1
                else:
                    break
            # if it was bigger than anything on stack going downstream it stays alive
            else:
                alive += 1                
    # our return value is all upstreamfishes that stayed alive, and downstream fishes still in stack
    alive += downs
    return alive
