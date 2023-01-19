#include "BaseMenu.h"
#include "../../UI/Image/Image.h"
#include "../../UI/Button/Button.h"
#include "../../UI/Label/Label.h"

#include "../../Event/Delegate/Delegate.h"
#include "../../Utils/Debug/Debug.h"
#include  <format>

Core::BaseMenu::BaseMenu(Window* _owner)
{
	owner = _owner;
}

Core::BaseMenu::BaseMenu(const BaseMenu& _copy)
{
	elements=_copy.elements;
	owner = _copy.owner;
	isOpen = _copy.isOpen;
}

Core::BaseMenu::~BaseMenu()
{
	for (UI::UIElement*& element : elements) // ça permet que si quelqu'un l'utilise elements alors qu'on le suprime ça le met a null
	{
		delete element;
		element = nullptr;
	}
	elements.clear();
}

void Core::BaseMenu::SetActive(bool _status)
{
	for (UI::UIElement* element : elements)
		element->SetActive(_status);
}

void Core::BaseMenu::Open()
{
	isOpen = true;
	SetActive(true);
}

void Core::BaseMenu::Close()
{
	isOpen = false;
	SetActive(false);
}

void Core::BaseMenu::Draw()
{
	if (!isOpen)return;
	for (UI::UIElement* _element : elements)
		_element->Draw();
}

void Core::BaseMenu::OnUpdate()
{
	if (!isOpen)return;
	for (UI::UIElement* _element : elements)
		_element->OnUpdate();
}

bool Core::BaseMenu::IsOpen() const
{
	return isOpen;
}

void Core::BaseMenu::OnResize(const sf::Vector2f& _size)
{

}

Core::UI::Image* Core::BaseMenu::CreateImage(const sf::Vector2f& _position, const char* _texture)
{
	Core::UI::Image* _image = new Core::UI::Image(owner, _texture);
	Check((_image != nullptr && _image->IsValid()), std::format("[BaseMenu] => failure to create the image width {} texture", _texture),nullptr)
	_image->SetPosition(_position);
	elements.push_back(_image);

	return _image;
}

Core::UI::Button* Core::BaseMenu::CreateButton(const sf::Vector2f& _position, const char* _texture, const Event::Delegate<void>& _onClick)
{
	UI::Button* _button = new UI::Button(owner, _texture);
	Check((_button != nullptr && _button->IsValid()), std::format("[BaseMenu] => failure to create the image width {} texture", _texture), nullptr)
		_button->OnClick = _onClick;
	_button->SetPosition(_position);
	elements.push_back(_button);

	return _button;
}

Core::UI::Label* Core::BaseMenu::CreateLabel(const sf::Vector2f& _position, const char* _text)
{
	UI::Label* _label = new UI::Label(owner, _text);
	Check((_label != nullptr && _label->IsValid()), std::format("[BaseMenu] => failure to create the image width {} texture", _text), nullptr)
	_label->SetPosition(_position);
	elements.push_back(_label);

	return _label;
}
