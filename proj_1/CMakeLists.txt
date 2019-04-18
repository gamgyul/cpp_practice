PROJECT ("TEST_ACCOUNT_MGR")

INCLUDE_DIRECTORIES($ENV{TB_HOME}/client/include)
LINK_DIRECTORIES($ENV{TB_HOME}/client/lib)
link_libraries(tbcli)
ADD_EXECUTABLE (p1.out p1.cc dbutil.cc account.cc)