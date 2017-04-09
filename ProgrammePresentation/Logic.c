int32_t main ()
{
    char a = getchar() - '0';
    char unused = getchar();
    char b = getchar() - '0';
    if (a && b)
        putchar('&');
    if (a || b)
        putchar('|');
    putchar(10);
    return 0;
}
