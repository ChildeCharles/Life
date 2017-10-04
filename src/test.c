#include<stdio.h>
#include<stdlib.h>
	
int main(int argc, char** argv)
	{
	FILE *in = fopen("Data1", "r");
	char letter;
	int counter;
	int** board;
	int i, j;
	int rows = 0;
	int cols = 0;

	if(in == NULL)
	{
		printf("Can't open file to read or is empty!\n");
		exit(1);
	}
	while((letter = getc(in)) != EOF)
	{
		printf("%c", letter);
		if(rows == 0 && (letter == '0' || letter == '1'))
		{
			cols++;
		}
		if(letter == '\n')
		{
			rows++;
		}
	}
printf("rows: %d\ncols: %d\n", rows, cols);
	board = (int**)malloc(rows*sizeof(int *));
        for(i = 0; i<cols;i++)
        {
                board[i] = (int*)malloc(cols*sizeof(int));
        }
	i = 0;
	j = 0;
	fclose(in);
	in = fopen("Data1", "r");
printf("\n\n\n");
//LOLX
	while((letter = getc(in)) !=EOF)
	{	
		if(letter == '\n')
		{
			i++;
			j = 0;
		}
		else if(letter == '0')
		{
			board[i][j] = 0;
			j++;
		}
		else if(letter == '1')
		{
			board[i][j] = 1;
			j++;
		}
		else if(letter == ' ') ;
		else
		{
                        printf("Encounter '%c'. Incorrect data in file: %s\n", letter, "Data1");
			return 1;
                }
	}
//TEST
printf("Rows: %d\nCols: %d\n", rows, cols);
for(i = 0; i < rows; i++)
{
printf("\n");
	for(j = 0; j < cols; j++)
		printf("%d ", board[i][j]);
}
	return 0;
	}

int freeboard(int** board);
