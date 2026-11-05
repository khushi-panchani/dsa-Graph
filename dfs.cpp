// 1. Create an undirected graph using an adjacency list.
// 2. Add edges to connect different vertices in the graph.
// 3. Start DFS from vertex 0 and mark each visited vertex.
// 4. Recursively visit all unvisited adjacent vertices as deeply as possible.

#include <iostream>
#include <list>
#include <queue>
#include <vector>
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


    }
    void dfshelper(int u , vector<bool>& vis){
        cout<<u<<" ";
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                dfshelper(v , vis);

            }
        }
        
    }

    void dfs(){
        vector<bool> vis(v , false);
        dfshelper(0 , vis );
    }
};

int main(){
    
    graph g(6);
    g.addedges(1,4);
    g.addedges(0,2);
    g.addedges(0,4);
    g.addedges(2,5);
    g.addedges(2,3);

    cout<<"dfs : "<<endl;
    g.dfs();

    return 0;
}
