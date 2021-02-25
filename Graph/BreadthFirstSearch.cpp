#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>* adj;
    public:
        Graph(int V){
            this->V = V;
            this->adj = new list<int>[this->V];
        }

        void addEdge(int source, int destination){
            adj[source].push_back(destination);
        }

        void BFS(){
            int source = 0;

            vector<bool> visited(this->V, false);
            list<int> Q;

            Q.push_back(source);
            while(!Q.empty()){
                source = Q.front();
                Q.pop_front();
                cout<<source<<"  ";
                for(auto itr = this->adj[source].begin(); itr!=this->adj[source].end(); itr++){
                    if(!visited[*itr]){
                        visited[*itr] = true;
                        Q.push_back(*itr);
                    }
                }
            }
        }
};


int main(){
    Graph graph(6);
    graph.addEdge(0,4);
    graph.addEdge(3,4);
    graph.addEdge(4,3);
    graph.addEdge(4,2);
    graph.addEdge(2,1);
    graph.BFS();
}