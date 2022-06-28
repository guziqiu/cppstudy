#include <iostream>
#include <cstdio>
#define MAX_N 512
using namespace std;

string func(string str) {
    string ans;
    cout << str << endl;
    for (int i = 0; i < str.size(); i++) {
      int l = i, r = i + 1;
      int num = 1;
      while (str[l] == str[r]) r++,num++, cout << "str[" << l << "] = " << str[l] <<  ",str[" << r - 1 << "] = " << str[r - 1] << endl;
      if (num > ans.size()) ans = str.substr(l, r - 1);
      cout << l << ", " <<  r << endl;
      cout << str.substr(l, r - 1) << endl;
      i = r;
    }
    return ans;
}

int main() {
    char str[MAX_N + 5] = "aAaBBBcCDD";
    // scanf("%s", str);
    printf("%s\n", func(str).c_str());
    
    return 0;
}
