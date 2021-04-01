#include <iostream>
#include <vector>

#include "blackjack.h"
#include "oop_3.h"
#include "oop_4.h"


using namespace std;

int main() {
//  1.
    cout << "2." << endl;
    lesson4::ArrayInt arrayInt;
    arrayInt.push_back(1);
    arrayInt.push_back(3);
    arrayInt.push_back(2);
    arrayInt.push_back(10);
    arrayInt.push_back(7);

    arrayInt.print();
    arrayInt.sort();
    arrayInt.print();
    arrayInt.pop_back();
    arrayInt.print();
    arrayInt.pop_front();
    arrayInt.print();


//  2.
    cout << endl << "2." << endl;
    vector<int> integers = {1,2,3,3,2,1,4,6,10,2,3,5};
    cout << "Diffs: " << lesson4::count_different_ints_in_vector(integers, integers.size()) << endl;


//  blackjack
    cout << endl << "BLACKJACK!" << endl;
    blackjack::Hand hand;
    blackjack::Card card;
    blackjack::Card card2;
    blackjack::Card card3;
    blackjack::Card card4;

    cout << "Card1: " << card.GetTextValue() << endl;
    cout << "Card2: " << card2.GetTextValue() << endl;
    cout << "Card3: " << card3.GetTextValue() << endl;
    cout << "Card4: " << card4.GetTextValue() << endl;

    hand.Add(card);
    hand.Add(card2);
    hand.Add(card3);
    hand.Add(card4);
    cout << "My random hand: " << hand.GetValue() << endl;
    hand.Clear();
    cout << "My empty hand: " << hand.GetValue() << endl;

    return 0;
}
