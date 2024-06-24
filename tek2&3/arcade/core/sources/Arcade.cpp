/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#include "Arcade.hpp"
#include "Texture.hpp"

Arcade::Arcade()
{
    _graphical = nullptr;
    _game = nullptr;
    _menu = std::make_unique<MainMenu>();
    _dlGame = NULL;
    _dlGraphical = NULL;
    _graphPathDeque = initGraphPathDeque();
    _gamePathDeque = initGamePathDeque();
    _actualGraphPath = 0;
    _actualGamePath = 0;
    _inGame = false;
    _inMenu = true;
    _framerate = 60;
    _playerName = "Player1";
}

Arcade::~Arcade()
{
}

void Arcade::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    _pixelsPerCell = pixelsPerCell;
    _graphical->setPixelsPerCell(pixelsPerCell);
}

void Arcade::setFramerate(unsigned framerate)
{
    _framerate = framerate;
}

ICore::Texture *Arcade::loadTexture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height)
{
    ICore::Texture texture(pngFilename, character, characterColor, backgroundColor, width, height, std::move(_graphical->loadTexture(pngFilename, character, characterColor, backgroundColor, width, height)));

    _textureDeque.push_back(std::move(texture));
    return (&_textureDeque.back());
}

void Arcade::openWindow(IDisplayModule::Vector2u pixelsWantedWindowSize)
{
    _windowSize = pixelsWantedWindowSize;
    _graphical->openWindow(pixelsWantedWindowSize);
}

bool Arcade::isButtonPressed(ICore::Button button)
{
    if (_graphical->isButtonPressed(button))
        return (true);
    return (false);
}

ICore::MouseButtonReleaseEvent Arcade::getMouseButtonReleaseEvent()
{
    return (_graphical->getMouseButtonReleaseEvent());
}

void Arcade::startTextInput()
{
    return (_graphical->startTextInput());
}

std::string Arcade::getTextInput()
{
    return (_graphical->getTextInput());
}

void Arcade::endTextInput()
{
    return (_graphical->endTextInput());
}

void Arcade::clearScreen(ICore::Color color)
{
    return (_graphical->clearScreen(color));
}

void Arcade::renderSprite(ICore::Sprite sprite)
{
    IDisplayModule::Sprite displaySprite;

    displaySprite.rawPixelPosition = sprite.pixelPosition;
    displaySprite.texture = sprite.texture->getTexture();
    _graphical->renderSprite(displaySprite);
    return;
}

void Arcade::addNewScore(std::uint32_t score)
{
    std::string filename("./score");
    std::string gameName(getNameOfGame());
    std::string elementToWrite(_playerName);
    std::fstream file;

    if (gameName == "")
        return;
    filename.append(gameName);
    elementToWrite.append(": ");
    elementToWrite.append(std::to_string(score));
    file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!file)
        std::cerr << "Sorry! Score isn't recordable. Check permission on your ./score[GAME] file!" << std::endl;
    else {
        file << elementToWrite << std::endl;
        file.close();
    }
    return;
}

std::string Arcade::getNameOfGame(void)
{
    if (_gamePathDeque.size() == 0)
        return ("");
    std::string ret(_gamePathDeque[_actualGamePath]);

    ret.resize(ret.size() - 3);
    if (ret.find_last_of('/') != std::string::npos)
        ret.erase(0, ret.find_last_of('/') + 1);
    return (ret);
}

const std::string &Arcade::getPlayerName(void)
{
    return (_playerName);
}

void Arcade::setPlayerName(std::string name)
{
    _playerName = name;
}

void Arcade::changeLibraryByPath(std::string path, bool graphical)
{
    void *dl;

    if (!(dl = dlopen(path.c_str(), RTLD_LAZY))) {
        std::cerr << "dlopen error: " << dlerror() << std::endl;
        return;
    }
    if (graphical) {
        if (!dlsym(dl, "gEpitechArcadeGetDisplayModuleHandle")) {
            dlclose(dl);
            std::cerr << "wrong library type: the library provided as argument is not an appropriate graphical library" << std::endl;
            return;
        }
        closeDl(true);
        _dlGraphical = dl;
        initClassFromDl(true);
        return;
    }
    if (!dlsym(dl, "gEpitechArcadeGetGameModuleHandle")) {
        dlclose(dl);
        std::cerr << "wrong library type: the library provided as argument is not an appropriate game library" << std::endl;
        return;
    }
    closeDl(false);
    _dlGame = dl;
    initClassFromDl(false);
}

void Arcade::setDlGraphical(void *dlGraphical)
{
    _dlGraphical = dlGraphical;
}

