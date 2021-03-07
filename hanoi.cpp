#include "hanoi.h"
#include <iostream>

Hanoi::Hanoi(int _num_discs, bool _print) 
: A (new Stack('A')), B(new Stack('B')), C(new Stack('C')),
  num_discs(_num_discs), current_round(0) {
        for(int i=num_discs; i>0; --i) A->vals.push_back(i);
    }

Hanoi::~Hanoi() {
    delete A;
    delete B;
    delete C;
}

void Hanoi::move_disc(Stack *from, Stack *to) {
    int temp = from->vals[from->vals.size()-1];
    to->vals.push_back(temp);
    from->vals.pop_back();
}



void Hanoi::print_state() const {
    std::cout << "Round " << current_round << "\nA = ";
    for (auto &it_A: A->vals) {std::cout << it_A <<  " ";}
    std::cout << "\nB = ";
    for (auto &it_B: B->vals) {std::cout << it_B <<  " ";}
    std::cout << "\nC = ";
    for (auto &it_C: C->vals) {std::cout << it_C <<  " ";}
    std::cout << "\n--------------\n";
}

void Hanoi::solve() {
    print_state();
    solve_recursive(A,B,C, num_discs);
}

void Hanoi::solve_recursive(Stack *from, Stack *via, Stack *to, int n) {
    if (n==0) return;
    else {
        solve_recursive(from,to,via,n-1);
        move_disc(from,to);
            ++current_round;
            print_state();
        solve_recursive(via,from,to, n-1);
    }
}