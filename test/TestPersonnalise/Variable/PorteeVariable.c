int32_t main()
{
    int32_t a = 3;
    {
    	int32_t a = 50;
    	int32_t b = 40;
    }
    int32_t b = 6;
    return a + b; // Expected return : 9
}