void Arcade::initClassFromDl(bool graphical)
{
    std::unique_ptr<IDisplayModule> (*displayHandle)(void);
    std::unique_ptr<IGameModule> (*gameHandle)(void);

    if (graphical) {
        *(void **) &displayHandle = dlsym(_dlGraphical, "gEpitechArcadeGetDisplayModuleHandle");
        _graphical = (*displayHandle)();
        return;
    }
    *(void **) &gameHandle = dlsym(_dlGame, "gEpitechArcadeGetGameModuleHandle");
    _game = (*gameHandle)();
}

void Arcade::closeDl(bool graphical)
{
    if (graphical) {
        _graphical = nullptr;
        dlclose(_dlGraphical);
        return;
    }
    _game = nullptr;
    if (_dlGame != NULL)
        dlclose(_dlGame);
}

void Arcade::exitArcade()
{
    destroyRawTexture();
    closeDl(true);
    closeDl(false);
    throw ArcadeError("exit arcade", "exit arcade");
}

void Arcade::gameRestart(void)
{
    std::unique_ptr<IGameModule> (*gameHandle)(void);

    _game = nullptr;
    *(void **) &gameHandle = dlsym(_dlGame, "gEpitechArcadeGetGameModuleHandle");
    _game = (*gameHandle)();
    _textureDeque.clear();
    _game->init(this);
    gameLoop();
    throw ArcadeError("game restart", "game restart");
}

void Arcade::goBackToMenu(void)
{
    _game = nullptr;
    invertInBool();
    _textureDeque.clear();
    _menu = std::make_unique<MainMenu>();
    _menu->init(this);
    gameLoop();
    throw ArcadeError("go back to menu", "go back to menu");
}

void Arcade::checkFunctionButton(void)
{
    if (isButtonPressed(IDisplayModule::Button::F1)) {
        destroyRawTexture();
        changeLibraryByPath(getPrevLibrary(true), true);
        setPixelsPerCell(_pixelsPerCell);
        openWindow(_windowSize);
        reloadAllTexture();
    }
    if (isButtonPressed(IDisplayModule::Button::F2)) {
        destroyRawTexture();
        changeLibraryByPath(getNextLibrary(true), true);
        setPixelsPerCell(_pixelsPerCell);
        openWindow(_windowSize);
        reloadAllTexture();
    }
    if (isButtonPressed(IDisplayModule::Button::F7) || _graphical->isClosing() == true)
        exitArcade();
    if (_inMenu == true)
        return;
    if (isButtonPressed(IDisplayModule::Button::F3)) {
        if (_gamePathDeque.size() == 1)
            return;
        changeLibraryByPath(getPrevLibrary(false), false);
        _textureDeque.clear();
        _game->init(this);
        gameLoop();
        throw ArcadeError("change game library", "previous");
    }
    if (isButtonPressed(IDisplayModule::Button::F4)) {
        if (_gamePathDeque.size() == 1)
            return;
        changeLibraryByPath(getNextLibrary(false), false);
        _textureDeque.clear();
        _game->init(this);
        gameLoop();
        throw ArcadeError("change game library", "next");
    }
    if (isButtonPressed(IDisplayModule::Button::F5))
        gameRestart();
    if (isButtonPressed(IDisplayModule::Button::F6))
        goBackToMenu();
}

void Arcade::gameLoop(void)
{
    struct timespec tend;

    while (1) {
        clock_gettime(CLOCK_MONOTONIC, &tend);
        long oneFrameTime = (long long)((1.f/(float)_framerate) * (1000000000.f));
        if (tend.tv_nsec + oneFrameTime <= 999999999)
            tend.tv_nsec += oneFrameTime;
        else {
            tend.tv_sec += 1;
            tend.tv_nsec = oneFrameTime - (999999999 - tend.tv_nsec);
        }_graphical->update();
        try {
            checkFunctionButton();
        }catch (ArcadeError const &error) {
            break;
        }
        if (_inMenu) {
            try {
                _menu->update();
            }
            catch (ArcadeError const &error) {
                break;
            }
            _menu->draw();
        }
        else {
            _game->update();
            _game->draw();
        }_graphical->display();
        clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &tend, NULL);
    }
}

void Arcade::launchGame(void)
{
    if (_inMenu)
        _menu->init(this);
    else
        _game->init(this);
    gameLoop();
}

void Arcade::destroyRawTexture(void)
{
    for (size_t i = 0; i < _textureDeque.size(); i++)
        _textureDeque[i].destroyRawTexture();
}

