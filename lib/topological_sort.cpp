#include <bits/stdc++.h>
using namespace std;

template <class T>
void topological_sort_dfs(const vector<vector<T>> &graph, int from, vector<bool> &visited, vector<T> &result) {
    visited[from] = true;

    for (const auto &to : graph[from]) {
        if (!visited[to]) {
            topological_sort_dfs(graph, to, visited, result);
        }
    }

    // 帰りがけ順
    result.push_back(from);
}

template <class T>
vector<T> topological_sort(const vector<vector<T>> &graph) {
    vector<T> result;
    vector<bool> visited(graph.size());

    for (int i = 0; i < static_cast<int>(graph.size()); ++i) {
        if (!visited[i]) {
            topological_sort_dfs(graph, i, visited, result);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}
