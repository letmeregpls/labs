#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float a, b, step, diapazon, count, x, j;
    int i;
    printf("Введите левую границу>> \n");
    scanf("%f", &a);
    printf("Введите правую границу>> \n");
    scanf("%f", &b);
    printf("Введите длину шага>> \n");
    scanf("%f", &step);
        if (step <= 0)
        {
            printf("Некоректный ввод данных");
            _Exit (EXIT_SUCCESS);
        }
    diapazon = b - a;
    count = diapazon / step;
        if (count < 1)
        {
            printf("Некоректный ввод данных");
            _Exit (EXIT_SUCCESS);
        }

        for (int i = 0; i<count; i++)
            {
                x = a+step*i;
                j=(1+x);
                if (j<0)
                    {
                        printf("Не существует log от отрицательного числа \n");
                    }   
                else
                    {
                    printf("Для x = %.7f\ty = %.7f \n", x, log(j));
                    }
            }
    return 0;
}