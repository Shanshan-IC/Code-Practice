/*1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.*/

//record the row or col need to be zero

#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void setZero(vector<vector<int>> &a, int row, int col)
{
	if (a.empty())
		return;
	bool rows[row], cols[col];
	memset(rows, false, sizeof(rows));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == 0)
			{
				rows[i] = true;
				cols[j] = true;
			}
		}
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (rows[i] || cols[j])
				a[i][j] = 0;
}