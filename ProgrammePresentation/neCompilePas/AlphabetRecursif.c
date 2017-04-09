void printRecursiveAlphabet(char currentChar); 

int32_t main()
{
    printRecursiveAlphabet('a');
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
}
