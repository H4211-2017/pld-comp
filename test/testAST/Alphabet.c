#include <stdint.h>
int32_t main()
{
    int32_t a;
    for (a = 97; a < 123; a = a + 1)
    {
        putchar(a);
        putchar(32);
    }
    return a;
}
