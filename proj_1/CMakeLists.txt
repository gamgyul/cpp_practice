PROJECT ("TEST_ACCOUNT_MGR")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

INCLUDE_DIRECTORIES($ENV{TB_HOME}/client/include)
LINK_DIRECTORIES($ENV{TB_HOME}/client/lib)
SET (CMAKE_EXE_LINKER_FLAGS "-g -std=c++11")
link_libraries(tbcli)
ADD_EXECUTABLE (p1.out p1.cc dbutil.cc account.cc)