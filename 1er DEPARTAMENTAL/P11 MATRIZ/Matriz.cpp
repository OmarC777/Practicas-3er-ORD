#include "Matriz.h"
#include <iostream>
using namespace std;
Matriz::Matriz()
{
}

Matriz::~Matriz()
{
}
void Matriz::Multi(int A[2][2], int cons)
{
	int res[2][2];
	cout << "Producto de matrices" << endl;
	for (int i = 0; i < 2; i++ )
	{
		for (int j = 0; j < 2; j++)
		{
			res[i][j] = A[i][j] * cons;
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}
} 
void Matriz::Multi(int A[2][2], int B[2][2])
{
	int res[2][2] = {0};
	cout << "Producto de matrices" <<endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res[i][j] += A[i][k] * B[k][j];
			}
			cout << res[i][j] << "\t";
		}
		cout << endl;
	}
}
