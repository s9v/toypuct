import random

def main():
    tests = random.randint(1, 10)
    print(tests)

    for _ in range(tests):
        a = random.randint(0, 100)
        b = random.randint(0, 100)
        ca = random.randint(0, 100)
        cb = random.randint(0, 100)
        fa = random.randint(0, 100)
        print(a, b, ca, cb, fa)


if __name__ == '__main__':
    main()

