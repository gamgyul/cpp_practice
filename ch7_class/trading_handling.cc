#include <iostream>
#include <string>
#include "sales_data.h" 
int main(){
    Sales_data total;
    if (read(std::cin, total)){
        Sales_data trans;
        while(read(std::cin, trans)){
            if(total.isbn() == trans.isbn())
            total.combine(trans);
        
        else{
            print(std::cout, total) << std::endl;
            total = trans;
            }
        }
        print(std::cout, total);
    }
    else
    std::cerr<< "No Data!" << std::endl;
    return 0;
} 