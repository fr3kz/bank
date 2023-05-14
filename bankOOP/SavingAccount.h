#pragma once
#include <iostream>
#include "Account.h"
class SavingAccount : public Account
{
public:
	virtual void display_account() override;
};

