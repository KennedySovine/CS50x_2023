from cs50 import get_float

answer = get_float("Changed owed: ")
while answer < 0:
    answer = get_float("Change owed: ")
    continue

cents = (int)(answer * 100)

count = 0

while cents >= 0:
    if cents - 25 >= 0:
        count += 1
        cents -= 25
        continue
    elif cents - 10 >= 0:
        count += 1
        cents -= 10
        continue;
    elif cents - 5 >= 0:
        count += 1
        cents -= 5
        continue
    elif cents - 1 >= 0:
        count += 1
        cents -= 1
        continue
    break
print(count)