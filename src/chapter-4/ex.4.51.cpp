// ex.4.51

// en: Write a client that takes an integer N from the first argument
// on the command line, then prints out N poker hands, by putting N
// items on a random queue (see Exercise 4.7), then printing out the
// result of picking five cards at a time from the queue.

// ru: Напишите программу-клиент, которая принимает из первого
// аргумента коммандной строки целое число N, а затем выводит
// результат раздачи карт на N игроков в покер. Для этого она должна
// занести в неупорядоченную очередь N элементов (см. упр. 4.7) и
// затем выдавать результат выбора из этой очереди по пять карт за
// один раз.

#include <iostream>

#include <psv/random_queue.h>

class Card {
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

    // FIXME: weird default values to make it possible to construct
    // array of Cards
    Card() : suit_{diamonds}, rank_{ace} {}

    Card(Suit suit, Rank rank) : suit_{suit}, rank_{rank} {}

    bool operator==(const Card& other) const {
        return suit_ == other.suit_ && rank_ == other.rank_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Card& i);

   private:
    Suit suit_;
    Rank rank_;
};

std::ostream& operator<<(std::ostream& os, Card::Suit s) {
    switch (s) {
        case Card::diamonds: {
            os << "diamonds";
            break;
        }
        case Card::clubs: {
            os << "clubs";
            break;
        }
        case Card::hearts: {
            os << "hearts";
            break;
        }
        case Card::spades: {
            os << "spades";
            break;
        }
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, Card::Rank r) {
    switch (r) {
        case Card::jack: {
            os << "jack";
            break;
        }
        case Card::queen: {
            os << "queen";
            break;
        }
        case Card::king: {
            os << "king";
            break;
        }
        case Card::ace: {
            os << "ace";
            break;
        }
        default:
            os << static_cast<int>(r);
            break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, const Card& i) {
    os << i.rank_ << " of " << i.suit_;
    return os;
}

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int N>\n";
    return 1;
}

void FillPocker(psv::RandomQueue<Card>& deck) {
    for (Card::Suit s = Card::diamonds; s <= Card::spades;
         s = static_cast<Card::Suit>(s + 1)) {
        for (Card::Rank r = Card::two; r <= Card::ace;
             r = static_cast<Card::Rank>(r + 1)) {
            deck.Push(Card{s, r});
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    int N = std::atoi(argv[1]);
    if (N <= 0) {
        return usage(argv[0]);
    }

    const int size = 52;
    psv::RandomQueue<Card> deck{size};
    FillPocker(deck);

    const int hand = 5;
    for (int i = 0; i < N && !deck.Empty(); ++i) {
        for (int j = 0; j < hand && !deck.Empty(); ++j) {
            std::cout << deck.Pop() << '\n';
        }

        if (i + 1 < N) std::cout << '\n';
    }

    return 0;
}
