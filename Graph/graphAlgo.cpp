#include "impByArray.cpp"
#define INF 99999
class GraphAlgo : public Graph{
	private:
		vector<int> dist;
		vector<int> path;

	public:
		GraphAlgo(int n):Graph(n){
			for(int i =0;i<n;i++){
				dist.push_back(INF);
			}

			for(int i =0;i<n;i++){
				path.push_back(-1);
			}

		}

		bool comp(auto &a, auto &b){
			if(a.first > b.first){
				return false;
			}else{
				return true;
			}
		}

		void Dijkstra(int src){
			cout<<"Dijkstra algoritm";
			priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			pq.push(make_pair(0,src));

			dist[src] = 0;


			while(!pq.empty()){

				auto current = pq.top().second;
				pq.pop();
				

				for (auto x: getNeibour(current)){
					
					int newDist = dist[current]+adjMatrix[current][x];
					
					if (newDist<dist[x]){
						dist[x] = newDist;
						pq.push(make_pair(newDist,x));
						path[x] = current;
					}
				}

			}
			for (int i = 0; i < n; ++i)
			{
				cout<<dist[i]<<",";
			}

		}




		void BellmanFord(int src){
			vector <int> q;
			q.push_back(src);
			dist[src] = 0 ;
			while(!q.empty()){
				int top = q[0];
				q.erase(q.begin());
				for(auto x: getNeibour(top)){
					auto newDist = adjMatrix[top][x] + dist[top];
					if(newDist<dist[x]){
						dist[x] = newDist;
						if(find(q.begin(),q.end(),x)==q.end()){
							q.push_back(x);
						}
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cout<<dist[i]<<",";
		}
	}

	void Prims(int src){
			cout<<"Prims algoritm"<<"\n";
			priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
			pq.push(make_pair(0,src));

			dist[src] = 0;


			while(!pq.empty()){

				auto current = pq.top().second;
				pq.pop();
				

				for (auto x: getNeibour(current)){
					
					int newDist = adjMatrix[current][x];
					
					if (newDist<dist[x]){
						dist[x] = newDist;
						pq.push(make_pair(newDist,x));
						path[x] = current;
					}
				}

			}
			for (int i = 0; i < n; ++i)
			{
				cout<<path[i]<<",";
			}

		}



};




int main()
{
	GraphAlgo G(5);
	G.addEdge(0,1,2);
	G.addEdge(1,2,3);
	G.addEdge(1,3,4);

	G.addEdge(3,4,3);
	G.addEdge(0,4,5);

	G.printEdges();
	// G.Dijkstra(1);
	// G.printVisited();
	// G.dfsRun();
	// G.bfsRun();
	// G.BellmanFord(1);
	G.Prims(0);


	return 0;
	
}