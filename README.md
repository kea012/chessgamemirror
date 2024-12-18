# Chess Game
 
Authors: [Kenny Ea](https://github.com/kea012)
         [Ryan Gomez](https://github.com/potobeans)
         [Ethan Mukai](https://github.com/emukai3)
         [Yuzhe Lin](https://github.com/L-yz16)      

## Project Description

Description:

A basic chess game with complete playable functionality. The game is played on an 8 by 8 checkered board with black and white squares. There are six different types of pieces, each able to make unique movements across the board. The game is played by two players, with one controlling a team consisting initially of 16 black pieces and the other player controlling an identical team of 16 white pieces. The game is turn-based, each turn consisting of the player choosing a single move for one of their pieces, with each type having their own unique movement traits. The game ends when a player’s “king” piece is both under attack and restricted from movement due to the opposing player’s pieces, without a method of blocking the attack.

Why is it important to us?:

Chess is a moderately complex board game, with each piece having its own unique rules and interactions within the game. This, paired with the task of creating a logically robust board layout for the pieces form a challenging project that will test our skills with object-oriented programming and class interactions.

Tools:

We plan to use c++ to make the chess game.

Input/Output:

Our inputs and outputs will be through the terminal. The input will ask if you want to play. It will ask what color you want to play as. Users will be able to select one of their pieces and select a valid position to move the piece to. If a move is unable to be performed, a warning message will appear, and prompt the user to select a different move. If a king is put in checkmate, the game will end, a message will output the winner, and the game will reset. If a pawn reaches the opposite side of the board, a prompt will ask the player what piece they would like to exchange for it and will swap the piece. We are going to also output the board and the pieces on the board so that the players know how it will look. 

Features:

As a team we will create a basic chase game. Before entering the game, players will be able to choose the side they wish to play on. A main feature of the game is the interactable chess pieces, with each type having its own moveset in terms of board traversal. These pieces will be created via the use of a superclass “character” and several derived classes. The character class will have all the basic data members and member functions each character needs, such as color of piece, location, and dead/alive. The derived classes will contain the name of the piece, moveset, and specify special traits for the king and pawn pieces. Players will have the opportunity to move the pieces across the board via user input. The board, a feature of the game that specifies the position of each piece, will be a nested array, each section capable of containing a piece object, very much like the real game. Movement of pieces will be tracked by the board and will allow for easy intersection checking between pieces for both movement and attacking. Upon the intersection of two opposing pieces, the piece on the side of the attacker will take up the space of the piece previously in that segment, besides the king. Each new turn will print the updated board onto the screen for the players to view. In the case of a player attempting to make an illegal move, a message will display, prompting the user to make a different move. Another primary feature of the game is the “king” piece, which is important to winning the game. As it cannot move into spaces able to be moved to by opposing pieces, and requires it to be both under attack by another piece and have no other location to move in order to be checkmated, it must have a unique system with the board in order to tell when these events take place.

### Navigation Diagram

Description:

When the user begins the program, they will first be prompted to make an input to start a new game. Once the user starts a new game, the main gameplay loop will begin and the chessboard will be printed to the screen with all pieces in their proper initial positions.

Once a game has started, the first player will take their turn. During each turn, players will input text to select one of their pieces positions and then input text to select a new position to move that piece. If the player makes an invalid input (e.g. enters an invalid position to move a piece to) they will be prompted to input new values again until their input is valid. After a player makes a valid movement for their selected piece, the program will print out the board, updated to reflect the movement (and capture, if one was made). If the player moves a pawn to the opposite end of the board during their turn, they will be prompted to make an input to select a piece to promote their pawn to. Once the player makes a valid input, the board will again be printed, reflecting the piece that their pawn has been promoted to. After this, the player's turn will be completed.

After each player's turn, the program will check if any game-ending conditions have been reached, which means either a checkmate or a draw. If a draw is detected, the game will end with no winner, sending the user back to the start screen. If a checkmate is detected, the game will end with the player who put the other player in checkmate as the winner and will send the user back to the start screen. From the start screen, the user can make an input to start a new game.

If no game-ending conditions are detected after one player’s turn, then the other player’s turn will begin. Both player’s turns will function the exact same way, where they can make one valid movement for one of their pieces.

Navigation Diagram Visual:

![Screenshot 2024-11-04 at 2 52 16 PM](https://github.com/user-attachments/assets/0ed6d3aa-5a04-4045-a466-c38455416276)

### Screen Layouts

Description:

Our chess game will be done through a terminal. Below is a basic layout of how the game will work. We will start by asking if the players want to play or not. If they enter “no”, the program will quit. If they enter “yes” as you see below, we will tell the players how the roles will work between player1 and player2. We will also output the initial chess board game. After that we then prompt player 1 to input with a display menu that gives them their options. Our display menu will allow them to create a new game, quit the game, and make a move. If a player selects m, we will prompt them to select the position of the piece they want to move and then, prompt them to enter the position that they want to move to. After every turn we will automatically display the chess board. Once player1 is done we then prompt player two to go with the same menu. The game will run in this general format. We will account for input errors. If they enter something wrong we will just prompt the players with the menu and board while telling them to try again.

Screen Layout Visual In Terminal:

If you want to start a new chess game, enter “yes” or “no”.

yes

Player 1 goes first and is white.
Player 2 goes second and is black.

![ascii chessboard](https://github.com/user-attachments/assets/7fb97c1c-c906-47ba-adc4-a654ed932c6b)

Player 1 select your input.

Chess Game Menu:

Enter 'S' to start a new game or 'Q' to quit the program

Enter 'M' to make a movee or 'Q' to quit game

m

Enter a position to select a piece.

A2

Enter a position to move selected piece to or 'R' to select a different piece
Possible moves: A3, A4

A3

Enter 'C' to confirm movement or 'R' to select a different position

Display Board:

![ascii chessboard move 2](https://github.com/user-attachments/assets/9d004ad5-af43-4413-96a7-e3fe4b1b7a24)

Player 2 select your input.


## Class Diagram

Description:

The Character class is a base class that each of the classes for the different types of chess pieces inherits from. It includes member variables that are common to all the types of pieces. It includes some mutator and accessor functions for some of its member variables and some functions that will be overridden in the subclasses for the different pieces to represent the different behavior of the pieces.

The Board class is composed of containers, holding pointers to Character objects that represent each piece currently in play. One of these containers is a 2D array that represents the chessboard itself, with the positions of each Character object in the array representing their individual locations on the board. In this array, empty positions (that have a nullptr) represent unoccupied squares on the board. The Board object also contains two vectors of Character pointers, each containing pointers to all of a player’s pieces. Functions in the board class relate to operations that can be made with the board, like moving a piece from one position to another, adding a piece, or removing a piece. The Board class will also have a function to print a representation of the chessboard and all the pieces on it to the console.

The purpose of the Game class is to handle elements of user interaction with the game. The Game class contains a Board object with a composition relationship which it performs actions on via its own functions. It has a member variable that will track which player’s turn is currently happening, which will be used in determining which pieces are valid for the current player to select and move and for determining the winner in certain cases. It has a turn function which can be called on the Game object for each turn and will perform some necessary actions for each user’s turn.

Class Diagram Visual:

<img width="690" alt="Screenshot 2024-11-08 at 2 20 06 PM" src="https://github.com/user-attachments/assets/cc6b4dc8-1972-4775-a55c-93f19a1a6b9e">

## Project Revision

After meeting with the TA, the only thing that we needed to revise was the UML diagram. Below we not only fixed their suggestions, but we also added more to our diagram/project to account for the SOLID principle methodologies that we learned.

The Position class was introduced to help better follow the single-responsibility principle. The class helps to aggregate information regarding position, including the row and column in the chess board as separate integers and the position as a string containing a letter and number, which are very commonly used to describe a specific position in a chess board. The class is also able to convert between these different representations of position, helping to eliminate the need to do so in other classes.

The GameState and GameAction classes and their subclasses were introduced to help better follow the single-responsibility rule, open-closed principle, and dependency inversion principle. Rather than having the Game class track all the different ways to parse user input, which regularly changes throughout an actual game, the Game class has a single GameState object, containing a subclass of GameState that implements the parseUserInput function according to the state the subclass represents. The parseUserInput function has a GameAction return type and will always return a specific GameAction subclass depending on the state itself and what input was read. Each GameAction subclass implements the performAction function, which performs actions on the Game object (which almost always includes updating its GameState variable) and returns a string to be output for the user.

The Move class was introduced to better follow the single-responsibility rule and to avoid circular dependencies. Originally, the movement of pieces was to be in either the Board or Character class, but we realized that this would likely bloat the classes beyond their initial uses. We also found that because the movement of pieces required the interaction between the two classes, it was very possible that putting the functionality in either of the classes may have lead to circular dependencies, a problem that would have required a lot of extra work to fix. As a result, we determined that a new Move class would fulfill our needs in supplying the information as to how each piece moves and generating their possible moves based on a piece’s location relative to others. This class follows the Single-Responsibility Principle by having the single purpose of determining where a selected piece may move.


## Class Diagram With Solid Principles

![UML Diagram Project CS100 drawio](https://github.com/user-attachments/assets/a90974da-cd3d-4981-ad41-3cab8dae8183)

 ## Final deliverable
 ## Screenshots
 <img width="708" alt="Screenshot 2024-12-06 at 12 28 43 PM" src="https://github.com/user-attachments/assets/244ab9e9-483b-4eb1-bfba-97b1685e0ee9">
<img width="691" alt="Screenshot 2024-12-06 at 12 30 12 PM" src="https://github.com/user-attachments/assets/e2284d82-8280-42ff-85b7-67e4319d2801">
<img width="553" alt="Screenshot 2024-12-06 at 12 34 10 PM" src="https://github.com/user-attachments/assets/22b3face-a586-4e8e-91ea-809ddbcef282">
<img width="659" alt="Screenshot 2024-12-06 at 12 35 26 PM" src="https://github.com/user-attachments/assets/cc270d46-c0da-4ef9-9dba-db85685f8f73">
<img width="682" alt="Screenshot 2024-12-06 at 12 36 16 PM" src="https://github.com/user-attachments/assets/eec57d31-5c7d-4920-aeaf-5e4923379772">
<img width="742" alt="Screenshot 2024-12-06 at 12 38 22 PM" src="https://github.com/user-attachments/assets/e3ceeb16-ffef-4751-a0f2-ef2d13a065dd">

 ## Installation/Usage
 To play the game, compile the Chess.cpp file and run the executable. This can be done by running "cmake .", "make chess", and "./chess". The game is played entirely in the console, and output to the console informs players of what types of inputs they can make and what those inputs will do.
 ## Testing
 Unit Testing: First, we made sure that all the object works for the game. Then, we made a unit test for funtions of our classes, including Board class, Character classes 
 (Bishop, King, Knight, Pawn, Queen, Rook), Move classes (BishopMove, KingMove, KnightMove, PawnMove, QueenMove, RookMove), Position class, GameAction class, GameState class. Each 
 function of our classes will be tested multiple times with different cases if necessary.

 Playtesting: The game was played by different players to ensure moves following the rule of chess and smooth gameplay. Additionally, playtesting helped us discover errors and fix 
 them.


