#include "Ui.h"
#include "Repo.h"
#include "Film.h"
#include "Controller.h"
#include <iostream>
using namespace std;

Ui::Ui() {}

void Ui::Menu() {

	Controller c;
	Repo r;

	int choice;
	do
	{
		system("CLS");
		cout << "<<MENU>>" << endl;
		cout << "Enter your choice or press 0 to exit!" << endl;
		cout << "1-->Admin mode" << endl;
		cout << "2-->User mode" << endl;
		cout << "Your choice:";
		cin >> choice;

		c.ui_menu(choice, &r);

	} while (choice != 0);

}

void Ui::Menu_Admin(Repo* r) {

	Controller c;

	int choice;
	do
	{
		system("CLS");
		cout << "Admin Mode!" << endl;
		cout << "Enter your choice or press 0 to exit!" << endl;
		cout << "1-->Add movie" << endl;
		cout << "2-->Delete movie" << endl;
		cout << "3-->Update number of likes" << endl;
		cout << "4-->List of movies" << endl;
		cout << "5-->Innit a list of movies" << endl;
		cout << "6-->Return to main menu!" << endl;
		cout << "Your choice:";
		cin >> choice;

		c.ui_menu_Admin(choice, r);

	} while (choice != 0);

}

void Ui::Menu_User(Repo* r) {

	Controller c;

	int choice;
	do
	{
		system("CLS");
		cout << "User Mode!" << endl;
		cout << "Enter your choice or press 0 to exit!" << endl;
		cout << "1-->Show movies by genre" << endl;
		cout << "2-->Add movie to the Watchlist" << endl;
		cout << "3-->Remove movie from the Watchlist" << endl;
		cout << "4-->Show movies from the Watchlist" << endl;
		cout << "5-->Return to main menu!" << endl;
		cout << "Your choice:";
		cin >> choice;

		c.ui_menu_User(choice, r);

	} while (choice != 0);

}


