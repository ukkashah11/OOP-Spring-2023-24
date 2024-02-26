/*Syed Ukkashah Ahmed Shah
  23K-0055
  Added comments where necessary
*/
#include <iostream>
#include <cctype>
using namespace std;
class ChessPiece{
    private:
    string name, color;
    char symbol;
    public:
    void setName(string name){
        this->name = name;
    }
    void setColor(string color){
        this->color = color;
    }
    void setSymbol(){
        if(color == "black"){
            symbol = name[0];
            if(name=="Knight"){
                symbol = 'N';
            }
        }
        else{
            symbol = tolower(name[0]); //uppercase symbol if color is black
            if(name=="Knight"){
                symbol = 'n';
            }
        }
    }
    char getSymbol()const{
        return symbol;
    }
    string getColor()const{
        return color;
    }
    string getName()const{
        return name;
    }
    ChessPiece(){
        setName("Pawn");
        setColor("white");
        setSymbol();
    }
    ChessPiece(string name, string color): name(name), color(color){setSymbol();} 
};
class ChessBoard{
private:
ChessPiece* board[8][8];
public:
ChessBoard() {
	// initialising all pieces as per the sample in the question paper, Using DMA for the Chess Pieces
        board[0][0] = new ChessPiece("Rook", "white");
        board[0][1] = new ChessPiece("Knight", "white");
        board[0][2] = new ChessPiece("Bishop", "white");
        board[0][3] = new ChessPiece("King", "white");
        board[0][4] = new ChessPiece("Queen", "white");
        board[0][5] = new ChessPiece("Bishop", "white");
        board[0][6] = new ChessPiece("Knight", "white");
        board[0][7] = new ChessPiece("Rook", "white");
        for (int i = 0; i < 8; i++) board[1][i] = new ChessPiece();
        board[7][0] = new ChessPiece("Rook", "black");
        board[7][1] = new ChessPiece("Knight", "black");
        board[7][2] = new ChessPiece("Bishop", "black");
        board[7][3] = new ChessPiece("King", "black");
        board[7][4] = new ChessPiece("Queen", "black");
        board[7][5] = new ChessPiece("Bishop", "black");
        board[7][6] = new ChessPiece("Knight", "black");
        board[7][7] = new ChessPiece("Rook", "black");
        for (int i = 0; i < 8; i++) board[6][i] = new ChessPiece("Pawn", "black");
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = new ChessPiece(".", "none");
            }
        }
	}
void display() const 
    {
        cout << "  a b c d e f g h\n";
        for(int i = 0; i < 8; ++i) {
            cout << 8 - i << " ";
            for(int j = 0; j < 8; ++j) {
                if(board[i][j] == nullptr) {
                    cout << ". ";
                } else {
                    cout << board[i][j]->getSymbol() << ' ';
                }
            }
            cout << 8 - i << "\n";
        }
        cout << "  a b c d e f g h\n";
    }
    bool movePiece(string source, string destination) {
		// getting all positions from string
		int dest_row = 7-(destination[1]-'1'), dest_col = destination[0]-'a', src_row = 7-(source[1]-'1'), src_col = source[0]-'a'; //
		char src_name = board[src_row][src_col]->getSymbol(), dest_name = board[dest_row][dest_col]->getSymbol(); // chess piece name
		cout << "validating move for '" << src_name << "' from " << source << " to " << destination << ":" << endl;
		if (src_name == 'n' || src_name == 'N') {
			bool vertical = abs(dest_row - src_row) == 2 && abs(dest_col - src_col) == 1; // 2 up/down and 1 right/left
			bool horizontal = abs(dest_row - src_row) == 1 && abs(dest_col - src_col) == 2; // 1 up/down and 2 right/left
			// check for any of the cases and also make sure dest is not occupied by another piece
			return vertical || horizontal && dest_name == '.';
		} else if (src_name == 'p' || src_name == 'P') {
			return src_col == dest_col && // checking if same column
				// checking  upward  movement and obstacle
				((src_row - dest_row == 1 || src_row - dest_row == 2) && board[src_row-1][src_col]->getSymbol() == '.') || 
				// checking downward movement and obstacle
				((dest_row - src_row == 1 || dest_row - src_row == 2) && board[src_row+1][src_col]->getSymbol() == '.');
		}
		return false;
	}
    ~ChessBoard(){ //destructor called to deallocate the memory in the heap for the board pieces
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                delete board[i][j];
            }
        }
    }

};
int main(){
    cout<<"SYED UKKASHAH\n23K-0055\n\n"<<endl;
    ChessBoard board;
	board.display();
	cout << endl << endl;
	// invalid move - white knight
	cout << (board.movePiece("g8", "f7") ? "valid" : "not valid") << endl << endl;
	// valid move - white knight
	cout << (board.movePiece("b8", "c6") ? "valid" : "not valid") << endl << endl;
	// invalid move - black pawn
	cout << (board.movePiece("c2", "h2") ? "valid" : "not valid") << endl << endl;
	// valid move - black pawn
	cout << (board.movePiece("e2", "e4") ? "valid" : "not valid") << endl << endl;
	return 0;
}
