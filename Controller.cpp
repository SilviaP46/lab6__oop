#include "Controller.h"
#include "Validation.h"
#include "Repo.h"
#include "Film.h"
#include "UI.h"
#include "App.h"
#include<iostream>
using namespace std;


Controller::Controller() {}



void Controller::ui_menu(int choice, Repo* r) {

	Ui g;

	int op = choice;

	switch (op) {


	case 0:

		cout << "Bye Bye!";

		system("PAUSE");

	case 1:

		g.Menu_Admin(r);

		system("PAUSE");
		break;

	case 2:


		g.Menu_User(r);

		system("PAUSE");
		break;

	}
}

void Controller::ui_menu_Admin(int choice, Repo* r) {

	Film* movie;
	Ui g;
	int year, likes, op = choice, nr;
	string title, trailer, genre;
	Validation* v;

	switch (op) {


	case 0:

		cout << "Bye Bye!";

		system("PAUSE");

	case 1:
		cout << "Please name the movie you wish to add!" << endl;
		cin >> title;
		//	if (v->check_string(title) == false)
			//{
			//	cout << "The title must only contain letters! Try Again!" << endl;
			//	cin >> title;
			//}
		cout << "Genre?" << endl;
		cin >> genre;
		cout << "Year?" << endl;
		cin >> year;
		cout << "Likes?" << endl;
		cin >> likes;
		cout << "Trailer?" << endl;
		cin >> trailer;

		movie = new Film(title, genre, year, likes, trailer);
		if (r->exists_in_movie_list(title))
		{
			cout << "This movie already exits!" << endl;

		}
		else {
			r->add_Movie(*movie);
			//int poz = r->Movie_List.size() - 1;
			//r->Movie_List.at(poz).print();
			r->print_movie_list();

			delete movie;
		}

		system("PAUSE");
		break;

	case 2:

		cout << "Which movie would you like to delete?";
		cin >> title;

		if (r->exists_in_movie_list(title) == false)
		{
			cout << "This movie does not exist!" << endl;

		}
		else
		{
			r->delete_Movie(title);
			cout << "Movie deleted!" << endl;
		}


		system("PAUSE");
		break;

	case 3:
		cout << "Which movie would you like to update?";
		cin >> title;
		cout << "New quantity of likes" << endl;
		cin >> nr;

		if (r->exists_in_movie_list(title) == false)
		{
			cout << "This movie does not exist!" << endl;

		}
		else
		{
			r->update_Movie_likes(title, nr);
		}

		system("PAUSE");
		break;

	case 4:

		r->print_movie_list();

		system("PAUSE");
		break;

	case 5:

		r->innit_list();

		system("PAUSE");
		break;

	case 6:

		g.Menu();
	}


}


void Controller::ui_menu_User(int choice, Repo* r) {

	Film* movie;
	Ui g;
	int year, likes, op = choice, nr;
	string title, trailer, genre, answer;

	switch (op) {


	case 0:

		cout << "Bye Bye!";

		system("PAUSE");

	case 1:
		cout << "Genre?" << endl;
		cin >> genre;

		r->search(genre);

		system("PAUSE");
		break;


	case 2:
		cout << "Which movie would you like to add to your watchlist?" << endl;
		cin >> title;
		if (r->exists_in_watch_list(title))
		{
			cout << "This movie already exits!" << endl;

		}
		else {

			r->add_WatchList(title);
			//int poz = r->WatchList.size() - 1;
			//r->WatchList.at(poz).print();
			r->print_watch_list();
		}


	case 3:
		cout << "Which movie would you like to remove from the Watchlist?" << endl;
		cin >> title;
		cout << "Did you like the movie?" << endl;
		cin >> answer;
		if (r->exists_in_watch_list(title) == false)
		{
			cout << "This movie does not exist!" << endl;

		}
		else
		{
			r->remove_from_WatchList(title, answer);
			cout << "Movie deleted!" << endl;
		}



		system("PAUSE");
		break;

	case 4:
		r->print_movie_list();

		system("PAUSE");
		break;

	case 5:

		g.Menu();


		system("PAUSE");
		break;
	}

}
