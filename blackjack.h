//
// Created by Михаил Спиридонов on 01.04.2021.
//

#ifndef CPP_LESSON8_BLACKJACK_H
#define CPP_LESSON8_BLACKJACK_H

namespace blackjack
{
    enum Suits { clubs, diamonds, hearts, spades };
    enum Value {
        ace=1, two=2, three=3,
        four=4, five=5, six=6,
        seven=7, eight=8, nine=9,
        ten=10, jack=11, queen=12, king=13
    };

    // just to print it nicely
    std::string suit_to_string(Suits type) {
        switch (type) {
            case clubs:
                return "Clubs";
            case diamonds:
                return "Diamonds";
            case hearts:
                return "Hearts";
            case spades:
                return "Spades";
            default:
                return "Error!";
        }
    }
    std::string value_to_string(Value type) {
        switch (type) {
            case ace:
                return "Ace";
            case two:
                return "Two";
            case three:
                return "Three";
            case four:
                return "Four";
            case five:
                return "Five";
            case six:
                return "Six";
            case seven:
                return "Seven";
            case eight:
                return "Eight";
            case nine:
                return "Nine";
            case ten:
                return "Ten";
            case jack:
                return "Jack";
            case queen:
                return "Queen";
            case king:
                return "King";
        }
    }

    class Card {
        Suits suit;
        Value value;
        bool position;
    public:
        Card() {
            // randomize values for now
            suit = static_cast<Suits>(rand() % spades);
            value = static_cast<Value>(rand() % king);
            position = false;
        }
        void flip() {
            position = !position;
        }
        std::string GetValue() {
            std::ostringstream ss;
            ss << value_to_string(value) << " of " << suit_to_string(suit);
            return ss.str();
        }
    };
}


#endif //CPP_LESSON8_BLACKJACK_H
