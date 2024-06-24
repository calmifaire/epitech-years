/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include "ArgumentChecker.hpp"
#include "MainMenu.hpp"

class Arcade : public ICore {
    public:
        Arcade();
        ~Arcade();
        void setPixelsPerCell(std::uint32_t pixelsPerCell);
        void setFramerate(unsigned framerate);
        ICore::Texture *loadTexture(const std::string &pngFilename, char character, ICore::Color characterColor, ICore::Color backgroundColor, std::size_t width, std::size_t height);
        void openWindow(ICore::Vector2u pixelsWantedWindowSize);
        bool isButtonPressed(ICore::Button button);
        ICore::MouseButtonReleaseEvent getMouseButtonReleaseEvent();
        void startTextInput();
        std::string getTextInput();
        void endTextInput();
        void clearScreen(ICore::Color color);
        void renderSprite(ICore::Sprite sprite);
        void addNewScore(std::uint32_t score);
        const std::string &getPlayerName(void);

        void setPlayerName(std::string name);
        void setDlGraphical(void *graphical);
        void changeLibraryByPath(std::string path, bool graphical);
        void initClassFromDl(bool graphical);
        void closeDl(bool graphical);
        void checkFunctionButton(void);
        void gameRestart(void);
        void goBackToMenu(void);
        void exitArcade(void);
        void gameLoop(void);
        void launchGame(void);
        void destroyRawTexture(void);
        void reloadAllTexture(void);
        void clearDeque(void);
        void invertInBool(void);
        std::deque<std::string> initGraphPathDeque(void);
        std::deque<std::string> initGamePathDeque(void);
        void initActualGraphGraphical(std::string lib);
        void initActualGameGraphical(std::string lib);
        std::string getPrevLibrary(bool graphical);
        std::string getNextLibrary(bool graphical);
        std::string getNameOfGame(void);
        const std::deque<std::string> &getGraphPathDeque(void);
        const std::deque<std::string> &getGamePathDeque(void);
        const long &getActualGraphPath(void);
        const long &getActualGamePath(void);
        void setActualGraphPath(long path);
        void setActualGamePath(long path);
        void clearTextureDeque(void);
        void initGame(void);

    protected:
        std::deque<ICore::Texture> _textureDeque;
        std::unique_ptr<IDisplayModule> _graphical;
        std::unique_ptr<IGameModule> _game;
        std::unique_ptr<MainMenu> _menu;
        void *_dlGraphical;
        void *_dlGame;
        std::deque<std::string> _graphPathDeque;
        std::deque<std::string> _gamePathDeque;
        long _actualGraphPath;
        long _actualGamePath;
        bool _inGame;
        bool _inMenu;
        unsigned _framerate;
        std::uint32_t _pixelsPerCell;
        IDisplayModule::Vector2u _windowSize;
        std::string _playerName;
    private:
};

#endif /* !ARCADE_HPP_ */
