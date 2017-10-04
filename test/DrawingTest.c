#include<stdio.h>
#include "../src/Draw.h"
#include "../src/Input.h"
int main(int argc, char** argv){
int rows = 4;
int cols = 4;
int** board = makeboard("TestData");
Draw(board, rows, cols, "test2.png");
DrawSymbols(board, rows, cols, "test2.txt");
return 0;
}
