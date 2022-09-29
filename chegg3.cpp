#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
	unsigned max = 1000;
	vector< set<unsigned> >prime_factors (max+1);
	
	vector<bool>prime(max+1);//Vector of bool to store if a number is prime or not
	
	for(int i=0;i<=max;i++)//Initializing all numbers as prime first
		prime[i] = true;
	
	prime[1] = 	false;//We know that 1 is not a prime. So we make it false
	
	for(int j=2;j<=max;j++){//We start our iteration from 2
		
		if(prime[j]){// If j is prime, we make all of its multiplier upto max as non-prime
						//Then we store the prime into the prime factors of those multiplier		
			for(int k=2*j;k<=max;k+=j){
				
				prime_factors[k].insert(j);//Storing the prime as a factor of k
				prime[k] = false;			//Making k non-prime
			}
		}
	}
	
	return 0;
}
