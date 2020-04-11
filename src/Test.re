open TestLib;
open Freecell;

let ensureRanksAreSequential= () => {
  let module L = Belt.List;

  let allRanks = [
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
  ];

  let values = L.map(allRanks, rankValue);

  let (allSequential, _) =
    L.reduce(values, (true, 0), ((allSeq, prev), v) =>
      (allSeq && v - prev == 1, v)
    );

  [
    assertEqual(
      ~expected=true,
      ~actual=allSequential,
      "Ranks must be sequential in order to have equivalence",
    ),
  ];
};

let testMoveLegalitySubdomains = () => {
  let module L = Belt.List;

  let twoOfHearts = {suit: Hearts, rank: Two};
  let threeOfHearts = {suit: Hearts, rank: Three};
  let threeOfClubs = {suit: Clubs, rank: Three};
  let fourOfClubs = {suit: Clubs, rank: Four};
  let twoOfDiamonds = {suit: Diamonds, rank: Two};
  let threeOfSpades = {suit: Spades, rank: Three};
  let fiveOfSpades = {suit: Spades, rank: Five};

  let descendingDifferentColor = [
    (twoOfHearts, threeOfClubs, true, "2h -> 3c is legal"),
    (twoOfHearts, threeOfSpades, true, "2h -> 3s is legal"),
    (twoOfDiamonds, threeOfSpades, true, "2d -> 3s is legal"),
  ];

  let arbitraryDifferentColor = [
    (fourOfClubs, twoOfDiamonds, false, "4c -> 2d is not legal"),
    (twoOfDiamonds, fiveOfSpades, false, "2d -> 5s is not legal"),    
  ];

  let descendingSameColor = [
    (twoOfHearts, threeOfHearts, false, "2h -> 3h is not legal"),
    (fourOfClubs, fiveOfSpades, false, "4c -> 5s is not legal"),
  ];

  let arbitrarySameColor = [
    (threeOfSpades, fiveOfSpades, false, "3s -> 5s is not legal"),
    (threeOfClubs, fiveOfSpades, false, "3c -> 5s is not legal"),
  ];

  let testTable =
    L.flatten([
      descendingDifferentColor,
      arbitraryDifferentColor,
      descendingSameColor,
      arbitrarySameColor,
    ]);

  L.map(testTable, ((source, dest, expected, msg)) =>
    Bool.assertEqual(~expected, ~actual=isLegalMove(source, dest), msg)
  )
  @ ensureRanksAreSequential();
};

runSuite([
  testMoveLegalitySubdomains,
]);
