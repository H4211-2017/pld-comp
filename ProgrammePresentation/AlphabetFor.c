int32_t main ()
{
    int32_t a;
    for (a = 97; a < 123; a += 1)
    {
        putchar(a);
        putchar(' ');
    }
    putchar(10); // \n
    return 0;
}
