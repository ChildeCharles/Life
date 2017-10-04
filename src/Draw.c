#include<stdio.h>
#include <stdlib.h>
#include<png.h>
/*PNGlib requested info*/
int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void write_png_file(char* file_name) {
	FILE *fp = fopen(file_name, "wb");
	if (!fp)
		printf("[write_png_file] File %s could not be opened for writing", file_name);

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

	if (!png_ptr)
		printf("[write_png_file] png_create_write_struct failed");

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
		printf("[write_png_file] png_create_info_struct failed");

	if (setjmp(png_jmpbuf(png_ptr)))
		printf("[write_png_file] Error during init_io");

	png_init_io(png_ptr, fp);

	if (setjmp(png_jmpbuf(png_ptr)))
		printf("[write_png_file] Error during writing header");

	png_set_IHDR(png_ptr, info_ptr, width, height,
			bit_depth, color_type, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	png_write_info(png_ptr, info_ptr);

	if (setjmp(png_jmpbuf(png_ptr)))
		printf("[write_png_file] Error during writing bytes");

	png_write_image(png_ptr, row_pointers);

	if (setjmp(png_jmpbuf(png_ptr)))
		printf("[write_png_file] Error during end of write");

	png_write_end(png_ptr, NULL);

	for (y=0; y<height; y++)
		free(row_pointers[y]);
	free(row_pointers);

	fclose(fp);
}

void process_file(int** board, int rows, int cols) {
	width = cols;
	height = rows;
	bit_depth = 8;
	color_type = PNG_COLOR_TYPE_GRAY;

	number_of_passes = 7;
	row_pointers = (png_bytep*) malloc(sizeof(png_bytep) * height);
	for (y=0; y<height; y++)
		row_pointers[y] = (png_byte*) malloc(sizeof(png_byte) * width);
	for (y=0; y<height; y++) {
		png_byte* row = row_pointers[y];
		for (x=0; x<width; x++) {
			/*Changes here*/
			if(board[y][x] == 1)
			{
				row[x] = 0; /*Pomaluj na czarno*/
			}
			else if(board[y][x] == 0)
			{
				row[x] = 255; /*Pomaluj na bialo*/
			}  
			/*Should be end of changes*/
			printf("Pixel at position [ %d - %d ] has RGBA values: %d\n",
					x, y, row[x]);
		}
	}
}
int Draw(int** board, int rows, int cols, char* outfile)
{
	process_file(board, rows, cols);
	write_png_file(outfile);
	return 0;
}

int DrawSymbols(int** board, int rows, int cols, char* outfile)
{
	FILE *out = fopen(outfile,  "w");
	int i, j;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			fprintf(out, "%d ", board[i][j]);
		}
		fprintf(out, "\n");
	}
	return 0;
}

