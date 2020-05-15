#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "../include/game_info.hpp"
#include "../include/Board.hpp"
#include "../include/Piece.hpp"

// turn % 2 == 0 -> white
// turn % 2 == 1 -> black

bool is_on_board(int x, int y) { return ((x < 8 && x >= 0) && (y < 8 && y >= 0)) ? true : false; }

bool is_unoccupied(const std::array<std::array<std::string, 8>, 8>& board, int x, int y) {
  return board[x][y] == " " ? true : false;
}

std::vector<std::array<int, 2>> pawn_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  if (turn % 2 == 0) {
    if (x == 6) {
      if (is_unoccupied(board, x - 2, y) && is_unoccupied(board, x - 1, y)) {
        moves.push_back({ x - 2, y });
        moves.push_back({ x - 1, y });
      }
    } else {
      if (is_on_board(x - 1, y) && is_unoccupied(board, x - 1, y)) moves.push_back({ x - 1, y });
    }
  } else {
    if (x == 1) {
      if (is_unoccupied(board, x + 2, y) && is_unoccupied(board, x + 1, y)) {
        moves.push_back({ x + 2, y });
        moves.push_back({ x + 1, y });
      }
    } else {
      if (is_on_board(x + 1, y) && is_unoccupied(board, x + 1, y)) moves.push_back({ x + 1, y });
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> king_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  int count = 0; 
  int count1 = 0;
  int count2 = -1;

  for (int i = 0; i < 8; ++i) {
    switch (i % 3) {
      case 0: { 
        if (is_on_board(x - 1, y - 1 + count) && is_unoccupied(board, x - 1, y - 1 + count)) {
          moves.push_back({ x - 1, y - 1 + count });
        }
        ++count;
        break;
      }
      case 1: {
        if (is_on_board(x + 1, y - 1 + count1) && is_unoccupied(board, x + 1, y - 1 + count1)) {
          moves.push_back({ x + 1, y - 1 + count1 });
        }
        ++count1;
        break;
      }
      default: {
        if (is_on_board(x, y + count2) && is_unoccupied(board, x, y + count2)) {
          moves.push_back({ x, y + count2 });
        }
        count2 = 1;
        break;
      }
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> bishop_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;

  bool piece_disruption1 = false;
  bool piece_disruption2 = false;
  bool piece_disruption3 = false;
  bool piece_disruption4 = false;
  for (int i = 1; i < 8; ++i) {
    if (is_on_board(x + i, y + i) && !piece_disruption1) {
      if (!is_unoccupied(board, x + i, y + i)) piece_disruption1 = true;
      if (!piece_disruption1) moves.push_back({ x + i, y + i });
    }
    if (is_on_board(x - i, y - i)) {
      if (!is_unoccupied(board, x - i, y - i)) piece_disruption2 = true;
      if (!piece_disruption2) moves.push_back({ x - i, y - i });
    }
    if (is_on_board(x - i, y + i)) {
      if (!is_unoccupied(board, x - i, y + i)) piece_disruption3 = true;
      if (!piece_disruption3) moves.push_back({ x - i, y + i });
    }
    if (is_on_board(x + i, y - i)) {
      if (!is_unoccupied(board, x + i, y - i)) piece_disruption4 = true;
      if (!piece_disruption4) moves.push_back({ x + i, y - i });
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> rook_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;

  bool piece_disruption1 = false;
  bool piece_disruption2 = false;
  bool piece_disruption3 = false;
  bool piece_disruption4 = false;
  for (int i = 1; i < 8; ++i) {
    if (is_on_board(x + i, y) && !piece_disruption1) {
      if (!is_unoccupied(board, x + i, y)) piece_disruption1 = true;
      if (!piece_disruption1) moves.push_back({ x + i, y });
    }
    if (is_on_board(x - i, y)) {
      if (!is_unoccupied(board, x - i, y)) piece_disruption2 = true;
      if (!piece_disruption2) moves.push_back({ x - i, y });
    }
    if (is_on_board(x, y + i)) {
      if (!is_unoccupied(board, x, y + i)) piece_disruption3 = true;
      if (!piece_disruption3) moves.push_back({ x, y + i });
    }
    if (is_on_board(x, y - i)) {
      if (!is_unoccupied(board, x, y - i)) piece_disruption4 = true;
      if (!piece_disruption4) moves.push_back({ x, y - i });
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> queen_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;

  bool piece_disruption1 = false;
  bool piece_disruption2 = false;
  bool piece_disruption3 = false;
  bool piece_disruption4 = false;
  bool piece_disruption5 = false;
  bool piece_disruption6 = false;
  bool piece_disruption7 = false;
  bool piece_disruption8 = false;

  for (int i = 1; i < 8; ++i) {
    if (is_on_board(x + i, y) && !piece_disruption1) {
      if (!is_unoccupied(board, x + i, y)) piece_disruption1 = true;
      if (!piece_disruption1) moves.push_back({ x + i, y });
    }
    if (is_on_board(x - i, y)) {
      if (!is_unoccupied(board, x - i, y)) piece_disruption2 = true;
      if (!piece_disruption2) moves.push_back({ x - i, y });
    }
    if (is_on_board(x, y + i)) {
      if (!is_unoccupied(board, x, y + i)) piece_disruption3 = true;
      if (!piece_disruption3) moves.push_back({ x, y + i });
    }
    if (is_on_board(x, y - i)) {
      if (!is_unoccupied(board, x, y - i)) piece_disruption4 = true;
      if (!piece_disruption4) moves.push_back({ x, y - i });
    }
  }

  for (int i = 1; i < 8; ++i) {
    if (is_on_board(x + i, y + i) && !piece_disruption1) {
      if (!is_unoccupied(board, x + i, y + i)) piece_disruption5 = true;
      if (!piece_disruption5) moves.push_back({ x + i, y + i });
    }
    if (is_on_board(x - i, y - i)) {
      if (!is_unoccupied(board, x - i, y - i)) piece_disruption6 = true;
      if (!piece_disruption6) moves.push_back({ x - i, y - i });
    }
    if (is_on_board(x - i, y + i)) {
      if (!is_unoccupied(board, x - i, y + i)) piece_disruption7 = true;
      if (!piece_disruption7) moves.push_back({ x - i, y + i });
    }
    if (is_on_board(x + i, y - i)) {
      if (!is_unoccupied(board, x + i, y - i)) piece_disruption8 = true;
      if (!piece_disruption8) moves.push_back({ x + i, y - i });
    }
  }
  return moves;
}

bool validate_knight_move(int xFrom, int yFrom, int xTo, int yTo) {
  if (is_on_board(xTo, yTo)) {
    if ((xFrom - 1 == xTo && yFrom - 2 == yTo) || 
        (xFrom - 2 == xTo && yFrom - 1 == yTo) ||
        (xFrom - 1 == xTo && yFrom + 2 == yTo) ||
        (xFrom - 2 == xTo && yFrom + 1 == yTo) ||
        (xFrom + 1 == xTo && yFrom - 2 == yTo) ||
        (xFrom + 2 == xTo && yFrom - 1 == yTo) ||
        (xFrom + 1 == xTo && yFrom + 2 == yTo) ||
        (xFrom + 2 == xTo && yFrom + 1 == yTo)) {
          return true;
    }
    return false;
  }
  return false;
}

std::vector<std::array<int, 2>> knight_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;

  if (is_on_board(x - 1, y - 2) && is_unoccupied(board, x - 1, y - 2)) moves.push_back({ x - 1, y - 2 });
  if (is_on_board(x - 2, y - 1) && is_unoccupied(board, x - 2, y - 1)) moves.push_back({ x - 2, y - 1 });
  if (is_on_board(x - 1, y + 2) && is_unoccupied(board, x - 1, y + 2)) moves.push_back({ x - 1, y + 2 });
  if (is_on_board(x - 2, y + 1) && is_unoccupied(board, x - 2, y + 1)) moves.push_back({ x - 2, y + 1 });
  if (is_on_board(x + 1, y - 2) && is_unoccupied(board, x + 1, y - 2)) moves.push_back({ x + 1, y - 2 });
  if (is_on_board(x + 2, y - 1) && is_unoccupied(board, x + 2, y - 1)) moves.push_back({ x + 2, y - 1 });
  if (is_on_board(x + 1, y + 2) && is_unoccupied(board, x + 1, y + 2)) moves.push_back({ x + 1, y + 2 });
  if (is_on_board(x + 2, y + 1) && is_unoccupied(board, x + 2, y + 1)) moves.push_back({ x + 2, y + 1 });

  return moves;
}

std::vector<std::string> is_valid_move(Board& board, int turn, int xFrom, int yFrom, int xTo, int yTo) 
{
  std::vector<std::string> validated_move;
  if (!is_on_board(xTo, yTo)) { return validated_move; }

  std::map<Board::Position, Piece*>::iterator it_from;
  std::vector<std::array<int, 2>> possible_moves;

  if (turn % 2 == 0) {
    std::map<Board::Position, Piece*>::iterator it_to_white;
    // check if white piece on destination
    it_to_white = board.white_pieces.find(Board::Position(xTo, yTo));
    if (it_to_white != board.white_pieces.end()) { return validated_move; }

    std::map<Board::Position, Piece*>::iterator it_to_black;
    it_to_black = board.black_pieces.find(Board::Position(xTo, yTo));
    it_from = board.white_pieces.find(Board::Position(xFrom, yFrom));

    if (it_from != board.white_pieces.end()) {
      std::string piece_type = it_from -> second -> get_board_char();

      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else if (piece_type == "B") {
        possible_moves = bishop_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else if (piece_type == "R") {
        possible_moves = rook_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else if (piece_type == "Q") {
        possible_moves = queen_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else {
        if (validate_knight_move(it_from -> first.x, it_from -> first.y, xTo, yTo)) {
          validated_move.push_back(piece_type);
          if (it_to_black != board.black_pieces.end()) {
            validated_move.push_back(it_to_black -> second -> get_board_char());
            // piece has been captured, safely destroy pointer
            delete it_to_black -> second; 
            board.black_pieces.erase(it_to_black);
          }
          return validated_move;
        }
      }
    } else {
      return validated_move;
    }
  } else {
    std::map<Board::Position, Piece*>::iterator it_to_black;
    // check if black piece on destination
    it_to_black = board.black_pieces.find(Board::Position(xTo, yTo));
    if (it_to_black != board.black_pieces.end()) { return validated_move; }

    // check if white piece on destination - capture
    std::map<Board::Position, Piece*>::iterator it_to_white;
    it_to_white = board.white_pieces.find(Board::Position(xTo, yTo));
    it_from = board.black_pieces.find(Board::Position(xFrom, yFrom));

    if (it_from != board.black_pieces.end()) {
      std::string piece_type = it_from -> second -> get_board_char();
      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        }
      } else if (piece_type == "B") {
        possible_moves = bishop_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else if (piece_type == "R") {
        possible_moves = rook_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else if (piece_type == "Q") {
        possible_moves = queen_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        board.print_possible_moves(possible_moves);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            validated_move.push_back(piece_type);
            return validated_move;
          }
        } 
      } else {
        if (validate_knight_move(it_from -> first.x, it_from -> first.y, xTo, yTo)) {
          validated_move.push_back(piece_type);
          if (it_to_white != board.white_pieces.end()) {
            validated_move.push_back(it_to_black -> second -> get_board_char());
            // piece has been captured, safely destroy pointer
            delete it_to_black -> second; 
            board.white_pieces.erase(it_to_white);
          }
          return validated_move;
        }
        // board.print_possible_moves(possible_moves);
        // for (std::array<int, 2>& move : possible_moves) {
        //   if (move[0] == xTo && move[1] == yTo) {
        //     return piece_type;
        //   }
        // } 
      }
    } else {
      return validated_move;
    }
  }
  return validated_move;
}

bool move_piece(Board& board, Game_Info::State& game_state) 
{
  std::map<std::string, std::string> current_move;
  while (current_move.empty()) {
    current_move = Game_Info::print_move_prompt(game_state);
    if (game_state.game_end == true) return false;
  }

  char letterTo, letterFrom;
  int numberTo, numberFrom;
  for (int i = 0; i < current_move["spaceFrom"].length(); ++i) {
    if (i == 0) {
      letterFrom = current_move["spaceFrom"][i];
      letterTo = current_move["spaceTo"][i];
    } else {
      numberFrom = current_move["spaceFrom"][i] - '0';
      numberTo = current_move["spaceTo"][i] - '0';
    }
  }
  int xTo, yTo;
  int xFrom, yFrom;

  xTo = std::abs(numberTo - 8);
  yTo = int(letterTo) - '0' - 49;
  xFrom = std::abs(numberFrom - 8);
  yFrom = int(letterFrom) - '0' - 49;

  std::vector<std::string> moved_piece = is_valid_move(board, game_state.turn, xFrom, yFrom, xTo, yTo);

  if (!moved_piece.empty()) {
    std::map<Board::Position, Piece*>::iterator it;
    if (game_state.turn % 2 == 0) {
      /* updating pointer map flow */
      // 1. find pointer to piece being moved
      it = board.white_pieces.find(Board::Position(xFrom, yFrom));
      // 2. assign piece pointer to new position
      board.white_pieces[Board::Position(xTo, yTo)] = it -> second;
      // 4. Erase map entry of old position
      board.white_pieces.erase(Board::Position(xFrom, yFrom));

      board.board[xTo][yTo] = "\x1b[1;97m" + moved_piece[0];
    } else {
      /* updating pointer map flow */
      // 1. find pointer to piece being moved
      it = board.black_pieces.find(Board::Position(xFrom, yFrom));
      // 2. assign piece pointer to new position
      board.black_pieces[Board::Position(xTo, yTo)] = it -> second;
      // 4. Erase map entry of old position
      board.black_pieces.erase(Board::Position(xFrom, yFrom));
      board.board[xTo][yTo] = "\x1b[1;30m" + moved_piece[0];
    }
    board.board[xFrom][yFrom] = " ";

    std::string capture_string;
    moved_piece.size() == 2 ? capture_string = " -- " + moved_piece[1] + " captured." : "";
    std::string move_str = current_move["color"] + ": " + moved_piece[0] + " from " + letterFrom + std::to_string(numberFrom) + " to " + letterTo + std::to_string(numberTo) + (capture_string == "" ? "" : capture_string);
    std::cout << move_str + "\n";
    ++game_state.turn;
    game_state.log.push_back(move_str);
  } else {
    std::cout << "\nInvalid Move\n";
  }
  // else capture()
  return true;
}

int main() 
{
  Game_Info::State game_state = { false, 0 };
  Game_Info::print_initial_prompt(game_state);
  Board board;
  board.init();

  while (game_state.game_end == false) {
    board.draw_board();
    move_piece(board, game_state);
  }
  return 0;
}