void Arcade::reloadAllTexture(void)
{
    for (size_t i = 0; i < _textureDeque.size(); i++) {
        _textureDeque[i].setTexture(
            std::move(_graphical->loadTexture(
            _textureDeque[i].getPngFilename(),
            _textureDeque[i].getCharacter(),
            _textureDeque[i].getCharacterColor(),
            _textureDeque[i].getBackgroundColor(),
            _textureDeque[i].getWidth(),
            _textureDeque[i].getHeight())));
    }
}

void Arcade::invertInBool(void)
{
    _inGame = (_inGame ? false : true);
    _inMenu = (_inMenu ? false : true);
}

std::deque<std::string> Arcade::initGraphPathDeque(void)
{
    std::string path = "./lib";
    std::deque<std::string> ret;
    void *lib = NULL;

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (!(lib = dlopen(entry.path().u8string().c_str(), RTLD_NOW)))
            continue;
        if (!dlsym(lib, "gEpitechArcadeGetDisplayModuleHandle")) {
            dlclose(lib);
            continue;
        }
        ret.push_back(entry.path().u8string().c_str());
    }
    return (ret);
}

std::deque<std::string> Arcade::initGamePathDeque(void)
{
    std::string path = "./lib";
    std::deque<std::string> ret;
    void *lib = NULL;

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (!(lib = dlopen(entry.path().u8string().c_str(), RTLD_NOW)))
            continue;
        if (!dlsym(lib, "gEpitechArcadeGetGameModuleHandle")) {
            dlclose(lib);
            continue;
        }
        ret.push_back(entry.path().u8string().c_str());
    }
    return (ret);
}

void Arcade::initActualGraphGraphical(std::string lib)
{
    std::filesystem::path libPath(lib);

    for (size_t i = 0; _graphPathDeque.size(); i++)
        if (libPath.filename() == std::filesystem::path(_graphPathDeque[i]).filename()) {
            _actualGraphPath = i;
            return;
        }
    _actualGraphPath = -1;
}

void Arcade::initActualGameGraphical(std::string lib)
{
    std::filesystem::path libPath(lib);

    for (size_t i = 0; _gamePathDeque.size(); i++)
        if (libPath.filename() == std::filesystem::path(_gamePathDeque[i]).filename()) {
            _actualGamePath = i;
            return;
        }
    _actualGamePath = -1;
}

std::string Arcade::getPrevLibrary(bool graphical)
{
    if (graphical) {
        if (_actualGraphPath == -1 || _graphPathDeque.size() <= 1)
            return ("");
        if (_actualGraphPath == 0) {
            _actualGraphPath = _graphPathDeque.size() - 1;
            return (_graphPathDeque.back());
        }
        return (_graphPathDeque[--_actualGraphPath]);
    }
    if (_actualGamePath == -1 || _gamePathDeque.size() <= 1)
        return ("");
    if (_actualGamePath == 0) {
        _actualGamePath = _gamePathDeque.size() - 1;
        return (_gamePathDeque.back());
    }
    return (_gamePathDeque[--_actualGamePath]);
}

std::string Arcade::getNextLibrary(bool graphical)
{
    if (graphical) {
        if (_actualGraphPath == -1 || _graphPathDeque.size() <= 1)
            return ("");
        if ((size_t)_actualGraphPath == _graphPathDeque.size() - 1) {
            _actualGraphPath = 0;
            return (_graphPathDeque[0]);
        }
        return (_graphPathDeque[++_actualGraphPath]);
    }
    if (_actualGamePath == -1 || _gamePathDeque.size() <= 1)
        return ("");
    if ((size_t)_actualGamePath == _gamePathDeque.size() - 1) {
        _actualGamePath = 0;
        return (_gamePathDeque[0]);
    }
    return (_gamePathDeque[++_actualGamePath]);
}

const std::deque<std::string> &Arcade::getGraphPathDeque(void)
{
    return (_graphPathDeque);
}

const std::deque<std::string> &Arcade::getGamePathDeque(void)
{
    return (_gamePathDeque);
}

const long &Arcade::getActualGraphPath(void)
{
    return (_actualGraphPath);
}

const long &Arcade::getActualGamePath(void)
{
    return (_actualGamePath);
}

void Arcade::setActualGraphPath(long path)
{
    _actualGraphPath = path;
}

void Arcade::setActualGamePath(long path)
{
    _actualGamePath = path;
}

void Arcade::clearTextureDeque(void)
{
    _textureDeque.clear();
}

void Arcade::initGame(void)
{
    _game->init(this);
}