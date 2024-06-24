/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MainMenu
*/

#include "MainMenu.hpp"
#include "Arcade.hpp"

MainMenu::MainMenu()
{
    _font = "assets/emulogic.ttf";
    _width = 1280;
    _height = 320;
    _pixelPerCells = 16;
    _framerate = 30;
    _cursor = 0;
    _textInput = false;
    _textInputStr = "";
}

MainMenu::~MainMenu()
{
}

std::vector<ICore::Texture *> MainMenu::createMajAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 65; i < 91; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createMinAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 97; i < 123; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createNumbers(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 48; i < 58; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualMajAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 65; i < 91; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualMinAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 97; i < 123; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualNumbers(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 48; i < 58; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createCursorMajAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 65; i < 91; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createCursorMinAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 97; i < 123; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createCursorNumbers(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 48; i < 58; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualCursorMajAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 65; i < 91; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualCursorMinAlphabet(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 97; i < 123; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

std::vector<ICore::Texture *> MainMenu::createActualCursorNumbers(void)
{
    std::vector<ICore::Texture *> ret;

    for (int i = 48; i < 58; i++)
        ret.push_back(_core->loadTexture(_font, (char)i, ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells));
    return (ret);
}

void MainMenu::init(Arcade *coreHandle)
{
    _core = coreHandle;
    _core->setPixelsPerCell(_pixelPerCells);
    _core->setFramerate(_framerate);
    _core->openWindow((IDisplayModule::Vector2u){_width, _height});
    _wall = _core->loadTexture(_font, '#', ICore::Color::cyan, ICore::Color::blue, _pixelPerCells, _pixelPerCells);
    _space = _core->loadTexture(_font, ' ', ICore::Color::black, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _doublePoint = _core->loadTexture(_font, ':', ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _point = _core->loadTexture(_font, '.', ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _slash = _core->loadTexture(_font, '/', ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _exclamation = _core->loadTexture(_font, '!', ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _underscore = _core->loadTexture(_font, '_', ICore::Color::blue, ICore::Color::black, _pixelPerCells, _pixelPerCells);

    _doublePointActual = _core->loadTexture(_font, ':', ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _pointActual = _core->loadTexture(_font, '.', ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _slashActual = _core->loadTexture(_font, '/', ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _exclamationActual = _core->loadTexture(_font, '!', ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells);
    _underscoreActual = _core->loadTexture(_font, '_', ICore::Color::green, ICore::Color::black, _pixelPerCells, _pixelPerCells);

    _doublePointCursor = _core->loadTexture(_font, ':', ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _pointCursor = _core->loadTexture(_font, '.', ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _slashCursor = _core->loadTexture(_font, '/', ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _exclamationCursor = _core->loadTexture(_font, '!', ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _underscoreCursor = _core->loadTexture(_font, '_', ICore::Color::blue, ICore::Color::white, _pixelPerCells, _pixelPerCells);

    _doublePointActualCursor = _core->loadTexture(_font, ':', ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _pointActualCursor = _core->loadTexture(_font, '.', ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _slashActualCursor = _core->loadTexture(_font, '/', ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _exclamationActualCursor = _core->loadTexture(_font, '!', ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells);
    _underscoreActualCursor = _core->loadTexture(_font, '_', ICore::Color::green, ICore::Color::white, _pixelPerCells, _pixelPerCells);

    _blueMajAlphabet = createMajAlphabet();
    _blueMinAlphabet = createMinAlphabet();
    _blueNumbers = createNumbers();

    _actualMajAlphabet = createActualMajAlphabet();
    _actualMinAlphabet = createActualMinAlphabet();
    _actualNumbers = createActualNumbers();

    _cursorMajAlphabet = createCursorMajAlphabet();
    _cursorMinAlphabet = createCursorMinAlphabet();
    _cursorNumbers = createCursorNumbers();

    _cursorActualMajAlphabet = createActualCursorMajAlphabet();
    _cursorActualMinAlphabet = createActualCursorMinAlphabet();
    _cursorActualNumbers = createActualCursorNumbers();
}

void MainMenu::activateCursor(void)
{
    if (_cursor < 10) {
        if (!(_cursor == _core->getActualGraphPath())) {
            _core->destroyRawTexture();
            _core->changeLibraryByPath(_core->getGraphPathDeque()[_cursor], true);
            _core->setActualGraphPath((long)_cursor);
            _core->setPixelsPerCell(_pixelPerCells);
            _core->openWindow({_width, _height});
            _core->reloadAllTexture();
        }
        return;
    }
    if (_cursor < 20) {
        if (!(_cursor == _core->getActualGamePath() - 10)) {
            _core->setActualGamePath((long)_cursor - 10);
        }
        return;
    }
    if (_core->getGamePathDeque().size() > 0) {
        _core->changeLibraryByPath(_core->getGamePathDeque()[_core->getActualGamePath()], false);
        _core->clearTextureDeque();
        _core->invertInBool();
        if (_textInputStr.find_first_not_of(' ') != std::string::npos)
            _core->setPlayerName(_textInputStr);
        _core->initGame();
        _core->gameLoop();
        throw ArcadeError("start!", "good luck!");
    }
}

void MainMenu::moveLeft(void)
{
    if (_cursor < 10) {
        if (_core->getGamePathDeque().size() > 0) {
            _cursor = 10;
        }
        return;
    }
    if (_cursor < 20)
        _cursor = 0;
    return;
}

void MainMenu::moveDown(void)
{
    if (_cursor < 10) {
        if (_cursor == 7 || (size_t)_cursor == _core->getGraphPathDeque().size() - 1) {
            _cursor = 20;
            return;
        }
        _cursor += 1;
        return;
    }
    if (_cursor < 20) {
        if (_cursor == 17 || (size_t)(_cursor - 10) == _core->getGamePathDeque().size() - 1) {
            _cursor = 20;
            return;
        }
        _cursor += 1;
        return;
    }
    _cursor = 0;
}

void MainMenu::moveUp(void)
{
    if (_cursor < 10) {
        if (_cursor == 0) {
            _cursor = 20;
            return;
        }
        _cursor -= 1;
        return;
    }
    if (_cursor < 20) {
        if (_cursor == 10) {
            _cursor = 20;
            return;
        }
        _cursor -= 1;
        return;
    }
    _cursor = _core->getGraphPathDeque().size() - 1;
}

void MainMenu::checkPressedButton(void)
{
    if (_textInput) {
        std::string input = _core->getTextInput();
        for (int i = 0; input[i]; i++) {
            if (input[i] == '\b') {
                if (_textInputStr.size() != 0)
                    _textInputStr.resize(_textInputStr.size() - 1);
                continue;
            }
            if (input[i] == '\n') {
                _core->endTextInput();
                _textInput = false;
                break;
            }
            _textInputStr.push_back(input[i]);
        }
    }
    else {
        if (_core->isButtonPressed(ICore::Button::A) ||
            _core->isButtonPressed(ICore::Button::Start) ||
            _core->isButtonPressed(ICore::Button::Select))
            activateCursor();
        if (_core->isButtonPressed(ICore::Button::Left) || _core->isButtonPressed(ICore::Button::Right))
            moveLeft();
        if (_core->isButtonPressed(ICore::Button::Up))
            moveUp();
        if (_core->isButtonPressed(ICore::Button::Down))
            moveDown();
        ICore::MouseButtonReleaseEvent event = _core->getMouseButtonReleaseEvent();
        if (event.type != ICore::MouseButtonReleaseEvent::Type::None) {
            if (event.type == ICore::MouseButtonReleaseEvent::Type::Left) {
                if (event.cellPosition.x >= 1 && event.cellPosition.x <= 78 &&
                    event.cellPosition.y >= 1 && event.cellPosition.y <= 3) {
                    _textInput = true;
                    _core->startTextInput();
                }
            }
        }
    }
}

void MainMenu::update(void)
{
    checkPressedButton();
    return;
}

void MainMenu::drawSquare(void)
{
    ICore::Sprite spriteWall;

    spriteWall.pixelPosition = {0, 0};
    spriteWall.texture = _wall;
    for (; spriteWall.pixelPosition.x != _width; spriteWall.pixelPosition.x += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition.x = 0; spriteWall.pixelPosition.y != _height; spriteWall.pixelPosition.y += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition = {_width - _pixelPerCells, 0}; spriteWall.pixelPosition.y != _height; spriteWall.pixelPosition.y += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition = {0, _height - _pixelPerCells}; spriteWall.pixelPosition.x != _width; spriteWall.pixelPosition.x += _pixelPerCells)
        _core->renderSprite(spriteWall);
}

void MainMenu::drawSeparators(void)
{
    ICore::Sprite spriteWall;

    spriteWall.pixelPosition = {0, 0};
    spriteWall.texture = _wall;
    for (spriteWall.pixelPosition = {416 , 64}; spriteWall.pixelPosition.y != 240; spriteWall.pixelPosition.y += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition = {848, 64}; spriteWall.pixelPosition.y != 240; spriteWall.pixelPosition.y += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition = {0, 64}; spriteWall.pixelPosition.x != _width; spriteWall.pixelPosition.x += _pixelPerCells)
        _core->renderSprite(spriteWall);
    for (spriteWall.pixelPosition = {0, 240}; spriteWall.pixelPosition.x != _width; spriteWall.pixelPosition.x += _pixelPerCells)
        _core->renderSprite(spriteWall);
}

void MainMenu::drawBox(void)
{
    drawSquare();
    drawSeparators();
}

void MainMenu::writeText(std::string text, ICore::Vector2u startingPos)
{
    ICore::Sprite spriteChar;

    spriteChar.pixelPosition = startingPos;
    for (size_t i = 0; text[i]; i++) {
        if (i > 24)
            break;
        if (isdigit(text[i]) != 0)
            spriteChar.texture = _blueNumbers[text[i] - 48];
        else if (isupper(text[i]) != 0)
            spriteChar.texture = _blueMajAlphabet[text[i] - 65];
        else if (isalpha(text[i]) != 0)
            spriteChar.texture = _blueMinAlphabet[text[i] - 97];
        else if (text[i] == '/')
            spriteChar.texture = _slash;
        else if (text[i] == ':')
            spriteChar.texture = _doublePoint;
        else if (text[i] == '.')
            spriteChar.texture = _point;
        else if (text[i] == '!')
            spriteChar.texture = _exclamation;
        else if (text[i] == '_')
            spriteChar.texture = _underscore;
        else
            spriteChar.texture = _space;
        _core->renderSprite(spriteChar);
        spriteChar.pixelPosition.x += _pixelPerCells;
    }
}

void MainMenu::writeActualText(std::string text, ICore::Vector2u startingPos)
{
    ICore::Sprite spriteChar;

    spriteChar.pixelPosition = startingPos;
    for (size_t i = 0; text[i]; i++) {
        if (i > 24)
            break;
        if (isdigit(text[i]) != 0)
            spriteChar.texture = _actualNumbers[text[i] - 48];
        else if (isupper(text[i]) != 0)
            spriteChar.texture = _actualMajAlphabet[text[i] - 65];
        else if (isalpha(text[i]) != 0)
            spriteChar.texture = _actualMinAlphabet[text[i] - 97];
        else if (text[i] == '/')
            spriteChar.texture = _slashActual;
        else if (text[i] == ':')
            spriteChar.texture = _doublePointActual;
        else if (text[i] == '.')
            spriteChar.texture = _pointActual;
        else if (text[i] == '!')
            spriteChar.texture = _exclamationActual;
        else if (text[i] == '_')
            spriteChar.texture = _underscoreActual;
        else
            spriteChar.texture = _space;
        _core->renderSprite(spriteChar);
        spriteChar.pixelPosition.x += _pixelPerCells;
    }
}

void MainMenu::writeCursorText(std::string text, ICore::Vector2u startingPos)
{
    ICore::Sprite spriteChar;

    spriteChar.pixelPosition = startingPos;
    for (size_t i = 0; text[i]; i++) {
        if (i > 24)
            break;
        if (isdigit(text[i]) != 0)
            spriteChar.texture = _cursorNumbers[text[i] - 48];
        else if (isupper(text[i]) != 0)
            spriteChar.texture = _cursorMajAlphabet[text[i] - 65];
        else if (isalpha(text[i]) != 0)
            spriteChar.texture = _cursorMinAlphabet[text[i] - 97];
        else if (text[i] == '/')
            spriteChar.texture = _slashCursor;
        else if (text[i] == ':')
            spriteChar.texture = _doublePointCursor;
        else if (text[i] == '.')
            spriteChar.texture = _pointCursor;
        else if (text[i] == '!')
            spriteChar.texture = _exclamationCursor;
        else if (text[i] == '_')
            spriteChar.texture = _underscoreCursor;
        else
            spriteChar.texture = _space;
        _core->renderSprite(spriteChar);
        spriteChar.pixelPosition.x += _pixelPerCells;
    }
}

void MainMenu::writeActualCursorText(std::string text, ICore::Vector2u startingPos)
{
    ICore::Sprite spriteChar;

    spriteChar.pixelPosition = startingPos;
    for (size_t i = 0; text[i]; i++) {
        if (i > 24)
            break;
        if (isdigit(text[i]) != 0)
            spriteChar.texture = _cursorActualNumbers[text[i] - 48];
        else if (isupper(text[i]) != 0)
            spriteChar.texture = _cursorActualMajAlphabet[text[i] - 65];
        else if (isalpha(text[i]) != 0)
            spriteChar.texture = _cursorActualMinAlphabet[text[i] - 97];
        else if (text[i] == '/')
            spriteChar.texture = _slashActualCursor;
        else if (text[i] == ':')
            spriteChar.texture = _doublePointActualCursor;
        else if (text[i] == '.')
            spriteChar.texture = _pointActualCursor;
        else if (text[i] == '!')
            spriteChar.texture = _exclamationActualCursor;
        else if (text[i] == '_')
            spriteChar.texture = _underscoreActualCursor;
        else
            spriteChar.texture = _space;
        _core->renderSprite(spriteChar);
        spriteChar.pixelPosition.x += _pixelPerCells;
    }
}

void MainMenu::graphicalList(void)
{
    const std::deque<std::string> &copy(_core->getGraphPathDeque());
    const long &actual = _core->getActualGraphPath();
    ICore::Vector2u pos = {16, 112};

    for (size_t i = 0; i < copy.size() && i < 8; i++) {
        if ((long)i == actual && _cursor == (int)(i))
            writeActualCursorText(copy[i], pos);
        else if ((long)i == actual)
            writeActualText(copy[i], pos);
        else if ((int)i == _cursor)
            writeCursorText(copy[i], pos);
        else
            writeText(copy[i], pos);
        pos.y += 16;
    }
}

void MainMenu::gameList(void)
{
    const std::deque<std::string> &copy(_core->getGamePathDeque());
    const long &actual = _core->getActualGamePath();
    ICore::Vector2u pos = {864, 112};

    for (size_t i = 0; i < copy.size() && i < 8; i++) {
        if ((long)i == actual && _cursor == (int)(i + 10))
            writeActualCursorText(copy[i], pos);
        else if ((long)i == actual)
            writeActualText(copy[i], pos);
        else if ((int)(i + 10) == _cursor)
            writeCursorText(copy[i], pos);
        else
            writeText(copy[i], pos);
        pos.y += 16;
    }
}

void MainMenu::scoreList(void)
{
    std::string filename = "./score";
    filename.append(_core->getNameOfGame());
    std::ifstream file;
    std::string line;
    ICore::Vector2u pos = {432, 112};
    int i = 0;

    file.open(filename, std::fstream::in);
    if (!file) {
        writeText("No ./score exists for", {464, 112});
        writeText("this game", {576, 128});
        return;
    }
    while (std::getline(file, line) && i++ < 7) {
        if (line.length() >= 24)
            writeText(line, pos);
        else
            writeText(line, {640 - ((uint32_t) line.length() * 16 / 2), pos.y});
        pos.y += 16;
    }

}

void MainMenu::draw(void)
{
    _core->clearScreen(ICore::Color::black);
    drawBox();
    if (_textInput)
        writeActualText("Player Name:", {544, 16});
    else
        writeText("Player Name:", {544, 16});
    writeActualText(_textInputStr, {640 - ((uint32_t) _textInputStr.length() * 16 / 2), 32});
    writeText("Graphical", {144, 80});
    graphicalList();
    writeText("Score:", {592, 80});
    scoreList();
    writeText("Games", {1024, 80});
    gameList();
    if (_cursor == 20)
        writeActualCursorText("START!", {592, 272});
    else
        writeText("START!", {592, 272});
    return;
}