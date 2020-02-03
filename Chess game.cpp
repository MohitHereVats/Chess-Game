#include<bits/stdc++.h>
using namespace std;

class CAPiece
{
 private:
     char mcColor;
     virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) = 0;
	// a pure virtual function which is overwritten for each piece class to check that the souce and the destination indicate a particular legitimate
	// move for a particular piece type
 public:
      CAPiece(char color)
      {
       mcColor=color;
      }
     ~CAPiece() {}
     virtual char GetPiece()=0;
     char GetColor()
     {
        return mcColor;
     }

	bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8]) { //checks whether destinaton is empty or of
	                                                                                                   // opposite color
		CAPiece* qpDest = qpaaBoard[iDestRow][iDestCol];
		if ((qpDest == 0) || (mcColor != qpDest->GetColor())) {
			return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, qpaaBoard);
		}
		return false;
	}

};
class CPawn: public CAPiece
{
  public:
    CPawn(char color): CAPiece(color){}
    ~CPawn(){};
  private:
    virtual char GetPiece()
    {
      return 'P';
    }
  bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
  {
   if(qpaaBoard[iDestRow][iDestCol]==0)    // this tells us that destination is unoccupied
   {
     if(GetColor()=='W')
     {
      if((iSrcCol==iDestCol) && (iSrcRow+1==iDestRow))
            return true;
     }
     else
     {
       if((iSrcCol==iDestCol) && (iSrcRow-1==iDestRow))
            return true;
     }

   }
   else
   {
     if(GetColor()=='W')
     {
       if((iSrcCol+1==iDestCol) || (iSrcCol-1==iDestCol))
       {
         if((iSrcRow+1==iDestRow))
            return true;
       }
     }
     else
     {
      if((iSrcCol+1==iDestCol) || (iSrcCol-1==iDestCol))
       {
         if((iSrcRow-1==iDestRow))
            return true;
       }
     }
   }

   return false;
 }
};

class CKing:public CAPiece
{
 public:
     CKing(char color): CAPiece(color){}
     ~CKing() {}
 private:
     virtual char GetPiece()
     {
        return 'K';
     }

    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
    {
        int iRowDelta = iDestRow - iSrcRow;
		int iColDelta = iDestCol - iSrcCol;
		if (((iRowDelta >= -1) && (iRowDelta <= 1)) &&
			((iColDelta >= -1) && (iColDelta <= 1)))
		{
			return true;
		}
		return false;
    }

} ;

class CKnight : public CAPiece
{
public:
	CKnight(char color) : CAPiece(color) {}
	~CKnight() {}
private:
	virtual char GetPiece()
	{
      return 'N';
	}

    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
    {
        if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1))
        {
			if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2))
			{
				return true;
			}
		}
		if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2))
		{
			if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1))
			{
				return true;
			}
		}
		return false;
    }

};

class CBishop : public CAPiece
{
public:
	CBishop(char color) : CAPiece(color) {}
	~CBishop() {}
private:
	virtual char GetPiece()
	{
		return 'B';
	}
     bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
    {
     if((iDestRow-iSrcRow==iDestCol-iSrcCol) || (iDestRow-iSrcRow== iSrcCol - iDestCol))
     {
       int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
       int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			int iCheckRow;
			int iCheckCol;
			for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
				iCheckRow !=  iDestRow;
				iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
			{
				if (qpaaBoard[iCheckRow][iCheckCol] != 0)
                {
					return false;
				}
			}
			return true;

     }

     return false;
    }
};
class CRook : public CAPiece
{
  public:
      CRook(char color): CAPiece(color){}
      ~CRook(){}
  private:
      virtual char GetPiece()
      {
        return 'R';
      }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
    {
     if(iSrcRow==iDestRow)
     {
       int colOffSet=iDestCol-iSrcCol>0? 1 :-1;
       for(int k=colOffSet+iSrcCol;k!=iDestCol;k+=colOffSet)
        {
         if(qpaaBoard[iSrcRow][k]!=0)
              return false;
        }
        return true;
     }
     else if((iDestCol==iSrcCol))
     {
      int rowOffSet=iDestRow - iSrcRow>0 ?1 :-1 ;
      for(int k=rowOffSet+iSrcRow;k!=iDestRow;k+=rowOffSet)
      {
        if(qpaaBoard[k][iSrcCol]!=0)
            return false;
      }
      return true;
     }
     return false;
    }

};

