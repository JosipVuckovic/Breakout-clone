#ifndef STATEMACHINE_H
#define STATEMACHINE_H
#include "State.h"

#include <memory>
#include <stack>

typedef std::unique_ptr<State> StateRef; 
class StateMachine
{
	bool isRemoving, isAdding, isReplacing;

	std::stack<StateRef> states;
	StateRef newState;
public:
	StateMachine();
	~StateMachine();
	

	// add state
	void AddState(StateRef newState, bool isReplacing = true);

	// if you exit state, EG. from menu to game state then remove it
	void RemoveState();

	void ProcessStateChanges();
	
	StateRef& GetActiveState();

};

#endif 