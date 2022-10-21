#pragma once
#include "Object.h"
#include <vector>
class MenuItem;
class Menu: public Object
{

protected:
	std::string title = "";
	Menu* oldMenu = nullptr;
	bool isOpen = false;
	std::vector<MenuItem*> items = std::vector< MenuItem*>();
public:
	Menu() = default;
	Menu(const std::string& _title, std::initializer_list< MenuItem*> _item);
	Menu(const Menu& _copy);
	~Menu()override;

public:
	virtual void Open();
	void Close();
	virtual void Update();
	void OpenOlMenu();
	void DisplayItem();
	std::vector<MenuItem*> Item()const;
	void Choose(const int _index);
	Menu* OldMenu() const;
	void SetOldMenu(Menu* _old);
	bool Equals(const Menu* _other);

};

