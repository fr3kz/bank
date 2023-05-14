#include <iostream>
#include "User.h"
#include "Employee.h"
#include "Customer.h"
#include "Admin.h"
#include "Database.h";

int main()
{

	Database database;

	database.connect_database();
	

	/*User* user = new Customer(1, 1, "hyla", "hyla", "hyla", "hyla", 1);

	user->show_menu();
	std::cout << "---------------------------------------" << std::endl;
	user = new Employee(1, 1, 1, "hyla", "hyla", "hyla", "hyla", 1);
	user->show_menu();
	std::cout << "---------------------------------------" << std::endl;
	user = new Admin(1, 1, 1, "hyla", "hyla", "hyla", "hyla", 1);
	user->show_menu();*/

	return 0;
	
}

