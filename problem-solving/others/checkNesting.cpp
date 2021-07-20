//

#include <bits/stdc++.h>
using namespace std;


bool checkNesting(string p) {
    int count = 0;
    for (int i = 0; i <= p.size() - 1; i++) {
        if (p[i] == '(') count++;
        else {
            count--;
            if (count < 0) return false;
        }
    }
    return count == 0;
}

int main(){
    string p = ")";

    cout << checkNesting(p) << endl;
    
    return 0;
}
