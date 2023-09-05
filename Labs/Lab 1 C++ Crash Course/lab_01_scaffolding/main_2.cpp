#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
Animal* AnimalFactory(std::string type, float hunger, float thirst);

int main(int argc, char*argv[]){
    // Extract # of animals we're expecting to read from the CLA
    int num_animals = std::stoi(argv[1]);
    // Extract the
    std::string fname(argv[2]);
    std::ifstream input_file(fname);

    std::vector<Animal*> animal_arr;

    std::string current_line;
    // For use with tokenizing
    std::string temp;
    std::string curr_type;
    float curr_hunger;
    float curr_thirst;

    // Loop through the number of animals we have.
    for(int i = 0; i < num_animals; i++){
        // Read the current line from the file
        std::getline(input_file, current_line);
        // Convert the current line into a stream
        std::stringstream current_line_stream(current_line);

        // Copy the type directly into our 'type' variable
        std::getline(current_line_stream, curr_type, ' ');

        // Copy the hunger value into your temp variable
        std::getline(current_line_stream, temp, ' ');
        // Convert our temp variable into a float & store into 'curr_hunger'
        curr_hunger = std::stof(temp);

        // Copy the thirst value into your temp variable
        std::getline(current_line_stream, temp, ' ');
        // Convert our temp variable into a float & store into 'curr_thirst'
        curr_thirst = std::stof(temp);

        animal_arr.push_back(AnimalFactory(curr_type, curr_hunger, curr_thirst));
    }

    for(int i = 0; i < num_animals; i++){
        animal_arr[i]->Speak();
        std::cout << animal_arr[i]->GetHunger() << std::endl;
        std::cout << animal_arr[i]->GetThirst() << std::endl;
    }
}

Animal* AnimalFactory(std::string type, float hunger, float thirst){
    if(type == "Cat"){
        return new Cat(hunger, thirst);
    }else if(type == "Dog"){
        return new Dog(hunger, thirst);
    }else if(type == "Bird"){
        return new Bird(hunger, thirst);
    }else if(type == "Hamster"){
        return new Hamster(hunger, thirst);
    }else if(type == "Snake"){
        return new Snake(hunger, thirst);
    }
}
