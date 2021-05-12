#include "common.h"

class Array;
class IntWrapper;

class Array{
private:

    friend IntWrapper;

    const int dim_; //차원
    int* size_;
    
    struct Address {
        int level;
        void *next;
    };
    
    Address *top_;
public:
    Array(int dim, int* array_size) : dim_(dim) {
        size_ = new int[dim_];
        for(int i = 0; i < dim ; ++i) {
            size_[i] = array_size[i];
        }

        top_ = new Address;
        top_->level = 0;
        InitializeAddress(top_);
    }

    ~Array() {
        DeleteAddress(top_);
    }
    IntWrapper operator[](const int index);
    void InitializeAddress(Address *current) {
        if(!current) return;
        if(current->level == dim_ - 1) {
            current->next = new int[size_[current->level]];
            return;
        }
        
        current->next = new Address[size_[current->level]];
        for(int i =0; i< size_[current->level]; ++i) {
            (static_cast<Address *>(current->next) + i)->level = current->level + 1;
            InitializeAddress((static_cast<Address *>(current->next) + i));
        }
    }

    void DeleteAddress(Address *current) {
        if(!current) return;
        if(current->level == dim_ - 1) {
            delete[] static_cast<int *>(current->next);
            return;
        }
        else {
            for(int i = 0; i < size_[current->level]; ++i) {
                DeleteAddress(static_cast<Address *>(current->next) + i);
            }
            delete[] static_cast<Address *>(current->next);
        }

    }
};

class IntWrapper {
    void *data_;

    int level_;
    Array *array_;
public:
    IntWrapper(int index, int level = 0, void *data = NULL, Array *array = NULL)
        : level_(level), data_(data), array_(array) {
        if(level_ < 1 || index>= array_->size_[level_ - 1]) {
            data = NULL;
            return;
        }

        if(level_ == array_->dim_) {
            data_ = static_cast<void *>
              ((static_cast<int *>(static_cast<Array::Address *>(data)->next) + index));
        }
        else {
            data_ = static_cast<void *>
              (static_cast<Array::Address *>(static_cast<Array::Address *>(data)->next)
                                             + index);
        }
    }

    IntWrapper operator[](const int index) {
        if(!data_) return 0;
        return IntWrapper(index, level_ + 1, static_cast<void *>(data_), array_);
    }

    IntWrapper &operator= (const int& a) {
        if(data_) *static_cast<int *>(data_) = a;
        return *this;
    }
    operator int() {
        if (data_) return *static_cast<int *>(data_);
        return 0;
    }
};


IntWrapper Array::operator[](const int index) {
    return IntWrapper(index, 1, static_cast<void *>(top_), this);
}

int main() {
    int size[] = {2,3,4};
    Array arr(3,size);

    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 4; ++k) {
                arr[i][j][k] = (i+1) * (j+1) * (k+1);
            }
        }
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 4; ++k) {
                std::cout << i << " " << j << " " << k <<" "
                    << arr[i][j][k] << std::endl;
            }
        }
    }
    return 0;
}