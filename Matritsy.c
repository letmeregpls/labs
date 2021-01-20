#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** create_matrix(int rows, int cols);
void scan_matrix(int** mat, int rows, int cols);
void rand_matrix(int** mat,int rows,int cols);
void print_matrix(int** mat, int rows, int cols);
void swap(int* a, int* b);
void move_max(int** mat, int rows, int cols);
void free_matrix(int** mat, int rows);


int main()
{
	int rows, cols;
int* a; 
int* b;
	printf("Enter the hight of matrix:");
	scanf("%d", &rows);
	printf("Enter the length of matrix:");
	scanf("%d", &cols);

	int** mat = create_matrix(rows, cols);
	rand_matrix(mat, rows, cols);
	print_matrix(mat, rows, cols);
	move_max(mat, rows, cols);
	free_matrix(mat, rows);
    swap(a,b);

	return 0;
}

		//Выделение пямяти
	int **create_matrix(int rows, int cols)
		{
			int** mat = malloc(rows*sizeof(int*));
			if (mat == NULL)
    			{
        		return NULL;
    			}

			for(int i = 0; i < cols; ++i)
				{
    			mat[i] = malloc(cols*sizeof(int));
				if (mat[i] == NULL)
        			{
						// если не выделилась память для строки, то нужно очистить то, что уже выделили
						// тут в цикле очищаем память выделенную для строк, а после память для указателей на строки
					while (i > 0)
						{
							i -= 1;
							free(mat[i]);
						}
					free(mat);
					return NULL;
        			}
				}
		return mat;
		}


		//Заполнение матрицы
	void rand_matrix(int** mat,int rows,int cols)
		{
			printf("Func_rand_working!\n");
			for (int i=0 ; i<rows; i++)
			{
				for (int j=0; j<cols; j++)
				{
				mat[i][j] = rand() % 10;
				}
			}
		}

		//Вывод матрицы
	void print_matrix(int** mat, int rows, int cols)
		{
			printf("Func_print_working:\n");
			for (int i=0 ; i<rows; i++)
				{
					for (int j=0; j<cols; j++)
					{
						printf("%4d",mat[i][j]);
					}
					puts("");
				}
			puts("");		
		}

	void move_max(int** mat, int rows, int cols)
        {
            // индексы наибольшего элемента
            int maxrow = 0;
            int maxcol = 0;

            // находим максимальный
            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < cols; j++) 
                {
                    if (mat[i][j] > mat[maxrow][maxcol]) 
                    {
                        maxrow = i;
                        maxcol = j;
                    }
                }
            }

            // двигаем столбик с максимальным на первое (нулевое) место
            for (int i = 0; i < rows; i++) 
            {
                swap(&mat[i][0], &mat[i][maxcol]);
            }

            // двигаем строку с максимальным на первое (нулевое) место
            for (int j = 0; j < cols; j++) 
            {
                swap(&mat[0][j], &mat[maxrow][j]);
            }
            void print_matrix(int** mat, int rows, int cols);
        }


	void free_matrix(int** mat, int rows)
		{
			printf("Func_free_working!\n");
			for (int i = 0; i < rows; i++)
			{
				free (mat[i]);
			}
		free(mat);
		}

    // swap меняет два элемента местами
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
