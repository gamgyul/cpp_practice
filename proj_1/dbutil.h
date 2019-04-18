#ifndef DBUTIL_H_
#define DBUTIL_H_

#include <iostream>
#include <string>
#include "sqlcli.h"
#define BUFSIZE 512
#define error_check(a_ret, a_hndltype, a_hndl, a_buf) \
	error_check_real(__FILE__, __LINE__, (a_ret), (a_hndltype), (a_hndl), (a_buf))
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
	

};

void error_check_real(char* a_file, int a_line, SQLRETURN a_ret, SQLSMALLINT a_hndltype, SQLHANDLE a_hndl, char* a_buf);

}  // namespace dbutil

#endif  //DBUTIL_H_
