#include <string>
#include <iostream>
#include <cctype>
using std::string; 
using std::cin; using std::cout; using std::endl;

std::istream& stream_print(std::istream &in1);
int main(){
    
    stream_print(std::cin); 

    return 0;
}

std::istream& stream_print(std::istream &in1){
    in1.clear();
    std:: string str;
    while ( in1 >> str)
        std::cout << str << " ";
    std::cout <<std::endl;
    in1.clear();
     return in1;
}