class CQueen : public CAPiece
{
  public:
      CQueen(char color):CAPiece(color){}
      ~CQueen(){}
  private:
    virtual char GetPiece()
    {
      return 'Q';
    }

    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, CAPiece* qpaaBoard[8][8])
    {
     if(iSrcRow==iDestRow)
     {
       int colOffSet=iDestCol-iSrcCol>0? 1 :-1;
       for(int k=colOffSet+iSrcCol;k!=iDestCol;k+=colOffSet)
        {
         if(qpaaBoard[iSrcRow][k]!=0)
              return false;
        }
        return true;
     }
     else if((iDestCol==iSrcCol))
     {
      int rowOffSet=iDestRow - iSrcRow>0 ?1 :-1 ;
      for(int k=rowOffSet+iSrcRow;k!=iDestRow;k+=rowOffSet)
      {
        if(qpaaBoard[k][iSrcCol]!=0)
            return false;
      }
      return true;
     }

   else if((iDestRow-iSrcRow==iDestCol-iSrcCol) || (iDestRow-iSrcRow== iSrcCol - iDestCol))
     {
       int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
       int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
			int iCheckRow;
			int iCheckCol;
			for (iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
				iCheckRow !=  iDestRow;
				iCheckRow = iCheckRow + iRowOffset, iCheckCol = iCheckCol + iColOffset)
			{
				if (qpaaBoard[iCheckRow][iCheckCol] != 0)
                {
					return false;
				}
			}
			return true;
     }

     return false;
    }

};

class CBoard
{
public:
    CAPiece* mqpaaBoard[8][8];

