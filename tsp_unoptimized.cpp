#include<bits/stdc++.h>

using namespace std;


int N = 4;
int S = 0;
int ALL = (1<<N) -1;

int m[4][4] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int g(int p, int mask) {
	if(mask == ALL) {
		return m[p][S];
	}
	int ans = INT_MAX;
	for (int i = 0; i < N; ++i)
	{
		if(!(mask&(1<<i)))
			ans = m[p][i] + min(ans, g(i, mask|(1<<p)));
	}
	return ans;
}


int main() {
	cout << ALL << endl;
	cout << g(0,1);
	return 0;
}
