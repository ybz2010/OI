#include<bits/extc++.h>
using namespace std;
int a,b,sum;
int x,y,z;
signed main()
{
	scanf("%d%d",&a,&b);
	puts("3");
	if (a > 0 && b > 0)
	{
		y = b;
		z = a * 3 - b;
		if (y > z)
		{
			x = z - y;
			z = y;
		}
	}
	else if (a > 0 && b < 0)
	{
		x = y = b;
		z = a * 3 - (x + y);
	}
	else if (a < 0 && b > 0)
	{
		y = z = b;
		x = 3 * a - (y + z);
	}
	else if (a < 0 && b < 0)
	{
		a = -a,b = -b;
		y = b;
		z = a * 3 - b;
		if (y > z)
		{
			x = z - y;
			z = y;
		}
		x = -x,y = -y,z = -z;
	}
	else if (a == 0 && b > 0)
	{
		y = z = b;
		x = -2 * b;
	}
	else if (a == 0 && b < 0)
	{
		x = y = b;
		z = -2 * b;
	}
	else if (a > 0 && b == 0)
	{
		x = y = 0;
		z = 3 * a;
	}
	else if (a < 0 && b == 0)
	{
		y = z = 0;
		x = 3 * a;
	}
	else 
		x = y = z = 0;
	printf("%d %d %d",x,y,z);
	return 0;
}
