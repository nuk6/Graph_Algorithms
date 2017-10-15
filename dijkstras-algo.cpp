#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF (int)1e9
typedef pair<int,int> pii;
typedef vector<int> vi;
bool visited[1000000];

struct comparator
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b)const{
		return( a.second > b.second);
	}
	
};



class Graph{
	int v;
	list<pii>* adj_list;

public:
	Graph(int v);
	void fun();
	int dfs(Graph& g);
	int bfs(Graph& g);
	int num_of_vertices();
	int number_of_components(Graph& g);
	vi single_source_shortest_path(int s);
	void add_edge(int u , int v, int w);
	//vector<vector<int>> all_pairs_shortest_paths()
};
Graph :: Graph(int v){
	this->v = v;
	adj_list = new list<pii>[v];
}

void Graph :: add_edge(int u, int v, int w){
	adj_list[u].push_back(make_pair(v,w));
	adj_list[v].push_back(make_pair(u,w));
}

vi Graph :: single_source_shortest_path(int s){

	priority_queue<pii, vector<pii>, comparator> pq;

	pq.push(make_pair(s,0));
	vector<int> dist(v, 99999) ;
	dist[s] = 0;
	pq.push(make_pair(s,0));
	//cout<<"Number = "<<
	while(!pq.empty()){
		int u = pq.top().first;
		pq.pop();
		for(auto i : adj_list[u]){
			int weight = i.second;
			int vertex = i.first;
			if(dist[u]+weight < dist[vertex]){
				dist[vertex] = dist[u]+weight;
				pq.push(make_pair(vertex,dist[vertex]));
			}
		}
	}

	return dist;
}

void Graph :: fun(){
	cout<<"Hey there!!";
}

int number_of_components(Graph& g){

}

int Graph::dfs(Graph& g){
	cout<<g.v;
	return 1;
}

int  Graph::num_of_vertices(){
	return this->v;
}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.add_edge(0, 1, 4);
    g.add_edge(0, 7, 8);
    g.add_edge(1, 2, 8);
    g.add_edge(1, 7, 11);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 8, 2);
    g.add_edge(2, 5, 4);
    g.add_edge(3, 4, 9);
    g.add_edge(3, 5, 14);
    g.add_edge(4, 5, 10);
    g.add_edge(5, 6, 2);
    g.add_edge(6, 7, 1);
    g.add_edge(6, 8, 6);
    g.add_edge(7, 8, 7);
 
    vi ans = g.single_source_shortest_path(0);
    for(auto i : ans){
    	cout<<i<<endl;
    }

 
    return 0;
}





