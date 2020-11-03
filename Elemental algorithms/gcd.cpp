#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	if (b==0)
	{
		return a;
	}
	else{
		int c = a%b;
		return gcd(b,c);
	}
}

int main()
{
	int a=12,b=6;
	std::cout << gcd(a,b) << endl;
	return 0;
}
