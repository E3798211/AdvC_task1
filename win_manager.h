
#ifndef   WIN_MANAGER_H_INCLUDED
#define   WIN_MANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

#include "button.h"
#include "plot.h"
#include "sort.hpp"
#include "counting_int.h"

class WinManager
{
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text status;

    /* Drawable objects */
    enum
    {
        BUTTON_SET_BUBBLESORT,
        BUTTON_SET_STDSORT,

        BUTTON_FILL_ASCENDING,
        BUTTON_FILL_DESCENDING,
        BUTTON_FILL_RANDOM,

        BUTTON_START_SORT,
        BUTTON_CLEAR,

        NBUTTONS
    };
    Button buttons[NBUTTONS];

    Plot assignments;
    Plot comparisons;

    /* Non-drawble, implement inner logic */
    enum class FillType
    {
        ASCENDING,
        DESCENDING,
        RANDOM
    };
    FillType    fill_type;

    enum class SortType
    {
        BUBBLE,
        STDSORT
    };
    /*
     * Just to track current func for status. Bad solution
     * since it requires some kind of code duplication...
     */
    SortType    sort_type;  

    sorts::sort_t<CountingInt> sort;

    /* Button callbacks */
    static void setBubblesort(WinManager *wm) noexcept;
    static void setStdsort(WinManager *wm) noexcept;
    static void setFillAscending(WinManager *wm) noexcept;
    static void setFillDescending(WinManager *wm) noexcept;
    static void setFillRandom(WinManager *wm) noexcept;
    static void setStartSort(WinManager *wm) noexcept;
    static void setClear(WinManager *wm) noexcept;

    /* Helpers */
    void processMouseKeyPress() noexcept;
    
    void updateStatus() noexcept;

    /* Returns whether the call was successful */
    bool fillArray(std::vector<CountingInt> &arr) const noexcept;

public:
    explicit WinManager(int width, int height, const std::string &name);

    /* Returns whether user has closed the window himself */
    bool run() noexcept;
};

#endif // WIN_MANAGER_H_INCLUDED

