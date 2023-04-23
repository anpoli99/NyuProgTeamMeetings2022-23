#include <bits/stdc++.h>
using namespace std;

// The solution here is simple: check every number until
// we reach a Harshad number. I thought when I chose this
// problem that I had a proof of its correctness (that Harshard
// numbers are "dense" and you'd find one fairly quickly), but
// the proof is more involved; you can show that the density of 
// Harshard numbers is about log log x / log x, but I'll give a
// probabilistic intuition "semi-proof" here:
// There are only 9*9=81 possible sums of digits, so if you assume
// the prime factorization of a number and its sum are independent,
// the probability of finding a number is at least 1/81. I think
// showing this independence is probably very difficult, but it seems
// intuitive.

int digit_sum(int x){
    // I find it helpful to segment the code into helper functions;
    // That way you can debug them separately and it's easier to
    // read/correct the main function.
    int sum = 0;
    while(x != 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main(){
    int x;
    cin >> x;
    while(x % digit_sum(x) != 0){
        x++;
    }
    cout << x << endl;
}  