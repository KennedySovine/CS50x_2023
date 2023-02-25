from cs50 import get_string


text = get_string("Text: ")

#letters
letter = 0
for i in (text):
    if i.isalpha():
        letter += 1

#words
word = 1
for i in (text):
    if i.isspace():
        word += 1

#sentences
sent = 0
for i in (text):
    if i == '?' or i == '.' or i == '!':
        sent += 1

#index
index = 0
index = (0.0588 * (letter/(word/100)))
index = index - (0.296 * (sent/(word/100)))
index = round(index - 15.8)

#determining
if index < 16 and index >= 1:
    print("Grade " + str(index) + "\n", end="")
elif index >= 16:
    print("Grade 16+\n", end="")
else:
    print("Before Grade 1\n", end="")