#include <iostream>
#include <string>
#include <cstdio>
#include "dbutil.h"

using namespace dbutil;
int database::connect(char* dsn, char* user, char* pwd ){
    try {
        ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLalloc Fail");}
        ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
        error_check(ret, SQL_HANDLE_ENV, env, buf);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLalloc Fail");}
        ret = SQLConnect(dbc, (SQLCHAR*)dsn, SQL_NTS, (SQLCHAR*)user, SQL_NTS, (SQLCHAR*)pwd, SQL_NTS);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLConnect fail");}
        is_connected = true;
    }
    catch(std::runtime_error err) {
        is_connected = false;
        error_check(ret, SQL_HANDLE_DBC, dbc, buf);
    }
    
    return (is_connected ? 0 : -1);
}
// int database::insert(int account_num, char* name){
// 	ret SQL
// }

//int database::insert();

void
dbutil::error_check_real(std::string a_file, int a_line, SQLRETURN a_ret, SQLSMALLINT a_hndltype,
                        SQLHANDLE a_hndl, char* a_buf) {

    SQLRETURN rc;
    SQLINTEGER native_error;
    SQLSMALLINT textlength;
    SQLCHAR sqlstate[256];

    switch (a_ret) {
    case SQL_INVALID_HANDLE:
        std::cout << "Invalid handle " << std::endl;
        break;
    case SQL_SUCCESS:
        break;
    case SQL_SUCCESS_WITH_INFO:
        std::cout << "SQL_SUCCESS_WITH_INFO " << std::endl;


        rc = SQLGetDiagRec(a_hndltype, a_hndl, 1, sqlstate, &native_error, (SQLCHAR*)a_buf, 256, &textlength);
        printf("sqlstate : %s\n", sqlstate);
        printf("native error: %d\n", (int)native_error);
        printf("Message text: %s\n", a_buf);
        break;
    case SQL_ERROR:

        printf("error at %s\n line number: %d\n", (char *)a_file.c_str(), a_line);

        rc = SQLGetDiagRec(a_hndltype, a_hndl, 1, sqlstate, &native_error, (SQLCHAR*)a_buf, 256, &textlength);
        printf("sqlstate : %s\n", sqlstate);
        printf("native error: %d\n", (int)native_error);
        printf("Message text: %s\n", a_buf);

    default:
        break;
    }
}
