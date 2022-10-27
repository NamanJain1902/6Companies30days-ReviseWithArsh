#ifndef HERO_H
#define HERO_H  

#include <string>
#include "string_utility.h"

class Hero {    
    std::string name;
    char firstChar[2]{};
    
    public:
    int health;
    Hero() {
        // this->firstChar[0] = this->firstChar[1] = '';     
    }
    Hero(int _health, std::string _name) : health(_health), name(_name) {
        this->getNameInitials();
    }
    Hero(const Hero &nextLevel) {
        this->name = "She-Hulk";
        this->health = nextLevel.health + 100;
        this->getNameInitials();
    }
    void getNameInitials() {
        std::string s = this->name;
        s += ' ';
        std::string t;
        int i = 0;
        for(auto x: s){
            if(i == 2) break;
            if(!isDelimiter(x)) t+=x;
            else {this->firstChar[i++]=toupper(t[0]);t="";}
        }
    }
    void set_health(int _health) {
        this->health = _health;
    }
    
    int get_health() {
        std::cout << "\n Hero get.\n";
        return this->health;
    }

    friend std::ostream& operator<<(std::ostream& os, const Hero& hero)
    {
        return os << "("
                  << hero.firstChar[0] << hero.firstChar[1] << ": "
                  << hero.name << ", "
                  << hero.health
                  << ")";
    }
};
#endif