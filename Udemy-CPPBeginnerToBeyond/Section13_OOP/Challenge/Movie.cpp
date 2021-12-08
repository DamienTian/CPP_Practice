#include "Movie.h"  

Movie::Movie(std::string name, std::string rating, int watched) : 
    name(name), rating(rating), watched(watched){
    //std::cout << "Constructor called on movie " << name << std::endl;
}

Movie::Movie(const Movie& movie) : 
    Movie(movie.get_name(), movie.get_rating(), movie.get_watched()){
    //std::cout << "Cpoy Constructor called on movie " << this->name << std::endl;
}
 
Movie::~Movie(){
	
}

