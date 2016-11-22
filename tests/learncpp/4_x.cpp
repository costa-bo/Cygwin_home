#include <iostream>
#include <string>

using namespace std;

enum class MonsterType{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};

string getMonsterTypeName(MonsterType type)
{
    string name;

    if (type == MonsterType::OGRE){
        name = "Ogre";
    } else if (type == MonsterType::DRAGON) {
        name = "Dragon";
    } else if (type == MonsterType::ORC) {
        name = "Orc";
    } else if (type == MonsterType::GIANT_SPIDER) {
        name = "Giant Spider";
    } else {
        name = "Slime";
    }

    return name;
}

struct Monster{
    MonsterType monsterType;
    std::string name;
    int32_t health;
};

void printMonster(Monster monster)
{
    cout << "Monster type: " << getMonsterTypeName(monster.monsterType) << endl;
    cout << "Name: " << monster.name << endl;
    cout << "Health: " << monster.health << endl << endl;
}

int main()
{
    Monster first_monster = {MonsterType::SLIME, "egla", 1000};
    Monster second_monster = {MonsterType::OGRE, "arostos", 50};

    printMonster(first_monster);
    printMonster(second_monster);
}
