/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "ArcadeMain.hpp"

#define UNUSED(x) (void)(x)

class Arcade;

class MainMenu {
    public:
        MainMenu();
        ~MainMenu();
        void init(Arcade *coreHandle);
        void update();
        void draw();

        std::vector<ICore::Texture *> createMajAlphabet(void);
        std::vector<ICore::Texture *> createMinAlphabet(void);
        std::vector<ICore::Texture *> createNumbers(void);
        std::vector<ICore::Texture *> createActualMajAlphabet(void);
        std::vector<ICore::Texture *> createActualMinAlphabet(void);
        std::vector<ICore::Texture *> createActualNumbers(void);
        std::vector<ICore::Texture *> createCursorMajAlphabet(void);
        std::vector<ICore::Texture *> createCursorMinAlphabet(void);
        std::vector<ICore::Texture *> createCursorNumbers(void);
        std::vector<ICore::Texture *> createActualCursorMajAlphabet(void);
        std::vector<ICore::Texture *> createActualCursorMinAlphabet(void);
        std::vector<ICore::Texture *> createActualCursorNumbers(void);
        void checkPressedButton(void);
        void drawBox(void);
        void drawSquare(void);
        void drawSeparators(void);
        void graphicalList(void);
        void gameList(void);
        void scoreList(void);
        void writeText(std::string text, ICore::Vector2u startingPos);
        void writeActualText(std::string text, ICore::Vector2u startingPos);
        void writeCursorText(std::string text, ICore::Vector2u startingPos);
        void writeActualCursorText(std::string text, ICore::Vector2u startingPos);
        void activateCursor(void);
        void moveLeft(void);
        void moveUp(void);
        void moveDown(void);

    protected:
        Arcade *_core;
        ICore::Texture *_wall;
        ICore::Texture *_space;
        ICore::Texture *_doublePoint;
        ICore::Texture *_point;
        ICore::Texture *_slash;
        ICore::Texture *_exclamation;
        ICore::Texture *_underscore;

        ICore::Texture *_doublePointActual;
        ICore::Texture *_pointActual;
        ICore::Texture *_slashActual;
        ICore::Texture *_exclamationActual;
        ICore::Texture *_underscoreActual;

        ICore::Texture *_doublePointCursor;
        ICore::Texture *_pointCursor;
        ICore::Texture *_slashCursor;
        ICore::Texture *_exclamationCursor;
        ICore::Texture *_underscoreCursor;

        ICore::Texture *_doublePointActualCursor;
        ICore::Texture *_pointActualCursor;
        ICore::Texture *_slashActualCursor;
        ICore::Texture *_exclamationActualCursor;
        ICore::Texture *_underscoreActualCursor;

        std::vector<ICore::Texture *> _blueMajAlphabet;
        std::vector<ICore::Texture *> _blueMinAlphabet;
        std::vector<ICore::Texture *> _blueNumbers;

        std::vector<ICore::Texture *> _actualMajAlphabet;
        std::vector<ICore::Texture *> _actualMinAlphabet;
        std::vector<ICore::Texture *> _actualNumbers;

        std::vector<ICore::Texture *> _cursorMajAlphabet;
        std::vector<ICore::Texture *> _cursorMinAlphabet;
        std::vector<ICore::Texture *> _cursorNumbers;

        std::vector<ICore::Texture *> _cursorActualMajAlphabet;
        std::vector<ICore::Texture *> _cursorActualMinAlphabet;
        std::vector<ICore::Texture *> _cursorActualNumbers;

        std::string _font;
        u_int32_t _width;
        u_int32_t _height;
        u_int32_t _pixelPerCells;
        u_int32_t _framerate;
        int _cursor;
        bool _textInput;
        std::string _textInputStr;
    private:
};

#endif /* !MAINMENU_HPP_ */
