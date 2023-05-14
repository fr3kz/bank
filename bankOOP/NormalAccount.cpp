#include "NormalAccount.h"
#include <iostream>

NormalAccount::NormalAccount(double balance_) : Account(balance_)
{
}

void NormalAccount::display_account()
{
	std::cout << "to jest konto konsumenckie" << std::endl;
}
