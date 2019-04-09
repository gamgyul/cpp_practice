#include <iostream>
#include <string>
#include "account.h"
void account::print_menu(){
    std::cout << "------Menu------" <<std:: endl;
        std::cout << "1. 계좌 개설      " <<std:: endl;
        std::cout << "2. 입금          " <<std:: endl;
        std::cout << "3. 출금          " <<std:: endl;
        std::cout << "4. 계좌 정보 출력  " <<std:: endl;
        std::cout << "5. 종료          " <<std:: endl;
    
}
account::info account::get_info_from_num(int input_num){
   int rotate_cnt = 0;
                while (rotate_cnt <= 3) {
                    std::cout << " 입금" <<std::endl;
                    std::cout << " 계좌번호:" <<std::endl;
                    std::cin >> input_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "잘못된 계좌입니다. 다시 입력해 주세요" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
}