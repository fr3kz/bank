#include "Employee.h"
#include <iostream>
#include "Database.h"
#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include <iomanip>

Employee::Employee(bool is_admin_, bool is_staff_, int user_id_, std::string first_name_, std::string last_name_, std::string email_, std::string password_, int phone_number_, int is_active_)
	:User(user_id_, first_name_, last_name_, email_, password_, phone_number_ ,is_active_)
{
	is_admin = is_admin_;
	is_staff = is_staff_;
}

void Employee::show_menu()
{
	system("cls");
	int choice = 0;

	while (choice != 5)
	{
		std::cout << "[1] - Wnioski do akceptacji\n";
		std::cout << "[2] - Wyswietl uzytkownika\n";
		std::cout << "[3] - Lista uztykownikow\n";
		std::cout << "[4] - Wyloguj\n";

		std::cout << "Prosze wybrac numer: ";
		std::cin >> choice;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		switch (choice)
		{
		case 1:
			show_applications();
			break;
		case 2:
			show_user_details();
			break;
		case 3:
			users_list();
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}

void Employee::show_applications()
{
	Database database;
	std::vector<int> users_id;
	int usr_id;

	users_id = database.get_applications();

	std::cout << "Witaj " << this->first_name <<  " masz " << users_id.size() << " wnioskow do sprawdzenia." << std::endl; 

	std::cout << "Lista id wnioskow" << std::endl;
	for (int i = 0; i < users_id.size(); i++)
	{
		std::vector<std::string> users_credential;
		users_credential = database.get_user_credentials(users_id[i]);
		std::cout << "ID uzytkownika " << users_id[i] << " " << users_credential[1] << " " << users_credential[2] << std::endl;
	}

	std::cout << "Wpisz id aby rozpatrzyc wniosek" << std::endl;
	std::cin >> usr_id;

	show_application(usr_id);


}

void Employee::show_application(int user_id)
{
	system("cls");
	int choice;
	Database database;
	std::vector<std::string> credentials;
	credentials = database.get_user_credentials(user_id);

	std::cout << "User Credentials:" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "Imie: " << credentials[0] << std::endl;
	std::cout << "Nazwisko: " << credentials[1] << std::endl;
	std::cout << "Email: " << credentials[2] << std::endl;
	std::cout << "Numer telefonu: " << credentials[3] << std::endl;
	std::cout << std::endl;

	std::cout << "Wybierz:" << std::endl;
	std::cout << "-------" << std::endl;
	std::cout << "[0] Akceptuj" << std::endl;
	std::cout << "[1] Odrzuc" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	if (choice == 0)
	{
		database.accept_application(user_id);
		std::cout << "Aplikkacja przyjeta." << std::endl;
	}
	else
	{
		std::cout << "Aplikkacja odrzucona" << std::endl;
	}
}

void Employee::users_list()
{
	system("cls");
	Database database;
	std::vector<int> users_id;
	users_id = database.get_all_clients();


	const int idColumnWidth = 10;
	const int firstNameColumnWidth = 20;
	const int lastNameColumnWidth = 20;

	std::cout << std::left << std::setw(idColumnWidth) << "ID";
	std::cout << std::left << std::setw(firstNameColumnWidth) << "Imie";
	std::cout << std::left << std::setw(lastNameColumnWidth) << "Nazwisko";
	std::cout << std::endl;

	for (int i = 0; i < users_id.size(); ++i)
	{
		std::vector<std::string> users_credential;
		users_credential = database.get_user_credentials(users_id[i]);

		std::cout << std::left << std::setw(idColumnWidth) << users_id[i];
		std::cout << std::left << std::setw(firstNameColumnWidth) << users_credential[0];
		std::cout << std::left << std::setw(lastNameColumnWidth) << users_credential[1];
		std::cout << std::endl;
	}

}


void Employee::show_user_details()
{
	Database database;
	int user_id;

	std::cout << "Podaj ID u¿ytkownika, ktorego chcesz wyswietlic: ";
	std::cin >> user_id;

	std::vector<std::string> user_credentials;
	user_credentials = database.get_user_credentials(user_id);

	std::cout << "Dane uzytkownika:" << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << "ID: " << user_id << std::endl;
	std::cout << "Imie: " << user_credentials[0] << std::endl;
	std::cout << "Naziwsko: " << user_credentials[1] << std::endl;
	std::cout << "Adres: " << user_credentials[2] << std::endl;
	std::cout << "Email: " << user_credentials[3] << std::endl;
	std::cout << "Numer telefonu: " << user_credentials[4] << std::endl;
}
