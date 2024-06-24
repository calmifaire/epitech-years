/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** ArcadeNcurses
*/

#include "RawTextureNcurses.hpp"

ArcadeNcurses::ArcadeNcurses()
{
    _pixelsPerCell = 0;
    _win = NULL;
    _input = -1;
    _isTextInputOn = false;
    _textInput = "";
}

ArcadeNcurses::~ArcadeNcurses()
{
    endwin();
}

std::unique_ptr<IDisplayModule> gEpitechArcadeGetDisplayModuleHandle(void)
{
    return (std::make_unique<ArcadeNcurses>());
}

void ArcadeNcurses::setPixelsPerCell(std::uint32_t pixelsPerCell)
{
    _pixelsPerCell = pixelsPerCell;
}

std::uint32_t ArcadeNcurses::getPixelsPerCell(void)
{
    return (_pixelsPerCell);
}

std::unique_ptr<IDisplayModule::RawTexture> ArcadeNcurses::loadTexture(const std::string &pngFilename, char character, IDisplayModule::Color characterColor, IDisplayModule::Color backgroundColor, std::size_t width, std::size_t height)
{
    UNUSED(pngFilename);
    return (std::make_unique<RawTextureNcurses>(character, characterColor, backgroundColor, width, height));
}

void ArcadeNcurses::openWindow(IDisplayModule::Vector2u windowSize)
{
    UNUSED(windowSize);
    initscr();
    nodelay(stdscr, TRUE);
    WINDOW *win = newwin(LINES, COLS, 0, 0);
    nodelay(win, TRUE);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start_color();
    initAllColorPair();
    mousemask(BUTTON1_RELEASED | BUTTON2_RELEASED, NULL);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    setWindow(win);
    return;
}

bool ArcadeNcurses::isButtonPressed(IDisplayModule::Button button)
{
    if (_input == keyToCursesKey.at(button))
        return (true);
    return (false);
}

IDisplayModule::MouseButtonReleaseEvent ArcadeNcurses::getMouseButtonReleaseEvent()
{
    MouseButtonReleaseEvent event;
    MEVENT eventNcurses;

    event.type = MouseButtonReleaseEvent::Type::None;
    event.cellPosition = (IDisplayModule::Vector2u){0, 0};
    if (_input == KEY_MOUSE)
        if (!getmouse(&eventNcurses)) {
            if (eventNcurses.bstate & BUTTON1_RELEASED)
                event.type = MouseButtonReleaseEvent::Type::Left;
            if (eventNcurses.bstate & BUTTON2_RELEASED)
                event.type = MouseButtonReleaseEvent::Type::Right;
            event.cellPosition = (IDisplayModule::Vector2u){(uint32_t)eventNcurses.x - 1, (uint32_t)eventNcurses.y - 1};
        }
    return (event);
}

void ArcadeNcurses::startTextInput()
{
    _isTextInputOn = true;
    return;
}

std::string ArcadeNcurses::getTextInput()
{
    return (_textInput);
}

void ArcadeNcurses::endTextInput()
{
    _isTextInputOn = false;
    _textInput = "";
    return;
}

void ArcadeNcurses::clearScreen(IDisplayModule::Color color)
{
    werase(_win);
    wbkgd(_win, COLOR_PAIR(findPair(color, color)));
    return;
}

void ArcadeNcurses::renderSprite(IDisplayModule::Sprite sprite)
{
    RawTextureNcurses *texture = dynamic_cast<RawTextureNcurses *>(sprite.texture);
    char character = texture->getCharacter();
    uint32_t x = ((sprite.rawPixelPosition.x + texture->getWidth() / 2) / _pixelsPerCell) + 1;
    uint32_t y = ((sprite.rawPixelPosition.y + texture->getHeight() / 2) / _pixelsPerCell) + 1;

    wattron(_win, COLOR_PAIR(texture->getColor()));
    mvwaddch(_win, y, x, character);
    wattroff(_win, COLOR_PAIR(texture->getColor()));
    return;
}

void ArcadeNcurses::display()
{
    wattron(_win, COLOR_PAIR(findPair(IDisplayModule::Color::black, IDisplayModule::Color::white)));
    box(_win, 0, 0);
    wattroff(_win, COLOR_PAIR(findPair(IDisplayModule::Color::black, IDisplayModule::Color::white)));
    wrefresh(_win);
    return;
}

bool ArcadeNcurses::isClosing()
{
    return (false);
}

void ArcadeNcurses::update(void)
{
    _textInput = "";
    _input = getch();
    if (_isTextInputOn && (isalnum(_input) || _input == KEY_BACKSPACE || _input == '\n')) {
        if (_input == KEY_BACKSPACE)
            _textInput.push_back('\b');
        else if (_input == '\n')
            _textInput.push_back('\n');
        else
            _textInput.push_back((char)_input);
    }
    return;
}

WINDOW *ArcadeNcurses::getWindow()
{
    return (_win);
}

void ArcadeNcurses::setWindow(WINDOW *win)
{
    _win = win;
}

void ArcadeNcurses::initAllColorPair(void)
{
    int i = 1;

    for (int ii = 0; ii < 8; ii++)
        for (int iii = 0; iii < 8; iii++)
                init_pair(i++, iii, ii);
}

int ArcadeNcurses::findPair(IDisplayModule::Color background, IDisplayModule::Color foreground)
{
    return ((int)background * 8 + (int)foreground + 1);
}