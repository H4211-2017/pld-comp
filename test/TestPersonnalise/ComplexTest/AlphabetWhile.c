int32_t main ()
{
    int32_t a = 97;
    while (a < 123)
    {
        putchar(a);
        putchar(32);
        a += 1;
    }
    putchar(10); // \n
    return 0;
}
