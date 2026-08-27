def solve(case: int):
    a, b, ca, cb, fa = tuple(map(int, input().split()))

    MAX = max(cb * (fa - a), fa - a)
    
    print(f'== TEST {case} ==')
    for x in range(MAX + 1):
        if (
            min(
                a + xa + (b + x - xa) // cb * ca
                for xa in range(x+1)
            ) >= fa
        ):
            print(x)
            break
        # else:
        #     print(-x)

def main():
    for case in range(int(input())):
        solve(case)

if __name__ == '__main__':
    main()

