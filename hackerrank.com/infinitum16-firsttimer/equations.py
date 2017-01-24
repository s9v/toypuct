import math

x, y, a1, b1 = (0, 0, 0, 0)

def gcdext(a, b):
	if (a == 0):
		return (b, 0, 1)

	g, x1, y1 = gcdext(b % a, a)

	x = y1 - (b // a)*x1
	y = x1

	return (g, x, y)

def f(r):
	return math.sqrt((x - r*b1)**2 + (y + r*a1)**2)

def main():
	q = int(raw_input())

	while (q):
		q -= 1

		a, b, c = map(int, raw_input().split())

		global x, y
		g, x, y = gcdext(a, b)

		k = c//g

		x *= k
		y *= k

		global a1, b1
		a1 = a//g
		b1 = b//g

		#INTMAX = int(1e9+100)
		#INTMIN = int(-1e9-100)
		INTMAX = 1000
		INTMIN = -1000

		minr1 = (x-INTMAX-1)//b1 + 1
		minr2 = (INTMIN-y-1)//a1 + 1
		minr = max(minr1, minr2)

		maxr1 = x//b1
		maxr2 = (INTMAX-y)//a1
		maxr = min(maxr1, maxr2)

		#print "*", minr, "...", maxr

		while (maxr - minr >= 3):
			m1 = minr + (maxr - minr)//3
			m2 = maxr - (maxr - minr)//3

			if (f(m1) < f(m2)):
				maxr = m2
			else:
				minr = m1

		r = None

		#print "*", minr, "...", maxr

		for rr in range(minr, maxr+1):
			#print ">", rr, x - rr*b1, y + rr*a1, f(rr)
			if (r is None or f(rr) < f(r)):
				r = rr

		ansx = x - r*b1
		ansy = y + r*a1

		print ansx, ansy

main()
