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

        void DFSHelper(vector<bool>& visited, int source){
            visited[source] = true;
            cout<<source<<" ";
            for(auto itr = this->adj[source].begin(); itr != this->adj[source].end(); itr++){
                if(!visited[*itr]){
                    DFSHelper(visited, *itr);
                }
            }
        }

        void DFS(){
            vector<bool> visited(this->V, false);
            for(int v = 0; v < this->V; v++){
                if(!visited[v]) DFSHelper(visited,v);
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
    graph.DFS();
}