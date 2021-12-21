// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// prototypes
void ruler(const int width);
void make_text_middle(const std::string& text, int width);

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void ruler(const int width) {
    std::cout << "\n" << std::setfill('-') << std::setw(width/2) << " ruler " << std::setfill('-') << std::setw(width/2) << "" << std::endl;
    for(int i {0}; i < width; ++i){
        std::cout << (i % 10);
    }
    std::cout << std::endl;
    
    for(int i {0}; i < width; ++i){
        std::cout << "|";
    }
    std::cout << std::endl;
    
}

void make_text_middle(const std::string& text, int width){
    std::cout << std::setw(width/2 - text.length()/2) << // Create space to fill
                 std::left << std::setfill('-') << "" <<
                 text <<                                 // Fill text
                 std::setfill('-') << std::setw(width/2 - text.length()/2) << "" // Fill the rest space
    << std::endl;
}

int main()
{
    const int width = 70;
   
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
                },
                { 
                    "Argentina", { 
                        { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };
    
//    ruler(width);
    
    // Format title
    make_text_middle(tours.title, width);
    std::cout << std::setfill('=') << std::setw(width) << "" << std::endl;
    
    // ruler(width);
    
    // Set column distance between each column
    int d1 = width * 0.3;
    int d2 = width * 0.3;
    int d3 = width * 0.4;
    
    // Format column title
    std::cout << std::setfill(' ');
    std::cout << std::setw(d1) << std::left << "Country"  
              << std::setw(d2) << std::left <<"Cities"
              << std::setw(d3) << std::left << "Population"
              << "Cost" << std::endl;
              
    std::cout << std::setw(width) << std::setfill('-') << "" <<std::endl;
    
    // Set precision
    std::cout << std::setprecision(2) << std::fixed;
    
    // Set fill back to space
    std::cout << std::setfill(' ');
    
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(d1) << std::left << country.name;
        for(size_t i {0}; i < country.cities.size(); ++i) {       // loop through the cities for each country
            if(i == 0){
                std::cout <<std::setw(d2) << country.cities[i].name 
                        << std::setw(d3) << country.cities[i].population 
                        << country.cities[i].cost << std::endl;
            }
            else{
                std::cout << std::setw(d1) << std::left << "" 
                        << std::setw(d2) << country.cities[i].name 
                        << std::setw(d3) << country.cities[i].population 
                        << country.cities[i].cost << std::endl;
            }
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}