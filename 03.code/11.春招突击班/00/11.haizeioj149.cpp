#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;


int lastWord (char *str){
    int len = strlen(str);
    int ans = 0;
    for (int i = len - 1; str[i] != ' '; i--) {
        ////printf("%c ", str[i]);
        ans++;
    }
    return ans;
}

int lastWord2(string &str) {
    int ans = 0;
    for (int i = str.size(); str[i] != ' '; i--) ans++;
    return ans; 
}
 
int main() {
    //char str[55];
    //scanf("%[^\n]s", str);
   
    //printf("%d\n", lastWord(str));


    char str1[55];
    scanf("%[^\n]s", str1);
   
    string str;
    str = str1;
    
    cout << str << endl;
    int ans = 0;
    for (int i = str.size() - 1; str[i] != ' ' && i >= 0; i--) {
        cout << str[i] << " ";
        ans++;
    }
    cout << ans << endl; 
    
    return 0;
}

