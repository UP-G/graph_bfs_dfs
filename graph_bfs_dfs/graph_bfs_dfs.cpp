#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void dfs(bool** matrS, int n, int start) {
    stack <int> q;
    bool** matrSS = new bool* [n];
    for (int i = 0; i < n; i++)
        matrSS[i] = new bool[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) matrSS[i][j] = matrS[i][j];
    q.push(start);
    matrSS[start][start] = 1;
    cout << endl << "Обход в глубину: " << " ";
    while (!q.empty()) {
        start = q.top();
        cout << start << " ";
        q.pop();
        for (int u = 0; u < n; u++) {
            if (matrSS[start][u] and !matrSS[u][u]) {
                q.push(u);
                matrSS[u][u] = 1;
            }
        }
    }
}
void bfs(bool** A, int N, int start) {
    queue <int> q;
    bool* visited = new bool[N];
    bool* inqueue = new bool[N];
    int cur; // номер посещаемой вершины
    for (int i = 0; i < N; i++)
        visited[i] = inqueue[i] = false;
    q.push(start);
    visited[start] = inqueue[start] = true;
    cout << endl << "Обход в ширину: " << " ";
    while (!q.empty())
    {
        cur = q.front();
        cout << cur << " ";
        visited[cur] = true;
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (!inqueue[i] && A[cur][i])
            {
                q.push(i);
                inqueue[i] = true;
            }
        }

    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int n, start;
    cout << "n= ";
    cin >> n;
    bool** matrS = new bool* [n];
    for (int i = 0; i < n; i++)
        matrS[i] = new bool[n];
    for (int i = 0; i < n; i++)
    {
        if (n - i - 1 > 0)
            cout << "Для вершины " << i + 1 << " смежность для упорядоченных " << n - i - 1 << " вершин\n";
        matrS[i][i] = 0;
        for (int j = i + 1; j < n; j++)
        {
            bool tp;
            cin >> tp;
            matrS[j][i] = matrS[i][j] = tp;
        }
    }
    cout << "\nStart(v)= ";
    cin >> start;
    bfs(matrS, n, start);
    dfs(matrS, n, start);
}