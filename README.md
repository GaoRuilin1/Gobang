# Proposal

Team member: Gao Ruilin

​							Zhao Yazhou (3035772638)

Group 64 in ENGG1340 / COMP2113

## **Introduction**  

Go Bang is an abstract two-player strategy board game, traditionally played with two kinds of stones, black and white stones on a board. It is not only easy to play but can enhance thinking ability and improve intelligence. 

## **Rules**  

Players alternate turns placing a stone of their color on an empty intersection. Black plays first. 

The winner will be the first player who build an unbroken chain of 5 stones horizontally, vertically, or diagonally.  

## **Features to implement**  

`initial the board`
`print the board`
`check if there is an unbroken chain of 5 stones horizontally, vertically, or diagonally, end the game and update the score`
`Save and store the game status`
`Read/get the game status`
`Scoring system`  

## **Adjustments**

Because in this game their will be a strong advantage for the first player so we adjust the “Pro” opening rule. This rule restrict the first player to place the first stone at the center of the board.The second stone had to be placed at least three intersections away from the center.

## Vision

| Vison | Description                                                  |                                                              |
| ----- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| V1.0  | Players can choose: `Start` before the game, `Quit` and `Surrender` during the game. At the end of the game, winner will be declared. | `Start`: If players choose `Start`, game begains. `Quit`: If players choose `Quit`, game over, no winner declared. `Surrender`: If one player choose `Surrender`, the other player will be declared as winner directly. |
| V2.0  | Players can choose: `Start` before the game, `Quit` and `Surrender`  and  `Save`  during the game. At the end of the game, winner will be declared. | `Save`: If playes choose `Save` , they could contine the saved game later. |
| V3.0  | Players can choose: `Start` , `Tutorial` before the game, `Quit` and `Surrender`  and  `Save`  during the game. At the end of the game, winner will be declared. | `Tutorial`: Players could get several tutorials from a document. |
| V4.0  | A beautiful GUI will be developed.                           |                                                              |

