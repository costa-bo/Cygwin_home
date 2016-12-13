#include <iostream>
#include <string>

class Monster
{
public:
    enum MonsterType{
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

public:
    Monster(MonsterType type, std::string name, 
            std::string roar, int hitPoints) : 
            m_type(type), m_name(name), 
            m_roar(roar), m_hitPoints(hitPoints)
    {
    }

    std::string getTypeString(MonsterType type)
    {
        switch(type){
            case Dragon: return "Dragon"; 
            case Goblin: return "Goblin"; 
            case Ogre: return "Dragon"; 
            case Orc: return "Orc"; 
            case Skeleton: return "Skeleton"; 
            case Troll: return "Troll"; 
            case Vampire: return "Vampire"; 
            case Zombie: return "Zombie"; 
            default: return "Monster Type not found"; 
        }
    }

    void print()
    {
        std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
    }

};


class MonsterGenerator
{
public:
    MonsterGenerator();

    // Generate a random number between min and max (inclusive)
    // Assumes srand() has already been called
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    static Monster generateMonster()
    {
        Monster::MonsterType RandType = static_cast<Monster::MonsterType>(getRandomNumber(1, Monster::MAX_MONSTER_TYPES - 1));
        int randHitPoints = getRandomNumber(1, 100);

        static std::string s_names[6] = {"Basis", "Babis", "Mantas", "Olia", "Makis", "George"};
        static std::string s_roars[6] = {"miaou", "beee", "pritch", "Centos", "smouts", "frrrrr"};

        std::string randName = s_names[getRandomNumber(0, 5)];
        std::string randRoar = s_roars[getRandomNumber(0, 5)];


        return Monster(RandType, randName, randRoar, randHitPoints);
    }

};

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    //Monster skele(Monster::Skeleton, "Bones", "*rattle*", 4);
    //skele.print();

    Monster m = MonsterGenerator::generateMonster();
    m.print();
 
    return 0;
}
