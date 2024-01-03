#pragma once
#include<string>
#include<iostream>
#include<vector>
#include <assert.h> 
using namespace std;

class Character {
public:
    Character(string name, int health, int level) : m_name(name), m_health(health), m_level(level) {}
    string getName() const { 
        return m_name;
    }
    int getHealth() const {
        return m_health;
    }
    int getLevel() const { 
        return m_level;
    }
    void setName(string name) {
        m_name = name;
    }
    void setHealth(int health) {
        m_health = health;
    }
    void setLevel(int level) {
        m_level = level; 
    }

private:
    string m_name;
    int m_health;
    int m_level;
    // other attributes here
    // the tester class is a friend of the Character class
    friend class CharacterTest;
};
class Wizard : public Character {
public:
    Wizard(string name, int health, int level, int mana, vector<string> spells, int spellPower) : Character(name, health, level), m_mana(mana), m_spells(spells), m_spellPower(spellPower) {}
    int getMana() const { 
        return m_mana; 
    }
    void setMana(int mana) {
        m_mana = mana; 
    }
    int getSpellPower() const {
        return m_spellPower;
    }
    void setSpellPower(int spellPower) {
        m_spellPower = spellPower; 
    }
    vector<string> getSpells() const {
        return m_spells;
    }
    void setSpells(vector<string> spells) {
        m_spells = spells; 
    }
    bool castSpell(string spell) {
        for (string s : m_spells) {
            if (s == spell) {
                if (m_mana >= 10) {
                    m_mana -= 10;
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }
private:
    int m_mana;
    vector<string> m_spells;
    int m_spellPower;
    friend class WizzardTest;
}
;
class Knight :public Character {
public:
    Knight(string name, int health, int level, double armor, int swordDamage) :Character(name, health, level), m_armor(armor), m_swordDamage(swordDamage) {}
    double getArmor() const {
        return m_armor;
    }
    void setArmor(double armor) {
        m_armor = armor;
    }
    int getSwordDamage() const {
        return m_swordDamage;
    }
    void setSwordDamage(int swordDamage) {
        m_swordDamage = swordDamage;
    }
    void takeDamage(int damage) {
        m_armor = double(damage);
        if (m_armor < 0.0) {
            setHealth(0);
        }
    }
private:
    double m_armor;
    int m_swordDamage;
    friend class KnightTest;
};

class CharacterTest {
public:
    static void testSetName() {
        // TODO your code here
        Character c1("Alex", 15, 5);
        assert(c1.getName() == "Alex");
        c1.setName("Ana");
        assert(c1.getName() == "Ana");
    }
    static void testSetLevel() {
        Character c1("Alex", 15, 5);
        assert(c1.getLevel() == 5);

        c1.setLevel(6);
        assert(c1.getLevel() == 6);
    }
    static void testSetHealth() {
        Character c1("Alex", 15, 5);
        assert(c1.getHealth() == 15);

        c1.setHealth(10);
        assert(c1.getHealth() == 10);
    }
    // TODO other test methods
    static void runAll() {
        testSetName();
        testSetLevel();
        testSetHealth();
        // TODO call all the other methods
    }
};
    class WizardTest {
    public:
        static void testSetMana() {
            Wizard w1("Gandalf", 100, 10, 50, { "s1", "s2", "s3" }, 20);
            assert(w1.getMana() == 50);
            w1.setMana(30);
            assert(w1.getMana() == 30);
        }

        static void testSetSpellPower() {
            Wizard w1("Gandalf", 100, 10, 50, { "s1", "s2", "s3" }, 20);
            assert(w1.getSpellPower() == 20);
            w1.setSpellPower(30);
            assert(w1.getSpellPower() == 30);
        }

        static void testCastSpell() {
            Wizard w1("Gandalf", 100, 10, 50, { "s1", "s2", "s3" }, 20);
            assert(w1.castSpell("s1"));
            assert(w1.getMana() == 40);
            assert(!w1.castSpell("s4"));
            assert(w1.getMana() == 40);
        }

        static void runAll() {
            testSetMana();
            testSetSpellPower();
            testCastSpell();
        }

    };
    class KnightTest {
    public:
        static void testSetArmor() {
            Knight k1("random", 100, 10, 20.0, 10);
            assert(k1.getArmor() == 20.0);
            k1.setArmor(30.0);
            assert(k1.getArmor() == 30.0);
        }

        static void testSetSwordDamage() {
            Knight k1("random", 100, 10, 20.0, 10);
            assert(k1.getSwordDamage() == 10);
            k1.setSwordDamage(15);
            assert(k1.getSwordDamage() == 15);
        }

        static void testTakeDamage() {
            Knight k1("random", 100, 10, 20.0, 10);
            k1.takeDamage(30);
            assert(k1.getArmor() == 30.0);
            k1.takeDamage(80);
            assert(k1.getArmor() == 80.0);
        }
        static void runAll() {
            testSetArmor();
            testSetSwordDamage();
            testTakeDamage();
        }
    };

    