#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<bool> visited(5,false);
vector<vector<int>> graph(5);
vector<bool> visit(5,false);
vector<bool> v(5,false);


void dfs(int vertex){
   visited[vertex] = true;

   cout<<vertex<<" ";

   for(int neighbour : graph[vertex]){
        if(!visited[neighbour]){
            dfs(neighbour);
        }
   }
}


void dfs_stack(int vertex){
    stack<int> s;
    s.push(vertex);
   
    while(!s.empty()){
        int current = s.top();
        visit[current] = true;
        s.pop();
        cout<<current<<" ";

        for(int neighbour : graph[current]){
            if(!visit[neighbour]){
                s.push( neighbour);
                
            }
        }
    }
}

void BFS(int start){
    queue<int> q;
    q.push(start);

    v[start] = true;
    while(!q.empty()){
        int current  = q.front();
        q.pop();
        cout<<current<<" ";
        for(int neighbours : graph[current]){
            if(!v[neighbours]){
                q.push(neighbours);
                visit[neighbours] = true;

            }
        }
    }


}


int main(){


    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);

    dfs(0);
    cout<<endl;
    dfs_stack(0);
    cout<<endl;
    BFS(0);
    return 0;
}

