#include <iostream>

#include "oop_3.h"
#include "oop_5.h"
#include "oop_6.h"
#include "blackjack.h"


using namespace std;

int main() {
//  1. & 2.
    int input;
    cout << "Please enter a valid int: ";
    lesson6::cin_only_number_format(&input);
    cout << "You inputed: " << input << lesson6::endll << "Test endll" << lesson6::endll;

//  blackjack
    cout << endl << "4." << endl;
    blackjack::Card card;
    blackjack::Card card2;
    blackjack::Hand hand;
    hand.Add(card);
    hand.Add(card2);
    blackjack::Player player("Michael");
    player.addHand(hand);

    cout << "card: " << card << endl;
    card.flip();
    cout << "card: " << card << endl;
    cout << "player: " << player << endl;


    return 0;
}
