// ex.3.6

// en: Define a struct suitable for representing a playing card.

// ru: Определите структуру для представления игральных карт.

struct Card {
    enum class Suit : char { clubs, diamonds, hearts, spades };
    enum class Rank : char { ace = 1, jack = 11, queen = 12, king = 13 };
    Suit suit;
    char rank;
};

int main() {
    Card c{Card::Suit::clubs, 5};
    (void)c;
    return 0;
}
