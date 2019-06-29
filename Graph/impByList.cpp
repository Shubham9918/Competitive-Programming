#include <bits/stdc++.h>

using namespace std;

class Graph{
	private:
		int n;
	    vector<vector<int>>* adj;
		bool *visited;


	public:
		Graph(int n){
			this->n = n;
			visited = new bool [n];
			adj = new vector<vector<int>> [n];
		}

		void addEdge(int frm, int to, int cost){
			if (frm>=0 && frm<n && to>=0 && to<n){
				vector<int> temp;
				temp.push_back(to);
				temp.push_back(cost);
				adj[frm].push_back(temp);
			}
		}

		void printEdges(){
			for (int i = 0; i < n; ++i){
				for(auto j: adj[i]){
					cout<<i<<"-->"<<j[0]<<'='<<j[1]<<"\n";
				}
			}
		}

};

int main()
{
	Graph G(5);
	G.addEdge(0,2,10);
	G.addEdge(1,3,5);
	G.addEdge(4,4,2);
	G.printEdges();
	// G.printVisited();
	return 0;
}