#include <bits/stdc++.h>
using namespace std;


bool validate(int x, int y, int z){
    if(x + y == z || x * y == z) return true;
    return false;
}
int main(){
    int qr;
    for(cin >> qr; qr; qr--){
        int x, y, z;
        cin >> x >> y >> z;
        // Division (x / y = z) is really the same as multiplication (x = y * z)
        // The numbers are so small it probably won't matter, but we can avoid
        // precision by only checking addition/multiplication, skipping subtraction/division
        bool ok = validate(x,y,z) || validate(x,z,y) || validate(y,z,x);
        // a small bonus: multiplication is commutative, so we only have to check 3 cases
        if(ok) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}