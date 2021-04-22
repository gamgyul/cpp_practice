#include <iostream>
#include <string>
#include <cstdio>
#include "dbutil.h"

using namespace dbutil;
int database::connect(std::string dsn, std::string user, std::string pwd ){
    try {
        ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLalloc Fail");}
        ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
        error_check(ret, SQL_HANDLE_ENV, env, buf);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLalloc Fail");}
        ret = SQLConnect(dbc, (SQLCHAR*)dsn.c_str(), SQL_NTS, (SQLCHAR*)user.c_str(), SQL_NTS, (SQLCHAR*)pwd.c_str(), SQL_NTS);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLConnect fail");}
        is_connected = true;
    }
    catch(std::runtime_error err) {
        is_connected = false;
        error_check(ret, SQL_HANDLE_DBC, dbc, buf);
    }
    
    return (is_connected ? 0 : -1);
}
int database::insert(int account_num, char* name){
	try {
        ret = SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLalloc Fail");}
        ret = SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_INT, SQL_INTEGER, 0, 0, &account_num, sizeof(int), NULL);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLBind1 Fail");}
        ret = SQLBindParameter(stmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 0, 0, name, sizeof(name), NULL);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLBind2 Fail");}
        ret = SQLExecDirect(stmt, (SQLCHAR *)"INSERT INTO ACCOUNT VALUES (?,?,0)", SQL_NTS);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLExec Fail");}
        ret = SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        if (ret == SQL_ERROR) {throw std::runtime_error("SQLFree Fail");}
    }
    catch(std::runtime_error err) {
        error_check(ret, SQL_HANDLE_STMT, stmt, buf);
        return -1;
    }
    return 0;
}

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
