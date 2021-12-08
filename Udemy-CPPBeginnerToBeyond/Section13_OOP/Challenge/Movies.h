#ifndef MOVIES_H
#define MOVIES_H
#pragma once

#include <iostream>
#include <vector>
#include "Movie.h"
	
class Movies  
{
	private:
		// vector to store Movie
		std::vector<Movie>* movies_collection;

	public:

		Movies();
		// Copy constructor
		Movies(const Movies& movie);
		// Move constructor (never called)
		Movies(Movies&& movies);
		~Movies();

		bool add_movie(std::string name, std::string rating, int watched);
		bool increment_watched(std::string name);
		void display();
};
#endif