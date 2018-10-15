// TicTacToe.cpp   for CS 141 lab 6
//
// Instructions: Change the program below so that it no longer
// uses global variables to represent the board, but rather:
//    1. Declares the board in main() as a 9 character array
//    2. Passes the board to a supplied displayBoard() function
//    3. Change the code so that it uses the array to make moves and check for a win,
//       appropriately doing this using functions.
//
// You get one point each for:
//    1. Getting displayBoard() to work
//    2. Allowing making moves
//    3. [extra credit] detecting and displaying a message when there is a win,
//       which is three of a player's pieces in a row, column or diagonal.

#include <iostream>
using namespace std;



//---------------------------------------------------------------------
// You will need to comment out this old version once you change your program.
/*void displayBoard()
{
    cout << endl
    << "------- \n"
    << "|" << p0 << "|" << p1 << "|" << p2 << "|   1  2  3\n"
    << "------- \n"
    << "|" << p3 << "|" << p4 << "|" << p5 << "|   4  5  6\n"
    << "------- \n"
    << "|" << p6 << "|" << p7 << "|" << p8 << "|   7  8  9\n"
    << "------- "
    << endl;
}    */


//---------------------------------------------------------------------
// Your new program version should use the following
void displayBoard( char board[])
{
    cout << endl
    << "------- \n"
    << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|   1  2  3\n"
    << "------- \n"
    << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|   4  5  6\n"
    << "------- \n"
    << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|   7  8  9\n"
    << "------- "
    << endl;
}
//---------------------------------------------------------------------
void makeMove(char board[], int userInput, char pieceToMove)
{

			board[userInput -1] = pieceToMove;

}
//---------------------------------------------------------------------
int checkForWin(char board[], char pieceToMove) 
{
	int flag=0;
	if ( (board[0]==board[1] && board[1]==board[2] && board[2]!=' ') ||  // top row
         (board[3]==board[4] && board[4]==board[5] && board[5]!=' ') ||  // middle row
         (board[6]==board[7] && board[7]==board[8] && board[8]!=' ') ||  // bottom row
         (board[0]==board[3] && board[3]==board[6] && board[6]!=' ') ||  // left column
         (board[1]==board[4] && board[4]==board[7] && board[7]!=' ') ||  // middle column
         (board[2]==board[5] && board[5]==board[8] && board[8]!=' ') ||  // right column
         (board[0]==board[4] && board[4]==board[8] && board[8]!=' ') ||  // upper-left to lower-right diagonal
         (board[6]==board[4] && board[4]==board[2] && board[2]!=' ')     // lower-left to upper-right diagonal
		) {
		displayBoard(board);
        cout << endl
        << "Congratulations player " << pieceToMove << ". You WON!" << endl;
        flag=1;
        return flag;
	}
}

//---------------------------------------------------------------------
int main()
{
    // Initialize the board
    //*** Hint Initialize the board as a 1D array
    
    char p[9]={ ' ',' ',' ',' ',' ',' ',' ',' ',' '};          // P[] ARRAY declaration where we put piecetomove ( either X or O) in array.

    char pieceToMove = 'X';        // Variable which is either X or O. We put this in arrays p[].
    int position = 0;              // At what position you want to make a move.
    int moveNumber = 1;            // Count the number of moves.
    
    cout << "Welcome to the TicTacToe game! " << endl
    << "Take turns entering the position (1..9)" << endl
    << "into which your piece will be placed. "
    << endl
    << endl;
    // *** Hint call the new version of display board
    displayBoard(p);        // Dislays the board initially.
    
    // Main loop
    while( true) {
        // Prompt for and get move.  Leave this here in your new version.
        cout << moveNumber << ". Enter the move (1..9) for " << pieceToMove << ": ";
        cin >> position;              // User prompts where he wants to put X or 0 in board.
        
        // Make move.  Note that while the board positions are labelled 1..9,
        // the board variables are numbered p0..p8, which is off by one.
        // *** Hint: This whole section of code should change in your new version
        makeMove(p, position, pieceToMove);
        
        //Checking for a win
        if (checkForWin(p, pieceToMove) == 1) {
			break;
		}
        
        // Change to other piece for next move.  Leave this here in your new version.
        if( pieceToMove == 'X') {              // For next move, changes the value of piece to Move.
            pieceToMove = 'O';
        }
        else {
            pieceToMove = 'X';
        }
        
        // *** Hint call the new version of display board
        displayBoard(p);
        
        moveNumber++;   // Increment the move number.
    }// End while
    
    cout << "Exiting program..." << endl;
    return 0;
}//  End Main
