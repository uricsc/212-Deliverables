# Lab 11 - Sets and Maps

## 1. Introduction

In this lab we will be looking into how to store data read from text files into sets and maps, both of which can be thought of as using binary search trees in their implementations. We will be utilizing classes from the STL (Standard Template Library) such as fstream, set and map. The goal of this lab will be to become familiar with use cases of set and map, as well as their operations to provide a framework in which to understand the underlying data structures that make them tick during lecture.

## 2. Data


Today we'll be working with a real-world dataset. This dataset has 3,959 rows of data, each with 14 columns in the following format:

``` FIPS,Admin2,Province_State,Country_Region,Last_Update,Lat,Long_,Confirmed,Deaths,Recovered,Active,Combined_Key,Incidence_Rate,Case-Fatality_Ratio```

To handle the commas, we can use an overloaded version of ```std::getline()```. If you reference the manual page (http://www.cplusplus.com/reference/string/string/getline/) you'll see that there is a version of the function that accepts a delimiter. By passing an argument here, we specify how we want the string to be split up. Every call to ```std::getline()``` will read the data up to the next symbol set as the delimiter. You can place this in a loop to parse a delimited string. This would turn the code above into:

```c++
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::string line;
    std::string entry;
    std::ifstream table;                // 1. Create instance
    
    table.open("file.csv");                    // 2. Open the file
    
    if(table.fail()){                           //    Check open
        cerr << "Can't open file\n";
        return 1;
    }
    
    while(std::getline(table, line)){           // 3. get a line of data from table, store in 'line'
        std::stringstream streamline(line);
        while(std::getline(streamline, entry, ',')){  // 4. loop each "column" in 'line'. It will be stored into 'entry'
            std::cout << entry << std::endl;
        }
    }    
    
    table.close();                                  // 5. Close the file
    // ...
}
```

### 3. Sets

The reason for being called a "set" comes directly from set theory, a branch of mathematics, in which a set is a collection of distinct objects. In other words, each element that could be in the set is either in the set or not in the set, there is no "amount" associated with a given element. There are a myriad of operations that you can perform on a set. Look at the [set reference](http://en.cppreference.com/w/cpp/container/set) page to familiarize yourself with the basic operations.

```c++
#include <set>
#include <string>

int main() {
    std::set<std::string> animals; // creating a set of strings

	myset.insert("cat");
	myset.insert("dog");
	myset.insert("horse");

	// ...
}
```

## 4. Maps

Maps are similar to sets, in that each contains a number of unique elements that are in order. The *key* difference between sets and maps in general is that sets store elements all by themselves, whereas maps store *key-value pairs*. A key-value pair is a pair of two elements where the first element, the key, is used to index the map, and the second element, the value, is what is stored/returned. Similar to the set reference page, there exists a [map reference](https://en.cppreference.com/w/cpp/container/map) page for you to explore as well.

Here is an example of maps in action:

```c++
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mymap;

    mymap["dog"] = 7;
    mymap.emplace("cat", 4); // This is the same as mymap["cat"] = 4
    mymap.insert({{"fish", 11}}); // This is the same as mymap["fish"] = 11
    mymap["cat"]++;

    std::cout << mymap["dog"] << std::endl; // Prints 7
    std::cout << mymap["cat"] << std::endl; // Prints 5
    std::cout << mymap["fish"] << std::endl; // Prints 11

}
```

Note that when you use `emplace` or `insert` with a key that is *already in the map*, the value will **not** be replaced.

## 5. Task for Today

You will be working with a database compiled and maintained by John Hopkins University containing information on cases of COVID-19 (The full database can be found here https://github.com/CSSEGISandData/COVID-19). The goal of this task is to read through the provided text file, insert each unique country into a set and then insert key-value pairs of states/provinces and their associated **confirmed** COVID-19 cases into a map. States/provinces will be the key, and confirmed cases will be the value. If a line of of the text file **does not have an associated state/province, then use the country as the key**.

The database is comma-separated; the third column of data is the state/province where the COVID-19 cases are occurring. The fourth column of data is the country and the current confirmed cases of COVID-19 will be the eight column of data. Every row has a country name and the same number of commas, but not every row has a state/province.

### 5.1 Code

You will be given confirmed_cases.txt (database of confirmed COVID-19 cases), and need to write a program to the following specifications:

- Accept the arguments \<dataset> \<command list>
- Read the dataset and create a `set` and a `map` using the dataset per the instructions in section 2
- Reads the command list file that handles the following commands:
  - "set <state/province/country>"
    - should return whether the state/province/country exists in the set (1 or 0)
  - "map <state/province/country>"
    - should return the # of confirmed cases (0 if the state/province/country is not in the map!)

### 5.2 Questions

In Gradescope, respond to the following questions in Lab 9 : Sets & Maps {QUESTIONS}

1. What is the big O runtime of insert on a set? A map?
2. What is the difference between a set and a map?
3. Why are sets and maps useful?
4. How many countries currently have confirmed cases of COVID-19? (set methods)
5. How many confirmed cases does Kazakhstan currently have? (map methods)
6. Which country has the most confirmed cases?

## 6. Submission

You will submit your `set_map.cpp` to Lab 09 : Sets & Maps {CODE}
and your question responses to Lab 09 : Sets & Maps {QUESTIONS}
