def solve(case: int):
    a, b, ca, cb, fa = tuple(map(int, input().split()))

    MAX = max(cb * (fa - a), fa - a, 0)
    
    for x in range(MAX + 1):
        # print(f'//{x}')
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
    else:
        print('?')

def main():
    for case in range(int(input())):
        solve(case)

if __name__ == '__main__':
    main()

