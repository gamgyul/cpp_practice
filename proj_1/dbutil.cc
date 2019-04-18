#include <iostream>
#include <string>
#include <cstdio>
#include "dbutil.h"

using namespace dbutil;
int database::connect(char* dsn, char* user, char* pwd ){
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
	
	ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
	error_check(ret, SQL_HANDLE_ENV, env, buf);

	ret = SQLConnect(dbc, (SQLCHAR*)dsn, SQL_NTS, (SQLCHAR*)user, SQL_NTS, (SQLCHAR*)pwd, SQL_NTS);
    if (ret != SQL_ERROR)
        is_connected = true;
	error_check(ret, SQL_HANDLE_DBC, dbc, buf);
    return (is_connected ? 0 : -1);
}

//int database::insert();

void
dbutil::error_check_real(char *a_file, int a_line, SQLRETURN a_ret, SQLSMALLINT a_hndltype, SQLHANDLE a_hndl, char* a_buf){

	SQLRETURN rc;
	SQLINTEGER native_error;
	SQLSMALLINT textlength;
	SQLCHAR sqlstate[256];

	switch (a_ret){

	case SQL_INVALID_HANDLE:
		std::cout <<"Invalid handle "<<std::endl;
		break;
	case SQL_SUCCESS:
		break;
	case SQL_SUCCESS_WITH_INFO:
		std::cout <<"SQL_SUCCESS_WITH_INFO "<<std::endl;


		rc = SQLGetDiagRec(a_hndltype, a_hndl, 1, sqlstate, &native_error, (SQLCHAR*)a_buf, 256, &textlength);
		printf("sqlstate : %s\n", sqlstate);
		printf("native error: %d\n", (int)native_error);
		printf("Message text: %s\n", a_buf);
		break;
	case SQL_ERROR:

		printf("error at %s\n line number: %d\n", a_file, a_line);

		rc = SQLGetDiagRec(a_hndltype, a_hndl, 1, sqlstate, &native_error, (SQLCHAR*)a_buf, 256, &textlength);
		printf("sqlstate : %s\n", sqlstate);
		printf("native error: %d\n", (int)native_error);
		printf("Message text: %s\n", a_buf);
		
	default:
		break;
	}
}