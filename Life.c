#include<stdio.h>
#include<stdlib.h>
#include "src/Input.h"
#include "src/Simulation.h"
int main(int argc, char** argv){
	if(argc < 3 || argc > 4)
	{
		printf("Incorrect input. Usage: ./Life [%s] [%s] [%s] \n", "%s", "%d", "%d");
		printf("%s - Name of file which contains first generation. Must be file containing only 0 & 1. Check if you don't have empty line at the end of your file!\n", "%s");
		printf("%s - Number of generations you want to make. Must be number higher than 0. Value after coma will be ommited.\n", "%d");
		printf("%s - Every %s will be printed. Allows ommiting similar generations. Must be number higher than 0. Value after coma will be ommited. Optional. Defaultly set as 1 -> every generation is printed.\n", "%d", "%d");
		return 1;
	}
	char* filename = argv[1];
	int generationNumber = atoi(argv[2]);
	int skippedGenerations = 1;
	if(argc == 4)
	{
		skippedGenerations = atoi(argv[3]);
	}
	if(generationNumber < 1)
	{
		printf("generationNumber '%d' isn't higher than 0. \n", generationNumber);
		return 2;
	}
	if(skippedGenerations < 1)
	{
		printf("skippedGenerations '%d' isn't higher than 0. \n", skippedGenerations);
		return 3;
	
	}
	int i,j;
	int** board = makeboard(filename);
	int rows = getrows(filename);
	int cols = getcols(filename);

	Simulation(board, rows, cols, generationNumber, skippedGenerations);





	freeboard(board, rows, cols);
return 0;
}
