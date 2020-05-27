#include "Repo.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Repo::Repo() {}

void Repo::innit_list() {
	Film film;
	film.set_Title("Titanic");
	film.set_Genre("Romance");
	film.set_Year(1997);
	film.set_Likes(10060);
	film.set_Trailer("https://www.youtube.com/watch?v=2e-eXJ6HgkQ");
	add_Movie(film);

	film.set_Title("Harry Potter");
	film.set_Genre("Adventure");
	film.set_Year(2001);
	film.set_Likes(7568);
	film.set_Trailer("https://www.youtube.com/watch?v=VyHV0BRtdxo");
	add_Movie(film);

	film.set_Title("Interstellar");
	film.set_Genre("SF");
	film.set_Year(2018);
	film.set_Likes(3809);
	film.set_Trailer("https://www.youtube.com/watch?v=zSWdZVtXT7E");
	add_Movie(film);

	film.set_Title("Batman");
	film.set_Genre("Action");
	film.set_Year(1995);
	film.set_Likes(5450);
	film.set_Trailer("https://www.youtube.com/watch?v=tOfNUoX6U30");
	add_Movie(film);

	film.set_Title("Spiderman");
	film.set_Genre("Action");
	film.set_Year(2015);
	film.set_Likes(3479);
	film.set_Trailer("https://www.youtube.com/watch?v=vHJCPjxMAPM");
	add_Movie(film);

	film.set_Title("Frozen");
	film.set_Genre("Comedy");
	film.set_Year(2013);
	film.set_Likes(20000);
	film.set_Trailer("https://www.youtube.com/watch?v=TbQm5doF_Uc");
	add_Movie(film);

	film.set_Title("It");
	film.set_Genre("Horror");
	film.set_Year(2013);
	film.set_Likes(100);
	film.set_Trailer("https://www.youtube.com/watch?v=7no56Zw1e20");
	add_Movie(film);


}

bool Repo::exists_in_movie_list(string title)
{
	for (int i = 0; i < Movie_List.size(); i++) {
		if (Movie_List.at(i).get_Title() == title)
		{
			return true;
			break;
		}
	}
	return false;
}

bool Repo::exists_in_watch_list(string title)
{
	for (int i = 0; i < WatchList.size(); i++) {
		if (WatchList.at(i).get_Title() == title)
		{
			return true;
			break;
		}
	}
	return false;
}


void Repo::add_Movie(Film f)
{
	if (this->exists_in_movie_list(f.get_Title()))
		throw exception("Movie already exists");
	Movie_List.push_back(f);
	print_to_file(f);

}

void Repo::print_to_file(Film f)
{
	ofstream out("movie.txt", ios::app);
	out << f.get_Title() << ' ' << f.get_Genre() << ' ' << f.get_Year() << ' ' << f.get_Likes() << ' ' << f.get_Trailer() << endl;
	cout << "Movie added successfully!" << endl;
	out.close();
}

void Repo::print_list_to_file()
{
	ofstream out("movie.txt", ios::app);
	for (int i = 0;i < Movie_List.size();i++)
		out << Movie_List.at(i).get_Title() << ' ' << Movie_List.at(i).get_Genre() << ' ' << Movie_List.at(i).get_Year() << ' ' << Movie_List.at(i).get_Likes() << ' ' << Movie_List.at(i).get_Trailer() << endl;
	out.close();
}

void Repo::clear_file()
{
	ofstream ofs("movie.txt", ofstream::out | ofstream::trunc);
	ofs.close();
}

void Repo::delete_Movie(string title) {

	for (int i = 0; i < Movie_List.size(); i++) {
		if (Movie_List.at(i).get_Title() == title) {
			Movie_List.erase(Movie_List.begin() + i);
			clear_file();
			print_list_to_file();
			return;
		}
	}

}

int Repo::update_Movie_likes(string name, int p) {
	for (int i = 0; i < Movie_List.size(); i++) {
		if (Movie_List.at(i).get_Title() == name) {
			cout << "Old likes:" << Movie_List.at(i).get_Likes() << endl;
			Movie_List.at(i).set_Likes(p);
			cout << "New likes:" << Movie_List.at(i).get_Likes() << endl;
			clear_file();
			print_list_to_file();
			return Movie_List.at(i).get_Likes();
		}
	}

}

void Repo::print_movie_list() {
	for (int i = 0; i < Movie_List.size(); i++)
		cout << endl << "Title: " << Movie_List.at(i).get_Title() << " Genre:" << Movie_List.at(i).get_Genre() << " Year:" << Movie_List.at(i).get_Year() << " Likes: " << Movie_List.at(i).get_Likes() << " Trailer:" << Movie_List.at(i).get_Trailer() << endl;

}

void Repo::print_watch_list() {
	for (int i = 0; i < WatchList.size(); i++)
		cout << "Title: " << WatchList.at(i).get_Title() << " Genre:" << WatchList.at(i).get_Genre() << " Year:" << WatchList.at(i).get_Year() << " Likes:" << WatchList.at(i).get_Likes() << " Trailer" << WatchList.at(i).get_Trailer() << endl;
}

int Repo::search(string genre) {
	int nr = 0;
	for (int i = 0; i < Movie_List.size(); i++) {
		if (Movie_List.at(i).get_Genre() == genre)
		{
			Movie_List.at(i).print();
			nr++;
		}
	}
	return nr;

}



void Repo::add_WatchList(string title)
{
	if (this->exists_in_watch_list(title))
		throw exception("Movie already exists");
	for (int i = 0; i < Movie_List.size(); i++)
		if (Movie_List.at(i).get_Title() == title) {
			WatchList.push_back(Movie_List.at(i));
		}
}

void Repo::remove_from_WatchList(string title, string answer)
{
	for (int i = 0; i < WatchList.size(); i++) {
		if (WatchList.at(i).get_Title() == title) {
			WatchList.erase(WatchList.begin() + i);
			return;
		}
	}

	if (answer == "yes")
		like(title);
	else
		return;

}

void Repo::like(string a) {
	for (int i = 0; i < Movie_List.size(); i++) {
		if (Movie_List.at(i).get_Title() == a) {
			Movie_List.at(i).set_Likes(Movie_List.at(i).get_Likes() + 1);
		}
	}
}


Repo::~Repo() {}

