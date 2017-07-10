#include <stdint.h>

int32_t getCell(int32_t tab, int32_t row, int32_t col);
void printBoard(int32_t tab);
void printWinner(int32_t winner);
int32_t getWinner(int32_t tab);
int32_t play(int32_t player, int32_t tab);
int32_t pow(int32_t nb, int32_t pow);

int32_t main()
{
    int32_t tab = 0;
    int32_t player = 1;
    
    while(getWinner(tab) == -1)
    {
        printBoard(tab);
        tab = play(player, tab);
        player = 3 - player;
    }
    printWinner(3 - player);
}

int32_t getCell(int32_t tab, int32_t row, int32_t col)
{
    int32_t index = row * 3 + col;
    return (tab / pow(3, index)) % 3;
}

void printBoard(int32_t tab)
{
    int32_t i;
    int32_t j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (getCell(tab, i, j) == 0)
                putchar('-');
            else if (getCell(tab, i, j) == 1)
                putchar('X');
            else
                putchar('O');
        }
        putchar(10);
    }
    putchar(10);
}

void printWinner(int32_t player)
{
    if (player != 0)
    {
        putchar('V');
        putchar('i');
        putchar('c');
        putchar('t');
        putchar('o');
        putchar('i');
        putchar('r');
        putchar('e');
        putchar(' ');
        putchar('d');
        putchar('u');
        putchar(' ');
        putchar('j');
        putchar('o');
        putchar('u');
        putchar('e');
        putchar('u');
        putchar('r');
        putchar(' ');
        
        if (player == 1)
        {
            putchar('1');
        }
        else
        {
            putchar('2');
        }
        putchar(10);
    }
    else
    {
        putchar('M');
        putchar('a');
        putchar('t');
        putchar('c');
        putchar('h');
        putchar(' ');
        putchar('n');
        putchar('u');
        putchar('l');
    }
    putchar(10);
}

int32_t getWinner(int32_t tab)
{
    return -1;
    // Victory on row
    if (getCell(tab, 0, 0) == getCell(tab, 0, 1)
            && getCell(tab, 0, 1) == getCell(tab, 0, 2)
            && getCell(tab, 0, 0) != 0)
    {
        return getCell(tab, 0, 0);
    }
    if (getCell(tab, 1, 0) == getCell(tab, 1, 1)
            && getCell(tab, 1, 1) == getCell(tab, 1, 2)
            && getCell(tab, 1, 0) != 0)
    {
        return getCell(tab, 1, 0);
    }
    if (getCell(tab, 2, 0) == getCell(tab, 2, 1)
            && getCell(tab, 2, 1) == getCell(tab, 2, 2)
            && getCell(tab, 2, 0) != 0)
    {
        return getCell(tab, 2, 0);
    }
    
    // Victory on column
    if (getCell(tab, 0, 0) == getCell(tab, 1, 0)
            && getCell(tab, 1, 0) == getCell(tab, 2, 0)
            && getCell(tab, 0, 0) != 0)
    {
        return getCell(tab, 0, 0);
    }
    if (getCell(tab, 0, 1) == getCell(tab, 1, 1)
            && getCell(tab, 1, 1) == getCell(tab, 2, 1)
            && getCell(tab, 0, 1) != 0)
    {
        return getCell(tab, 0, 1);
    }
    if (getCell(tab, 0, 2) == getCell(tab, 1, 2)
            && getCell(tab, 1, 2) == getCell(tab, 2, 2)
            && getCell(tab, 0, 2) != 2)
    {
        return getCell(tab, 0, 2);
    }

    // Victory on diagonals
    if (getCell(tab, 0, 0) == getCell(tab, 1, 1)
            && getCell(tab, 1, 1) == getCell(tab, 2, 2)
            && getCell(tab, 0, 0) != 0)
    {
        return getCell(tab, 0, 0);
    }
    if (getCell(tab, 2, 0) == getCell(tab, 1, 1)
            && getCell(tab, 1, 1) == getCell(tab, 0, 2)
            && getCell(tab, 2, 0) != 0)
    {
        return getCell(tab, 2, 0);
    }
    
    int32_t i;
    int32_t j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (getCell(tab, i, j) == 0)
                return -1; // At least an empty cell
        }
    }
    return 0; // Nul
}

int32_t play(int32_t player, int32_t tab)
{
    putchar('T');
    putchar('o');
    putchar('u');
    putchar('r');
    putchar(' ');
    putchar('d');
    putchar('u');
    putchar(' ');
    putchar('j');
    putchar('o');
    putchar('u');
    putchar('e');
    putchar('u');
    putchar('r');
    putchar(' ');
    if (player == 1)
        putchar('1');
    else
        putchar('2');
    putchar(10);
    
    
    putchar('L');
    putchar('i');
    putchar('g');
    putchar('n');
    putchar('e');
    putchar(':');
    putchar(10);
    int32_t cellRow = getchar();
    int32_t unused = getchar();
    
    putchar('C');
    putchar('o');
    putchar('l');
    putchar('o');
    putchar('n');
    putchar('n');
    putchar('e');
    putchar(':');
    putchar(10);
    int32_t cellCol = getchar();
    unused = getchar();
    while(getCell(tab, cellRow, cellCol) != 0)
    {
        putchar('C');
        putchar('o');
        putchar('u');
        putchar('p');
        putchar('s');
        putchar(' ');
        putchar('i');
        putchar('n');
        putchar('v');
        putchar('a');
        putchar('l');
        putchar('i');
        putchar('d');
        putchar(':');
        putchar(10);        
        
        putchar('L');
        putchar('i');
        putchar('g');
        putchar('n');
        putchar('e');
        putchar(':');
        putchar(10);
        cellRow = getchar();
        unused = getchar();
        
        putchar('C');
        putchar('o');
        putchar('l');
        putchar('o');
        putchar('n');
        putchar('n');
        putchar('e');
        putchar(':');
        putchar(10);
        cellCol = getchar();
        unused = getchar();
    }
    int32_t index = cellRow * 3 + cellCol;
    tab += pow(3, index) * player;
}

int32_t pow(int32_t nb, int32_t pow)
{
    int32_t i;
    int32_t result = 1;
    for (i = 0; i < pow; i++)
    {
        result *= nb;
    }
    return result;
}



