/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeSdl2
*/

#include "RawTextureSdl2.hpp"

ArcadeSdl2::ArcadeSdl2()
{
    _pixelsPerCell = 0;
    _isTextInputOn = false;
    _isClosing = false;
    _textInput = "";
    _win = NULL;
}

ArcadeSdl2::~ArcadeSdl2()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_win);
    SDL_Quit();
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void)
{
    return (std::make_unique<ArcadeSdl2>());
}

void ArcadeSdl2::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    _pixelsPerCell = pixelsPerCell;
}

std::uint32_t ArcadeSdl2::getPixelsPerCell(void)
{
    return (_pixelsPerCell);
}


std::unique_ptr<IDisplayModule::RawTexture> ArcadeSdl2::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height)
{
    UNUSED(width);
    UNUSED(height);
    return (std::make_unique<RawTextureSdl2>(pngFilename, character, characterColor, backgroundColor, _pixelsPerCell, _renderer));
}

void ArcadeSdl2::openWindow(IDisplayModule::Vector2u windowSize)
{
    if (_win != NULL) {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_win);
        SDL_Quit();
    }
    SDL_Init(SDL_INIT_VIDEO);
    _win = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowSize.x, windowSize.y, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    _renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    return;
}

bool ArcadeSdl2::isButtonPressed(IDisplayModule::Button button)
{
    std::map<SDL_Scancode, bool>::iterator it = _keyPressedMap.find(keystoSdl2keys.at(button));

    if (it != _keyPressedMap.end()) {
        if (it->second == true) {
            it->second = false;
            return (true);
        }
    }
    return (false);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeSdl2::getMouseButtonReleaseEvent()
{
    return (_mouseEvent);
}

void ArcadeSdl2::startTextInput()
{
    _isTextInputOn = true;
    return;
}

std::string ArcadeSdl2::getTextInput()
{
    return (_textInput);
}

void ArcadeSdl2::endTextInput()
{
    _isTextInputOn = false;
    _textInput = "";
    return;
}

void ArcadeSdl2::clearScreen(IDisplayModule::Color color)
{
    SDL_SetRenderDrawColor(_renderer,
    std::get<0>(colorToSdl2Color[(int)color]),
    std::get<1>(colorToSdl2Color[(int)color]),
    std::get<2>(colorToSdl2Color[(int)color]), 255);
    SDL_RenderClear(_renderer);
    return;
}

void ArcadeSdl2::renderSprite(IDisplayModule::Sprite sprite)
{
    RawTextureSdl2 *rawTexture = dynamic_cast<RawTextureSdl2 *>(sprite.texture);
    SDL_Texture *texture = rawTexture->getTexture();
    SDL_Rect position;
    position.x = sprite.rawPixelPosition.x;
    position.y = sprite.rawPixelPosition.y;
    SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(_renderer, texture, NULL, &position);
    return;
}

void ArcadeSdl2::display()
{
    SDL_RenderPresent(_renderer);
    return;
}

bool ArcadeSdl2::isClosing()
{
    return (_isClosing);
}

void ArcadeSdl2::update(void)
{
    SDL_Event event;
    _keyPressedMap.clear();
    _mouseEvent.type = MouseButtonReleaseEvent::Type::None;
    _mouseEvent.cellPosition = (IDisplayModule::Vector2u){0, 0};
    _textInput = "";
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            if (_isTextInputOn && ((event.key.keysym.scancode >= 4 && event.key.keysym.scancode <= 39) || event.key.keysym.scancode ==  SDL_SCANCODE_BACKSPACE || event.key.keysym.scancode == SDL_SCANCODE_RETURN)) {
                if (event.key.keysym.scancode > 29 && event.key.keysym.scancode <= 39)
                    _textInput.push_back((char) event.key.keysym.scancode + 18);
                else if (event.key.keysym.scancode <= 29)
                    _textInput.push_back((char) event.key.keysym.scancode + 93);
                else if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
                    _textInput.push_back('\b');
                else
                    _textInput.push_back('\n');
            }
            else if (!_isTextInputOn)
                _keyPressedMap.insert(std::make_pair(event.key.keysym.scancode, true));
        }else if (event.type == SDL_QUIT)
            _isClosing = true;
        else if (event.type == SDL_MOUSEBUTTONUP) {
            _mouseEvent.type = MouseButtonReleaseEvent::Type::Left;
            int x = 0;
            int y = 0;
            SDL_GetMouseState(&x, &y);
            _mouseEvent.cellPosition = (IDisplayModule::Vector2u){(u_int32_t) x / _pixelsPerCell,(u_int32_t) y / _pixelsPerCell};
        }
    }
    return;
}
