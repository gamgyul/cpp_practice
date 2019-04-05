#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
class account{
private:
    char name[15];
    int account_num;
    int total_money;
public:
    
    int connect_account(int account);
};

void print_menu();
#endif