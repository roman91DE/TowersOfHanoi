#pragma once
#include <vector>

struct Stack{
    std::vector<int> vals;
    char name; 
    Stack(char _name): name(_name) {}
};


class Hanoi{
    public:
        Stack *A, *B, *C;
        const int num_discs;
        int current_round;
    public:
        Hanoi(int _num_discs);
        ~Hanoi();
        void move_disc(Stack *from, Stack *to);
        void solve();
        void solve_recursive(Stack *from, Stack *via, Stack *to, int n);
        void print_state() const;
};