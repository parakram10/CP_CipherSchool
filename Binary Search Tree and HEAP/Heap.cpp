#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    private:
        int *harr;
        int count;
        int capacity;

        int left(int index){
            return (2*index)+1;
        }

        int right(int index){
            return (2*index)+2;
        }

        int parent(int index){
            return (index-1)/2;
        }
    
    public:
        MinHeap(int n){
            this->capacity = n;
            this->count = 0;
            this->harr = new int(this->capacity);
        }

        void insertInHeap(int data){
            if(this->count == this->capacity){
                cout<<"Heap is full!!";
                return;
            }
            this->count++;
            int index = count-1;
            this->harr[index] = data;
            while(index!=0 && harr[index] < harr[this->parent(index)]){
                swap(harr[index], harr[this->parent(index)]);
                index = parent(index);
            }
        }

        void printHeap(){
            for(int i=0;i<this->count;i++) cout<<this->harr[i]<<"  ";
        }

        void minheapify(int index){
            int l = this->left(index);
            int r = this->right(index);

            int smallest = index;
            if(l<this->count && this->harr[l] < this->harr[smallest]) smallest = l;

            if(r<this->count && this->harr[r] < this->harr[smallest])   smallest = r;

            if(smallest != index){
                swap(this->harr[smallest], this->harr[index]);
                minheapify(smallest);
            }
        }

        void deletionInHeap(){
            if(this->count == 0){
                cout<<"Heap is already empty!!";
                return;
            }
            if(this->count == 1) this->count--;

            else{
                this->harr[0] = this->harr[this->count-1];
                this->count--;
                minheapify(0);
            }
        }
};


int main(){
    vector<int> v = {1,4,2,8,10,5};
    MinHeap minheap(10);
    for(int i=0;i<v.size();i++) minheap.insertInHeap(v[i]);
    minheap.printHeap();
    minheap.deletionInHeap();
    cout<<"\n";
    minheap.printHeap();
}
