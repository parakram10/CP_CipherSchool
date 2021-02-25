#include<bits/stdc++.h>
using namespace std;

class GraphNode{
    public:
        int data;
        int destination;
        GraphNode(int data, int destination){
            this->data = data;
            this->destination = destination;
        }
};

class Graph{
    private:
        int V;
        list<GraphNode*> *adj;
    
    public:
        Graph(int V){
            this->V = V;
            this->adj = new list<GraphNode*>[this->V];
        }

        void addEdge(int source, int destination, int data){
            if(source >= this->V || destination >= this->V) return;

            this->adj[source].push_back(new GraphNode(data, destination));
            this->adj[destination].push_back(new GraphNode(data, source));
        }

        void deleteEdge(int source, int destination){
            if(source >= this->V || destination >= this->V) return;

            for(auto itr = this->adj[source].begin(); itr!=this->adj[source].end(); itr++){
                if((*itr)->destination == destination){
                    this->adj[source].erase(itr);
                    break;
                }
            }

            for(auto itr = this->adj[destination].begin(); itr!=this->adj[destination].end(); itr++){
                if((*itr)->destination == source){
                    this->adj[destination].erase(itr);
                    break;
                }
            }
        }

        void printEdge(){
            for(int v = 0; v < this->V; v++){
                cout<<v<<"   ";
                for(auto itr = this->adj[v].begin(); itr!=this->adj[v].end();itr++){
                    cout<<"( "<<(*itr)->data<<" , "<<(*itr)->destination<<" )";
                }
                cout<<"\n";
            }
        }
};


int main(){
    Graph graph(6);
    graph.addEdge(1,0,10);
    graph.addEdge(2,5,5);
    graph.addEdge(1,4,13);
    graph.addEdge(3,4,20);
    graph.addEdge(5,2,55);
    graph.printEdge();
    graph.deleteEdge(5,2);
    cout<<"\n";
    graph.printEdge();
}