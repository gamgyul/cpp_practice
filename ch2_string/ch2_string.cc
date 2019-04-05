#include <string>
#include <iostream>
#include <cctype>
using std::string; 
using std::cin; using std::cout; using std::endl;
int main(){
    string s("Hello World!!!");

    decltype(s.size()) punct_cnt =0;

    for (auto c : s){
        c= toupper(c);
    }

    cout << s << endl;
}
  