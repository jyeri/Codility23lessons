def solution(S):
    stack = []
    opens = ['(', '[', '{']
    matches = {")":"(", "]":"[", "}": "{"}

    # this is clever, it doesn't break without but makes some cases so much faster
    if len(S) % 2 != 0:
        return 0

    # iterate S
    for i in S:
        # if opener -> append to stack
        if i in opens:
            stack.append(i)
        # else we check if there is nothing in stack -> therefor its closing without open
        # and we check if it matches what we pop from stack
        else:
            if len(stack) == 0 or matches[i] != stack.pop():
                return 0
    # we check if everything from stack was actually closed
    if len(stack) == 0:
        return 1
    # if not its invalid
    return 0