#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        vector<vector<bool> > adj;
    
    public:
        Graph(int V){
            this->V = V;
            this->adj = vector<vector<bool> >(this->V, vector<bool>(this->V, false));
        }

        void addEdge(int source, int destination){
            if(source >= this->V || destination >= this->V) return;
            this->adj[source][destination] = true;
            this->adj[destination][source] = true;
        }

        void deleteEdge(int source, int destination){
            if(source >= this->V || destination >= this->V) return;
            this->adj[destination][source] = false;
            this->adj[source][destination] = false;
        }

        void printEdge(){
            for(int i=0;i<this->V;i++){
                for(int j=0;j<this->V;j++){
                    cout<<this->adj[i][j]<<"  ";
                }
                cout<<"\n";
            }
        }
};

int main(){
    Graph graph(5);
    graph.addEdge(0,4);
    graph.addEdge(3,4);
    graph.addEdge(1,4);
    graph.addEdge(2,4);
    graph.addEdge(1,2);
    graph.printEdge();
}