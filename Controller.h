#pragma once
#include "Repo.h"
#include <iostream>
#include <string>
#include <algorithm>
class Controller {
public:
	vector <Film> movies;
public:
	Controller();
	void ui_menu(int choice, Repo* r);
	void ui_menu_Admin(int choice, Repo* r);
	void ui_menu_User(int choice, Repo* r);


};


