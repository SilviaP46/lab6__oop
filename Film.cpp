#include "Film.h"
#include <iostream>
using namespace std;

Film::Film() {

	Title = "";
	Genre = "";
	Year = 0;
	Likes = 0;
	Trailer = "";
}

Film::Film(string title, string genre, int year, int likes, string trailer) {
	Title = title;
	Genre = genre;
	Year = year;
	Likes = likes;
	Trailer = trailer;
}


string Film::get_Title() const {

	return Title;

}

string Film::get_Genre() const {

	return Genre;

}

int Film::get_Year() const {

	return Year;

}

int Film::get_Likes() const {

	return Likes;

}

string Film::get_Trailer() const {

	return Trailer;

}

void Film::set_Title(string title) {

	this->Title = title;
}

void Film::set_Genre(string genre) {

	this->Genre = genre;
}

void Film::set_Year(int year) {

	this->Year = year;
}

void Film::set_Likes(int likes) {

	this->Likes = likes;
}

void Film::set_Trailer(string trailer) {

	this->Trailer = trailer;
}

void Film::print()
{
	cout << endl << " Title: " << Title << " Genre: " << Genre << " Likes: " << Likes << " Year: " << Year << " Trailer: " << Trailer << endl;

}


Film::~Film() {}
