from cs50 import get_int

#get card number from user
def get_valid_input():
    uin = get_int("Number: ")
    while uin < 0 or uin > 9999999999999999:
        uin = get_int("Number: ")
    return uin

card = str(get_valid_input())
length = len(card)
# print(length) # for testing
#Luhn’s Algorithm
luhn = 0
#every other digits starting w/ 2nd to last
for a in range(length-2, -1, -2):
    # print(a)
    if len(card[a]*2) == 2:
        luhn += ((int(card[a]*2)//10) + (int(card[a]*2)%10))
    else:
        luhn += int(card[a])*2
print(luhn)
# right = 13
#rest of the digits
for b in range(length-1, -1, -2):
    luhn += int(card[b])
print(luhn)
remainder = luhn%10
print(remainder)
if remainder == 0:
    if card[0] == 3 and (card[1] == 4 or card[1] == 7):
        print("AMEX")
    elif card[0] == 5 and (card[1] == 1 or card[1] == 2 or card[1] == 3 or card[1] == 4 or card[1] == 5):
        print("MASTERCARD")
    elif card[0] == 4:
        print("VISA")
else:
    print("INVALID")
