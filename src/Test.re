open TestLib;
open Freecell;

let testMoveLegality = () => {
  let fiveOfSpades = {suit: Spades, rank: 5};
  let sixOfHearts = {suit: Hearts, rank: 6};

  let isFiveToSixLegal = isLegalMove(
    ~sourceCard=fiveOfSpades,
    ~destinationCard=sixOfHearts
  );

  let isSixToFiveLegal = isLegalMove(
    ~sourceCard=sixOfHearts,
    ~destinationCard=fiveOfSpades
  );

  [
    Bool.assertEqual(
      ~expected=true,
      ~actual=isFiveToSixLegal,
      "Moving the five of spades onto the six of hearts is a legal move"
    ),
    Bool.assertEqual(
      ~expected=false,
      ~actual=isSixToFiveLegal,
      "Moving the six of hearts onto the five of spades is not a legal move"
    )
  ];
};

runSuite([testMoveLegality]);
