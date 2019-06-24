#include <iostream>
#include <math.h>
using namespace std;

// a => 97
long getCode(string s){
    int len = s.size();
    long ret = 0;
    for(int i = len-1, factor = 0; i >= 0; i--, factor++){
        ret += (s[i]-96) * pow(25, factor);
    }
    return ret;
}

int main(){
    int n;
    string s;
    cout << "how many string do you wanna input: " ;
    cin >> n;
    cout << "input string one by one: " << endl;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << getCode(s)  << endl;
    }
    
    return 0;
}