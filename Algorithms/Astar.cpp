#include<iostream> 
using namespace std;
#include<vector>
#include<queue>

    int heuristic(int r,int c,int gr,int gc){
    return abs(r-gr) + abs(c-gc);
}


int main(){
    vector<string> maze ={"S..",".#.","..E"};
    int rows = maze.size();
    int cols = maze[0].size();
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,1,-1};
    int sr,sc;
    int gr,gc;

    for(int i =0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(maze[i][j] == 'S'){
                sr = i;
                sc = j;
            }

            if(maze[i][j] == 'E'){
                gr = i;
                gc = j;
            }
        }
    }

    vector<vector<int>>dist(rows,vector<int>(cols,1e9));
    vector<vector<pair<int,int>>>parent(rows,vector<pair<int,int>>(cols,{-1,-1}));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    dist[sr][sc] = 0;
    int h =
    heuristic(
        sr,
        sc,
        gr,
        gc
    );
    pq.push({h,{sr,sc}});

    while(!pq.empty())
{
    int currentF = pq.top().first;

    int r = pq.top().second.first;
    int c = pq.top().second.second;

    pq.pop();

    // Goal reached
    if(r == gr && c == gc)
    {
        break;
    }

    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        // Outside maze
        if(nr < 0 ||
           nr >= rows ||
           nc < 0 ||
           nc >= cols)
        {
            continue;
        }

        // Wall
        if(maze[nr][nc] == '#')
        {
            continue;
        }

        // Since every move costs 1
        int newG = dist[r][c] + 1;

        if(newG < dist[nr][nc])
        {
            dist[nr][nc] = newG;

            parent[nr][nc] = {r,c};

            int h =
                heuristic(
                    nr,
                    nc,
                    gr,
                    gc
                );

            int f = newG + h;

            pq.push(
            {
                f,
                {nr,nc}
            });
        }
    }
}

vector<pair<int,int>> path;
int r = gr;
int c = gc;

while(r !=-1 and c != -1){
    path.push_back({r,c});

    pair<int,int> p = parent[r][c];

    r = p.first;
    c = p.second;
}

for(int i = path.size()-1;
    i >= 0;
    i--)
{
    cout
        << "("
        << path[i].first
        << ","
        << path[i].second
        << ")";

    if(i != 0)
    {
        cout << " -> ";
    }
}



}