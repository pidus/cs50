from cs50 import get_int

#get card number from user
def get_valid_input():
    uin = get_int("Number: ")
    while uin < 0 or uin > 9999999999999999:
        uin = get_int("Number: ")
    return uin

card = str(get_valid_input())
length = len(card)

#Luhn’s Algorithm
luhn = 0
#every other digits starting w/ 2nd to last
for a in range(length-2, -1, -2):
    tmp = int(card[a])*2
    if tmp < 10:
        luhn += tmp
    else:
        luhn += tmp-9
# rest of the digits
for b in range(length-1, -1, -2):
    luhn += int(card[b])
remainder = luhn%10

if remainder == 0:
    if length == 15 and int(card[0]) == 3 and (int(card[1]) == 4 or int(card[1])) == 7:
        print("AMEX")
    elif length == 16 and int(card[0]) == 5 and (int(card[1]) == 1 or int(card[1]) == 2 or int(card[1]) == 3 or int(card[1]) == 4 or int(card[1]) == 5):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and int(card[0]) == 4:
        print("VISA")
else:
    print("INVALID")
