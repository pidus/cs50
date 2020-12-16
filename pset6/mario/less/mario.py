from cs50 import get_int

# get input
def get_positive_int():
    num = get_int("Height: ")
    while num < 1 or num > 8:
        # loop user complies
        num = get_int("Height: ")
    return num

value = get_positive_int()

# for each row
for i in range(value):
    # blank space
    for j in reversed(range(i, value - 1)):
        print(" ", end="")
    # print brick
    for k in range(i+1):
        print("#", end="")
    # new line
    print("")
