#include<bits/stdc++.h>
using namespace std;

class UndirectedGraph{
    int V;
    list<int> *adj;
    public:
        UndirectedGraph(int V){
            this->V = V;
            this->adj = new list<int>[this->V];
        }

        void addEdge(int source, int destination){
            if(source >= this->V || destination >= this->V) return;
            this->adj[source].push_back(destination);
            this->adj[destination].push_back(source);
        }

        void deleteNode(int source, int destination){
            if(source >= this->V || destination >= this->V) return;
            auto iter = find(this->adj[source].begin(), this->adj[source].end(), destination);
            this->adj[source].erase(iter);
            auto iter1 = find(this->adj[destination].begin(), this->adj[destination].end(), source);
            this->adj[destination].erase(iter1);
        }

        void printGraph(){
            for(int v=0; v<this->V; v++){
                cout<<v<<"   ";
                for(auto iter = this->adj[v].begin(); iter!=this->adj[v].end(); iter++) cout<<*iter<<" ---> ";
                cout<<"\n";
            }
        }
};

int main(){
    UndirectedGraph ug(5);
    ug.addEdge(0,1);
    ug.addEdge(1,2);
    ug.addEdge(4,3);
    ug.addEdge(2,4);
    ug.addEdge(1,4);
    ug.printGraph();
    ug.deleteNode(0,1);
    ug.printGraph();
}