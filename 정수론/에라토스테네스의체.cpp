#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;



/*unsigned int prime[(MAX+31) / 32];

bool isPrime(int k) {

	return prime[k >> 5] & (1 << (k & 31));
}
void unPrime(int k) {

	prime[k >> 5] &= ~(1 << (k & 31));
}


*/
unsigned char prime[1000008/8];
bool isPrime(int k) {
	return prime[k >> 3] & (1 << (k & 7));
}
void unPrime(int k) {
	 prime[k >> 3] &= ~(1 << (k & 7));
}


int main() {

	//에라토스테네스의 체 비트마스크로 

	int n, m; 
	cin >> n >> m; 
	//memset(primes, true, sizeof(primes));
	memset(prime, 255, sizeof(prime));
	unPrime(0);
	unPrime(1);
	for (int i = 2; i <= sqrt(m); i++) {

		if (isPrime(i)) {
			
			for (int j = i * i; j <= m; j += i) {
				unPrime(j);
				//primes[j]=false;
			}
		}

	}

	for (int i = n; i <= m; i++) {
		if (isPrime(i))cout << i<<'\n';
	}

	return 0;

	




}
