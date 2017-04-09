void printRecursiveAlphabet(char currentChar); 

int32_t main()
{
    printRecursiveAlphabet('a');
    putchar(10);
    return 0;
}

void printRecursiveAlphabet(char currentChar)
{
    putchar(currentChar);
    putchar(' ');
    if (currentChar != 'z')
    {
        printRecursiveAlphabet(currentChar + 1);
    }
    putchar(0);
}
