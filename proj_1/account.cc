#include <iostream>
#include <string>
#include "account.h"
void account::print_menu(){
    std::cout << "------Menu------" <<std:: endl;
        std::cout << "1. ���� ����      " <<std:: endl;
        std::cout << "2. �Ա�          " <<std:: endl;
        std::cout << "3. ���          " <<std:: endl;
        std::cout << "4. ���� ���� ���  " <<std:: endl;
        std::cout << "5. ����          " <<std:: endl;
    
}
account::info account::get_info_from_num(int input_num){
   int rotate_cnt = 0;
                while (rotate_cnt <= 3) {
                    std::cout << " �Ա�" <<std::endl;
                    std::cout << " ���¹�ȣ:" <<std::endl;
                    std::cin >> input_num;
                    // rc = select(account_num, name);
                    // if (rc != success) {
                    //     std::cout << "�߸��� �����Դϴ�. �ٽ� �Է��� �ּ���" <<std::endl;
                    //     rotate_cnt++;
                    //     continue;
                    // }
                }
}