	CBoard()
	{
		for (int iRow = 0; iRow < 8; ++iRow)
        {
			for (int iCol = 0; iCol < 8; ++iCol)
			{
				mqpaaBoard[iRow][iCol] = 0;
			}
		}
		// Allocate and place black pieces
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			mqpaaBoard[6][iCol] = new CPawn('B');
		}
		mqpaaBoard[7][0] = new CRook('B');
		mqpaaBoard[7][1] = new CKnight('B');
		mqpaaBoard[7][2] = new CBishop('B');
		mqpaaBoard[7][3] = new CKing('B');
		mqpaaBoard[7][4] = new CQueen('B');
		mqpaaBoard[7][5] = new CBishop('B');
		mqpaaBoard[7][6] = new CKnight('B');
		mqpaaBoard[7][7] = new CRook('B');
		// Allocate and place white pieces
		for (int iCol = 0; iCol < 8; ++iCol)
		{
			mqpaaBoard[1][iCol] = new CPawn('W');
		}
		mqpaaBoard[0][0] = new CRook('W');
		mqpaaBoard[0][1] = new CKnight('W');
		mqpaaBoard[0][2] = new CBishop('W');
		mqpaaBoard[0][3] = new CKing('W');
		mqpaaBoard[0][4] = new CQueen('W');
		mqpaaBoard[0][5] = new CBishop('W');
		mqpaaBoard[0][6] = new CKnight('W');
		mqpaaBoard[0][7] = new CRook('W');
	}
	~CBoard()
	{
		for (int iRow = 0; iRow < 8; ++iRow)
        {
			for (int iCol = 0; iCol < 8; ++iCol)
			{
				delete mqpaaBoard[iRow][iCol];
				//mqpaaBoard[iRow][iCol] = 0;
			}
		}
	}

	void Print()
	{
		const int kiSquareWidth = 4;
		const int kiSquareHeight = 3;
		for (int iRow = 0; iRow < 8*kiSquareHeight; ++iRow)
        {
			int iSquareRow = iRow/kiSquareHeight;
			// Print side border with numbering
			if (iRow % 3 == 1)
			{
				cout << '-' << (char)('1' + 7 - iSquareRow) << '-';
			}
			else
			{
				cout << "---";
			}
			// Print the chess board
			for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol)
			{
				int iSquareCol = iCol/kiSquareWidth;
				if (((iRow % 3) == 1) && ((iCol % 4) == 1 || (iCol % 4) == 2) && mqpaaBoard[7-iSquareRow][iSquareCol] != 0)
				{
					if ((iCol % 4) == 1)
					{
						cout << mqpaaBoard[7-iSquareRow][iSquareCol]->GetColor();
					}
					else
					{
						cout << mqpaaBoard[7-iSquareRow][iSquareCol]->GetPiece();
					}
				}
                 else
                {
					if ((iSquareRow + iSquareCol) % 2 == 1)
                    {
						cout << '*';
					}
					else
                    {
						cout << ' ';
					}
				}
			}
			cout << endl;
		}
		// Print the bottom border with numbers
		for (int iRow = 0; iRow < kiSquareHeight; ++iRow)
            {
			if (iRow % 3 == 1)
			{
				cout << "---";
				for (int iCol = 0; iCol < 8*kiSquareWidth; ++iCol)
				{
					int iSquareCol = iCol/kiSquareWidth;
					if ((iCol % 4) == 1)
					{
						cout << (iSquareCol + 1);
					}
					else
					{
						cout << '-';
					}
				}
				cout << endl;
			}
			else
			{
				for (int iCol = 1; iCol < 9*kiSquareWidth; ++iCol)
                {
					cout << '-';
				}
				cout << endl;
			}
		}
	}

	bool IsInCheck(char cColor)
	{
		// Find the king
		int iKingRow;
		int iKingCol;
		for (int iRow = 0; iRow < 8; ++iRow) {
			for (int iCol = 0; iCol < 8; ++iCol) {
				if (mqpaaBoard[iRow][iCol] != 0) {
					if (mqpaaBoard[iRow][iCol]->GetColor() == cColor) {
						if (mqpaaBoard[iRow][iCol]->GetPiece() == 'K') {
							iKingRow = iRow;
							iKingCol = iCol;
						}
					}
				}
			}
		}
		// Run through the opponent's pieces and see if any can take the king
		for (int iRow = 0; iRow < 8; ++iRow) {
			for (int iCol = 0; iCol < 8; ++iCol) {
				if (mqpaaBoard[iRow][iCol] != 0) {
					if (mqpaaBoard[iRow][iCol]->GetColor() != cColor) {
						if (mqpaaBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iKingRow, iKingCol, mqpaaBoard)) {
							return true;
						}
					}
				}
			}
		}

		return false;
	}

	bool canMove(char cColor) {
		// Run through all pieces
		for (int iRow = 0; iRow < 8; ++iRow) {
			for (int iCol = 0; iCol < 8; ++iCol) {
				if (mqpaaBoard[iRow][iCol] != 0) {
					// If it is a piece of the current player, see if it has a legal move
					if (mqpaaBoard[iRow][iCol]->GetColor() == cColor) {
						for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow) {
							for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol) {
								if (mqpaaBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, mqpaaBoard)) {
									// Make move and check whether king is in check
									CAPiece* qpTemp					= mqpaaBoard[iMoveRow][iMoveCol];
									mqpaaBoard[iMoveRow][iMoveCol]	= mqpaaBoard[iRow][iCol];
									mqpaaBoard[iRow][iCol]			= 0;
									bool bCanMove = !IsInCheck(cColor);
									// Undo the move
									mqpaaBoard[iRow][iCol]			= mqpaaBoard[iMoveRow][iMoveCol];
									mqpaaBoard[iMoveRow][iMoveCol]	= qpTemp;
									if (bCanMove) {
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
		return false;
	}

};


class CChess
{
  private :
      CBoard myChessBoard;
      char playerTurn;
  public:
    CChess()
        {
          playerTurn='W';
        }
    ~CChess() {}

    void start()
    {
       do
       {
        getNextMove(myChessBoard.mqpaaBoard);     // what is this mqpaa.board
        alternateTurn();
       }while(!isGameOver());
       myChessBoard.Print();
    }

    void  getNextMove(CAPiece* qpaaBoard[8][8])
    {
      bool validMove=false;
      do
      {
        myChessBoard.Print();

        // Getting the input and converting them into the coordinates
         cout<<playerTurn<<" 's move :";
         int startingMove;
         cin>>startingMove;
         int iStartRow= (startingMove/10) -1 ;
         int iStartCol= (startingMove%10) -1 ;

        cout<<"\n To :";
        int endingMove;
        cin>>endingMove;
        int iEndRow= (endingMove/10) -1 ;
        int iEndCol= (endingMove%10) -1 ;

       // check the indicies are in range and the source and the destination are not same
       if((iStartRow>=0 && iStartRow<=7)&& (iStartCol>=0 &&
           iStartCol <=7) && (iEndRow>=0 && iEndRow<=7)  &&
           (iEndCol>=0 && iEndCol<=7)
           )
       {

          CAPiece* qpCurrPiece = qpaaBoard[iStartRow][iStartCol];
				// to Check that the piece is the correct color
				if ((qpCurrPiece != 0) && (qpCurrPiece->GetColor() == playerTurn))
                {
					// Check that the destination is a valid destination
					if (qpCurrPiece->IsLegalMove(iStartRow, iStartCol, iEndRow, iEndCol, qpaaBoard))
					{
						// Make the move
						CAPiece* qpTemp					= qpaaBoard[iEndRow][iEndCol];
						qpaaBoard[iEndRow][iEndCol]		= qpaaBoard[iStartRow][iStartCol];
						qpaaBoard[iStartRow][iStartCol]	= 0;
						// Make sure that the current player is not in check
						if (!myChessBoard.IsInCheck(playerTurn))
						{
							delete qpTemp;
							validMove = true;
						}
                        else
                        { // Undo the last move
							qpaaBoard[iStartRow][iStartCol] = qpaaBoard[iEndRow][iEndCol];
							qpaaBoard[iEndRow][iEndCol]		= qpTemp;
						}
					}
				}
        }



        if(!validMove)
        {
          cout<<"\n Invalid Move! ";
        }

      }while(!validMove);

    }


    bool isGameOver()
    {
      bool currentPlayerCanMove=false;
      currentPlayerCanMove=myChessBoard.canMove(playerTurn);
      if(!currentPlayerCanMove)
      {
       if(myChessBoard.IsInCheck(playerTurn))
        {
         alternateTurn();
         cout<<"\n CheckMate , "<<playerTurn<< " Wins! \n";
        }
       else
        {
         cout<<"\n Stalemate";
        }
      }
     return !currentPlayerCanMove;
    }

    void alternateTurn()
    {
      playerTurn = (playerTurn=='W')? 'B': 'W';
    }

};

int main()
{
  CChess obj;
  obj.start();

  return 0;
}




