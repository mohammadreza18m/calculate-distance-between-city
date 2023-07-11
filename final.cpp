//mohammadreza abdollahpour & sarina karami
#include <iostream>

using namespace std;

const int INF = 1e9; // A large value to represent infinity

int main()
{
    int n;
    int x;
    cin >> n;
    int G[n][n];
    int dist[n];
    bool visited[n] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> G[i][j];
        }
    }
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        dist[i] = (i == x) ? 0 : INF;
    }

    for (int k = 0; k < n - 1; k++)
    {
        int minDist = INF;
        int minIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                minIndex = i;
            }
        }

        visited[minIndex] = true;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && G[minIndex][j] != 0 && dist[minIndex] != INF && dist[minIndex] + G[minIndex][j] < dist[j])
            {
                dist[j] = dist[minIndex] + G[minIndex][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }

    return 0;
}
