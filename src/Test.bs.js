// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var TestLib$IneffectiveTests = require("./TestLib.bs.js");
var Freecell$IneffectiveTests = require("./Freecell.bs.js");

function testMoveLegality(param) {
  var fiveOfSpades = {
    suit: /* Spades */3,
    rank: 5
  };
  var sixOfHearts = {
    suit: /* Hearts */2,
    rank: 6
  };
  var isFiveToSixLegal = Freecell$IneffectiveTests.isLegalMove(fiveOfSpades, sixOfHearts);
  var isSixToFiveLegal = Freecell$IneffectiveTests.isLegalMove(sixOfHearts, fiveOfSpades);
  return /* :: */[
          TestLib$IneffectiveTests.Bool.assertEqual(true, isFiveToSixLegal, "Moving the five of spades onto the six of hearts is a legal move"),
          /* :: */[
            TestLib$IneffectiveTests.Bool.assertEqual(false, isSixToFiveLegal, "Moving the six of hearts onto the five of spades is not a legal move"),
            /* [] */0
          ]
        ];
}

TestLib$IneffectiveTests.runSuite(/* :: */[
      testMoveLegality,
      /* [] */0
    ]);

exports.testMoveLegality = testMoveLegality;
/*  Not a pure module */