#include "GameDie.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//class constructor that seeds the random number generator
GameDie::GameDie()
{
    srand(time(NULL));
    roll_counter.resize(FACES);

    for(int i=0; i<FACES; i++)
      roll_counter[i] = 0;
}

//overloaded constructor
GameDie::GameDie(unsigned int num)
{
    if( num == 0 )
    {
        roll_counter.resize(FACES);
    }
    else{
        roll_counter.resize(num);
    }
    for(int i=0; i<FACES; i++)
    {
        roll_counter[i] = 0;
    }

}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int GameDie::roll()
{
    int roll = rand() % roll_counter.size();
    roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <int> GameDie::get_distribution(){
    return roll_counter;
}

// returns the percentage of rolls for each face relative to the number of total
// rolls. Each percentage should be a double between 0 and 1 inclusively. For
// example, if we have a 4-sided die that has rolled each face 1 time and
// has the get_distribution() of:
// {1,1,1,1}
// then the get_percentages() function should return:
// {0.25,0.25,0.25,0.25}
// If there are no rolls yet, percentages should report 0 for each face in the vector. Otherwise, the percentage should be calculated by face rolls / total rolls.
vector <double> GameDie::get_percentages(){
    vector <double> result;
    int total = 0;
    result.resize(counter.size());
    for(unsigned int i = 0; i < counter.size(); i++) {
        total += counter[i];
    }
    if(total == 0) {
        return result;
    }
    for(unsigned int i = 0; i < counter.size(); i++) {
        result[i] = counter[i]/(double)total;
    }
    return result;
}