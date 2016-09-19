#pragma once
class BaseApp
{
public:
	virtual int Start() = 0;
	virtual bool Update() = 0;
	virtual void Draw() = 0;
	virtual void Stop() = 0;
	void Run();
	void CreateWindow()
};