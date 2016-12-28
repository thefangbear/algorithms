
import math

generated = []
seed = 7

def linear_congruential_generator():
    m = 2 * math.pow(10, 31)
    a = 1103515245
    c = 12345
    generated.append(math.ceil(((generated[len(generated) - 1] * a) + c) % m))

generated.append(seed)

for x in range(0, 100):
    print(">> Calling DP-devised LCG algorithm... <<\n")
    linear_congruential_generator()

print("\n>> Generation Finished. Printing numbers... <<\n")

for g in generated:
    print("\t", g)
