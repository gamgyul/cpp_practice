#include "common.h"

class Employee {
protected:
    std::string name_;
    int age_;

    std::string position_; //직책
    int rank_; //직책의 순위

public:
    Employee(std::string name, int age, std::string position, int rank)
            : name_(name), age_(age), position_(position), rank_ (rank) {}
    
    //복사생성자
    Employee(const Employee &emp) {
        name_ = emp.name_;
        age_ = emp.age_;
        position_ = emp.position_;
        rank_ = emp.rank_;
    }
    
    Employee() {}

    void print_info() {
        std::cout << "사원정보: " << name_ << "(" << position_ << "," << age_ <<") ==> "
                  << calculate_pay() << "만원" << std::endl;
    }

    int calculate_pay() {
        return 200 + 50 * rank_;
    }
};

class EmployeeList {
    int alloc_employee_;
    int current_employee_;
    Employee **employee_list_;
public:
    EmployeeList(int alloc_employee) : alloc_employee_(alloc_employee) {
        employee_list_ = new Employee*[alloc_employee_];
        current_employee_ = 0;
    }
    ~EmployeeList() {
        for(int i = 0; i< current_employee_; ++i) {
            delete employee_list_[i];
        }
        delete[] employee_list_;
    }

    void add_employee(Employee *e) {
        employee_list_[current_employee_] = e;
        current_employee_++;
    }

    void print_employee_info() {
        
        int total_cost = 0;
        for(int i = 0; i< current_employee_; ++i) {
            employee_list_[i]->print_info();
            total_cost += employee_list_[i]->calculate_pay();
        }
        std::cout << " 총인원 : " << current_employee_ << "명 " << std::endl;
        std::cout << " 총비용 : " << total_cost << "만원" << std::endl;
    }

};

class Manager : public Employee {

    int year_of_service_;

public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : Employee(name, age, position, rank), year_of_service_(year_of_service) {}

    Manager(const Manager & m) : Employee(m.name_, m.age_, m.position_, m.rank_), 
                                          year_of_service_(m.year_of_service_) {}


    int calculate_pay() {
        return 200 + 50 * rank_ + 5 * year_of_service_;
    }
    void print_info() {
        std::cout << "사원정보: " << name_ << "(" << position_ << ", " << age_ 
                  << ", " << year_of_service_ <<"년차) ==> "
                  << calculate_pay() << "만원" << std::endl;
    }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_employee(new Employee("유재석", 41, "부장", 7));
    emp_list.add_employee(new Employee("정준하", 43, "과장", 4));
    emp_list.add_employee(new Employee("박명수", 43, "차장", 5));
    emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();

    std::stack<std::pair<int, int>> s;
    std::pair<int, int> cord = s.top();

  return 0;
}