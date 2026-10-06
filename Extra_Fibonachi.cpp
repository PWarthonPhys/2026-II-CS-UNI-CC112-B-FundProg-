#include <iostream>
using namespace std;

int fibonachi( int a );

// definicion de fibonachi explicito:
// Sea n>2  f(n)= f(n-1) + f(n-2)
// 
// fibonachi (a-1) + fibonachi (a- 2);


int fibonachi(int a ){

    if(a <= 1){
        return 1;
    }
    
    return fibonachi(a-1)+  fibonachi(a-2);

}

int main() {
    int n;
    cout << "cuantos elementos tendrá la suseción";
    cin >> n ;
    cout << fibonachi(n) ;
    return 0;
}