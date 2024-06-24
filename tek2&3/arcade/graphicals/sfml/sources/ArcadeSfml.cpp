/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeSfml
*/

#include "RawTextureSfml.hpp"
#include <X11/Xlib.h>
#undef None

ArcadeSfml::ArcadeSfml()
{
    XInitThreads();
    _pixelsPerCell = 0;
    _isTextInputOn = false;
    _isClosing = false;
    _textInput = "";
}

ArcadeSfml::~ArcadeSfml()
{
    _win.close();
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void)
{
    return (std::make_unique<ArcadeSfml>());
}

void ArcadeSfml::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    _pixelsPerCell = pixelsPerCell;
}

std::uint32_t ArcadeSfml::getPixelsPerCell(void)
{
    return (_pixelsPerCell);
}

std::unique_ptr<IDisplayModule::RawTexture> ArcadeSfml::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height)
{
    UNUSED(width);
    UNUSED(height);
    return (std::make_unique<RawTextureSfml>(pngFilename, character, characterColor, backgroundColor, _pixelsPerCell));
}

void ArcadeSfml::openWindow(IDisplayModule::Vector2u windowSize)
{
    _win.create(sf::VideoMode(windowSize.x, windowSize.y), "Arcade");
    sf::View view(sf::Vector2f(windowSize.x / 2, windowSize.y/ 2), sf::Vector2f(windowSize.x, windowSize.y));
    _win.setView(view);
    return;
}

bool ArcadeSfml::isButtonPressed(IDisplayModule::Button button)
{
    std::map<sf::Keyboard::Key, bool>::iterator it = _keyPressedMap.find(keyToSfmlKey.at(button));

    if (it != _keyPressedMap.end()) {
        if (it->second == true) {
            it->second = false;
            return (true);
        }
    }
    return (false);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeSfml::getMouseButtonReleaseEvent()
{
    MouseButtonReleaseEvent event;

    event.type = MouseButtonReleaseEvent::Type::None;
    event.cellPosition = (IDisplayModule::Vector2u){0, 0};

    for (size_t i = 0; i < _evtQueue.size(); i++) {
        if (_evtQueue[i].mouseButton.button != sf::Mouse::Right && _evtQueue[i].mouseButton.button != sf::Mouse::Left)
            continue;
        event.type = _evtQueue[i].mouseButton.button == sf::Mouse::Right ? MouseButtonReleaseEvent::Type::Right : MouseButtonReleaseEvent::Type::Left;
        event.cellPosition.x = _evtQueue[i].mouseButton.x / _pixelsPerCell;
        event.cellPosition.y = _evtQueue[i].mouseButton.y / _pixelsPerCell;
    }
    return (event);
}

void ArcadeSfml::startTextInput()
{
    _isTextInputOn = true;
    return;
}

std::string ArcadeSfml::getTextInput()
{
    return (_textInput);
}

void ArcadeSfml::endTextInput()
{
    _isTextInputOn = false;
    _textInput = "";
    return;
}

void ArcadeSfml::clearScreen(IDisplayModule::Color color)
{
    _win.clear(colorToSfmlColor.at(color));
    return;
}

void ArcadeSfml::renderSprite(IDisplayModule::Sprite sprite)
{
    RawTextureSfml *rawTexture = dynamic_cast<RawTextureSfml *>(sprite.texture);
    const sf::Texture &texture = rawTexture->getTexture();
    sf::Sprite sfmlSprite(texture);
    sfmlSprite.setPosition(sf::Vector2f((float)sprite.rawPixelPosition.x, (float)sprite.rawPixelPosition.y));
    _win.draw(sfmlSprite);
    return;
}

void ArcadeSfml::display()
{
    _win.display();
    return;
}

bool ArcadeSfml::isClosing()
{
    return (_isClosing);
}

void ArcadeSfml::update(void)
{
    sf::Event event;
    _keyPressedMap.clear();
    _evtQueue.clear();
    _textInput = "";
    while (_win.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (_isTextInputOn && ((event.key.code >= 0 && event.key.code <= 35) || event.key.code == sf::Keyboard::Backspace || event.key.code == sf::Keyboard::Enter)) {
                if (event.key.code > 25 && event.key.code <= 35)
                    _textInput.push_back((char) event.key.code + 22);
                else if (event.key.code <= 25)
                    _textInput.push_back((char) event.key.code + 97);
                else if (event.key.code == sf::Keyboard::Backspace)
                    _textInput.push_back('\b');
                else
                    _textInput.push_back('\n');
            }
            else if (!_isTextInputOn)
                _keyPressedMap.insert(std::make_pair(event.key.code, true));
        }else if (event.type == sf::Event::Closed)
            _isClosing = true;
        else if (event.type == sf::Event::MouseButtonReleased)
            _evtQueue.push_back(event);
    }
    return;
}