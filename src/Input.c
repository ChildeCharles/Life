#include<stdio.h>
#include<stdlib.h>
int freeboard(int** board, int rows, int cols)
{	
	int i;
	for(i = 0; i < rows; i++)
	{
		free(board[i]);
	}
	free(board);
	return 0;	
}
int getrows(char* filename)
{
	FILE *in = fopen(filename, "r");
	char letter;
	int rows = 0;
	if(in == NULL)
	{
		printf("Can't open file to read or is empty!\n");
		exit(1);
	}
	while((letter = getc(in)) != EOF)
	{
		if(letter == '\n')
		{
			rows++;
		}
		else if(letter == '\0' || letter == '0' || letter == '1' || letter == ' ') ;
		else
		{
			printf("Encounter '%c'. Incorrect data in file: %s\n", letter, filename);
			exit(3);
		}
	}
	fclose(in);
	return rows;
}
int getcols(char* filename)
{
	FILE *in = fopen(filename, "r");
	char letter;
	int cols = 0;
	if(in == NULL)
	{
		printf("Can't open file to read or is empty!\n");
		exit(1);
	}
	while((letter = getc(in)) != EOF)
	{
		if(letter == '0' || letter == '1')
		{
			cols++;
		}
		else if(letter == '\n')
		{
			break;
		}
		else if(letter == '\0' || letter == '0' || letter == '1' || letter == ' ') ;
		else
		{
			printf("Encounter '%c'. Incorrect data in file: %s\n", letter, filename);
			exit(4);
		}
	}
	fclose(in);
	return cols;
}

int** makeboard(char* filename)
{
	FILE *in = fopen(filename, "r");
	char letter;
	int counter;
	int** board;
	int i, j;
	int rows = getrows(filename);
	int cols = getcols(filename);
	if(in == NULL)
	{
		printf("Can't open file to read or is empty!\n");
		exit(1);
	}
	/*Reserve memory*/
	board = (int**)malloc(rows*sizeof(int *));
	for(i = 0; i < rows; i++)
	{
		board[i] = (int*)malloc(cols*sizeof(int));
	}
	i = 0;
	j = 0;
	fclose(in);
	in = fopen(filename, "r");
	/*Read file to write it down */
	while((letter = getc(in)) !=EOF)
	{
		if(letter == '\n')
		{
			if(j != cols)
			{
				printf("Uneven table, check file: %s\n", filename);
				exit(5);
			}
			i++;
			j = 0;
		}
		if(letter == '0')
		{
			board[i][j] = 0;
			j++;
		}
		if(letter == '1')
		{
			board[i][j] = 1;
			j++;
		}
		if(letter == ' ' || letter == '0' || letter == '1' || letter == '\n' || letter == '\0') ;
		else
		{
			printf("Encounter '%c'. Incorrect data in file: %s\n", letter, filename);
			exit(2);
		}
	}
	fclose(in);
	return board;
}
