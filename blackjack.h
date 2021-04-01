#ifndef CPP_LESSON8_BLACKJACK_H
#define CPP_LESSON8_BLACKJACK_H

#include <vector>
#include <sstream>

namespace blackjack
{
    int extra_count_for_aces(int total, int aces) {
        if (total > 21 && aces > 0) {
            total -= 10;
            aces--;
            return extra_count_for_aces(total, aces);
        } else {
            return total;
        }
    }

    enum Suits { clubs, diamonds, hearts, spades };
    enum Value {
        ace, two, three,
        four, five, six,
        seven, eight, nine,
        ten, jack, queen, king
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
    int value_to_int(Value type) {
        switch (type) {
            case ace:
                return 11;
            case two:
                return 2;
            case three:
                return 3;
            case four:
                return 4;
            case five:
                return 5;
            case six:
                return 6;
            case seven:
                return 7;
            case eight:
                return 8;
            case nine:
                return 9;
            default:
                return 10;
        }
    }

    class Card {
        Suits suit;
        bool position;
    public:
        Value value;
        Card() {
            // randomize values for now
            suit = static_cast<Suits>(rand() % spades);
            value = static_cast<Value>(rand() % king);
            position = false;
        }
        void flip() {
            position = !position;
        }
        std::string GetTextValue() {
            std::ostringstream ss;
            ss << value_to_string(value) << " of " << suit_to_string(suit);
            return ss.str();
        }
        int getValue() {
            return value_to_int(value);
        }
    };

    class Hand {
        std::vector<Card> cards;
    public:
        void Add(Card card) {
            cards.push_back(card);
        }
        void Clear() {
            cards.clear();
        }
        int GetValue() {
            int aces = 0;
            int total = 0;

            for (Card &card : cards) {
                total += card.getValue();
                if (card.value == Value::ace) {
                    aces++;
                }
            }

            return extra_count_for_aces(total, aces);
        }
    };
};


#endif //CPP_LESSON8_BLACKJACK_H
