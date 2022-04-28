#include <iostream>
using namespace std;

int sum_of_two_digits(int first, int second);

int main(){
    int a = 0, b = 0;
    cin >> a;
    cin >> b;
    cout << sum_of_two_digits(a,b);

    return 0;
}

int sum_of_two_digits(int first, int second){
    return first + second;
}


