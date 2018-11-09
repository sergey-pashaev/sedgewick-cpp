// ex.4.7

// en: Give a class definition for Item, and overload the == and <<
// operators, so that they might be used in programs that process
// playing cards.

// ru: Дайте определение для класса Item и перегрущите операции == и
// << так, чтобы их можно было использовать в программе обработки
// игральных карт.

#include <iostream>

class Item {
   public:
    enum Suit { diamonds, clubs, hearts, spades };

    enum Rank {
        two = 2,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        ace
    };

    Item(Suit suit, Rank rank) : suit_{suit}, rank_{rank} {}

    bool operator==(const Item& other) const {
        return suit_ == other.suit_ && rank_ == other.rank_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Item& i);

   private:
    Suit suit_;
    Rank rank_;
};

std::ostream& operator<<(std::ostream& os, Item::Suit s) {
    switch (s) {
        case Item::diamonds: {
            os << "diamonds";
            break;
        }
        case Item::clubs: {
            os << "clubs";
            break;
        }
        case Item::hearts: {
            os << "hearts";
            break;
        }
        case Item::spades: {
            os << "spades";
            break;
        }
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, Item::Rank r) {
    switch (r) {
        case Item::jack: {
            os << "jack";
            break;
        }
        case Item::queen: {
            os << "queen";
            break;
        }
        case Item::king: {
            os << "king";
            break;
        }
        case Item::ace: {
            os << "ace";
            break;
        }
        default:
            os << static_cast<int>(r);
            break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Item& i) {
    os << i.rank_ << " of " << i.suit_;
    return os;
}

int main() {
    Item i{Item::clubs, Item::two};
    Item j{Item::hearts, Item::jack};
    std::cout << i << '\n';
    std::cout << j << '\n';
    return 0;
}
