#include <iostream>
#include <vector>
using namespace std;

void rotate90Clockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < m - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][m - 1 - j];
            matrix[n - 1 - i][m - 1 - j] = matrix[j][m - 1 - i];
            matrix[j][m - 1 - i] = temp;
        }
    }
}

vector<int> rotateTheImage(vector<int> inputImage)
{
    int n = inputImage[0];
    int row = inputImage[1];
    int col = inputImage[2];

    vector<vector<int>> matrix(row, vector<int>(col));
    int r = 0, c = 0, count = 0;
    for (int i = 3; i < n; i++)
    {
        matrix[r][c] = inputImage[i];
        if (count == col)
        {
            r++;
            c = 0;
        }
        else
        {
            c++;
        }
    }

    rotate90Clockwise(matrix);

    vector<int> ans;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }
    return ans;
}

int main()
{
    vector<int> image = {8, 2, 3, 1, 2, 3, 4, 5, 6};

    vector<int> rotatedImage = rotateTheImage(image);

    for (auto r : rotatedImage)
        cout << r << " ";
    return 0;
}
