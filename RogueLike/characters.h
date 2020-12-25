#include <utility>

namespace roguelike {
    class Character {
    public:
        int getHp() const;
        void setHp(int date);
        int getMaxHp() const;
        void setMaxHp(int date);
        int getDamage() const;
        void setDamage(int date);
        char getSymbol() const;
        void setSymbol(char date);
        std::pair<int, int> getPosition() const;

        virtual bool isDead() const;
        virtual void move(int dx, int dy);
        virtual void hurt(int value);
        virtual void setPosition(int x, int y);

    protected:
        int hp_;
        int maxHp_;
        int damage_;
        char symbol_;
        std::pair<int, int> position_;
    };

    class Knight : public Character {
    public:
        Knight(int x, int y);
        explicit Knight(std::pair<int, int> position);
    };

    class Princess : public Character {
    public:
        Princess(int x, int y);
        explicit Princess(std::pair<int, int> position);
    };

    class Wall : public Character {
    public:
        Wall(int x, int y);
        explicit Wall(std::pair<int, int> position);
    };

    class Monster : public Character {};

    class Zombie : public Monster {
    public:
        Zombie(int x, int y);
        explicit Zombie(std::pair<int, int> position);
    };

    class Dragon : public Monster {
    public:
        Dragon(int x, int y);
        explicit Dragon(std::pair<int, int> position);
    };
}