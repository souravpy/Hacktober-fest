from random import randint
print("Welcome to my mini game. I will think of a number between 0 and 10 for you to guess.")
pc = randint(0, 10)
player = ""
count = 0
while player != pc:
    player = int(input("Make your guess: "))
    count += 1
    if player != pc:
        print("You guessed wrong, try again.")
print("You guessed it! I was thinking of the number {0}. It took you {1} attempts to guess correctly. Congratulations!".format(pc, count))
