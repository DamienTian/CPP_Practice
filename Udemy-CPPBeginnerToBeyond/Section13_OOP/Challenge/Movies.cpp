#include "Movies.h"  
	
Movies::Movies(){
	movies_collection = new std::vector<Movie>;
}

Movies::Movies(const Movies& movies) : movies_collection(movies.movies_collection){}

Movies::Movies(Movies&& movies) : movies_collection(movies.movies_collection){
    movies.movies_collection = nullptr;
}
	
Movies::~Movies(){
	delete movies_collection;
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
    // Loop through the vector
    for(const Movie& m : *movies_collection){
        if(m.get_name() == name){
            return false;
        }
    }

    // Call Movie constructor
    movies_collection->push_back(Movie(name, rating, watched));
    return true;
}

bool Movies::increment_watched(std::string name){
    // Loop through the vector
    for(Movie& m : *movies_collection){
        if(m.get_name() == name){
            m.set_watched(m.get_watched() + 1);
            return true;
        }
    }

    return false;
}

void Movies::display(){
    if(movies_collection->empty()){
        std::cout << "Sorry, no movie ... " << std::endl;
    }
    else{
        std::cout << "\n============== Movies ================" << std::endl;
        for(const Movie& m : *movies_collection){
            std::cout << m.get_name() << ", " << m.get_rating() << ", " << m.get_watched() << std::endl;
        }
        std::cout << "======================================" << std::endl;
    }
}