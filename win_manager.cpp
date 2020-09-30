
#include "win_manager.h"

#include <numeric>
#include <cstdlib>
#include <iostream>

/*
 * Button actions
 */

// Need explicit instantiation here...
template void sorts::bubble(std::vector<CountingInt>&);
void WinManager::setBubblesort(WinManager *wm) noexcept {
    if (wm) {
        wm->sort = sorts::bubble<CountingInt>;
    }
}

template void sorts::stdsort(std::vector<CountingInt>&);
void WinManager::setStdsort(WinManager *wm) noexcept {
    if (wm) {
        wm->sort = sorts::stdsort<CountingInt>;
    }
}

void WinManager::setFillAscending(WinManager *wm) noexcept {
    if (wm) {
        wm->fill_type = FillType::ASCENDING;
    }
}

void WinManager::setFillDescending(WinManager *wm) noexcept {
    if (wm) {
        wm->fill_type = FillType::DESCENDING;
    }
}

void WinManager::setFillRandom(WinManager *wm) noexcept {
    if (wm) {
        wm->fill_type = FillType::RANDOM;
    }
}

bool WinManager::fillArray(std::vector<CountingInt> &arr) const noexcept {
    int size = arr.size();

    switch (fill_type) {
        case FillType::ASCENDING:
            std::iota(arr.begin(), arr.end(), 0);
            break;
        case FillType::DESCENDING:
            std::iota(arr.rbegin(), arr.rend(), 0);
            break;
        case FillType::RANDOM:
            
            std::generate(arr.begin(), arr.end(),
                          [size]()->CountingInt { return std::rand() % size; }
                         );
            break;
        default:
            std::cout << "Unknown fill_type = "
                      << static_cast<int>(fill_type) << "\n";
            return false;
    }
    return true;
}

void WinManager::setStartSort(WinManager *wm) noexcept {
    if (wm) {
        std::vector<sf::Vector2i> res_cmp;
        std::vector<sf::Vector2i> res_ass;

        /* Sorry for that... */
        std::vector<int> arr_sizes(100);
        const int step = 10;
        int cursize = step;
        for (size_t i = 0; i < arr_sizes.size(); i++) {
            arr_sizes[i] = cursize;
            cursize += step;
        }

        for (int size : arr_sizes) {
            std::vector<CountingInt> base(size);
            wm->fillArray(base);

            /* Main action */
            wm->sort(base);

            /* Gathering stats */
            int ncmp = 0;
            int nass = 0;
            for (auto &i : base) {
                ncmp += i.times_compared_against();
                nass += i.times_assigned();
            }
            
            res_cmp.push_back({ size, ncmp });
            res_ass.push_back({ size, nass });
        }

        /* Printing */
        wm->assignments.putPoints(res_ass);
        wm->comparisons.putPoints(res_cmp);
    }
}

void WinManager::setClear(WinManager *wm) noexcept {
    if (wm) {
        wm->assignments.clear();
        wm->comparisons.clear();
    }
}

/*
 * WinManager implementation
 */

WinManager::WinManager(int width, int height, const std::string &name)
    : window(sf::VideoMode(width, height), name)
    , assignments   (sf::Vector2u(250, 500))
    , comparisons   (sf::Vector2u(250, 500))
    , fill_type     (FillType::DESCENDING)
    , sort          (sorts::bubble)
{
    // TODO: fix error recovery
    if (!font.loadFromFile("UbuntuMono-B.ttf")) {
        std::cout << "Wow!\n";
        return;
    }
    
    buttons[BUTTON_SET_BUBBLESORT].setText("Bubblesort", font);
    buttons[BUTTON_SET_BUBBLESORT].move(40.0, 50.0);
    buttons[BUTTON_SET_BUBBLESORT].setOnPress(setBubblesort);

    buttons[BUTTON_SET_STDSORT].setText("Stdsort", font);
    buttons[BUTTON_SET_STDSORT].move(40.0, 100.0);
    buttons[BUTTON_SET_STDSORT].setOnPress(setStdsort);

    buttons[BUTTON_FILL_ASCENDING].setText("Fill up", font);
    buttons[BUTTON_FILL_ASCENDING].move(40.0, 150.0);
    buttons[BUTTON_FILL_ASCENDING].setOnPress(setFillAscending);

    buttons[BUTTON_FILL_DESCENDING].setText("Fill down", font);
    buttons[BUTTON_FILL_DESCENDING].move(40.0, 200.0);
    buttons[BUTTON_FILL_DESCENDING].setOnPress(setFillDescending);

    buttons[BUTTON_FILL_RANDOM].setText("Fill random", font);
    buttons[BUTTON_FILL_RANDOM].move(40.0, 250.0);
    buttons[BUTTON_FILL_RANDOM].setOnPress(setFillRandom);

    buttons[BUTTON_START_SORT].setText("Start", font);
    buttons[BUTTON_START_SORT].move(40.0, 300.0);
    buttons[BUTTON_START_SORT].setOnPress(setStartSort);

    buttons[BUTTON_CLEAR].setText("Clear", font);
    buttons[BUTTON_CLEAR].move(40.0, 350.0);
    buttons[BUTTON_CLEAR].setOnPress(setClear);

    assignments.move(230.0, 50.0);
    comparisons.move(500.0, 50.0);
}

void WinManager::processMouseKeyPress() noexcept {
    sf::Vector2i cursor = sf::Mouse::getPosition(window);
    for (auto &b : buttons)
        if (isButtonPressed(b, cursor))
            b.doPressAction(this);
}

bool WinManager::run() noexcept {
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
                return true;
            }
            if (e.type == sf::Event::MouseButtonPressed)
                processMouseKeyPress();
        }

        /* Just some grey color */
        window.clear(sf::Color(120,120,120));

        for (int i = 0; i < NBUTTONS; i++)
            window.draw(buttons[i]);
        window.draw(assignments);
        window.draw(comparisons);

        window.display();
    }
    return false;
}

