# Proposal

1. 游戏简介
2. 游戏规则（双方对战、胜利规则）

3. 技术细节
4. 版本迭代
   1. 双人全程对战
   2. save
   3. tutorial
   4. GUI
***
  1. **Introduction**  
Go Bang is an abstract two-player strategy board game, traditionally played with two kinds of stones, black and white stones on a board. It is not only easy to play but can enhance thinking ability and improve intelligence. 
  2. **Rules**  
Players alternate turns placing a stone of their color on an empty intersection. Black plays first. The winner will be the first player who build an unbroken chain of 5 stones horizontally, vertically, or diagonally.  
  3. **Features to implement**  
`initial the board`
`print the board`
`check if there is an unbroken chain of 5 stones horizontally, vertically, or diagonally, end the game and update the score`
`Save and store the game status`
`Read/get the game status`
`Scoring system`  
  4. **Adjustments**    
Because in this game their will be a strong advantage for the first player so we adjust the “Pro” opening rule. This rule restrict the first player to place the first stone at the center of the board.The second stone had to be placed at least three intersections away from the center.
