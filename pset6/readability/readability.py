from cs50 import get_string

passage = get_string("Enter passage: ")
letters = 0
words = 1
sentences = 0
#length = len(passage)

for p in passage:
    if p.isalpha():
        letters +=1

for p in passage:
    if p.isspace():
        words +=1

for p in passage:
    if p == '.' or p == '?' or p == '!':
        sentences +=1

index = 0.0588 * (letters*100/words) - (0.296*(sentences*100/words)) - 15.8
# print(index) # for testing
grade = int(round(index))

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
