#include <iostream>

using namespace std;

int main()

{

	double i,n=1,m=1,t,s=0 ; 

	for (i=1;i<=20;i++)

	{

		t = n ;    

		n = m ;    

		n += t;   

		s = s + m/n ; 

	}

	cout.width(8);
	cout<<234<<endl;

	return 0;

}