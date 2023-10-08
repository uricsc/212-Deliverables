#include "hash_table.h"
#include <fstream>
#include <sstream>

int main(int argc, char*argv[]){
    std::ifstream ifs(argv[1]);
    int mode = std::stoi(argv[2]);

    HashTable table(mode);

    std::string line;

    // Get the numbers to be inserted
    std::getline(ifs, line);
    std::stringstream ss(line);

    int num;
    // Insert the numbers
    while(ss >> num){
        table.insert(num);
    }
    table.print_table();
    std::cout << "Total Collisions: " << table.get_num_collisions() << std::endl;
}