#include <iostream>
#include "../include/game_info.hpp"

void Game_Info::print_game_log(const std::vector<std::string>& game_log) {
  std::cout << "\nGame Log:\n";
  for (std::string move : game_log) {
    std::cout << move + "\n"; 
  }
  std::cout << "\n";
}

void Game_Info::print_help_menu() {
  std::cout << "\nChess board is a grid.\nColumns are lettered a-h, rows numbered 1-8\n";
  std::cout << "Enter a square containing a piece (ex. e2)\n";
  std::cout << "Enter a square you want to move the piece to (ex. e4; all chess rules apply)\n";
  std::cout << "Board will reprint after each move\n\n";
}

void Game_Info::print_initial_prompt(Game_Info::State game_state) {
  std::string input;
  std::cout << "\nShall we play a game?\n";
  std::cout << "y - yes, n - no, h - help\n";
  std::cin >> input;
  if (input == "n") game_state.game_end = true;
  if (input == "h") Game_Info::print_help_menu();
  std::cout << "\nGlobal Thermonuclear War might be thrilling, but chess seems a bit safer.\n";
}
