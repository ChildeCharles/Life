#include<stdio.h>
#include<stdlib.h>
#include "../src/Input.h"

int main(int argc, char** argv){
	
	char* filename = "TestData";
        int i,j;
        int** board = makeboard(filename);
        int rows = getrows(filename);
        int cols = getcols(filename);
	printf("Rows: %d\nCols: %d\n", rows, cols);
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
return 0;
}
