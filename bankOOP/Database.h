#pragma once

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
class Database
{
protected:
	const std::string server = "tcp://127.0.0.1:3306"; // ip bazy danych
	const std::string username = "root"; // login
	const std::string password = ""; //haslo
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

public:
	void connect_database()
	{
        try
        {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
            std::cout << "dziala" << std::endl;
        }
        catch (sql::SQLException e)
        {
            std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
            system("pause");
            exit(1);
        }
	}
};

