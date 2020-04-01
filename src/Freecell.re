type suit =
  | Clubs
  | Diamonds
  | Hearts
  | Spades;

type color =
  | Red
  | Black;

type card = {
  suit,
  rank: int,
};

let cardColor = c =>
  switch (c.suit) {
  | Clubs
  | Spades => Black
  | Diamonds
  | Hearts => Red
  };

let areCardsDifferentColor = (c1, c2) => cardColor(c1) != cardColor(c2);

let areRanksInDescendingOrder = (~sourceCard, ~destinationCard) =>
  destinationCard.rank == sourceCard.rank + 1;

let isLegalMove = (~sourceCard, ~destinationCard) =>
  areCardsDifferentColor(sourceCard, destinationCard)
  && areRanksInDescendingOrder(~sourceCard, ~destinationCard);
