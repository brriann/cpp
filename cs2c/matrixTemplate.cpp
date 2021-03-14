#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename Object>
class matrix
{
public:
    matrix(int rows, int cols) : array(rows)
    {
        for (auto & thisRow : array)
        {
            thisRow.resize(cols);
        }
    }

    matrix(vector<vector<Object> > v) : array(v)
    {
        // copy ctr, v is lvalue
    }

    matrix(vector<vector<Object> > && v) : array(std::move(v))
    {
        // move ctr, v is rvalue
    }

    const vector<Object> & operator[](int row) const
    {
        return array[row];
    }

    vector<Object> & operator[](int row)
    {
        return array[row];
    }

    int numRows() const
    {
        return array.size();
    }

    int numCols() const
    {
        return numRows() ? array[0].size() : 0;
    }

private:
    vector<vector<Object> > array;
};

#endif // MATRIX_H

// test client, TODO, remove this
int main()
{
    vector<vector<int> > twoVector = {{1, 2}, {3, 4}};
    vector<vector<int> > threeVector = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    matrix<int> two = matrix<int>(twoVector);
    matrix<int> three = matrix<int>(threeVector);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << two[i][j] << "";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << three[i][j];
        }
        cout << endl;
    }

}