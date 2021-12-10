//
// Created by eagle on 2021/12/10.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        int inf = INT_MAX / 2;
        vector<vector<int>> path(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<int>> dp(n, vector<int>(1 << n, INT_MAX / 2));

        // 初始化边长矩阵，无权图，初始化边权值为1
        for (int i = 0; i < n; i++) {
            vector<int> &v = graph[i];
            path[i][i] = 0;
            for (int &x: v) {
                path[i][x] = 1;
                path[x][i] = 1;
            }
        }
        // floyd算法求各个点间路径长度
        floyd(graph, path, dist);
        printMatrix(path);
        // 状态压缩，记录dp矩阵
        dp_fill(dp, path);
        printMatrix(dp);
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i][(1 << n) - 1]);
        }
        return ans;
    }

    void floyd(vector<vector<int>> &graph,
               vector<vector<int>> &path,
               vector<vector<int>> &dist) {
        int n = graph.size();
        // floyd算法更新最短路径
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
//                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
                    if (path[i][j] > path[i][k] + path[k][j]) {
                        path[i][j] = path[i][k] + path[k][j];
                        dist[i][j] = k;
                    }
                }
            }
        }
    }

    void dp_fill(vector<vector<int>> &dp,
                 vector<vector<int>> &path) {
        int inf = INT_MAX / 2;
        int n = path.size();
        // 初始化dp矩阵
        for (int i = 0; i < n; i++) {
            dp[i][1 << i] = 0;
            dp[i][0] = 0;
        }
        //dp[i][j]表示从i出发，访问j的最短路径（j=00011表示访问第0,1个点）。
        for (int state = 0; state < (1 << n); state++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // 拆分：
                    // 例 i->1111(0,1,2,3)
                    // 拆成：path[i][0] + 0->1110
                    // 即：path[i][j] + dp[j][state-2^j]
                    if (path[i][j] != inf && (state & (1 << j))) {
                        dp[i][state] = min(dp[i][state],
                                           dp[j][state - (1 << j)] + path[i][j]);
                    }
                }
            }
        }
    }

    // 打印矩阵
    void printMatrix(vector<vector<int>> matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j: matrix[i]) {
                if (j != INT_MAX / 2) {
                    cout << j << "|";
                } else {
                    cout << "-|";
                }
            }
            cout << "\n";
        }
    }

    // 打印int的二进制表示
    void intToByte(int i, int n) {
        char *str = (char *) malloc((n + 1) * sizeof(char));
        memset(str, '0', (n + 1) * sizeof(char));
        int count = n - 1;
        str[n] = '\0';
        while (i > 0) {
            if ((i % 2) == 0) {
                str[count--] = '0';
            } else {
                str[count--] = '1';
            }
            i /= 2;
        }
        printf("%s", str);
    }

};

int main() {
    vector<vector<int>> graph = {{1, 2, 3},
                                 {0},
                                 {0},
                                 {0}};
    Solution solution;
    int n = solution.shortestPathLength(graph);
    cout << n << endl;
}
