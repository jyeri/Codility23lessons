# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(A):
    # we use set to make new list of of elements of A,
    # set function deletes duplicates,
    # so we can just return the length of new set made from A
    return len(set(A))