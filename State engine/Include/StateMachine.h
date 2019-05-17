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

	void AddState(StateRef newState, bool isReplacing = true);
	void RemoveState();
	void ProcessStateChanges();
	StateRef& GetActiveState();

};

#endif 