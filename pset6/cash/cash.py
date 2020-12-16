from cs50 import get_float

# // function to get user input:
def get_input():
    num = get_float("Change owed: ")
    while num <= 0:
        num = get_float("Change owed: ")
    return num

dollars = get_input()

# list coins
quarter = 25
dime = 10
nickel = 5
penny = 1

# conver dollar to cent
cents = int(dollars * 100)

# divide by bigger coin, then divide remaindr by smaller coin

q = cents // quarter
qr = cents % quarter

d = qr // dime
dr = qr % dime

n = dr // nickel
nr = dr % nickel

p = nr // penny
pr = nr % penny

total = q+d+n+p
print(f"{total}")

