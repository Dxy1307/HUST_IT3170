// Tìm hình chữ nhật tạo nên bởi các bit 1 có diện tích lớn nhất
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        } else {
            int top = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[top] * width);
    }
    return maxArea;
}

int maxRectangleArea(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                heights[j] += 1;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << maxRectangleArea(matrix) << endl;

    return 0;
}

// Dxy