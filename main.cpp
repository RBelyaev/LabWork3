#include <string>
#include "finite_state_machine.h"


int main()
{

    int start_state = 1;
    std::set<int> final_state = {2, 3};
	std::set<int> states = {1, 2, 3};
	std::set<std::string> alphabet = {"hockey", "bas", "foot"};

    std::map<std::pair<int, std::string>, int> transitionTable1 = {
        {std::pair<int, std::string>(1, "hockey"), 2}, {std::pair<int, std::string>(1, "bas"), 2}, {std::pair<int, std::string>(1, "foot"), 3},
        {std::pair<int, std::string>(2, "hockey"), 1}, {std::pair<int, std::string>(2, "bas"), 3}, {std::pair<int, std::string>(2, "foot"), 1},
        {std::pair<int, std::string>(3, "hockey"), 2}, {std::pair<int, std::string>(3, "bas"), 1}, {std::pair<int, std::string>(3, "foot"), 1}
    };

    FiniteStateMachine FSM(start_state, final_state, states, alphabet, transitionTable1);
    std::vector<std::string> str = {"hockey", "bas"};
    if(FSM.check(str))
        return 0;
    return 1;

}
