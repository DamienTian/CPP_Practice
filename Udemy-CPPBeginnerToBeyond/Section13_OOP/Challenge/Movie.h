#ifndef MOVIE_H
#define MOVIE_H
#pragma once

#include <iostream>
#include <string>

class Movie  
{
	private:
		std::string name;
		std::string rating;
		int watched;

	public:
		Movie(std::string name, std::string rating, int watched);
		// Copy Constructor
		Movie(const Movie& movie);
		
		~Movie();

		std::string get_name() const { return name; }
		void set_name(std::string name) { this->name = name; }

		std::string get_rating() const { return rating; }
		void set_rating(std::string rating) { this->rating = rating; }

		int get_watched() const { return watched; }
		void set_watched(int watched) { this->watched = watched; }

};
#endif