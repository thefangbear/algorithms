
import random
tries = 0
success = 0
for x in range(0,1000000):
    x = random.random()
    y = random.random()
    tries += 1
    print(">> TRYING >> ", x, y, "\n")
    if x * x + y * y <= 1 :
        print(">>\tSUCCESS\n")
        success += 1


pi = 4 * success / tries
print("\n>>> Final Pi Value: ", pi, " <<<\n")
