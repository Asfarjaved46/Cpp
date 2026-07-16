#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    vector<string> maze =
    {
        "S..",
        "#..",
        "##E"
    };

    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<pair<int,int>>> graph(rows * cols);

    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    // Build Graph
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(maze[r][c] == '#')
            {
                continue;
            }

            int current = r * cols + c;

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 &&
                   nr < rows &&
                   nc >= 0 &&
                   nc < cols &&
                   maze[nr][nc] != '#')
                {
                    int next =
                        nr * cols + nc;

                    graph[current]
                        .push_back(
                        {
                            next,
                            1
                        });
                }
            }
        }
    }

    // Find Start and End
    int start = -1;
    int end = -1;

    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            int node =
                r * cols + c;

            if(maze[r][c] == 'S')
            {
                start = node;
            }

            if(maze[r][c] == 'E')
            {
                end = node;
            }
        }
    }

    // Dijkstra
    vector<int> dist(
        rows * cols,
        1e9
    );

    vector<int> parent(
        rows * cols,
        -1
    );

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;

    pq.push({0,start});

    while(!pq.empty())
    {
        int currentDistance =
            pq.top().first;

        int currentNode =
            pq.top().second;

        pq.pop();

        if(currentDistance >
            dist[currentNode])
        {
            continue;
        }

        for(int j = 0;
            j < graph[currentNode].size();
            j++)
        {
            int nextNode =
                graph[currentNode][j]
                .first;

            int weight =
                graph[currentNode][j]
                .second;

            if(currentDistance +
                weight
                <
                dist[nextNode])
            {
                dist[nextNode]
                    =
                    currentDistance
                    + weight;

                parent[nextNode]
                    =
                    currentNode;

                pq.push(
                {
                    dist[nextNode],
                    nextNode
                });
            }
        }
    }

    cout << "Shortest Distance = "
         << dist[end]
         << endl;

    // Reconstruct Path
    vector<int> path;

    int current = end;

    while(current != -1)
    {
        path.push_back(current);

        current =
            parent[current];
    }

    cout << "Path : ";

    for(int i =
            path.size()-1;
        i >= 0;
        i--)
    {
        cout
            << path[i];

        if(i != 0)
        {
            cout
                << " -> ";
        }
    }

    cout << endl;

    // Draw Path
    for(int i = 0;
        i < path.size();
        i++)
    {
        int node =
            path[i];

        int r =
            node / cols;

        int c =
            node % cols;

        if(maze[r][c] != 'S' &&
           maze[r][c] != 'E')
        {
            maze[r][c] = '*';
        }
    }

    cout << endl;

    for(int i = 0;i < rows;i++){
        cout<< maze[i]<< endl;
    }
}