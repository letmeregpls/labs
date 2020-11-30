#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void decryption(char crypttext[], int i, int j, int k, int l, int m, int crylen);

int main()
{
        setlocale(LC_ALL,"Russian");

       char* crypttext;
    printf("Введите строку:");
    scanf("%m[^\n]",&crypttext);
 
    int crylen = strlen(crypttext);
    printf("Введено %d символов\n", crylen);

    int pos,i,j,k,l,m,b;

    for(int i = 65; i < 91; i++)     //Первый символ ключа
    {   
        for(int j = 65; j < 91; j++)     //Второй символ ключа
        {
            for(int k = 65; k < 91; k++)     //Третий символ ключа
            {
                for(int l = 65; l < 91; l++)     //Четвёртый символ ключа
                {
                    for(int m = 65; m < 91; m++)
                    {
                        decryption(crypttext, i, j, k, l, m, crylen);
                    }
                }
            }
        }  
    }

free (crypttext);
return (0);
}

        void decryption(char crypttext[], int i, int j, int k, int l, int m, int crylen)
        {
            int keypos = 1;
            int count = 0; 
            char encrypt[crylen];
                   for(int pos = 0; pos < crylen; pos++)
                    {
                            if(keypos == 1)                                                     
                            {                                                                   
                                encrypt[pos] = (crypttext[pos] ^ i);                            
                            }                                                                                                                                    
                            if(keypos == 2)                                                     
                            {                                                                   
                                encrypt[pos] = (crypttext[pos] ^ j);                            
                            }                                                                                                                                       
                            if(keypos == 3)                                                     
                            {                                                                   
                                encrypt[pos] = (crypttext[pos] ^ k);                            
                            }                                                                                                                                       
                            if(keypos == 4)                                                     
                            {                                                                   
                                encrypt[pos] = (crypttext[pos] ^ l);                            
                            } 
                            if(keypos == 5)                                                     
                            {                                                                   
                                encrypt[pos] = (crypttext[pos] ^ m);                            
                            }                                                                
                        keypos++;                                                               
                        if (keypos == 6)                                                        
                            keypos = 1;                                                                                                                       //
                      encrypt[crylen]='\0';
                        if(pos == crylen-1)
                        {   
                            for (int f = 0; f < crylen; f++)
                            {
                                    if( ( (encrypt[f] > 64)&&(encrypt[f] < 91) )||( (encrypt[f] > 96)&&(encrypt[f] < 123) ) )
                                    count++;
                                }
                                if(count == crylen)
                                {
                                printf("для ключа %c%c%c%c%c    ", i, j, k, l, m);
                                printf("Расшифрованный текст: %s\n", encrypt);
                            }
                        }
                    }
        }