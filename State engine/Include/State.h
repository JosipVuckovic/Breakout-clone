#ifndef STATE_H
#define STATE_H

class State
{

public:
	// initstate 
	virtual void Init() = 0;

	// handle userinput in begining state
	virtual void HandleInput() = 0;
	// update state
	virtual void Update(const float& deltaTime) = 0;

	//draw current frame in state 
	virtual void Draw(const float& DeltaTime) = 0;

	//pause state
	virtual void Pause() {};
	//resume state 
	virtual void Resume() {};
};
#endif 
