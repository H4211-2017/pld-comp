#include<stdint.h>

void printPlaque(char lettre1, char lettre2, int32_t nombre, char lettre3, char lettre4);
void printNombre(int32_t nombre);

int32_t main()
{
    char lettre1 = 'A';
    char lettre2 = 'A';
    
    int32_t nombre = 1;
    
    char lettre3 = 'A';
    char lettre4 = 'A';
    
    while(1)
    {
        printPlaque(lettre1, lettre2, nombre, lettre3, lettre4);
        putchar(10);
        nombre += 1;
        if (nombre > 999)
        {  
            nombre = 1;
            lettre4 += 1;
            if (lettre4 > 'Z')
            {
                lettre4 = 'A';
                lettre3 += 1;
                if (lettre3 > 'Z')
                {
                    lettre3 = 'A';
                    lettre2 += 1;
                    if (lettre2 > 'Z')
                    {
                        lettre2 = 'A';
                        lettre1 += 1;
                        if (lettre1 > 'Z')
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

void printPlaque(char lettre1, char lettre2, int32_t nombre, char lettre3, char lettre4)
{
    putchar(lettre1);
    putchar(lettre2);
    putchar('-');
    printNombre(nombre);
    putchar('-');
    putchar(lettre3);
    putchar(lettre4);
}

void printNombre(int32_t nombre)
{
    int32_t chiffre3 = nombre % 10;
    int32_t chiffre2 = (nombre - chiffre3) % 100 / 10;
    int32_t chiffre1 = (nombre - chiffre3 - chiffre2 * 10) / 100;
    
    putchar(chiffre1 + '0');
    putchar(chiffre2 + '0');
    putchar(chiffre3 + '0');
}




