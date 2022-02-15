#include <iostream>

class int_A;
class int_B;

class int_A {
    int a = 0;

public:
    void set(const int x) {
        a = x;
    }
    int get() {
        return a;
    }

    operator int();
    void operator=(const int x);
    // friend int_A& operator=(int_A& y, int_B x);
    int operator+(const int x);
    int operator+(int_B x);
    friend class int_B;
};

class int_B {
    int b = 0;

public:
    int_B() = default;
    void set(const int x) {
        b = x;
    }
    int get() {
        return b;
    }
    operator int();
    int_B(int_A obj_a) {
        this->b = obj_a.a;
    }

    void operator=(const int x);
    void operator=(int_A x);
    int operator+(const int x);
    int operator+(int_A x);
    // friend int_A& operator=(int_A& y, int_B x);
};

// int_A& operator= (int_A& y, int_B& x) {
//     y.a = x.b;
//     return y;
// }

// void int_A::operator=(int_B x) {
//     a = x.get();
// }

int int_A::operator+(int_B x) {
    return a + x.get();
}

void int_A::operator=(const int x) {
    a = x;
}

int int_A::operator+(const int x) {
    return a + x;
}

int_A::operator int() {
    return a;
}

void int_B::operator=(int_A x) {
    b = x;
}

int int_B::operator+(int_A x) {
    return b + x.get();
}

void int_B::operator=(const int x) {
    b = x;
}

int int_B::operator+(const int x) {
    return b + x;
}
int_B::operator int() {
    return b;
}

int main() {
    int_A m;
    int_B n;
    int c;

    m = 4;
    n = 5;
    m = n + m;
    c = m + 1;

    std::cout << m << ' ' << c << std::endl;

    return 0;
}