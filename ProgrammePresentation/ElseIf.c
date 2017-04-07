int32_t main()
{
    int32_t a;
    a = getchar();
    if (a == '0')
    {
        putchar('0');
        putchar(10);
    }
    else if (a == '1')
    {
        putchar('1');
        putchar(10);
    }
    else
    {
        putchar('3');
        putchar(10);
    }
    return 0;
}
