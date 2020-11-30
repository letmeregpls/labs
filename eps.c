#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float pogreshnost,h, raz, count, x, j, k;
float EPS = 1e-6;
int i, n;
int main()
{
    printf("Введите x в интервале (-1,1) >> \n");
    scanf("%f", &x);
        if ((x <= -1) || (x >= 1))
        {
            printf("Некоректный ввод данных");
            _Exit (EXIT_SUCCESS);
        }
    
    float summa = 0.0;
                n = 1;
                k = (pow(x, n)/n);
            while (fabs(k) > EPS)
            {
                summa += k;
                n++;
                k = (pow(-1,n-1)*pow(x, n)/n);
            }
                j=(1+x);   
                pogreshnost = fabs(summa - log(j)); 
                printf("Для x = %.6f \t log = %.6f \t ряд ~~ %.6f \n", x, log(j), summa);
                printf("Погрешность составляет ~~ %.6f", pogreshnost);
}