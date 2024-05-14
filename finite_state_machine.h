#pragma once
#include <vector>
#include <functional>
#include <set>
#include <map>

template<typename TypeOfState, typename TypeOfSymbol>
class FiniteStateMachine
{
private:

    TypeOfState start_state;
    TypeOfState current_state;
    std::set<TypeOfState> final_state;
	std::set<TypeOfState> states;
	std::set<TypeOfSymbol> alphabet;
    std::map<std::pair<TypeOfState, TypeOfSymbol>, TypeOfState> transitions;
    
public:

	FiniteStateMachine(	TypeOfState _start_state,
                        std::set<TypeOfState> _final_state,
                        std::set<TypeOfState> _states,
		                std::set<TypeOfSymbol> _alphabet,
                        std::map<std::pair<TypeOfState, TypeOfSymbol>, TypeOfState> _transitions) :

                        start_state(_start_state), current_state(_start_state), final_state(_final_state), 
                        states(_states), alphabet(_alphabet), transitions(_transitions) {}

    bool check(std::vector<TypeOfSymbol> str)
    {
        for(auto Symbol : str)
        {
            if (alphabet.find(Symbol) == alphabet.end()) return false;
            
            std::pair<TypeOfState, TypeOfSymbol> Transition = make_pair(current_state, Symbol);
            
            auto NewState = transitions.find(Transition);

            if (NewState!= transitions.end())
               current_state = NewState->second;
            else return false;
        }

        if (final_state.count(current_state)==0) return false;

        return true;
    }
};
