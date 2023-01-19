#include "TextureManager.h"
#include "../../Environement/Environement.h"

void Core::Manager::TextureManger::Init()
{
	std::vector<std::string> _files = Environement::GetAllFilesWithExtension(Environement::AssetPath.c_str(), ".png");
	for (std::string _path : _files)
	{
		sf::Texture* _texture = new sf::Texture();
		if (!_texture->loadFromFile(_path))
		{
			LOG_ERROR(std::format("[TextureManager] => error n load {} font !", _path));
			delete _texture;
			continue;
		}
		std::string _fileName = _path.substr(_path.find_last_of('/') + 1);
		_fileName = _fileName.substr(0, _fileName.find_first_of('.'));
		items.insert(std::pair(_fileName, _texture));
	}
}
