#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
         if(n<2) return false;
	    if(n<=3) return true;
	    if(n%2 == 0) return false; // all even number are divisor by 2
	    for(int i=3; i<= sqrt(n); i+=2) //for odd number
	    {
	       if(n%i==0) return false;
	    }

	    return true;
}
int main() {
	// your code goes here
	int t;
	cin >> t;

	while(t--)
	{
	    int n;
	    cin >> n;
	   // bool flag= true;

	    if(prime(n)) cout << "yes" << endl;
	    else cout << "no" << endl;
	}

}
s
