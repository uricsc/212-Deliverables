#include "adjacency_matrix.h"
#include "adjacency_list.h"
#include <sstream>

void adjacency_matrix(std::string ifname);
void adjacency_list(int mode, std::string ifname);

// Mode
// 0: Adjacency Matrix
// 1: Adjacency List
int main(int argc, char* argv[]){
    int mode = std::stoi(argv[2]);

    if(mode == 0){
        adjacency_matrix(argv[1]);
    }else{
        adjacency_list(mode, argv[1]);
    }
}

void adjacency_matrix(std::string ifname){
    AdjMatrix mat;
    std::ifstream ifs(ifname);
    std::string ofname = ifname.substr(0, ifname.rfind('.')) + "_output_0.dot";

    std::string line;

    int source;
    int dest;
    int weight;

    while(std::getline(ifs, line)){
        std::stringstream ss(line);
        ss >> source >> dest >> weight;
        mat.addEdge(source, dest, weight);
    }

    mat.printGraph();
    mat.outputGraph(ofname);
}

void adjacency_list(int mode, std::string ifname){
    AdjList lst;
    std::ifstream ifs(ifname);
    std::string ofname = ifname.substr(0, ifname.rfind('.')) + "_output_" + std::to_string(mode) + ".dot";
    std::string line;

    std::cout << ifname << std::endl;
    std::cout << ofname << std::endl;

    int source;
    int dest;
    int weight;

    while(std::getline(ifs, line)){
        std::stringstream ss(line);
        ss >> source >> dest >> weight;
        lst.addEdge(source, dest, weight);

    }

    lst.printGraph();
    if(mode == 1){
        lst.problem1(ofname);
    }else if(mode == 2){
        lst.problem2(ofname);
    }else if(mode == 3){
        lst.problem3(ofname);
    }else{
        lst.problem4(ofname);
    }

}