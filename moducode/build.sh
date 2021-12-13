#그냥 clang++로 빌드하는거



clang++ -std=c++11 -g -lpthread -I `pwd` -I ../ -o `basename $@ .cc`.out $@
