#include <iostream>
#include <string>
#include "account.h"


int main(int arcg, char** argv) {
    int menu_num, account_num, money, total_money;
    int rotate_cnt = 0;
    char name[15] = {0, };
    account::info current_account;
    while (1) {
        account::print_menu();
        std::cin >> menu_num;

        switch (menu_num) {
            case 1:
                std::cout << " ���°���" <<std::endl;
                std::cout << " ���¹�ȣ:" <<std::endl;
                std::cin >> account_num;
                std::cout << " �̸�:" <<std::endl;
                std::cin >> name;
                //create(account_num,name);
                std::cout << " ���»��� �Ϸ�" <<std::endl;
                break;
            case 2:
                current_account = account::get_info_from_num();
                    std::cout << current_account.getname() << "��" << std::endl;
                    std::cout << " �Ա� �ݾ�:" <<std::endl;
                    std::cin >> money;
                break;
                    //update(account_num, money);
            case 3: 
            rotate_cnt = 0;
                while (rotate_cnt <= 3) {
                    std::cout << " �Ա�" << std::endl;
                    std::cout << " ���¹�ȣ:" << std::endl;
                    std::cin >> account_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "�߸��� �����Դϴ�. �ٽ� �Է��� �ּ���" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
                    std::cout << name << "��" << std::endl;
                    std::cout << " �Ա� �ݾ�:" <<std::endl;
                    std::cin >> money;
                    
                    //update(account_num, money);
                break;
            case 4:
                while (rotate_cnt <= 3) {
                    std::cout << " ��������" <<std::endl;
                    std::cout << " ���¹�ȣ:" <<std::endl;
                    std::cin >> account_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "�߸��� �����Դϴ�. �ٽ� �Է��� �ּ���" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
            default:
                break;
        } 

    }


}

