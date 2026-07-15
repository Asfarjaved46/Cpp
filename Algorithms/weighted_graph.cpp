#include<iostream>
using namespace std;

#include<vector>
#include<queue>

int main(){

    vector<vector<pair<int,int>>> graph(4);

graph[0].push_back({1,4});
graph[0].push_back({2,1});

graph[1].push_back({0,4});
graph[1].push_back({3,2});

graph[2].push_back({0,1});
graph[2].push_back({3,5});

graph[3].push_back({1,2});
graph[3].push_back({2,5});

vector<int> dist(4,1e9);
dist[0] = 0;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

 int start = 0;

    dist[start] = 0;

    // (distance, node)
    pq.push({0, start});

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        // Ignore outdated entries
        if (currentDistance > dist[currentNode])
        {
            continue;
        }

        for (int j = 0; j < graph[currentNode].size(); j++)
        {
            int nextNode =
                graph[currentNode][j].first;

            int weight =
                graph[currentNode][j].second;

            if (currentDistance + weight
                    < dist[nextNode])
            {
                dist[nextNode] =
                    currentDistance + weight;

                pq.push(
                {
                    dist[nextNode],
                    nextNode
                });
            }
        }
    }

    cout << "Shortest distances from node "
         << start << ":\n";

    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " : "
             << dist[i] << endl;
    }
}



// pq.push({0,0});

// pq.top().first;
// pq.top().second; 

    // for(int i = 0;i<graph.size();i++){
    //     cout<<i<<" ->";
    //     for(int j = 0;j<graph[i].size();j++){
    //         cout<<"("<<graph[i][j].first<<" , "<<graph[i][j].second<<")";
    //     }
    //     cout<<endl;
    // }

}

