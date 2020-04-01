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

let areCardsDifferentColor = (c1, c2) => c1.suit != c2.suit;

let areRanksInDescendingOrder = (~sourceCard, ~destinationCard) =>
  destinationCard.rank == sourceCard.rank + 1;

let isLegalMove = (~sourceCard, ~destinationCard) =>
  areCardsDifferentColor(sourceCard, destinationCard)
  && areRanksInDescendingOrder(~sourceCard, ~destinationCard);
