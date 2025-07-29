# Chess Game in C++

A complete object-oriented chess game implementation written in C++ that allows two players to play chess in a console interface.

## 🎯 Project Overview

This project demonstrates a fully functional chess game built from scratch using C++ with object-oriented programming principles. The game includes all standard chess pieces, movement validation, check/checkmate detection, and a text-based user interface.

## ✨ Key Features

### Core Chess Mechanics
- **Complete piece implementation**: All 6 chess pieces (Pawn, Rook, Knight, Bishop, Queen, King)
- **Movement validation**: Each piece follows its specific movement rules
- **Capture mechanics**: Proper handling of piece captures
- **Turn-based gameplay**: Alternating turns between White and Black players

### Advanced Game Logic
- **Check detection**: Automatically detects when a king is in check
- **Checkmate detection**: Identifies when a player has no legal moves and is in check
- **Stalemate detection**: Recognizes when a player has no legal moves but is not in check
- **Legal move validation**: Prevents moves that would put your own king in check
- **Path obstruction**: Ensures pieces cannot jump over other pieces (except knights)

### User Interface
- **Visual board representation**: ASCII art chess board with clear piece identification
- **Coordinate system**: Uses standard chess notation (11-88 format)
- **Move input system**: Intuitive "from" and "to" coordinate input
- **Real-time board updates**: Board refreshes after each valid move
- **Error handling**: Clear feedback for invalid moves

## 🏗️ Technical Architecture

### Object-Oriented Design
The project follows solid OOP principles with a well-structured class hierarchy:

```
CAPiece (Abstract Base Class)
├── CPawn
├── CRook
├── CKnight
├── CBishop
├── CQueen
└── CKing
```

### Key Classes

#### `CAPiece` (Abstract Base Class)
- Defines common piece behavior
- Pure virtual functions for piece-specific logic
- Color management and basic move validation

#### Individual Piece Classes
- **`CPawn`**: Implements forward movement, diagonal capture, and piece-specific rules
- **`CRook`**: Horizontal and vertical movement with path checking
- **`CKnight`**: L-shaped movement pattern
- **`CBishop`**: Diagonal movement with obstruction detection
- **`CQueen`**: Combines rook and bishop movement patterns
- **`CKing`**: One-square movement in any direction

#### `CBoard`
- Manages the 8x8 game board
- Handles piece placement and initialization
- Provides board visualization
- Implements game state checking (check, checkmate, stalemate)

#### `CChess`
- Main game controller
- Manages game flow and turn alternation
- Handles user input and move processing
- Coordinates between board and piece classes

## 🎮 How to Play

1. **Compile the game**:
   ```bash
   g++ -o chess "Chess game.cpp"
   ```

2. **Run the game**:
   ```bash
   ./chess
   ```

3. **Make moves**:
   - Enter coordinates in format: `xy` where x is row (1-8) and y is column (1-8)
   - Example: `24` means row 2, column 4
   - First enter the source position, then the destination

4. **Game symbols**:
   - `W` = White pieces, `B` = Black pieces
   - `P` = Pawn, `R` = Rook, `N` = Knight, `B` = Bishop, `Q` = Queen, `K` = King

## 🔧 Technical Highlights

### Memory Management
- Proper dynamic memory allocation for pieces
- Clean destructor implementation to prevent memory leaks
- Safe pointer handling throughout the codebase

### Algorithm Implementation
- **Path validation algorithms**: For sliding pieces (rook, bishop, queen)
- **Check detection algorithm**: Efficiently scans for threats to the king
- **Move simulation**: Temporarily makes moves to validate they don't result in check

### Error Handling
- Comprehensive input validation
- Boundary checking for board coordinates
- Invalid move detection and user feedback

## 🚀 Advanced Features

### Game State Management
- **Move validation pipeline**: Multi-layer validation ensuring legal moves
- **Game termination detection**: Automatic detection of game-ending conditions
- **State preservation**: Ability to undo moves during validation

### Performance Optimizations
- Efficient board representation using 2D pointer array
- Minimal object creation during gameplay
- Optimized check detection algorithms

## 🎓 Learning Outcomes

This project demonstrates proficiency in:

- **Object-Oriented Programming**: Inheritance, polymorphism, encapsulation
- **C++ Advanced Features**: Virtual functions, pointers, dynamic memory allocation
- **Algorithm Design**: Game logic implementation, pathfinding
- **Software Architecture**: Clean code organization and modular design
- **Problem Solving**: Complex game rule implementation
- **User Interface Design**: Console-based interactive applications

## 🛠️ Potential Enhancements

Future improvements could include:
- En passant capture for pawns
- Castling implementation
- Pawn promotion
- Move history and notation
- AI opponent
- Graphical user interface
- Network multiplayer support
- Save/load game functionality

## 📋 Requirements

- C++ compiler (g++, clang++, or MSVC)
- Standard C++ library
- Console/terminal environment

## 🎯 Code Quality Features

- **Clean Architecture**: Well-separated concerns with clear class responsibilities
- **Maintainable Code**: Consistent naming conventions and code structure
- **Extensible Design**: Easy to add new features or modify existing ones
- **Robust Error Handling**: Comprehensive validation and error messages

---

This chess game implementation showcases a deep understanding of both chess rules and C++ programming concepts, demonstrating the ability to translate complex real-world logic into clean, functional code.
