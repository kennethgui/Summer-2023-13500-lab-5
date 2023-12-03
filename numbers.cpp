/*
kenneth guillont
kenneth.guillont83@myhunter.cuny.edu
lab 5D
*/

#include <iostream>
using namespace std;


bool isPrime(int x) {
    if(x <= 1) {
        return false;
    }
    else{
        for(int i = 2; i < x; i++) {
            if(x % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int nextPrime(int n) {
    int next = n + 1;
    while (!isPrime(next)) {
        next++;
    }
    return next;
}

bool countPrimes(int a, int b) {
    int count = 0;
    for(int i = a; i <= b; i++) {
        if(isPrime(i))
            count++;
    }
    return count;
}

int isTwinPrime(int n){
    if(isPrime(n)) {
        int p = n + 2;
        int s = n - 2;

        if (isPrime(n)) {
            return isPrime(p) || isPrime(s);
        }
    }
    return false;
}

int nextTwinPrime(int n) {
    int next = n + 1;

    while(true) {
        if(isTwinPrime(next))
            return next;
        next++;
    }
}

int largestTwinPrime(int a, int b) {
    int largeTwin = -1;

    for(int i = b; i >= a; i--) {
        if(isTwinPrime(i)) {
            largeTwin = i;
            break;
        }
    }
    return largeTwin;
}

bool isDivisibleBy(int x, int y) {
    if(x % y == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << "enter integer n: ";
    int n; cin >> n;
    
    cout << "enter integer d: ";
    int d; cin >> d;

    cout << "enter two integers a: ";
    int a; cin >> a;

    cout << "enter two integers b: ";
    int b; cin >> b;

   bool divs = isDivisibleBy(n, d);

   if(divs == true) {
    cout << "Yes\n";
   }
   else {
    cout << "No\n";
   }

   bool prim = isPrime(n);

   if(prim == true) {
    cout << "Yes\n";
   }
   else {
    cout << "No\n";
   }

    int nextPrim = nextPrime(n);
    cout << "The next smallest prime is " << nextPrim << endl;
    
    int primeCount = countPrimes(a, b);
    cout << "The number of prime numbers between " << a << " and " << b << " is: " << primeCount << endl;

    bool twin = isTwinPrime(n);

    if(twin == true) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    int nxtTwin = nextTwinPrime(n);
    cout << "The next twin prime of " << n << " is " << nxtTwin << endl;
    
    int largetwin = largestTwinPrime(a,b);
    cout << "The largest prime twin in the range is " << largetwin << endl;

return 0;
}
