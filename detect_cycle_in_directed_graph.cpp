#include <bits/stdc++.h>
using namespace std;
int label[1000],e,u,v;
vector<int> g[1000];

bool has_cycle(int u)
{
    label[u] = 1;
    bool ans = false;
    for(auto v : g[u])
    {
        if(label[v] == 1) return true;
        else if(label[v] == 0) ans |= has_cycle(v);
    }
    label[u] = 2;
    return ans;
}


int main() {
	cin >> e;
	for(int i = 0; i < e;++i)
	{
	    cin >> u >> v;
	    g[u].push_back(v);
	}
	cout << has_cycle(0);
	return 0;
}
