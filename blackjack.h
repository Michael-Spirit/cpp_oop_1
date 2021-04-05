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
        const bool isOpened() {
            return position;
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
        std::vector<Card> getCards() {
            return cards;
        }
    };

    class GenericPlayer {
        std::string name;
        Hand hand;
    public:
        explicit GenericPlayer(const char *n) {
            name = n;
        }
        virtual ~GenericPlayer() = default;
        virtual bool isHitting() = 0;
        void addHand(Hand h) {
            hand = h;
        }
        bool isBoosted() {
            if (hand.GetValue() > 21) return true;
            else return false;
        }
        void Bust() {
            std::cout << "Dear " << name << " you have been BOOSTED!" << std::endl;
        }
        std::string getName() {
            return name;
        }
        Hand getHand() {
            return hand;
        }
    };

    class Player : public GenericPlayer {
    public:
        Player(const char *n) : GenericPlayer(n) {}
        bool isHitting() {
            return false;
        };
        const void Win() {
            std::cout << "Congratulations! " << getName() << " you won this game!" << std::endl;
        }
        const void Lost() {
            std::cout << "Game over! " << getName() << " good luck next time!" << std::endl;
        }
        const void Push() {
            std::cout << "Its a Draw! " << getName() << " good luck next time!" << std::endl;
        }
    };

    class House : public GenericPlayer {
    public:
        bool isHitting() {
            return getHand().GetValue() <= 16;
        }
    };

    std::ostream& operator<< (std::ostream &out, Card card) {
        if (card.isOpened()) {
            out << card.GetTextValue() << std::endl;
        } else {
            out << "XXX" << std::endl;
        }

        return out;
    }

    std::ostream& operator<< (std::ostream &out, GenericPlayer &genericPlayer) {
        for (Card &card : genericPlayer.getHand().getCards()) {
            out << card.GetTextValue() << ", ";
        }
        out << " (Total: " << genericPlayer.getHand().GetValue() << ")" << std::endl;
        return out;
    }
};


#endif //CPP_LESSON8_BLACKJACK_H
