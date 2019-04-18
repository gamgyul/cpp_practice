#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
#include <cstdlib>
#include "dbutil.h"
namespace account{

class info{
private:
    std::string name;
    int account_num;
    int total_money;
public:
    int connect_account(int account);

    inline std::string getname(){
        return this->name;
    }
};

void print_menu();
info get_info_from_num(dbutil::database db);
}  // namespace account
#endif  // ACCOUNT_H_