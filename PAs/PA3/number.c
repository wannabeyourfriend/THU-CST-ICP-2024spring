# include <stdio.h>
# include <stdlib.h>

int getfirstnumber(int number)
{
	int thefirstnumber = number/100;
	return thefirstnumber;
}

int getsecondnumber(int number)
{
	int thesecondnumber = (number%100)/10;
	return thesecondnumber;
}

int getthirdnumber(int number)
{
	int thethirdnumber = number%10;
	return thethirdnumber;
}

int main()
{
	int a ;
	for( a = 100; a < 1000; a++)
	{
		int a_1 = getfirstnumber(a);
		int a_2 = getsecondnumber(a);
		int a_3 = getthirdnumber(a);
		if (a == a_1*a_1*a_1 + a_2*a_2*a_2 + a_3*a_3*a_3)
		{
			printf("%d\n",a);
		}
	}
	return 0;
	

}