type suit =
  | Clubs
  | Diamonds
  | Hearts
  | Spades;

type color =
  | Red
  | Black;

type rank =
  | Ace
  | Two
  | Three
  | Four
  | Five
  | Six
  | Seven
  | Eight
  | Nine
  | Ten
  | Jack
  | Queen
  | King;

let rankValue = r =>
  switch (r) {
  | Ace => 1
  | Two => 2
  | Three => 3
  | Four => 4
  | Five => 5
  | Six => 6
  | Seven => 7
  | Eight => 8
  | Nine => 9
  | Ten => 10
  | Jack => 11
  | Queen => 12
  | King => 13
  };

type card = {
  suit,
  rank,
};

let cardColor = c =>
  switch (c.suit) {
  | Clubs => Black
  | Spades => Black
  | Diamonds => Red
  | Hearts => Red
  };

let areCardsDifferentColor = (c1, c2) => cardColor(c1) != cardColor(c2);

let areRanksInDescendingOrder = (source, dest) =>
  rankValue(dest.rank) == rankValue(source.rank) + 1;

let isLegalMove = (source, dest) => {
  areCardsDifferentColor(source, dest)
  && areRanksInDescendingOrder(source, dest);
};
