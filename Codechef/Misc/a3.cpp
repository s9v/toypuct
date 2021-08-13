#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#define  pb  push_back
#define  mp  make_pair
#define  sz(X)  (int)X.size()
using namespace std;
typedef vector<int> vi;

int t;
int nhint;
vi  big, small, esit;
vi  nbig, nsmall, nesit;
vi  lims;

int main()
{
	//freopen("in.txt", "r", stdin);
	
	cin >> t;
	
	for (int test = 0; test < t; test++)
	{
		cin >> nhint;
		
		lims.clear();
		big.clear();
		nbig.clear();
		small.clear();
		nsmall.clear();
		esit.clear();
		nesit.clear();
		
		for (int i = 0; i < nhint; i++)
		{
			char oper;
			int lim;
			string logic;
			
			cin >> oper >> lim >> logic;
			
			if (oper == '>')
			{
				if (logic == "Yes")
					big.pb(lim);
				else
					nbig.pb(lim);
			}
			else if (oper == '<')
			{
				if (logic == "Yes")
					small.pb(lim);
				else
					nsmall.pb(lim);
			}
			else if (oper == '=')
			{
				if (logic == "Yes")
					esit.pb(lim);
				else
					nesit.pb(lim);
			}
			
			lims.pb(lim);
		}
		
		sort(lims.begin(), lims.end());
		lims.resize(unique(lims.begin(), lims.end())-lims.begin());
		
		sort(big.begin(), big.end());
		sort(nbig.begin(), nbig.end());
		sort(small.begin(), small.end());
		sort(nsmall.begin(), nsmall.end());
		sort(esit.begin(), esit.end());
		sort(nesit.begin(), nesit.end());
		
		int maxtruth = 0;
		
		for (int i = 0; i < sz(lims); i++)
		{
			for (int extra = -1; extra <= 1; extra++)
			{
				int target = lims[i] + extra;
				int truth = 0;
				
				truth += lower_bound(big.begin(), big.end(), target) - big.begin();
				truth += nbig.end() - lower_bound(nbig.begin(), nbig.end(), target);
				truth += small.end() - upper_bound(small.begin(), small.end(), target);
				truth += upper_bound(nsmall.begin(), nsmall.end(), target) - nsmall.begin();
				truth += upper_bound(esit.begin(), esit.end(), target) - lower_bound(esit.begin(), esit.end(), target);
				truth += nesit.size() - (upper_bound(nesit.begin(), nesit.end(), target) - lower_bound(nesit.begin(), nesit.end(), target));
				
				maxtruth = max(maxtruth, truth);
			}
		}
		
		cout << nhint - maxtruth << "\n";
	}
	
	return 0;
}
