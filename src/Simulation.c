#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Draw.h"
int Simulation(int** board, int rows, int cols, int generationNumber, int skippedGenerations)
{
	int i = 0;
	int j = 0;
	int n = 0; /*counter for generationNumber*/
	int skip = 1; /*counter for skippedGenerations*/
	char outfile[21] = {}; /*file in which created generation will be saved*/
	int counter;
	char stringNumber[4]; /*Used to give numbers to generations*/
	
	int** newboard = (int**)malloc(rows*sizeof(int *));
	for(i = 0; i < rows; i++)
       	{
		newboard[i] = (int*)malloc(cols*sizeof(int));
	}
	for(n = 0; n < generationNumber; n++)
	{
		/*Corners*/
		/*Upper Left*/
		counter = 0;
		if(board[0][1] == 1)
			counter++;
		if(board[1][0] == 1)
			counter++;
		if(board[1][1] == 1) 
			counter++;
		if((board[0][0] == 0 && counter == 3) || (board[0][0] == 1 && (counter == 2 || counter == 3) ) )
			newboard[0][0] = 1;
		else
			newboard[0][0] = 0;
		/*Upper Right*/
		counter = 0;
		if(board[0][cols-2] == 1)
			counter++;
		if(board[1][cols-1] == 1)
			counter++;
		if(board[1][cols-2] == 1)     
			counter++;
		if((board[0][cols-1] == 0 && counter == 3) || (board[0][cols-1] == 1 && (counter == 2 || counter == 3) ) )
			newboard[0][cols-1] = 1;
		else
			newboard[0][cols-1] = 0;
		/*Lower Left*/ 
		counter = 0;
		if(board[rows-2][0] == 1)
			counter++;
		if(board[rows-2][1] == 1)
			counter++;
		if(board[rows-1][1] == 1)     
			counter++;
		if((board[rows-1][0] == 0 && counter == 3) || (board[rows-1][0] == 1 && (counter == 2 || counter == 3) ) )
			newboard[rows-1][0] = 1;
		else
			newboard[rows-1][0] = 0;
		/*Lower Right*/	
		counter = 0;
		if(board[rows-2][cols-2] == 1)
			counter++;
		if(board[rows-2][cols-1] == 1)
			counter++;
		if(board[rows-1][cols-2] == 1)     
			counter++;
		if((board[rows-1][cols-1] == 0 && counter == 3) || (board[rows-1][cols-1] == 1 && (counter == 2 || counter == 3) ) ) 
			newboard[rows-1][cols-1] = 1;
		else
			newboard[rows-1][cols-1] = 0;
		/*Sides*/
		/*Left*/
		for(i = 1; i < rows-1; i++)
		{
			counter = 0;
			if(board[i-1][0] == 1)
				counter++;
			if(board[i-1][1] == 1)
				counter++;
			if(board[i+1][0] == 1)
				counter++;
			if(board[i+1][1] == 1)
				counter++;
			if(board[i][1] == 1)
				counter++;
			if((board[i][0] == 0 && counter == 3) || (board[i][0] == 1 && (counter == 2 || counter == 3) ) )
				newboard[i][0] = 1;
			else
				newboard[i][0] = 0;
		}
		/*Right*/
		for(i = 1; i < rows-1; i++)
		{
			counter = 0;
			if(board[i-1][cols-2] == 1)
				counter++;
			if(board[i-1][cols-1] == 1)
				counter++;
			if(board[i+1][cols-2] == 1)
				counter++;
			if(board[i+1][cols-1] == 1)
				counter++;
			if(board[i][cols-2] == 1)
				counter++;
			if((board[i][cols-1] == 0 && counter == 3) || (board[i][cols-1] == 1 && (counter == 2 || counter == 3 ) ) )
				newboard[i][cols-1] = 1;
			else
				newboard[i][cols-1] = 0;	
		}
		/*Upper*/
		for(j = 1; j < cols-1; j++)
		{
			counter = 0;
			if(board[0][j-1] == 1)
				counter++;
			if(board[0][j+1] == 1)
				counter++;
			if(board[1][j-1] == 1)
				counter++;
			if(board[1][j] == 1)
				counter++;
			if(board[1][j+1] == 1)
				counter++;
			if((board[0][j] == 0 && counter == 3) || (board[0][j] == 1 && (counter == 2 || counter == 3) ) )
				newboard[0][j] = 1;
			else
				newboard[0][j] = 0;
		}
		/*Lower*/
		for(j = 1; j < cols-1; j++)
		{
			counter = 0;
			if(board[rows-2][j-1] == 1)
				counter++;
			if(board[rows-2][j] == 1)
				counter++;
			if(board[rows-2][j+1] == 1)
				counter++;
			if(board[rows-1][j-1] == 1)
				counter++;
			if(board[rows-1][j+1] == 1)
				counter++;
			if((counter == 3 && board[rows-1][j] == 0) || (board[rows-1][j] == 1 && (counter == 2 || counter == 3) ) )
				newboard[rows-1][j] = 1;
			else
				newboard[rows-1][j] = 0;
		}
		/*Middle of the Board*/
		for(i=1; i < rows-1; i++)
		{
			for(j=1; j < cols-1; j++)
			{
				counter = 0;
				if(board[i-1][j-1] == 1)
					counter++;
				if(board[i-1][j] == 1)
					counter++;
				if(board[i-1][j+1] == 1)
					counter++;
				if(board[i][j-1] == 1)
					counter++;
				if(board[i][j+1] == 1)
					counter++;
				if(board[i+1][j-1] == 1)
					counter++;
				if(board[i+1][j] == 1)
					counter++;
				if(board[i+1][j+1] == 1)
					counter++;
				if((board[i][j] == 0 && counter == 3) || (board[i][j] == 1 && (counter == 2 || counter == 3) ) )
					newboard[i][j] = 1;
				else
					newboard[i][j] = 0;
			}
		}
		/*Rewriting board. !Riskty Around Here!*/
		for(i = 0; i < rows; i++)
		{
			for(j = 0; j < cols; j++)
				board[i][j] = newboard[i][j];
		}
		/*Drawing and eventually skipping generations*/
		if(skip % skippedGenerations == 0)
		{	
			strcpy(outfile, "pictures/Drawing");
			sprintf(stringNumber, "%d", skip);
			strcat(outfile, stringNumber);
			strcat(outfile, ".txt");
			DrawSymbols(board, rows, cols, outfile);
			strcpy(outfile, "pictures/Drawing");
			strcat(outfile, stringNumber);
			strcat(outfile, ".png");
			Draw(board, rows, cols, outfile);
		}
		skip++;
		/*Closure for 'for' from before following Game Of Life rules*/			
	}
	return 0;
}
