#include <iostream>
#include <string>
#include "account.h"
#include "dbutil.h"


int main(int arcg, char** argv) {
    int rc, menu_num, account_num, money, total_money;
    int rotate_cnt = 0;
    bool is_quit = false;
    char name[15] = {0, };
    account::info current_account;
    dbutil::database db;
    rc = db.connect("tibero", "tibero", "tmax");
    if (rc == SQL_ERROR) {
        std::cout << "login failed" << std::endl;
        exit(1);
    }
    std::cout << rc << std::endl;
    while (!is_quit) {
        account::print_menu();
        std::cin >> menu_num;

        switch (menu_num) {
            case 1:
                std::cout << " 계좌개설" <<std::endl;
                std::cout << " 계좌번호:" <<std::endl;
                std::cin >> account_num;
                std::cout << " 이름:" <<std::endl;
                std::cin >> name;
                db.insert(account_num,name);
                std::cout << " 계좌생성 완료" <<std::endl;
                break;
            case 2:
//                current_account = account::get_info_from_num();
                    std::cout << current_account.getname() << "님" << std::endl;
                    std::cout << " 입금 금액:" <<std::endl;
                    std::cin >> money;
                break;
                    //update(account_num, money);
            case 3:
            rotate_cnt = 0;
                while (rotate_cnt <= 3) {
                    std::cout << " 입금" << std::endl;
                    std::cout << " 계좌번호:" << std::endl;
                    std::cin >> account_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "잘못된 계좌입니다. 다시 입력해 주세요" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
                    std::cout << name << "님" << std::endl;
                    std::cout << " 입금 금액:" <<std::endl;
                    std::cin >> money;

                    //update(account_num, money);
                break;
            case 4:
                while (rotate_cnt <= 3) {
                    std::cout << " 계좌정보" <<std::endl;
                    std::cout << " 계좌번호:" <<std::endl;
                    std::cin >> account_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "잘못된 계좌입니다. 다시 입력해 주세요" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
            default:
                is_quit = true;
                break;
        }

    }


}

