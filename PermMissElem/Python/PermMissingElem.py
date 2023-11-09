# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    everything = 0
    missing = 0
    res = 0

    #sum every element in A
    for i in A:
        missing += i
    #sum every possible element in len(A) + 2
    # + 2 to add up index 0 and missing number
    for i in range(len(A) + 2):
        everything += i
    # everything is missing only the wanted result value
    res = everything - missing
    return res