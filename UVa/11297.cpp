// 11297 - Census
// http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2272

#include <iostream>
#include <cassert>
#include <fstream>
#define  mp make_pair
#define  dbg(vari) cerr << #vari << " = " << (vari) << endl
using namespace std;

time_t strt = clock();

typedef pair<int,int> pi;

const int STSIZE = 10*512;
const int LRG = 1e9;

int n, m, q;
int arr[STSIZE][STSIZE];
pi st[2*STSIZE][2*STSIZE]; // first → min   second → max

void yinit(int vx,int lx,int rx,int vy,int ly,int ry)
{
	if (ly == ry)
	{
		if (lx == rx)
			st[vx][vy].first = st[vx][vy].second = arr[lx][ly];
		else
		{
			st[vx][vy].first  = min(st[2*vx+1][vy].first, st[2*vx+2][vy].first);
			st[vx][vy].second = max(st[2*vx+1][vy].second, st[2*vx+2][vy].second);
		}
	}
	else
	{
		yinit(vx,lx,rx,2*vy+1,ly,(ly+ry)/2+0);
		yinit(vx,lx,rx,2*vy+2,(ly+ry)/2+1,ry);
		st[vx][vy].first = min(st[vx][2*vy+1].first, st[vx][2*vy+2].first);
		st[vx][vy].second = max(st[vx][2*vy+1].second, st[vx][2*vy+2].second);
	}
}

void xinit(int vx,int lx,int rx)
{
	if (lx != rx)
	{
		xinit(2*vx+1,lx,(lx+rx)/2+0);
		xinit(2*vx+2,(lx+rx)/2+1,rx);
	}
	yinit(vx,lx,rx,0,0,m-1);
}

void yupd(int vx,int lx,int rx,int vy,int ly,int ry,int qx,int qy,int val)
{
	if (qy < ly || ry < qy)
		return;
	
	if (ly == ry)
	{
		if (lx == rx)
			st[vx][vy].first = st[vx][vy].second = val;
		else
		{
			st[vx][vy].first  = min(st[2*vx+1][vy].first, st[2*vx+2][vy].first);
			st[vx][vy].second = max(st[2*vx+1][vy].second, st[2*vx+2][vy].second);
		}
	}
	else
	{
		yupd(vx,lx,rx,2*vy+1,ly,(ly+ry)/2+0,qx,qy,val);
		yupd(vx,lx,rx,2*vy+2,(ly+ry)/2+1,ry,qx,qy,val);
		st[vx][vy].first  = min(st[vx][2*vy+1].first, st[vx][2*vy+2].first);
		st[vx][vy].second = max(st[vx][2*vy+1].second, st[vx][2*vy+2].second);
	}
}

void xupd(int vx,int lx,int rx,int qx,int qy,int val)
{
	if (qx < lx || rx < qx)
		return;
	
	if (lx != rx)
	{
		xupd(2*vx+1,lx,(lx+rx)/2+0,qx,qy,val);
		xupd(2*vx+2,(lx+rx)/2+1,rx,qx,qy,val);
	}
	
	yupd(vx,lx,rx,0,0,m-1,qx,qy,val);
}

pi yfnd(int vx,int lx,int rx,int vy,int ly,int ry,int qa,int qb,int qc,int qd)
{
	if (qd < ly || ry < qc)
		return mp(LRG, -LRG);
	
	if (qc <= ly && ry <= qd)
		return st[vx][vy];
	else
	{
		pi foo1 = yfnd(vx,lx,rx,2*vy+1,ly,(ly+ry)/2+0,qa,qb,qc,qd);
		pi foo2 = yfnd(vx,lx,rx,2*vy+2,(ly+ry)/2+1,ry,qa,qb,qc,qd);
		return mp(min(foo1.first, foo2.first), max(foo1.second, foo2.second));
	}
}

pi xfnd(int vx,int lx,int rx,int qa,int qb,int qc,int qd)
{
	if (qb < lx || rx < qa)
		return mp(LRG, -LRG);
	
	if (qa <= lx && rx <= qb)
		return yfnd(vx,lx,rx,0,0,m-1,qa,qb,qc,qd);
	else
	{
		pi foo1 = xfnd(2*vx+1,lx,(lx+rx)/2+0,qa,qb,qc,qd);
		pi foo2 = xfnd(2*vx+2,(lx+rx)/2+1,rx,qa,qb,qc,qd);
		return mp(min(foo1.first, foo2.first), max(foo1.second, foo2.second));
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	xinit(0,0,n-1);
	
	cin >> q;
	
	char cmd;
	for (int fooquery = 0; fooquery < q; fooquery++)
	{
		cin >> cmd;
		
		if (cmd == 'q')
		{
			int qa, qb, qc, qd;
			cin >> qa >> qc;
			cin >> qb >> qd;
			qa--;
			qb--;
			qc--;
			qd--;
			
			pi footmp = xfnd(0,0,n-1,qa,qb,qc,qd);
			cout << footmp.second << " ";
			cout << footmp.first << "\n";
		}
		else if (cmd == 'c')
		{
			int x, y, v;
			cin >> x >> y >> v;
			x--;
			y--;
			xupd(0,0,n-1,x,y,v);
		}
		else
		{
			cerr << "TKMNOI sucks!";
		}
	}
	
	cerr << clock() - strt;
	return 0;
}
