#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"

int main(){

    float hunger_arr[5] = {0, 20, 40, 60, 80};
    float thirst_arr[5] = {10, 30, 50, 70, 90};
    float eat_amount = 25;
    float drink_amount = 50;

    Cat my_cat(hunger_arr[0], thirst_arr[0]);	// object constructed during compile-time
    Dog my_dog(hunger_arr[1], thirst_arr[1]);
    Bird my_bird(hunger_arr[2], thirst_arr[2]);
    Hamster my_hamster(hunger_arr[3], thirst_arr[3]);
    Snake my_snake(hunger_arr[4], thirst_arr[4]);

    std::cout << "Cat hunger: " << my_cat.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << my_dog.GetHunger() << std::endl;
    std::cout << "Bird hunger: " << my_bird.GetHunger() << std::endl;
    std::cout << "Hamster hunger: " << my_hamster.GetHunger() << std::endl;
    std::cout << "Snake hunger: " << my_snake.GetHunger() << std::endl;

    my_cat.Eat(eat_amount);
    my_dog.Eat(eat_amount);
    my_bird.Eat(eat_amount);
    my_hamster.Eat(eat_amount);
    my_snake.Eat(eat_amount);

    std::cout << "Cat hunger: " << my_cat.GetHunger() << std::endl;
    std::cout << "Dog hunger: " << my_dog.GetHunger() << std::endl;
    std::cout << "Bird hunger: " << my_bird.GetHunger() << std::endl;
    std::cout << "Hamster hunger: " << my_hamster.GetHunger() << std::endl;
    std::cout << "Snake hunger: " << my_snake.GetHunger() << std::endl;

    my_cat.Speak();
    my_dog.Speak();
    my_bird.Speak();
    my_hamster.Speak();
    my_snake.Speak();

    std::cout << "Cat thirst: " << my_cat.GetThirst() << std::endl;
    std::cout << "Dog thirst: " << my_dog.GetThirst() << std::endl;
    std::cout << "Bird thirst: " << my_bird.GetThirst() << std::endl;
    std::cout << "Hamster thirst: " << my_hamster.GetThirst() << std::endl;
    std::cout << "Snake thirst: " << my_snake.GetThirst() << std::endl;

    my_cat.Drink(drink_amount);
    my_dog.Drink(drink_amount);
    my_bird.Drink(drink_amount);
    my_hamster.Drink(drink_amount);
    my_snake.Drink(drink_amount);

    std::cout << "Cat thirst: " << my_cat.GetThirst() << std::endl;
    std::cout << "Dog thirst: " << my_dog.GetThirst() << std::endl;
    std::cout << "Bird thirst: " << my_bird.GetThirst() << std::endl;
    std::cout << "Hamster thirst: " << my_hamster.GetThirst() << std::endl;
    std::cout << "Snake thirst: " << my_snake.GetThirst() << std::endl;


    /*
     * The below code is an example of how to instantiate an object during run-time and invoke
        Dog* dog1 = new Dog(hunger_arr[1]);	// object constructed during run-time. 'dog1' is a pointer.
        // Note the '->' operator. This is used as a shortcut to de-reference a pointer & access the object.
        // The long-form version would be '(*dog1).GetHunger()' and yes, that set of '()' is required.
        std::cout << "Dog hunger: " << dog1->GetHunger() << std::endl;
        dog1->Eat(20);
        dog1->Speak();
     */
}
