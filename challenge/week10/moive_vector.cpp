#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie
{
public:
    string name;
    float score;
    Movie(string name = " ", float score = 0) {
        this->name = name;
        this->score = score;
    }
    void Print() {
        cout << name << ": " << score << endl;
    }

    
};

int main(void) {
    vector<Movie> movieArray;
    Movie movie1("apple", 8.0);
    Movie movie2("Rainy day", 9.2);
    Movie movie3("Catch me if you can", 9.3);

    movieArray.push_back(movie1);
    movieArray.push_back(movie2);
    movieArray.push_back(movie3);
    
    for (Movie m : movieArray)
        m.Print();

}