#include <memory>
#include <vector>
#include "characters.h"

namespace roguelike {
    class Map {
    public:
        Map();

        int getWidth() const;
        int getHeight() const;
        std::shared_ptr<Character> &getHero();
        std::vector<std::shared_ptr<Character>> &getCharacters();

        void resize(int width, int height);
        std::shared_ptr<Character> characterAtPos(int x, int y);

    private:
        int width_;
        int height_;
        std::shared_ptr<Character> hero_;
        std::vector<std::shared_ptr<Character>> characters_;
    };
}
