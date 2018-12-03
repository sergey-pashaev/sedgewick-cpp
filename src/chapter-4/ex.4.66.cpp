// ex.4.66

// en: Write a program to determine empirically the probability that
// various poker hands are dealt, using your ADT from Exercise 4.65.

// ru: Используя АТД из упражнения 4.65, напишите программу, которая
// опытным путем определяет вероятность раздачи различных наборов карт
// при игре в покер.

// poker hands:
// 1. (5 seq rank, same suit) straight flush is a poker hand
// containing five cards of sequential rank, all of the same suit
// 2. (4 same rank) Four of a kind, also known as quads, is a poker
// hand containing four cards of the same rank and one card of another
// rank
// 3. (3 same rank, 2 sane rank) A full house, also known as a full
// boat or a boat (and originally called a full hand), is a poker hand
// containing three cards of one rank and two cards of another rank
// 4. (5 same suit) A flush is a poker hand containing five cards all of the
// same suit, not all of sequential rank
// 5. (5 seq rank) A straight is a poker hand containing five cards of
// sequential rank, not all of the same suit
// 6. (3 same rank) Three of a kind, also known as trips or a set, is a poker
// hand containing three cards of the same rank and two cards of two other ranks
// 7. (2 same rank, 2 same rank) Two pair is a poker hand containing
// two cards of the same rank, two cards of another rank and one card
// of a third rank
// 8. One pair, or simply a pair, is a poker hand containing two cards
// of the same rank and three cards of three other ranks

#include <array>
#include <iostream>

#include <psv/random_queue.h>

namespace poker {

class Card {
   public:
    enum Suit { diamonds, clubs, hearts, spades };

    enum Rank {
        two,
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
    Card() : suit{diamonds}, rank{ace} {}

    Card(Suit s, Rank r) : suit{s}, rank{r} {}

    bool operator==(const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }

    bool operator!=(const Card& other) const { return !(*this == other); }

    Suit suit;
    Rank rank;
};

constexpr std::array<Card::Suit, 4> Suits = {
    Card::Suit::diamonds, Card::Suit::clubs, Card::Suit::hearts,
    Card::Suit::spades};

constexpr std::array<Card::Rank, 13> Ranks = {
    Card::Rank::two, Card::Rank::three, Card::Rank::four,  Card::Rank::five,
    Card::Rank::six, Card::Rank::seven, Card::Rank::eight, Card::Rank::nine,
    Card::Rank::ten, Card::Rank::jack,  Card::Rank::queen, Card::Rank::king,
    Card::Rank::ace};

typedef std::vector<Card> Hand;

class Deck {
   public:
    Deck() : cards_{52} {
        for (const Card::Suit s : Suits) {
            for (const Card::Rank r : Ranks) {
                cards_.Push(Card{s, r});
            }
        }
    }

    Hand Deal() {
        Hand hand;
        const int cards_in_hand = 5;
        hand.reserve(cards_in_hand);
        for (int i = 0; i < cards_in_hand && cards_.Size(); ++i) {
            hand.push_back(cards_.Pop());
        }
        return hand;
    }

   private:
    psv::RandomQueue<Card> cards_;
};

class HandInfo {
   public:
    void Read(const Hand& hand) {
        ++hands_;

        int suits[poker::Suits.size()] = {};
        int ranks[poker::Ranks.size()] = {};
        for (const Card c : hand) {
            suits[static_cast<int>(c.suit)]++;
            ranks[static_cast<int>(c.rank)]++;
        }

        int quads = 0;
        int trips = 0;
        int pairs = 0;

        int max_seq = 0;
        int cur_seq = 0;
        int max_i = 0;
        int cur_i = 0;
        for (const Card::Rank r : Ranks) {
            const int i = static_cast<int>(r);
            if (ranks[i]) {
                ++cur_seq;
                if (cur_seq == 1) cur_i = i;

                if (ranks[i] == 4) quads++;
                if (ranks[i] == 3) trips++;
                if (ranks[i] == 2) pairs++;
            } else {
                if (cur_seq > max_seq) {
                    max_seq = cur_seq;
                    max_i = cur_i;
                }
                cur_seq = 0;
            }
        }

        bool seq_rank = max_seq == 5;

        bool same_suit = false;
        for (const Card::Suit s : Suits) {
            const int i = static_cast<int>(s);
            if (suits[i] == 5) same_suit = true;
        }

        if (seq_rank && same_suit) {
            ++straight_flush_;
        } else if (quads) {
            ++quad_;
        } else if (trips && pairs) {
            ++full_house_;
        } else if (same_suit) {
            ++flush_;
        } else if (seq_rank) {
            ++straight_;
        } else if (trips) {
            ++trips_;
        } else if (pairs == 2) {
            ++two_pairs_;
        } else if (pairs == 1) {
            ++pairs_;
        }
    }

    void Print() const {
        std::cout << pairs_ << ':' << hands_ << " pair ("
                  << double(pairs_) / hands_ << ")\n";
        std::cout << two_pairs_ << ':' << hands_ << " two pair ("
                  << double(two_pairs_) / hands_ << ")\n";
        std::cout << trips_ << ':' << hands_ << " trips ("
                  << double(trips_) / hands_ << ")\n";
        std::cout << straight_ << ':' << hands_ << " straight ("
                  << double(straight_) / hands_ << ")\n";
        std::cout << flush_ << ':' << hands_ << " flush ("
                  << double(flush_) / hands_ << ")\n";
        std::cout << full_house_ << ':' << hands_ << " full house ("
                  << double(full_house_) / hands_ << ")\n";
        std::cout << quad_ << ':' << hands_ << " quad ("
                  << double(quad_) / hands_ << ")\n";
        std::cout << straight_flush_ << ':' << hands_ << " straight flush ("
                  << double(straight_flush_) / hands_ << ")\n";
    }

   private:
    // clang-format off
    int hands_          = 0;
    int straight_flush_ = 0;
    int quad_           = 0;
    int full_house_     = 0;
    int flush_          = 0;
    int straight_       = 0;
    int trips_          = 0;
    int two_pairs_      = 0;
    int pairs_          = 0;
    // clang-format on
};

}  // namespace poker

int usage(const char* bin) {
    std::cout << "Usage: " << bin << " <positive int HANDS>\n";
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return usage(argv[0]);
    }

    const int hands = std::atoi(argv[1]);
    if (hands <= 0) {
        return usage(argv[0]);
    }

    poker::HandInfo info;
    for (int j = 0; j < hands;) {
        poker::Deck deck;
        const int hands_in_deck = 10;
        for (int i = 0; i < hands_in_deck && j < hands; ++i, ++j) {
            info.Read(deck.Deal());
        }
    }
    info.Print();
    return 0;
}
