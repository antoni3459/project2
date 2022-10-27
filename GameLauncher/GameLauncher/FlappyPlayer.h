#pragma once
#include "IDrawable.h"
#include "Pipe.h"
#include "Pipe.h"
class Pipe;

class FlappyPlayer:public IDrawable
{
private :
	char bird[2][6] = { {'/','-','-','o','\\',' '},{
				'|','_','_','_',' ','>'} };
	int position = 6;
	bool isDead = false;

public:
	FlappyPlayer() = default;
	~FlappyPlayer() override = default;

public:
	int Position() const;
	bool IsDead() const;
	void SetPosition(const int _position);
	void SetDead(const bool _status);
	void Jump();
	bool IsCollide(const Pipe* _pipe);
public:

	virtual void Draw() override;
		virtual void Erase() override;
		virtual void Update() override;

};

