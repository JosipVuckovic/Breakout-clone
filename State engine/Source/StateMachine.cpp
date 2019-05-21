#include "..\\State engine\Include\StateMachine.h"
StateMachine::StateMachine(): isAdding(true), isRemoving(false), isReplacing(true)
{
}


StateMachine::~StateMachine()
{
}


void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	isAdding = true;
	this->isReplacing = isReplacing;
	this->newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
	if (isRemoving && !states.empty()) //if removing is true and state aren't empty
		//pop
	{
		states.pop();
		if(!states.empty())
		{
			//resume previous state
			states.top()->Resume();
		}
		//reset flag
		isRemoving = false; 
	}//or add state?
	if (isAdding) 
	{
		if(!states.empty())
		{
			if(isReplacing)
			{
				states.pop();
			}
			else
			{
				states.top()->Pause();
			}
		}
		states.push(std::move(newState));
		states.top()->Init();
		isAdding = false;
	}
}
StateRef& StateMachine::GetActiveState()
{
	return states.top();
}
