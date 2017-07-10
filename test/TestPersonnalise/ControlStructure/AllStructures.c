int32_t main()
{
    int32_t a = 50;
	if(5)
	{
		a = a - 5;
	}
	else
	{
		a = a + 5;
	}
	
	int32_t i = 0;
	while(i < 10)
	{
	    i++;
	    a = a + 2;
    }
    
	for(i=0;i<20;i++) 
	    --a;
    return a; // expected return: 45
}
