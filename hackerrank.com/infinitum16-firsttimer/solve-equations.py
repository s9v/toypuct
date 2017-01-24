def gcdext(a, b):
	if (a == 0):
		return (b, 0, 1)

	g, x1, y1 = gcdext(b % a, a)

	x = y1 - (b // a)*x1
	y = x1

	return (g, x, y)

def main():
	q = int(raw_input())

	while (q):
		q -= 1

		a, b, c = map(int, raw_input().split())

		g, x, y = gcdext(a, b)

		k = c//g

		x *= k
		y *= k

		a1 = a//g
		b1 = b//g

		r = x//b1

		while (x - r*b1 <= 0):
			r -= 1

		ansx = x - r*b1
		ansy = y + r*a1

		print ansx, ansy

main()