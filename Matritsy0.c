#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** create_matrix(int n, int m);
void scan_matrix(int** arr, int n, int m);
void rand_matrix(int** arr,int n,int m);
void print_matrix(int** arr, int n, int m);
void free_matrix(int** arr, int n);
int skalyar(int** arr, int n, int m)


int main()
{
	int n, m;

	printf("Enter the hight of matrix:");
	scanf("%d", &n);
	printf("Enter the length of matrix:");
	scanf("%d", &m);

	int** arr = create_matrix(n, m);
	rand_matrix(arr, n, m);
	print_matrix(arr, n, m);
	int skal = skalyar(arr, n, m);
	printf ("Скалярное произведение равно: %d", skal);
	free_matrix(arr,n)

	return 0;
}

		//Выделение пямяти
	int **create_matrix(int n, int m)
		{
			
			printf("Creating... \n");
			int** arr = malloc(n*sizeof(int*));
			if (arr == NULL) 
    			{
        		return NULL;
    			}

			for(int i = 0; i < m; ++i)
				{
    			arr[i] = malloc(m*sizeof(int)); 
				if (arr[i] == NULL)
        			{
						
					while (i > 0)
						{
							i -= 1;
							free(arr[i]); 
						}
					free(arr);
					return NULL;
        			}
				}
		return arr;
		}


		//Заполнение матрицы
	void rand_matrix(int** arr,int n,int m) 
		{
			printf("Func_rand_working!\n");
			for (int i=0 ; i<n; i++)
			{
				for (int j=0; j<m; j++)
				{
				arr[i][j] = rand() % 10; 
				}
			}
		}

		//Вывод матрицы
	void print_matrix(int** arr, int n, int m)
		{
			printf("Func_print_working:\n"); 
			for (int i=0 ; i<n; i++)
				{
					for (int j=0; j<m; j++)
					{
						printf("%4d",arr[i][j]);
					}
					puts(""); 
			puts("");		
		}
   
    void move_max(int** arr, int n, int m)
        {
           
            int maxn = 0;
            int maxm = 0;

            
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < m; j++) 
                {
                    if (arr[i][j] > arr[maxn][maxm]) 
                    {
                        maxn = i;
                        maxm = j;
                    }
                }
            }

            
            for (int i = 0; i < n; i++) 
            {
                swap(&arr[i][0], &arr[i][maxcol]);
            }

           
            for (int j = 0; j < m; j++) 
            {
                swap(&arr[0][j], &arr[maxn][j]);
            }
            void print_matrix(int** arr, int n, int m);
        }


	void free_matrix(int** arr, int n) 
		{
			printf("Func_free_working!\n");
			for (int i = 0; i < n; i++)
			{
				free (arr[i]);
			}
		free(arr); 
		}

  
