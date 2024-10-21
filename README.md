# \Chess Game\
 
> Authors: \[Kenny Ea](https://github.com/kea012)\
>          \[Ryan Gomez](https://github.com/potobeans)\
>          \[Ethan Mukai](https://github.com/emukai3)\
>          \[Yuzhe Le](https://github.com/L-yz16)\       

## Project Description
> A basic chess game with complete playable functionality. The game is played on an 8 by 8 checkered board with black and white squares. There are six different types of pieces, each able to make unique movements across the board. The game is played by two players, with one   controlling a team consisting initially of 16 black pieces and the other player controlling an identical team of 16 white pieces. The game is turn-based, each turn consisting of the player choosing a single move for one of their pieces, with each type having their own unique movement traits. The game ends when a player’s “king” piece is both under attack and restricted from movement due to the opposing player’s pieces, without a method of blocking the attack. Chess is important since its a moderately complex board game, with each piece having its own unique rules and interactions within the game. This, paired with the task of creating a logically robust board layout for the pieces form a challenging project that will test our skills with object-oriented programming and class interactions. We plan to use c++ for our project. Our inputs and outputs will be through the terminal. The input will ask if you want to play. It will ask what color you want to play as. Users will be able to select one of their pieces and select a valid position to move the piece to. If a move is unable to be performed, a warning message will appear, and prompt the user to select a different move. If a king is put in checkmate, the game will end, a message will output the winner, and the game will reset. If a pawn reaches the opposite side of the board, a prompt will ask the player what piece they would like to exchange for it and will swap the piece. We are going to also output the board and the pieces on the board so that the players know how it will look. There will be a lot of features that we are looking to implement. Before entering the game, players will be able to choose the side they wish to play on. A main feature of the game is the interactable chess pieces, with each type having its own moveset in terms of board traversal. These pieces will be created via the use of a superclass “character” and several derived classes. The character class will have all the basic data members and member functions each character needs, such as color of piece, location, and dead/alive. The derived classes will contain the name of the piece, moveset, and specify special traits for the king and pawn pieces. Players will have the opportunity to move the pieces across the board via user input. The board, a feature of the game that specifies the position of each piece, will be a nested array, each section capable of containing a piece object, very much like the real game. Movement of pieces will be tracked by the board and will allow for easy intersection checking between pieces for both movement and attacking. Upon the intersection of two opposing pieces, the piece on the side of the attacker will take up the space of the piece previously in that segment, besides the king. Each new turn will print the updated board onto the screen for the players to view. In the case of a player attempting to make an illegal move, a message will display, prompting the user to make a different move. Another primary feature of the game is the “king” piece, which is important to winning the game. As it cannot move into spaces able to be moved to by opposing pieces, and requires it to be both under attack by another piece and have no other location to move in order to be checkmated, it must have a unique system with the board in order to tell when these events take place.

 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Each team member needs to submit the Individual Contributions Form on Canvas for this phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase  II, and a description of their contributions. Remember that each team member should submit the form individually.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from the User Interface Design Document Template of CMSC 345 at the University of Maryland Global Campus)

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs and expected output, or any graphical user interface components if applicable (e.g. buttons, text boxes, etc). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
