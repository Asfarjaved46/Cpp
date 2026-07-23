#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int main()
{
    vector<string> maze = {"S..", ".#.", "..E"};

    int rows = maze.size();
    int cols = maze[0].size();

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int sr, sc;
    int gr, gc;
    for(int i = 0; i < rows; i++)
{
    for(int j = 0; j < cols; j++)
    {
        if(maze[i][j] == 'S')
        {
            sr = i;
            sc = j;
        }

        if(maze[i][j] == 'E')
        {
            gr = i;
            gc = j;
        }
    }
}
    vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
    queue<pair<int, int>> q;
    dist[gr][gc] = 0;
    q.push({gr, gc});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Outside maze
            if (nr < 0 || nr >= rows ||
                nc < 0 || nc >= cols)
            {
                continue;
            }

            // Wall
            if (maze[nr][nc] == '#')
            {
                continue;
            }

            // First visit
            if (dist[nr][nc] == 1e9)
            {
                dist[nr][nc] = dist[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }

    cout << "Flood Fill Distance Map:\n\n";

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (maze[r][c] == '#')
            {
                cout << "# ";
            }
            else
            {
                cout << dist[r][c] << " ";
            }
        }

        cout << endl;
    }

    cout << "\nRobot Path:\n";

    int r = sr;
    int c = sc;

    cout << "(" << r << "," << c << ")";

    while (!(r == gr && c == gc))
    {
        int bestR = r;
        int bestC = c;
        int bestDist = dist[r][c];

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= rows ||
                nc < 0 || nc >= cols)
            {
                continue;
            }

            if (maze[nr][nc] == '#')
            {
                continue;
            }

            if (dist[nr][nc] < bestDist)
            {
                bestDist = dist[nr][nc];
                bestR = nr;
                bestC = nc;
            }
        }

        r = bestR;
        c = bestC;

        cout << " -> (" << r << "," << c << ")";
    }

    cout << endl;

    return 0;
}
