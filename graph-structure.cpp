// 1. Creates a graph using an array of adjacency lists.
// 2. addedges() connects two vertices in an undirected graph.
// 3. print() displays the adjacency list of each vertex.
// 4. Destructor frees the dynamically allocated memory.

#include <iostream>
#include <list>

using namespace std;

class graph{
    int v;
    list<int> *l;

public:
    graph(int v){
        this->v = v;
        l = new list<int> [v];
    }    

    void addedges(int u , int v){
        l[u].push_back(v); 
        l[v].push_back(u); 
    }
    void print(){
        for(int i = 0; i < v ; i++ ){
            cout<< i << " : ";
            for(int val : l[i]){
                cout<<val<<"  ";
            }
            cout<<endl;
        }

    }
    ~graph() {
        delete[] l;
    }
};

int main(){
    
    graph g(5);
    g.addedges(1,2);
    g.addedges(0,4);
    g.addedges(3,2);
    g.addedges(3,4);
    g.addedges(0,3);
    g.print();

    return 0;
}
