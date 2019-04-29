#ifndef DBUTIL_H_
#define DBUTIL_H_

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "sqlcli.h"
#define BUFSIZE 512
#define error_check(a_ret, a_hndltype, a_hndl, a_buf) \
	error_check_real(__FILE__, __LINE__, (a_ret), (a_hndltype), (a_hndl), (a_buf))

// create table account(
// 	account number,
// 	name varchar2(30),
// 	money number,
// 	constraint pk_accounts primary key (accountno)
// );

namespace dbutil {
class database {
private: 
	SQLHANDLE env;
	SQLHANDLE dbc;
	SQLHANDLE stmt;
	SQLRETURN rc;

    bool is_connected;

	char buf[BUFSIZE];
	//char select[100] = "select 0 from dual";
	SQLRETURN ret;
public:
    database(){
        is_connected = false;
    }
    int connect(char* dsn, char* user, char* pwd );
	int insert(int account_num, char* name);

};

void error_check_real(std::string a_file, int a_line, SQLRETURN a_ret, SQLSMALLINT a_hndltype, SQLHANDLE a_hndl, char* a_buf);

}  // namespace dbutil

#endif  //DBUTIL_H_

