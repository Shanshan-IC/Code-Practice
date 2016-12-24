/*1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?*/
/*solution: Because we're rotating the matrix by 90 degrees, the easiest way to do this is to implement
the rotation in layers. We perform a circular rotation on each layer, moving the top
edge to the right edge, the right edge to the bottom edge, the bottom edge to the left
edge, and the left edge to the top edge.*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
	if (matrix.empty())
		return;

	int row = matrix.size();
	int col = matrix[0].size();
	//according the diagonal
	for (int i = 0; i < row-1; i++)
		for (int j = 0; j < col-1; j++)
			swap(matrix[i][j], matrix[row - j - 1][col-i-1]);

	//according the center horizontal
	for (int i = 0; i < row / 2; i++)
		for (int j = 0; j < col; j++)
			swap(matrix[i][j], matrix[row - i - 1][j]);

	//print out
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}


}