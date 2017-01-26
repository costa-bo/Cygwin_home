#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

public:
    Creature(std::string name, char symbol, int health, 
             int damage, int gold) : 
             m_name(name), m_symbol(symbol), 
             m_health(health), m_damage(damage), m_gold(gold)
    {
    }

    std::string getName() { return m_name; }
    char getSymbol() { return m_symbol; }
    int getHealth() { return m_health; }
    int getDamage() { return m_damage; }
    int getGold()   { return m_gold; }

    void reduceHealth(int damage) { m_health -= damage; }
    bool isDead() { return m_health <=0; }
    void addGold(int gold) { m_gold += gold; }
};

class Player : public Creature
{
private:
    int m_level;

public:
    Player(std::string name, char symbol='@', int health=10, int damage=1, int gold=0) : 
           Creature(name, symbol, health, damage, gold)
    {
        m_level = 1;
    }

    void levelUp(){
        m_level++;
        m_damage++;
    }

    int getLevel(){ return m_level; }
    bool hasWon(){ return m_level==20; }
};

class Monster : public Creature
{
public: 
    enum Type {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES 
    };

    struct MonsterData {
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[];

    Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol,
                                  monsterData[type].health, monsterData[type].damage,
                                  monsterData[type].gold)
    {
    }

    static Monster getRandomMonster()
    {
        int ran = getRandomNumber(0, MAX_TYPES-1);
        return Monster(static_cast<Type>(ran));
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

void attackMonster(Player &p, Monster &m)
{
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for "
              << m.getDamage() << " damage.\n";
}

void attackPlayer(Player &p, Monster &m)
{
    std::cout << "You hit the " << m.getName() << " for "
              << m.getDamage() << " damage.\n";

    m.reduceHealth(p.getDamage());
    
    
}

void fightMonster(Player &p, Monster &m)
{
    bool escaped;

    do {
        std::cout << "(R)un or (F)ight: ";
        char action;
        std::cin >> action;

        if (action=='r' || action=='R'){
            escaped = getRandomNumber(0,1);
            if (escaped){
                std::cout << "You successfully fled.\n";
                return;
            } else {
                std::cout << "You failed to flee.\n";
                attackMonster(p, m);
            }
        } else if (action=='f' || action=='F'){
            attackPlayer(p, m);
            attackMonster(p, m);
        }
    } while ((p.getHealth() > 0) && (m.getHealth() > 0));
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    rand(); // get rid of first result

    std::string name;
    std::cout << "Entre your name: ";
    std::cin >> name;
    std::cout << "Welcome, " << name << std::endl;
    Player p(name);

    do {
        Monster m = Monster::getRandomMonster();
        std::cout << "You have encounter a " << m.getName() << " (" << m.getSymbol() << ").\n";
        fightMonster(p, m);

        if (m.getHealth() <= 0){
            std::cout << "You killed the " << m.getName() << std::endl;
            p.levelUp();
            std::cout << "You are now at level " << p.getLevel() << std::endl;
            p.addGold(m.getGold());
            std::cout << "You found " << m.getGold() << std::endl;
        } else if (p.getHealth() <= 0){
            std::cout << "You died at level " << p.getLevel() << " and with "
                      << p.getGold() << " gold.\n";
            std::cout << "Too bad you can't take it with you!\n";
            break;
        }
    } while (true);
}
