//#include "Launcher.h"
//#include "Menu.h"
//#include "Items.h"
//#include "Utils.h"
//#include <iostream>
//
//Launcher::Launcher(const std::initializer_list<Items*> _items)
//{
//	for (Items* _item : _items)
//		items.push_back(_item);
//}
//
//Launcher::~Launcher()
//{
//	items.clear();
//	delete currentGame;
//}
//#pragma endregion constructor/destructor
//
//#pragma region methods
//void Launcher::Update()
//{
//	while (isOpen)
//	{
//		try
//		{
//			system("cls");
//			Display();
//			currentGameIndex = Utils::UserChoice<int>("Choose: ") - 1;
//			if (currentGameIndex == items.size())
//			{
//				isOpen = false;
//				continue;
//			}
//			StartGame();
//
//		}
//		catch (const std::exception& _e)
//		{
//			std::exception("out of range ");
//		}
//	}
//	system("cls");
//
//}
//
//void Launcher::StartGame()
//{
//	if (currentGameIndex < 0 || currentGameIndex > items.size())
//		throw std::exception("[Launcher] => game index out of range !");
//	Items* _item = items[currentGameIndex];
//	currentGame = _item->Menu();
//	_item->OnClick();
//}
//
//void Launcher::Display()
//{
//	const size_t _size = items.size();
//	for (size_t i = 0; i < _size; i++)
//	{
//		std::cout << std::to_string(i + 1) + ": ";
//		items[i]->DisplayItem();
//	}
//	Utils::Print(std::to_string(_size + 1) + ": quit");
//}
//
//void Launcher::Open()
//{
//	Update();
//}
//#pragma endregion