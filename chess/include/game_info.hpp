#include <vector>

namespace Game_Info {
  struct State {
    bool game_end;
    int turn;
    std::vector<std::string> log;
  };

  void print_game_log(const std::vector<std::string>& game_log);
  void print_help_menu();
  void print_initial_prompt(State game_state);
};
