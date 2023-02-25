from cs50 import get_int

answer = get_int("Height: ")
while answer < 1 or answer > 8:
    answer = get_int("Height: ")
    break

tags = 1
spaces = answer - 1;
while tags <= answer:
    for x in range(spaces):
        print(" ", end="")
        continue
    for u in range(tags):
        print("#", end="")
        continue
    print("\n", end="")
    tags += 1
    spaces -= 1