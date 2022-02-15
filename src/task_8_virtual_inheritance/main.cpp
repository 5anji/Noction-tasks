#include <iostream>

struct Animals {
    virtual void say() {
        std::cout << "Hello World" << std::endl;
    }
};

struct Cat : virtual private Animals {
    virtual void say() {
        std::cout << "Miau" << std::endl;
    }
};

struct Dog : virtual public Animals {
    virtual void say() {
        std::cout << "Gaf" << std::endl;
    }
};

struct Mammals : public Cat
        , public Dog {
    void say() {
        std::cout << "Mu" << std::endl;
    }
};

int main() {
    Dog d;
    Cat c;
    Mammals m;
    Animals* a[3];

    a[0] = &d;
    a[1] = reinterpret_cast<Animals*>(&c);
    a[2] = &m;

    for (size_t i = 0; i < 3; i++) {
        a[i]->say();
    }

    return 0;
}