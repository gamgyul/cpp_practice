#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
namespace account{

class info{
private:
    std::string name;
    int account_num;
    int total_money;
public:
    inline std::string getname();
    int connect_account(int account);

    std::string getname(){
        return this->name;
    }
};

void print_menu();
info get_info_from_num();
}
#endif  // ACCOUNT_H_