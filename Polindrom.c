#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* text;
    printf("Введите строку:");
    scanf("%m[^\n]",&text);
 
   int len = strlen(text);
    printf("Введено %d символов\n", len);
    
    int i, j, k;
    char* answer = calloc(1, sizeof(char));
    j = 0;
    k = 0;
        for (int i = 0;i < len; i++)
        {
            if( ( (text[i] > 64 ) && (text[i] < 91 ) ) || ( ((text[i] > 96 ) && (text[i] < 123 )) )   )
            {
                if ((text[i] > 64 ) && (text[i] < 91 ))
                {
                    answer[j] = text[i];
                    printf("%c",answer[j]);
                    j++;
                    answer = (char*)realloc(answer, 1);
                }
                else
                {
                    answer[j] = text[i] - (97-65);
                    printf("%c",answer[j]);
                    j++;
                    answer = (char*)realloc(answer, 1);
                }
            }
        }
    printf("\n");
    int answlen = strlen(answer) - 1;

        for (int i = 0; i < answlen/2; i++)
        {
            if(answer[i] == answer[answlen - i])
            k++;
        }
    if (k > (answlen/2) - 1)
    {
        printf("%s - полиндром", text);        
    }
    else
    {
        printf("%s - не полиндром", text);
    }
}