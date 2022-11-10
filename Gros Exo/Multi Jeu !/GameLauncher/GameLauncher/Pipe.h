#pragma once
#include "IDrawable.h"

#define PIPE "***"
class Pipe:public IDrawable
{
private:
	int gapPosition = 0;
	int position = 0;
	bool canDraw = false;
public :
	Pipe() = default;
	~Pipe()override = default;

public:
	void SetGapPosition(const int _gap);
	void SetPosition(const int _gap);
	void SetCanDraw(const bool _status);
	int GapPosition()const;
	int Position()const;
	bool CanDraw()const;
public:
	virtual void Draw()override;
		virtual void Erase()override ;
		virtual void Update()override ;

};

