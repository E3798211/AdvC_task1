
#ifndef   WIN_MANAGER_H_INCLUDED
#define   WIN_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

#include "button.h"
#include "sort.hpp"
#include "counting_int.h"

class WinManager
{
private:
    sf::RenderWindow window;
    sf::Font font;

    enum
    {
        BUTTON_SET_BUBBLESORT,
        BUTTON_SET_STDSORT,

        BUTTON_FILL_ASCENDING,
        BUTTON_FILL_DESCENDING,
        BUTTON_FILL_RANDOM,

        BUTTON_START_SORT,

        NBUTTONS
    };
    Button buttons[NBUTTONS];

    sorts::sort_t<CountingInt> sort;


    void processMouseKeyPress() noexcept;


    /* Button callbacks */
    static void setBubblesort(WinManager *wm) noexcept;
    static void setStdsort(WinManager *wm) noexcept;
    static void setFillAscending(WinManager *wm) noexcept;
    static void setFillDescending(WinManager *wm) noexcept;
    static void setFillRandom(WinManager *wm) noexcept;
    static void setStartSort(WinManager *wm) noexcept;
public:
    explicit WinManager(int width, int height, const std::string &name);

    /* Returns whether user has closed the window himself */
    bool run() noexcept;
};

#endif // WIN_MANAGER_H_INCLUDED

