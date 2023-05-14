#pragma once
#include "Account.h"
#include <iostream>
class NormalAccount : public Account
{

public:
	NormalAccount(double);
	virtual void display_account() override;
};

