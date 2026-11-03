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

    void bfs(){
        queue<int> q;
        vector<bool> vis(v , false);

        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            for(int v : l[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    
    graph g(5);
    g.addedges(1,2);
    g.addedges(0,4);
    g.addedges(3,2);
    g.addedges(3,4);
    g.addedges(0,3);
    g.bfs();

    return 0;
}
