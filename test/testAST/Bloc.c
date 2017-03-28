int32_t main()
{
    int32_t a = 3;
    {
    	int32_t a = 5;
    	int32_t b = 4;
    }
    int32_t b = 6;
    a + b;
}
