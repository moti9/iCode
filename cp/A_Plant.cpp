#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix
{
    vector<vector<long long>> mat;

    Matrix(int n, int m)
    {
        mat.assign(n, vector<long long>(m, 0));
    }

    Matrix operator*(const Matrix &other)
    {
        int n = mat.size();
        int m = other.mat[0].size();
        int p = other.mat.size();

        Matrix result(n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < p; k++)
                {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }

        return result;
    }
};

Matrix matrixPower(Matrix base, long long exp)
{
    int n = base.mat.size();

    Matrix result(n, n);
    for (int i = 0; i < n; i++)
    {
        result.mat[i][i] = 1;
    }

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = result * base;
        }
        base = base * base;
        exp /= 2;
    }

    return result;
}

int main()
{
    long long n;
    cin >> n;

    Matrix transition(2, 2);
    transition.mat[0][0] = 3;
    transition.mat[0][1] = 1;
    transition.mat[1][0] = 1;
    transition.mat[1][1] = 1;

    Matrix result = matrixPower(transition, n);

    cout << result.mat[0][0] << endl;

    return 0;
}
