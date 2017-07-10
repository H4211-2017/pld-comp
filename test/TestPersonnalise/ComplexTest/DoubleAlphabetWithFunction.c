void printAlphabet(char prefixe);

int32_t main()
{
    int32_t a = 97;
    while (a < 123)
    {
        printAlphabet(a);
        a += 1;
    }
    return 0;
}

void printAlphabet(char prefixe)
{
    int32_t a;
    for (a = 97; a < 123; a += 1)
    {
        putchar(prefixe);
        putchar(a);
        putchar(' ');
    }
    putchar(10);
}
