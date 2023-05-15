#include <iostream>
#include "User.h"
#include "Employee.h"
#include "Customer.h"
#include "Admin.h"
#include "Database.h"
#include "Account.h"
#include "NormalAccount.h"
#include "SavingAccount.h"


void Menu();
// pozniej mozna przemyslec czy nie schowac tych metod register i login do klasy user/customer zeby mniejszy syf byl
void Login();
void Register();

int main()
{
	Menu();

	return 0;
	
}


void Menu()
{
	int choice;
	std::cout << "Wybierz co chcesz zrobic 0 logowanie 1 rejestracja";
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		Login();
		break;
	case 1:
		Register();
		break;
	}

}

void Login()
{
	//TODO: wyczyszczenie konsoli,

	// logujemy sie przez userID
	int user_ID;
	std::string password;

	std::cout << "Podaj login";
	std::cin >> user_ID;

	std::cout << "Podaj haslo";
	std::cin >> password;

	//sprawdzanie typu uzytkowania
	Database database;
	database.connect_database();
	int is_customer = database.check_customer(user_ID);
	if(is_customer == 0)
	{
		//przejscie do menu usera,dodanie opcji zalogowany
	//	database.connect_database();
		//Customer  customer = database.get_customer_data_by_id(user_ID);
	//	std::cout << customer;
		std::cout << "zalogowano user";
	}else
	{
		database.connect_database();
		int is_employee = database.check_employe(user_ID);
		if (is_employee == 0)
		{
			//logowanie do pracowniczemu menu
			std::cout << "zalogowano admin";
		}else
		{
			//zle dane logowania
			std::cout << "niepoprawne dane";
		}
	}
	
	
}
void Register()
{
	/// testy bazy danych
	Database database;
	database.connect_database();
	/*database.select_all_Accounts_from_database();*/
	database.select_user_data(5);
	std::cout << "----------------------------" << std::endl;
	// testy dla Account
	Account* account = new NormalAccount(123.3, 0);
	account->display_account();
	std::cout << "\n----------------------------" << std::endl;
	account = new SavingAccount(144.5, 1);
	account->display_account();
	std::cout << "\n----------------------------" << std::endl;

	// testy dla User
	User* user = new Customer(1, 1, "hyla", "hyla", "hyla", "hyla", 1);
	user->show_menu();
	std::cout << "---------------------------------------" << std::endl;
	user = new Employee(1, 1, 1, "hyla", "hyla", "hyla", "hyla", 1);
	user->show_menu();
	std::cout << "---------------------------------------" << std::endl;
	user = new Admin(1, 1, 1, "hyla", "hyla", "hyla", "hyla", 1);
	user->show_menu();

}

