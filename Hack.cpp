#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

void levelUp(int exp, int &level, int* expNeed, int* currStats, int upStats[]) {
    int levelupOccur = 0;
    for (int i = 0; i < 24; i++) {
        if ((level == (i+1)) && (exp > expNeed[i])) {
            Sleep(500);
            cout << "Level Up!" << endl;
            level = level + 1;
            Sleep(250);
            cout << "Level: " << (level - 1) << " -> " << level << endl;
            Sleep(250);
            cout << "HP: " << currStats[0] << " -> " << (currStats[0] + upStats[i]) << endl;
            Sleep(250);
            cout << "MP: " << currStats[1] << " -> " << (currStats[1] + upStats[i+24]) << endl;
            Sleep(250);
            cout << "Attack: " << currStats[2] << " -> " << (currStats[2] + upStats[i+48]) << endl;
            Sleep(250);
            cout << "Defense: " << currStats[3] << " -> " << (currStats[3] + upStats[i+72]) << endl;
            Sleep(250);
            cout << "Magic: " << currStats[4] << " -> " << (currStats[4] + upStats[i+96]) << endl;
            currStats[0] = currStats[0] + upStats[i];
            currStats[1] = currStats[1] + upStats[i+24];
            currStats[2] = currStats[2] + upStats[i+48];
            currStats[3] = currStats[3] + upStats[i+72];
            currStats[4] = currStats[4] + upStats[i+96];
            levelupOccur = 1;
            break;
        }
    }
    if (level == 3 && levelupOccur == 1) {
        Sleep(500);
        cout << "The shop has been unlocked!" << endl;
    }
    if (level == 5 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
    if (level == 7 && levelupOccur == 1) {
        Sleep(500);
        cout << "Stat Training has been unlocked!" << endl;
    }
    if (level == 8 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
    if (level == 10 && levelupOccur == 1) {
        Sleep(500);
        cout << "Hard Battles have been unlocked!" << endl;
    }
    if (level == 12 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
    if (level == 16 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
    if (level == 19 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
    if (level == 23 && levelupOccur == 1) {
        Sleep(500);
        cout << "There are new items available in the shop!" << endl;
    }
}

int statBoost(int stat) {
    double boost = double(stat);
    boost = boost / 5;
    int add = int(boost);
    return add;
}

int burn(int maxHP) {
    double health = double(maxHP);
    health = health / 12;
    int damage = int(health);
    return damage;
}

int miracleSpellMP(int damage) {
    double MP = double(damage);
    MP = MP / 10;
    int restore = int(MP);
    return restore;
}

int miracleSpellHeal(int damage) {
    double healing = double(damage);
    healing = healing / 2;
    int health = int(healing);
    return health;
}

int miracleSpell(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = aMag * 1.23;
    double denom = def / aMag;
    double damage = roll * ((num / denom) + 18 + (level - 1) * 2);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int ultraCure(int userHP) {
    srand(time(0));
    double hp = double(userHP);
    int crit = (rand() % 16);
    double restore;
    int rRestore;
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Heal!" << endl;
        restore = userHP * .75;
        rRestore = int(restore);
        return rRestore;
    }
    else {
        restore = userHP * .5;
        rRestore = int(restore);
        return rRestore;
    }
}

int magicAidMP(int maxMP) {
    double MP = double(maxMP);
    MP = MP / 4;
    int MPRestore = int(MP);
    return MPRestore;
}

int magicAidHeal(int maxHP) {
    double healing = double(maxHP);
    healing = healing / 4;
    int health = int(healing);
    return health;
}

int drainingBlastHeal(int damage) {
    double healing = double(damage);
    healing = healing / 5;
    int health = int(healing);
    return health;
}

int drainingBlast(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = aMag * .71;
    double denom = def / aMag;
    double damage = roll * ((num / denom) + (level - 1) * 2.5);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int smashHitDefReduce(int aDef) {
    double def = double(aDef);
    double reduceDef = .5 * def;
    int rDef = int(reduceDef);
    return rDef;
}

int smashHit(int aDef, int eDef, int level) {
    srand(time(0));
    double uDef = double(aDef);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = uDef * 2.5;
    double denom = def / uDef;
    double damage = roll * ((num / denom) + 50);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int bodyBash(int aDef, int eDef, int level) {
    srand(time(0));
    double uDef = double(aDef);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = uDef;
    double denom = def / uDef;
    double damage = roll * ((num / denom) + (level - 1) * 3);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int repairDef(int aDef) {
    double def = double(aDef);
    double addDef = .75 * def;
    int rDef = int(addDef);
    return rDef;
}

int starbustHeal(int maxHP) {
    double healing = double(maxHP);
    healing = healing * .15;
    int health = int(healing);
    return health;
}

int starburst(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = .55 * mag;
    double denom = def / mag;
    double damage = roll * ((num / denom) + 1.5 * (level - 1));
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int megaFlame(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = 1.21 * mag;
    double denom = def / mag;
    double damage = roll * ((num / denom) + 15 + 2 * (level - 1));
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int freezingShock(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = 1.07 * mag;
    double denom = def / mag;
    double damage = roll * ((num / denom) + 2 * (level - 1));
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int counter(int damage) {
    return damage * 2;
}

int counterDamageTaken(int damage) {
    double dam = double(damage);
    dam = dam * .67;
    int rDamage = int(dam);
    return rDamage;
}

int tripleSlashThree(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 6;
    roll = roll / 100;
    double num = (atk * .5);
    double denom = def / atk;
    double damage = roll * (num / denom) + (level - 1);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int tripleSlashTwo(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = (atk * .35);
    double denom = def / atk;
    double damage = roll * (num / denom) + (level - 1);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int tripleSlashOne(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = (atk * .23);
    double denom = def / atk;
    double damage = roll * (num / denom) + (level - 1);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int sacredSwipe(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = (atk * 1.05);
    double denom = (def * .8) / atk;
    double damage = roll * ((num / denom) + (level - 1) * 2);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int healingStrikeHeal(int damage) {
    double healing = double(damage);
    healing = healing / 4;
    int health = int(healing);
    return health;
}

int healingStrike(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = (atk * .77);
    double denom = def / atk;
    double damage = roll * ((num / denom) + (level - 1) * 3);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

//2715293 - Cure Calculation
int cure(int userHP) {
    srand(time(0));
    double hp = double(userHP);
    int crit = (rand() % 16);
    double restore;
    int rRestore;
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Heal!" << endl;
        restore = userHP * .5;
        rRestore = int(restore);
        return rRestore;
    }
    else {
        restore = userHP * .3;
        rRestore = int(restore);
        return rRestore;
    }
}

//2719004 - Defensive Call Calculation
int defensiveCall(int aDef) {
    double def = double(aDef);
    double addDef = .35 * def;
    int rDef = int(addDef);
    return rDef;
}

int flameBurst(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = .56 * mag;
    double denom = def / mag;
    double damage = roll * ((num / denom) + 3 + 2 * (level - 1));
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

//2713661 - Flame Burst Calculation
int flameBurstTut(int aMag, int eDef, int level) {
    srand(time(0));
    double mag = double(aMag);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 16;
    roll = roll / 100;
    double num = .87 * mag;
    double denom = def / mag;
    double damage = roll * ((num / denom) + 3 + 2 * (level - 1));
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }

}
//2714802 - Slash Calculation
int slash(int aAtk, int eDef, int level) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = (rand() % 16) + 85;
    int crit = rand() % 6;
    roll = roll / 100;
    double num = (atk * 1.05);
    double denom = def / atk;
    double damage = roll * ((num / denom) + (level - 1) * 2);
    if (crit == 3) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

//2713890 - Attack Calculation
int attack(int aAtk, int eDef) {
    srand(time(0));
    double atk = double(aAtk);
    double def = double(eDef);
    double roll = rand() % 16;
    int crit = rand() % 16;
    roll = roll + 85;
    double dmgRoll = roll / 100;
    double num = .75 * atk;
    double denom = def / atk;
    double damage = dmgRoll * (num / denom);
    if (crit == 10) {
        Sleep(500);
        cout << "A Critical Hit!" << endl;
        damage = damage * 1.6;
    }
    int rDamage = int(damage);
    double round = damage - rDamage;
    if (round >= 0.5) {
        return rDamage + 1;
    }
    else {
        if (rDamage < 1) {
            return 1;
        }
        return rDamage;
    }
}

int expGain(int userLevel) {
    srand(time(0));
    int exp;
    if (userLevel == 1) {
        exp = (rand() % 7) + 3;
        return exp;
    }
    else if (userLevel == 2) {
        exp = (rand() % 8) + 4;
        return exp;
    }
    else if (userLevel == 3) {
        exp = (rand() % 9) + 6;
        return exp;
    }
    else if (userLevel == 4) {
        exp = (rand() % 11) + 9;
        return exp;
    }
    else if (userLevel == 5) {
        exp = (rand() % 13) + 12;
        return exp;
    }
    else if (userLevel == 6) {
        exp = (rand() % 13) + 14;
        return exp;
    }
    else if (userLevel == 7) {
        exp = (rand() % 15) + 19;
        return exp;
    }
    else if (userLevel == 8) {
        exp = (rand() % 16) + 22;
        return exp;
    }
    else if (userLevel == 9) {
        exp = (rand() % 18) + 28;
        return exp;
    }
    else if (userLevel == 10) {
        exp = (rand() % 20) + 34;
        return exp;
    }
    else if (userLevel == 11) {
        exp = (rand() % 19) + 37;
        return exp;
    }
    else if (userLevel == 12) {
        exp = (rand() % 21) + 38;
        return exp;
    }
    else if (userLevel == 13) {
        exp = (rand() % 21) + 40;
        return exp;
    }
    else if (userLevel == 14) {
        exp = (rand() % 19) + 49;
        return exp;
    }
    else if (userLevel == 15) {
        exp = (rand() % 20) + 51;
        return exp;
    }
    else if (userLevel == 16) {
        exp = (rand() % 20) + 54;
        return exp;
    }
    else if (userLevel == 17) {
        exp = (rand() % 21) + 56;
        return exp;
    }
    else if (userLevel == 18) {
        exp = (rand() % 22) + 60;
        return exp;
    }
    else if (userLevel == 19) {
        exp = (rand() % 28) + 66;
        return exp;
    }
    else if (userLevel == 20) {
        exp = (rand() % 34) + 78;
        return exp;
    }
    else if (userLevel == 21) {
        exp = (rand() % 36) + 81;
        return exp;
    }
    else if (userLevel == 22) {
        exp = (rand() % 46) + 85;
        return exp;
    }
    else if (userLevel == 23) {
        exp = (rand() % 48) + 86;
        return exp;
    }
    else if (userLevel == 24) {
        exp = (rand() % 55) + 97;
        return exp;
    }
    return 0;
}

int goldGain(int userLevel) {
    srand(time(0));
    int gold;
    if (userLevel == 1) {
        gold = (rand() % 26) + 25;
        return gold;
    }
    else if (userLevel == 2) {
        gold = (rand() % 31) + 40;
        return gold;
    }
    else if (userLevel == 3) {
        gold = (rand() % 41) + 60;
        return gold;
    }
    else if (userLevel == 4) {
        gold = (rand() % 61) + 80;
        return gold;
    }
    else if (userLevel == 5) {
        gold = (rand() % 51) + 110;
        return gold;
    }
    else if (userLevel == 6) {
        gold = (rand() % 71) + 140;
        return gold;
    }
    else if (userLevel == 7) {
        gold = (rand() % 66) + 175;
        return gold;
    }
    else if (userLevel == 8) {
        gold = (rand() % 81) + 200;
        return gold;
    }
    else if (userLevel == 9) {
        gold = (rand() % 101) + 230;
        return gold;
    }
    else if (userLevel == 10) {
        gold = (rand() % 91) + 275;
        return gold;
    }
    else if (userLevel == 11) {
        gold = (rand() % 131) + 320;
        return gold;
    }
    else if (userLevel == 12) {
        gold = (rand() % 141) + 360;
        return gold;
    }
    else if (userLevel == 13) {
        gold = (rand() % 166) + 410;
        return gold;
    }
    else if (userLevel == 14) {
        gold = (rand() % 156) + 470;
        return gold;
    }
    else if (userLevel == 15) {
        gold = (rand() % 171) + 530;
        return gold;
    }
    else if (userLevel == 16) {
        gold = (rand() % 181) + 590;
        return gold;
    }
    else if (userLevel == 17) {
        gold = (rand() % 161) + 680;
        return gold;
    }
    else if (userLevel == 18) {
        gold = (rand() % 171) + 730;
        return gold;
    }
    else if (userLevel == 19) {
        gold = (rand() % 176) + 800;
        return gold;
    }
    else if (userLevel == 20) {
        gold = (rand() % 176) + 875;
        return gold;
    }
    else if (userLevel == 21) {
        gold = (rand() % 251) + 950;
        return gold;
    }
    else if (userLevel == 22) {
        gold = (rand() % 301) + 1000;
        return gold;
    }
    else if (userLevel == 23) {
        gold = (rand() % 501) + 1100;
        return gold;
    }
    else if (userLevel == 24) {
        gold = (rand() % 601) + 1200;
        return gold;
    }
    else if (userLevel == 25) {
        gold = (rand() % 751) + 1250;
        return gold;
    }
    return 0;
}

//1001331 - Displays the Skills of the Swordsman Class
void displaySSkills(int level) {
    int select = -1;
    string proceed;
    while (select != 0) {
        Sleep(1000);
        cout << "Swordman Skills: " << endl << endl;
        if (level < 6) {
            Sleep(250);
            cout << "1 - Slash" << endl;
            Sleep(250);
            cout << "2 - Unlocked at Level 6" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 12" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 12) {
            Sleep(250);
            cout << "1 - Slash" << endl;
            Sleep(250);
            cout << "2 - Healing Strike" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 12" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 17) {
            Sleep(250);
            cout << "1 - Slash" << endl;
            Sleep(250);
            cout << "2 - Healing Strike" << endl;
            Sleep(250);
            cout << "3 - Sacred Swipe" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 23) {
            Sleep(250);
            cout << "1 - Slash" << endl;
            Sleep(250);
            cout << "2 - Healing Strike" << endl;
            Sleep(250);
            cout << "3 - Sacred Swipe" << endl;
            Sleep(250);
            cout << "4 - Triple Slash" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else {
            Sleep(250);
            cout << "1 - Slash" << endl;
            Sleep(250);
            cout << "2 - Healing Strike" << endl;
            Sleep(250);
            cout << "3 - Sacred Swipe" << endl;
            Sleep(250);
            cout << "4 - Triple Slash" << endl;
            Sleep(250); 
            cout << "5 - Counter" << endl;
        }
        cout << endl;
        Sleep(250);
        cout << "Enter the number next to a skill to learn about it. If you want to exit, enter 0." << endl;
        cin >> select;
        cout << endl;

        if (select == 1) {
            Sleep(750);
            cout << "Slash:" << endl;
            Sleep(250);
            cout << "Learnt at Level 1" << endl;
            Sleep(250);
            cout << "MP Cost: 3" << endl;
            Sleep(250);
            cout << "Description: Perform a Slash on the Enemy with the user's Sword.";
            cout << " This attack has an increased chance to land a critical hit." << endl << endl;
            Sleep(250);
            cout << "Enter any character to proceed." << endl;
            cin >> proceed;
            cout << endl;
        }
        if (select == 2) {
            if (level >= 6) {
                Sleep(750);
                cout << "Healing Strike:" << endl;
                Sleep(250);
                cout << "Learnt at Level 6" << endl;
                Sleep(250);
                cout << "MP Cost: 7" << endl;
                Sleep(250);
                cout << "Description: Have your Sword be blessed to restore your health when attacking the enemy." << endl;
                cout << "You will be healed by a portion of the damage done." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 6." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 3) {
            if (level >= 12) {
                Sleep(750);
                cout << "Sacred Swipe:" << endl;
                Sleep(250);
                cout << "Learnt at Level 12" << endl;
                Sleep(250);
                cout << "MP Cost: 10" << endl;
                Sleep(250);
                cout << "Description: Give your sword a mighty touch and swipe at the enemy." << endl;
                cout << "This attack ignores a portion of the enemy's defense." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 12." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 4) {
            if (level >= 17) {
                Sleep(750);
                cout << "Triple Slash:" << endl;
                Sleep(250);
                cout << "Learnt at Level 17" << endl;
                Sleep(250);
                cout << "MP Cost: 15" << endl;
                Sleep(250);
                cout << "Description: Hit the enemy 3 consecutive times, with each slash having slightly more power than" << endl;
                cout << "the one before it. The final slash also has an increased chance to land a critical hit." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 17." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 5) {
            if (level >= 23) {
                Sleep(750);
                cout << "Counter:" << endl;
                Sleep(250);
                cout << "Learnt at Level 23" << endl;
                Sleep(250);
                cout << "MP Cost: 21" << endl;
                Sleep(250);
                cout << "Description: Using your sword, shield the next attack that is coming your way, reducing the damage dealt to the user." << endl;
                cout << "Once attacked, you will retaliate with a counter attack, dealing twice as much damage as you received." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 23." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
    
    }
}

//1004781 - Displays Skills of the Mage Class
void displayMSkills(int level) {
    int select = -1;
    string proceed;
    while (select != 0) {
        Sleep(1000);
        cout << "Mage Skills: " << endl << endl;
        if (level < 5) {
            Sleep(250);
            cout << "1 - Flame Blast" << endl;
            Sleep(250);
            cout << "2 - Unlocked at Level 5" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 12" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 18" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 24" << endl;
        }
        else if (level < 12) {
            Sleep(250);
            cout << "1 - Flame Blast" << endl;
            Sleep(250);
            cout << "2 - Beam Blade" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 12" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 18" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 24" << endl;
        }
        else if (level < 18) {
            Sleep(250);
            cout << "1 - Flame Blast" << endl;
            Sleep(250);
            cout << "2 - Beam Blade" << endl;
            Sleep(250);
            cout << "3 - Freezing Shock" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 18" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 24" << endl;
        }
        else if (level < 24) {
            Sleep(250);
            cout << "1 - Flame Blast" << endl;
            Sleep(250);
            cout << "2 - Beam Blade" << endl;
            Sleep(250);
            cout << "3 - Freezing Shock" << endl;
            Sleep(250);
            cout << "4 - Mega Flame" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 24" << endl;
        }
        else {
            Sleep(250);
            cout << "1 - Flame Blast" << endl;
            Sleep(250);
            cout << "2 - Beam Blade" << endl;
            Sleep(250);
            cout << "3 - Freezing Shock" << endl;
            Sleep(250);
            cout << "4 - Mega Flame" << endl;
            Sleep(250); 
            cout << "5 - Starburst" << endl;
        }
        cout << endl;
        Sleep(250);
        cout << "Enter the number next to a skill to learn about it. If you want to exit, enter 0." << endl;
        cin >> select;
        cout << endl;

        if (select == 1) {
            Sleep(750);
            cout << "Flame Blast:" << endl;
            Sleep(250);
            cout << "Learnt at Level 1" << endl;
            Sleep(250);
            cout << "MP Cost: 4" << endl;
            Sleep(250);
            cout << "Description: Shoot a Small Burst of Flame at the enemy.";
            cout << " This attack has a small chance to inflict a burn." << endl << endl;
            Sleep(250);
            cout << "Enter any character to proceed." << endl;
            cin >> proceed;
            cout << endl;
        }
        if (select == 2) {
            if (level >= 5) {
                Sleep(750);
                cout << "Beam Blade:" << endl;
                Sleep(250);
                cout << "Learnt at Level 5" << endl;
                Sleep(250);
                cout << "MP Cost: 12" << endl;
                Sleep(250);
                cout << "Description: Turn your wand into a sword for the next 3 turns. All basic attacks will" << endl;
                cout << "utilize your magic stat when attacking, rather than your attack stat." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 5." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 3) {
            if (level >= 12) {
                Sleep(750);
                cout << "Freezing Shock:" << endl;
                Sleep(250);
                cout << "Learnt at Level 12" << endl;
                Sleep(250);
                cout << "MP Cost: 22" << endl;
                Sleep(250);
                cout << "Description: Quickly shoot a wave of freezing air at the opponent, dealing damage" << endl;
                cout << "and having a chance to stun the opponent." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 12." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 4) {
            if (level >= 18) {
                Sleep(750);
                cout << "Mega Flame:" << endl;
                Sleep(250);
                cout << "Learnt at Level 18" << endl;
                Sleep(250);
                cout << "MP Cost: 20" << endl;
                Sleep(250);
                cout << "Description: Power up your wand to shoot a large burst of flame at the enemy," << endl;
                cout << "which will deal damage and have an increased chance to burn the enemy." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 18." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 5) {
            if (level >= 24) {
                Sleep(750);
                cout << "Starburst:" << endl;
                Sleep(250);
                cout << "Learnt at Level 24" << endl;
                Sleep(250);
                cout << "MP Cost: 40" << endl;
                Sleep(250);
                cout << "Description: Utilize the power of the sky and cause powerful stars to rain on the enemy." << endl;
                cout << "This attack can hit between 2-4 times, each time dealing damage and healing the user for" << endl;
                cout << "15% of their Max HP." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 24." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
    
    }
}

//1009922 - Display Defender Skills
void displayDSkills(int level) {
    int select = -1;
    string proceed;
    while (select != 0) {
        Sleep(1000);
        cout << "Defender Skills: " << endl << endl;
        if (level < 8) {
            Sleep(250);
            cout << "1 - Defensive Call" << endl;
            Sleep(250);
            cout << "2 - Unlocked at Level 8" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 13" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 22" << endl;
        }
        else if (level < 13) {
            Sleep(250);
            cout << "1 - Defensive Call" << endl;
            Sleep(250);
            cout << "2 - Repair" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 13" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 22" << endl;
        }
        else if (level < 17) {
            Sleep(250);
            cout << "1 - Defensive Call" << endl;
            Sleep(250);
            cout << "2 - Repair" << endl;
            Sleep(250);
            cout << "3 - Body Bash" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 17" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 22" << endl;
        }
        else if (level < 22) {
            Sleep(250);
            cout << "1 - Defensive Call" << endl;
            Sleep(250);
            cout << "2 - Repair" << endl;
            Sleep(250);
            cout << "3 - Body Bash" << endl;
            Sleep(250);
            cout << "4 - Smash Hit" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 22" << endl;
        }
        else {
            Sleep(250);
            cout << "1 - Defensive Call" << endl;
            Sleep(250);
            cout << "2 - Repair" << endl;
            Sleep(250);
            cout << "3 - Body Bash" << endl;
            Sleep(250);
            cout << "4 - Smash Hit" << endl;
            Sleep(250); 
            cout << "5 - Iron Guard" << endl;
        }
        cout << endl;
        Sleep(250);
        cout << "Enter the number next to a skill to learn about it. If you want to exit, enter 0." << endl;
        cin >> select;
        cout << endl;

        if (select == 1) {
            Sleep(750);
            cout << "Defensive Call:" << endl;
            Sleep(250);
            cout << "Learnt at Level 1" << endl;
            Sleep(250);
            cout << "MP Cost: 5" << endl;
            Sleep(250);
            cout << "Description: Increase the user's defense by 35%."; 
            cout << " This defense boost will last for 3 turns." << endl << endl;
            Sleep(250);
            cout << "Enter any character to proceed." << endl;
            cin >> proceed;
            cout << endl;
        }
        if (select == 2) {
            if (level >= 8) {
                Sleep(750);
                cout << "Repair:" << endl;
                Sleep(250);
                cout << "Learnt at Level 8" << endl;
                Sleep(250);
                cout << "MP Cost: 8" << endl;
                Sleep(250);
                cout << "Description: Increase your defense and work on repairs to your armor." << endl;
                cout << "You will be unable to move the next turn, but will be healed for 75% of your max HP." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 8." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 3) {
            if (level >= 13) {
                Sleep(750);
                cout << "Body Bash:" << endl;
                Sleep(250);
                cout << "Learnt at Level 13" << endl;
                Sleep(250);
                cout << "MP Cost: 10" << endl;
                Sleep(250);
                cout << "Description: Jump at the enemy, using all the power in your body." << endl;
                cout << "This attack utilizes your defense stat to deal damage." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 13." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 4) {
            if (level >= 17) {
                Sleep(750);
                cout << "Smash Hit:" << endl;
                Sleep(250);
                cout << "Learnt at Level 17" << endl;
                Sleep(250);
                cout << "MP Cost: 20" << endl;
                Sleep(250);
                cout << "Description: Ram into the opponent with high power and impact, dealing massive damage." << endl;
                cout << "Your defense will be lowered for the next few turns, and you'll be unable to use any" << endl;
                cout << "defense raising moves." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 17." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 5) {
            if (level >= 22) {
                Sleep(750);
                cout << "Iron Guard:" << endl;
                Sleep(250);
                cout << "Learnt at Level 22" << endl;
                Sleep(250);
                cout << "MP Cost: 24" << endl;
                Sleep(250);
                cout << "Description: Fortify your armor with plates of iron." << endl;
                cout << "This doubles your defense stat for the next few turns." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 22." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
    
    }
}
//1007123 - Displays Cleric Skills
void displayCSkills(int level) {
    int select = -1;
    string proceed;
    while (select != 0) {
        Sleep(1000);
        cout << "Cleric Skills: " << endl << endl;
        if (level < 6) {
            Sleep(250);
            cout << "1 - Cure" << endl;
            Sleep(250);
            cout << "2 - Unlocked at Level 6" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 13" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 19" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 13) {
            Sleep(250);
            cout << "1 - Cure" << endl;
            Sleep(250);
            cout << "2 - Draining Blast" << endl;
            Sleep(250);
            cout << "3 - Unlocked at Level 13" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 19" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 19) {
            Sleep(250);
            cout << "1 - Cure" << endl;
            Sleep(250);
            cout << "2 - Draining Blast" << endl;
            Sleep(250);
            cout << "3 - Magic Aid" << endl;
            Sleep(250);
            cout << "4 - Unlocked at Level 19" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else if (level < 23) {
            Sleep(250);
            cout << "1 - Cure" << endl;
            Sleep(250);
            cout << "2 - Draining Blast" << endl;
            Sleep(250);
            cout << "3 - Magic Aid" << endl;
            Sleep(250);
            cout << "4 - Ultra Cure" << endl; 
            Sleep(250);
            cout << "5 - Unlocked at Level 23" << endl;
        }
        else {
            Sleep(250);
            cout << "1 - Cure" << endl;
            Sleep(250);
            cout << "2 - Draining Blast" << endl;
            Sleep(250);
            cout << "3 - Magic Aid" << endl;
            Sleep(250);
            cout << "4 - Ultra Cure" << endl;
            Sleep(250); 
            cout << "5 - Miracle Spell" << endl;
        }
        cout << endl;
        Sleep(250);
        cout << "Enter the number next to a skill to learn about it. If you want to exit, enter 0." << endl;
        cin >> select;
        cout << endl;

        if (select == 1) {
            Sleep(750);
            cout << "Cure:" << endl;
            Sleep(250);
            cout << "Learnt at Level 1" << endl;
            Sleep(250);
            cout << "MP Cost: 4" << endl;
            Sleep(250);
            cout << "Description: Heal the user by 30% of their Maximum HP."; 
            cout << " This has a small chance to critically heal, which heals for 50% Max HP." << endl << endl;
            Sleep(250);
            cout << "Enter any character to proceed." << endl;
            cin >> proceed;
            cout << endl;
        }
        if (select == 2) {
            if (level >= 6) {
                Sleep(750);
                cout << "Draining Blast:" << endl;
                Sleep(250);
                cout << "Learnt at Level 6" << endl;
                Sleep(250);
                cout << "MP Cost: 8" << endl;
                Sleep(250);
                cout << "Description: Throw a blast at your opponent, dealing damage to them." << endl;
                cout << "You will be healed for a portion of the damage done." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 6." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 3) {
            if (level >= 13) {
                Sleep(750);
                cout << "Magic Aid:" << endl;
                Sleep(250);
                cout << "Learnt at Level 13" << endl;
                Sleep(250);
                cout << "MP Cost: 14" << endl;
                Sleep(250);
                cout << "Description: Call in for a Magic Aid to help you in battle." << endl;
                cout << "This will restore your HP and MP." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 13." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 4) {
            if (level >= 19) {
                Sleep(750);
                cout << "Ultra Cure:" << endl;
                Sleep(250);
                cout << "Learnt at Level 19" << endl;
                Sleep(250);
                cout << "MP Cost: 25" << endl;
                Sleep(250);
                cout << "Description: Heal the user for 50% of their max HP." << endl;
                cout << "This has a small chance to critically heal, which heals for 75% Max HP." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 19." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
        if (select == 5) {
            if (level >= 23) {
                Sleep(750);
                cout << "Miracle Spell:" << endl;
                Sleep(250);
                cout << "Learnt at Level 23" << endl;
                Sleep(250);
                cout << "MP Cost: 32" << endl;
                Sleep(250);
                cout << "Description: Use your power to cast a miracle spell at your opponent." << endl;
                cout << "This will deal damage, along with restoring your HP and MP." << endl << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
            else {
                Sleep(750);
                cout << "This skill will be unlocked at Level 23." << endl;
                Sleep(250);
                cout << "Enter any character to proceed." << endl;
                cin >> proceed;
                cout << endl;
            }
        }
    
    }
}

//1005789 - Displays the Shop + Allows Player to Purchase Items from Shop
void displayShop(int level, int& gold, int* currItems) {
    int select = -1;
    string confirm;
    Sleep(1000);
    cout << "Welcome to the Shop! Enter the number next to an item to find out about it!" << endl;
    while (select != 0) {
        cout << endl;
        if (level >= 3) {
            Sleep(250);
            cout << "1 - Basic HP Patch" << endl;
            Sleep(250);
            cout << "2 - Basic MP Patch" << endl;
        }
        if (level >= 5) {
            Sleep(250);
            cout << "3 - Basic HP Patch+" << endl;
        }
        if (level >= 8) {
            Sleep(250);
            cout << "4 - Basic MP Patch+" << endl;
            Sleep(250);
            cout << "5 - Flaming Orb" << endl;
        }
        if (level >= 12) {
            Sleep(250);
            cout << "6 - Mega HP Patch" << endl;
            Sleep(250);
            cout << "7 - Mega MP Patch" << endl;
        }
        if (level >= 16) {
            Sleep(250);
            cout << "8 - Revival Tome" << endl;
        }
        if (level >= 19) {
            Sleep(250);
            cout << "9 - Ultra HP Patch" << endl;
            Sleep(250);
            cout << "10 - Ultra MP Patch" << endl;
        }
        if (level >= 23) {
            Sleep(250);
            cout << "11 - Restoration Bottle" << endl;
            Sleep(250);
            cout << "12 - Stat Booster" << endl;
        }

        Sleep(250);
        cout << "0 - Quit" << endl;
        cout << endl;
        cin >> select;

        if (select == 1 && level >= 3) {
            Sleep(250);
            cout << "Basic HP Patch - Restores 20 HP" << endl;
            Sleep(250);
            cout << "Cost: 200G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[0] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 200) {
                    gold -= 200;
                    currItems[0] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Basic HP Patch. You have " << currItems[0] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 2 && level >= 3) {
            Sleep(250);
            cout << "Basic MP Patch - Restores 10 MP" << endl;
            Sleep(250);
            cout << "Cost: 250G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[1] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 250) {
                    gold -= 250;
                    currItems[1] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Basic MP Patch. You have " << currItems[1] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 3 && level >= 5) {
            Sleep(250);
            cout << "Basic HP Patch+ - Restores 30 HP" << endl;
            Sleep(250);
            cout << "Cost: 325G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[2] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 325) {
                    gold -= 325;
                    currItems[2] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Basic HP Patch+. You have " << currItems[2] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 4 && level >= 8) {
            Sleep(250);
            cout << "Basic MP Patch+ - Restores 20 MP" << endl;
            Sleep(250);
            cout << "Cost: 475G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[3] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 475) {
                    gold -= 475;
                    currItems[3] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Basic MP Patch+. You have " << currItems[3] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 5 && level >= 8) {
            Sleep(250);
            cout << "Flaming Orb - Inflict a Burn on the enemy" << endl;
            Sleep(250);
            cout << "Cost: 675G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[4] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 675) {
                    gold -= 675;
                    currItems[4] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Flaming Orb. You have " << currItems[4] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 6 && level >= 12) {
            Sleep(250);
            cout << "Mega HP Patch - Restores 60 HP" << endl;
            Sleep(250);
            cout << "Cost: 700G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[5] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 700) {
                    gold -= 700;
                    currItems[5] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Mega HP Patch. You have " << currItems[5] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 7 && level >= 12) {
            Sleep(250);
            cout << "Mega MP Patch - Restores 30 MP" << endl;
            Sleep(250);
            cout << "Cost: 850G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[6] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 850) {
                    gold -= 850;
                    currItems[6] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Mega MP Patch. You have " << currItems[6] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 8 && level >= 16) {
            Sleep(250);
            cout << "Revival Tome - Revive yourself with 50% of your max HP if you fall in battle." << endl;
            Sleep(250);
            cout << "Cost: 2500G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[7] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 2500) {
                    gold -= 2500;
                    currItems[7] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Revival Tome. You have " << currItems[7] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 9 && level >= 19) {
            Sleep(250);
            cout << "Ultra HP Patch - Restores 125 HP." << endl;
            Sleep(250);
            cout << "Cost: 1300G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[8] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 1300) {
                    gold -= 1300;
                    currItems[8] += 1;
                    Sleep(250);
                    cout << endl << "You purchased an Ultra HP Patch. You have " << currItems[8] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 10 && level >= 19) {
            Sleep(250);
            cout << "Ultra MP Patch - Restores 60 MP." << endl;
            Sleep(250);
            cout << "Cost: 1600G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[9] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 2500) {
                    gold -= 2500;
                    currItems[7] += 1;
                    Sleep(250);
                    cout << endl << "You purchased an Ultra MP Patch. You have " << currItems[9] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 11 && level >= 23) {
            Sleep(250);
            cout << "Restoration Bottle - Restores 80 HP and removes any negative status conditions." << endl;
            Sleep(250);
            cout << "Cost: 1500G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[10] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 1500) {
                    gold -= 1500;
                    currItems[10] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Restoration Bottle. You have " << currItems[10] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
        if (select == 12 && level >= 23) {
            Sleep(250);
            cout << "Stat Booster - Boosts a chosen stat by 25% for the remainder of a battle." << endl;
            Sleep(250);
            cout << "Cost: 2000G" << endl;
            Sleep(250);
            cout << "Current Owned: " << currItems[11] << endl;
            Sleep(250);
            cout << "User's Gold: " << gold << "G" << endl;
            Sleep(250);
            cout << endl << "Would you like to purchase this item? Type 'y' if yes, or any other character to go back." << endl;
            cin >> confirm;

            if (confirm == "y") {
                if (gold >= 2000) {
                    gold -= 2000;
                    currItems[11] += 1;
                    Sleep(250);
                    cout << endl << "You purchased a Stat Booster. You have " << currItems[11] << " in total." << endl;
                }
                else {
                    Sleep(250);
                    cout << endl << "You do not have enough gold to purchase this item." << endl;
                }
            }
        }
    }
}

void displaySkillTrain(int* stats, int& gold, int* progress, int* added){
    srand(time(0));
    int options[10];
    int statSelect;
    int statUp[5];
    int selected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int count = 0;
    int select;
    int displayInfo = 0;
    Sleep(1000);
    cout << "Welcome to Stat Training! Here you can increase your stats to become stronger in battle!" << endl;
    Sleep(500);
    cout << "The costs to train one of your stats are displayed below." << endl << endl;
    Sleep(500);
    cout << "Which stat would you like to train?" << endl << endl;
    Sleep(250);
    cout << "1 - HP (Current Progress: " << progress[0] << "%) - Cost: " << (1000 + added[0] * 50) << "G" << endl;
    Sleep(250);
    cout << "2 - MP (Current Progress: " << progress[1] << "%) - Cost: " << (1000 + added[1] * 50) << "G" << endl;
    Sleep(250);
    cout << "3 - Attack (Current Progress: " << progress[2] << "%) - Cost: " << (1000 + added[2] * 50) << "G" << endl;
    Sleep(250);
    cout << "4 - Defense (Current Progress: " << progress[3] << "%) - Cost: " << (1000 + added[3] * 50) << "G" << endl;
    Sleep(250);
    cout << "5 - Magic (Current Progress: " << progress[4] << "%) - Cost: " << (1000 + added[4] * 50) << "G" << endl;
    Sleep(250);
    cout << "0 - Quit" << endl << endl;
    Sleep(750);
    cout << "Enter a number (1-5) next to the stat you want to train, or enter '0' to quit." << endl;
    cin >> statSelect;
    cout << endl;
    while (statSelect < 0 || statSelect > 5) {
        cout << "Invalid input. Please input a number between 0-5." << endl;
        cin >> statSelect;
        cout << endl;
    }
    if (statSelect == 0) {
        return;
    }
    if ((statSelect > 0 && statSelect < 6) && gold < (1000 + added[statSelect - 1] * 50)) {
        Sleep(500);
        cout << "You do not have enough gold to participate in stat training." << endl << endl;
        return;
    }
    gold = gold - (1000 + added[statSelect - 1] * 50);
    statSelect = statSelect - 1;

    for (int i = 0; i < 10; i++) {
        options[i] = rand() % 100;
        if (options[i] >= 0 && options[i] <= 39) {
            options[i] = 10;
        }
        else if (options[i] >= 40 && options[i] <= 69) {
            options[i] = 20;
        }
        else if (options[i] >= 70 && options[i] <= 84) {
            options[i] = 25;
        }
        else if (options[i] >= 85 && options[i] <= 94) {
            options[i] = 35;
        }
        else if (options[i] >= 95 && options[i] <= 98) {
            options[i] = 50;
        }
        else if (options[i] == 99) {
            options[i] = 100;
        }
    }

    while (count < 5) {
        if (displayInfo == 0) {
            Sleep(500);
            cout << "Choose a number between 1-10 and you'll gain a certain amount of progress to increasing a stat!" << endl;
            Sleep(250);
            cout << "You can also enter '0' to view the offering rate of the progression." << endl;
            Sleep(250);
            cout << "Once you reach 100% progress, your chosen stat will increase by one point, and the progress bar will reset." << endl;
            Sleep(250);
            cout << "Your progress on a stat will be saved, so don't worry if you do not complete a full bar." << endl;
            displayInfo = 1;
        }
        Sleep(250);
        cout << "You have " << (5 - count) << " choice(s) left." << endl << endl;
        Sleep(500);
        cout << "0 - View Offering Rate" << endl;

        for (int i = 0; i < 10; i++) {
            Sleep(250);
            if (selected[i] == 1) {
                cout << (i+1) << " - +" << options[i] << "% progression" << endl;
            }
            else {
                cout << (i+1) << " - ???" << endl;
            }
        }
        cout << endl;
        cin >> select;

        while (select < 0 || select > 10) {
            Sleep(500);
            cout << "Please input a number between 0-10." << endl;
            cin >> select;
        }
        cout << endl;
        if (select == 0) {
            Sleep(500);
            cout << "Offering Rate: " << endl;
            Sleep(250);
            cout << "40% chance to increase progression by 10%" << endl;
            Sleep(250);
            cout << "30% chance to increase progression by 20%" << endl;
            Sleep(250);
            cout << "15% chance to increase progression by 25%" << endl;
            Sleep(250);
            cout << "10% chance to increase progression by 35%" << endl;
            Sleep(250);
            cout << "4% chance to increase progression by 50%" << endl;
            Sleep(250);
            cout << "1% chance to increase progression by 100%" << endl << endl;
            continue;
        }
        if (selected[select - 1] == 1) {
            Sleep(500);
            cout << "You have already selected this option" << endl;
            continue;
        }
        else {
            Sleep(500);
            cout << "Your progression towards a boost in your stat has increased by " << options[select - 1] << "%" << endl;
            selected[select - 1] = 1;
            progress[statSelect] += options[select - 1];
            if (progress[statSelect] >= 100) {
                Sleep(500);
                cout << "Congrats! Your ";
                if (statSelect == 0) {
                    cout << "HP";
                }
                else if (statSelect == 1) {
                    cout << "MP";
                }
                else if (statSelect == 2) {
                    cout << "Attack";
                }
                else if (statSelect == 3) {
                    cout << "Defense";
                }
                else if (statSelect == 4) {
                    cout << "Magic";
                }
                cout << " stat has increased!" << endl;
                if (statSelect == 0) {
                    cout <<"HP: " << stats[statSelect] << " -> " << (stats[statSelect] + 1) << endl;
                }
                else if (statSelect == 1) {
                    cout <<"MP: " << stats[statSelect] << " -> " << (stats[statSelect] + 1) << endl;
                }
                else if (statSelect == 2) {
                    cout <<"Attack: " << stats[statSelect] << " -> " << (stats[statSelect] + 1) << endl;
                }
                else if (statSelect == 3) {
                    cout <<"Defense: " << stats[statSelect] << " -> " << (stats[statSelect] + 1) << endl;
                }
                else if (statSelect == 4) {
                    cout <<"Magic: " << stats[statSelect] << " -> " << (stats[statSelect] + 1) << endl;
                }
                stats[statSelect] += 1;
                added[statSelect] += 1;
                progress[statSelect] -= 100;
            }
            count++;
        }  
    }

}

void itemDisplay(int* items, int level) {
    Sleep(750);
    cout << "Items: " << endl << endl;
    if (level >= 3) {
        Sleep(250);
        cout << "1 - Basic HP Patch (You have:" << items[0] << ")" << endl;
        Sleep(250);
        cout << "2 - Basic MP Patch (You have:" << items[1] << ")" << endl;
    }
    if (level >= 5) {
        Sleep(250);
        cout << "3 - Basic HP Patch+ (You have:" << items[2] << ")" << endl;
    }
    if (level >= 8) {
        Sleep(250);
        cout << "4 - Basic MP Patch+ (You have:" << items[3] << ")" << endl;
        Sleep(250);
        cout << "5 - Flaming Orb (You have:" << items[4] << ")" << endl;
    }
    if (level >= 12) {
        Sleep(250);
        cout << "6 - Mega HP Patch (You have:" << items[5] << ")" << endl;
        Sleep(250);
        cout << "7 - Mega MP Patch (You have:" << items[6] << ")" << endl;
    }
    if (level >= 16) {
        Sleep(250);
        cout << "8 - Revival Tome (You have:" << items[7] << ")" << endl;
    }
    if (level >= 19) {
        Sleep(250);
        cout << "9 - Ultra HP Patch (You have:" << items[8] << ")" << endl;
        Sleep(250);
        cout << "10 - Ultra MP Patch (You have:" << items[9] << ")" << endl;
    }
    if (level >= 23) {
        Sleep(250);
        cout << "11 - Restoration Bottle (You have:" << items[10] << ")" << endl;
        Sleep(250);
        cout << "12 - Stat Booster (You have:" << items[11] << ")" << endl;
    }
}

//Displays the User's Current Stats, Gold, EXP, Level, and Items
void displayStats(int stats[], int gold, int exp, int level, int* items, int* expNeed) {
    string proceed;
    Sleep(1000);
    cout << "Current Stats:" << endl << endl;
    Sleep(250);
    cout << "Level: " << level << endl;
    Sleep(250);
    cout << "Current Exp: " << exp << endl;
    Sleep(250);
    for (int i = 0; i < 24; i++) {
        if (i == (level - 1)) {
            cout << "Exp Needed to Level Up: " << expNeed[i] << endl;
            break;
        }
    }
    Sleep(250);
    cout << "Gold: " << gold << endl;
    cout << endl;
    Sleep(250);
    cout << "User HP: " << stats[0] << endl;
    Sleep(250);
    cout << "User MP: " << stats[1] << endl;
    Sleep(250);
    cout << "User Attack: " << stats[2] << endl;
    Sleep(250);
    cout << "User Defense: " << stats[3] << endl;
    Sleep(250);
    cout << "User Magic: " << stats[4] << endl << endl;
    if (level >= 3){ 
        itemDisplay(items, level);
    }
    cout << endl << "Enter any key to proceed." << endl;
    cin >> proceed;
}

//Displays the Hub Menu
void displayHub(int level) {
    Sleep(1000);
    cout << "You are in the Hub! Select an option below by inputting a number between 1 and 5." << endl;
    Sleep(250);
    cout << "1 - View Stats" << endl;
    Sleep(250);
    if (level >= 3) {
        cout << "2 - Visit Shop" << endl;
    }
    else {
        cout << "2 - ??????????" << endl;
    }
    Sleep(250);
    if (level >= 7) {
        cout << "3 - Stat Training" << endl;
    }
    else {
        cout << "3 - ??????????" << endl;
    }
    Sleep(250);
    cout << "4 - View Skills" << endl;
    Sleep(250);
    cout << "5 - Fight" << endl;
}

//Displays the Opening Menu
void openMenu() {
    Sleep(500);
    cout << "Select a Class:" << endl << endl;
    Sleep(500);
    cout << "1 - Swordsman" << endl;
    Sleep(250);
    cout << "2 - Mage" << endl;
    Sleep(250);
    cout << "3 - Defender" << endl;
    Sleep(250);
    cout << "4 - Cleric" << endl << endl;
    Sleep(500);
    cout << "Input the number next to the class that you would like to choose." << endl;
}

void tutorialText(int job, int* stats, int* exp) {
    string proceed;
    string option = "0";
    string skillSelect = "0";
    int cstats[5];
    int userDamage;
    int hpRestore = 0;
    int enemyDamage;
    int gainedExp;
    bool activeDef = false;
    int defenseTurns = 0;
    int edefeat = 0;
    int eLevel = 1;
    int estats[] = {20, 5, 8, 3};
    for (int i = 0; i < 5; i++) {
        cstats[i] = stats[i];
    }
    Sleep(1000);
    cout << endl << "Welcome to Command Line Chronicles! ";
    Sleep(400);
    cout << "Before jumping straight" << endl;
    Sleep(400);
    cout << "into the game, let's begin a tutorial to help you get started." << endl;
    Sleep(400);
    cout << "Enter any key to continue." << endl;
    cin >> proceed;
    cout << endl;
    Sleep(500);
    cout << "You chose to be a ";
    if (job == 1) {
        cout << "Swordsman";
    }
    else if (job == 2) {
        cout << "Mage";
    }
    else if (job == 3) {
        cout << "Defender";
    }
    else if (job == 4) {
        cout << "Cleric";
    }
    cout << ", which has these starting stats:" << endl << endl;
    Sleep(250);
    cout << "HP: " << stats[0] << endl;
    Sleep(250);
    cout << "MP: " << stats[1] << endl;
    Sleep(250);
    cout << "Attack: " << stats[2] << endl;
    Sleep(250);
    cout << "Defense: " << stats[3] << endl;
    Sleep(250);
    cout << "Magic: " << stats[4] << endl << endl;
    cout << "Enter any key to continue." << endl;
    cin >> proceed;
    cout << endl << endl;
    Sleep(500);
    cout << "You'll be facing a Level 1 Slime in this tutorial with the";
    cout << " following stats:" << endl << endl;
    Sleep(750);
    cout << "Level 1 Slime:" << endl;
    Sleep(250);
    cout << "HP: 20" << endl;
    Sleep(250);
    cout << "Attack: 5" << endl;
    Sleep(250);
    cout << "Defense: 8" << endl;
    Sleep(250);
    cout << "Magic: 3" << endl << endl;
    Sleep(750);
    cout << "In future fights, the stats of your enemies will be hidden, outside" << endl;
    Sleep(250);
    cout << "of their HP. Note that enemies do not have an MP stat. This means any" << endl;
    Sleep(250);
    cout << "special skills an enemy has do not require MP to use." << endl;
    Sleep(750);
    cout << "Enter any key to continue." << endl;
    cin >> proceed;
    cout << endl;
    Sleep(750);
    cout << "Now with that information covered, let's get into the battle." << endl;
    Sleep(250);
    cout << "Enter any key to proceed." << endl;
    cin >> proceed;
    cout << endl;
    Sleep(2000);
    cout << "Battle Start!" << endl;
    Sleep(500);
    cout << "Enemy: Slime (Level 1)" << endl << endl;
    Sleep(1000);
    cout << "Your Turn:" << endl;
    Sleep(500);
    cout << "What would you like to do?" << endl << endl;
    Sleep(250);
    cout << "1 - Attack" << endl << endl;
    Sleep(250);
    cout << "HP: " << cstats[0] << "/" << stats[0] << endl;
    Sleep(250);
    cout << "MP: " << cstats[1] << "/" << stats[1] << endl;
    Sleep(250);
    cout << "Enemy HP: " << estats[0] << "/20" << endl << endl;
    while (option != "1") {
        Sleep(750);
        cout << "Let's Start by attacking the enemy to lower its HP." << endl;
        Sleep(250);
        cout << "Enter '1' to Attack." << endl;
        cin >> option;
        cout << endl;
    }
    userDamage = attack(cstats[2], estats[2]);
    if (userDamage > 19) {
        userDamage = 19;
    }
    Sleep(1000);
    cout << "You attacked the Enemy! You dealt " << userDamage << " damage!" << endl;
    estats[0] = estats[0] - userDamage;
    cout << endl;
    Sleep(1000);
    cout << "Enemy's Turn:" << endl;
    enemyDamage = attack(estats[1], cstats[3]);
    Sleep(500);
    cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
    cstats[0] = cstats[0] - enemyDamage;
    Sleep(1000);
    cout << "Your Turn:" << endl;
    Sleep(500);
    cout << "What would you like to do?" << endl << endl;
    Sleep(250);
    cout << "1 - Attack" << endl;
    Sleep(250);
    cout << "2 - Skills" << endl << endl;
    Sleep(250);
    cout << "HP: " << cstats[0] << "/" << stats[0] << endl;
    Sleep(250);
    cout << "MP: " << cstats[1] << "/" << stats[1] << endl;
    Sleep(250);
    cout << "Enemy HP: " << estats[0] << "/20" << endl << endl;
    while (option != "2") {
        Sleep(750);
        cout << "In addition to attacking, you can use Skills in battle. Skills can do a wide" << endl;
        Sleep(250);
        cout << "variety of things, like dealing more damage, raising stats, or restoring HP." << endl;
        Sleep(250);
        cout << "Enter '2' to use a Skill." << endl;
        cin >> option;
        cout << endl;
    }
    Sleep(1000);
    cout << "Skills:" << endl << endl;
    Sleep(500);
    if (job == 1) {
        cout << "1 - Slash (MP: 3)" << endl << endl;
    }
    else if (job == 2) {
        cout << "1 - Flame Burst (MP: 4)" << endl << endl;
    }
    else if (job == 3) {
        cout << "1 - Defensive Call (MP: 5)" << endl << endl;
    }
    else if (job == 4) {
        cout << "1 - Cure (MP: 4)" << endl << endl;
    }
    Sleep(500);
    while (skillSelect != "1") {
        cout << "Enter '1' to use your Skill." << endl;
        cin >> skillSelect;
        cout << endl;
    }


    if (job == 1) {
        userDamage = slash(cstats[2], estats[2], 1);
        cstats[1] = cstats[1] - 3;
    }
    else if (job == 2) {
        userDamage = flameBurstTut(cstats[4], estats[2], 1);
        cstats[1] = cstats[1] - 4;
    }
    else if (job == 3) {
        cstats[3] = cstats[3] + defensiveCall(cstats[3]);
        cstats[1] = cstats[1] - 5;
    }
    else if (job == 4) {
        hpRestore = cure(stats[0]);
        cstats[1] = cstats[1] - 4;
        if ((cstats[0] + hpRestore) > stats[0]) {
            hpRestore = stats[0] - cstats[0];
        }
    }

    if (job == 1) {
        Sleep(500);
        cout << "You used Slash! You dealt " << userDamage << " damage!" << endl << endl;
        estats[0] = estats[0] - userDamage;
    }
    if (job == 2) {
        Sleep(500);
        cout << "You used Flame Burst! You dealt " << userDamage << " damage!" << endl << endl;
        estats[0] = estats[0] - userDamage;
    }
    if (job == 3) {
        Sleep(500);
        cout << "You used Defensive Call. Your defense stat has increased." << endl << endl;
        activeDef = true;
        Sleep(1000);
        cout << "Enemy's Turn:" << endl;
        enemyDamage = attack(estats[1], cstats[3]);
        Sleep(500);
        cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
        cstats[0] = cstats[0] - enemyDamage;
        defenseTurns++;
        while (estats[0] > 0) {
            Sleep(1000);
            cout << "Your Turn:" << endl;
            Sleep(500);
            cout << "What would you like to do?" << endl << endl;
            Sleep(250);
            cout << "1 - Attack" << endl;
            Sleep(250);
            cout << "2 - Skills" << endl << endl;
            Sleep(250);
            cout << "HP: " << cstats[0] << "/" << stats[0] << endl;
            Sleep(250);
            cout << "MP: " << cstats[1] << "/" << stats[1] << endl;
            Sleep(250);
            cout << "Enemy HP: " << estats[0] << "/20" << endl << endl;
            cin >> option;
            if (option == "1") {
                userDamage = attack(cstats[2], estats[2]);
                Sleep(1000);
                cout << "You attacked the Enemy! You dealt " << userDamage << " damage!" << endl;
                estats[0] = estats[0] - userDamage;
                if (estats[0] < 1) {
                    break;
                }
                cout << endl;
                Sleep(1000);
                cout << "Enemy's Turn:" << endl;
                enemyDamage = attack(estats[1], cstats[3]);
                Sleep(500);
                cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
                cstats[0] = cstats[0] - enemyDamage;
                if (activeDef == true) {
                    defenseTurns++;
                    if (defenseTurns > 3) {
                        defenseTurns = 0;
                        activeDef == false;
                        cstats[3] = stats[3];
                        Sleep(500);
                        cout << "The effects of your defensive call have ended." << endl;
                    }
                }
            }
            else if (option == "2") {
                Sleep(1000);
                cout << "Skills:" << endl << endl;
                Sleep(500);
                cout << "1 - Defensive Call (MP: 5)" << endl << endl;
                Sleep(250);
                cout << "0 - Back" << endl << endl;
                Sleep(500);
                cout << "What skill would you like to use?" << endl;
                cin >> skillSelect;
                if (skillSelect == "1" && cstats[1] >= 5) {
                    Sleep(500);
                    cout << "You used Defensive Call.";
                    if (defenseTurns != 0) {
                        cout << " It had no effect!" << endl;
                    }
                    
                    else {
                        cstats[3] = cstats[3] + defensiveCall(cstats[3]);
                        cstats[1] = cstats[1] - 5;
                        Sleep(500);
                        cout << " Your defense stat has increased." << endl;
                        activeDef = true;
                    }
                    cout << endl;
                    Sleep(1000);
                    cout << "Enemy's Turn:" << endl;
                    enemyDamage = attack(estats[1], cstats[3]);
                    Sleep(500);
                    cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
                    cstats[0] = cstats[0] - enemyDamage;
                    if (activeDef == true) {
                        defenseTurns++;
                        if (defenseTurns > 3) {
                            defenseTurns = 0;
                            activeDef == false;
                            cstats[3] = stats[3];
                            Sleep(500);
                            cout << "The effects of your defensive call have ended." << endl;
                        }
                    }
                }
                else if (skillSelect == "1" && cstats[1] < 5) {
                    Sleep(500);
                    cout << "You do not have enough MP to use this Skill." << endl;
                    continue;
                }
                if (skillSelect == "0") {
                    continue;
                }
            }
        }
    }
    if (job == 4) {
        Sleep(500);
        cout << "You used Cure! You restored " << hpRestore << " HP." << endl << endl;
        cstats[0] = cstats[0] + hpRestore;
        Sleep(1000);
        cout << "Enemy's Turn:" << endl;
        enemyDamage = attack(estats[1], cstats[3]);
        Sleep(500);
        cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
        cstats[0] = cstats[0] - enemyDamage;
        while (estats[0] > 0) {
            Sleep(1000);
            cout << "Your Turn:" << endl;
            Sleep(500);
            cout << "What would you like to do?" << endl << endl;
            Sleep(250);
            cout << "1 - Attack" << endl;
            Sleep(250);
            cout << "2 - Skills" << endl << endl;
            Sleep(250);
            cout << "HP: " << cstats[0] << "/" << stats[0] << endl;
            Sleep(250);
            cout << "MP: " << cstats[1] << "/" << stats[1] << endl;
            Sleep(250);
            cout << "Enemy HP: " << estats[0] << "/20" << endl << endl;
            cin >> option;
            if (option == "1") {
                userDamage = attack(cstats[2], estats[2]);
                Sleep(1000);
                cout << "You attacked the Enemy! You dealt " << userDamage << " damage!" << endl;
                estats[0] = estats[0] - userDamage;
                if (estats[0] < 1) {
                    break;
                }
                cout << endl;
                Sleep(1000);
                cout << "Enemy's Turn:" << endl;
                enemyDamage = attack(estats[1], cstats[3]);
                Sleep(500);
                cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
                cstats[0] = cstats[0] - enemyDamage;
            }
            else if (option == "2") {
                Sleep(1000);
                cout << "Skills:" << endl << endl;
                Sleep(500);
                cout << "1 - Cure (MP: 4)" << endl;
                Sleep(250);
                cout << "0 - Back" << endl << endl;
                Sleep(500);
                cout << "What skill would you like to use?" << endl;
                cin >> skillSelect;
                if (skillSelect == "1" && cstats[1] >= 4) {
                    hpRestore = cure(stats[0]);
                    cstats[1] = cstats[1] - 4;
                    if ((cstats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - cstats[0];
                    }
                    Sleep(500);
                    cout << "You used Cure! You restored " << hpRestore << " HP." << endl << endl;
                    cstats[0] = cstats[0] + hpRestore;
                    Sleep(1000);
                    cout << "Enemy's Turn:" << endl;
                    enemyDamage = attack(estats[1], cstats[3]);
                    Sleep(500);
                    cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
                    cstats[0] = cstats[0] - enemyDamage;
                }
                else if (skillSelect == "1" && cstats[1] < 4) {
                    Sleep(500);
                    cout << "You do not have enough MP to use this Skill." << endl;
                    continue;
                }
                else if (skillSelect == "0") {
                    continue;
                }
            }
        }
    }

    if (estats[0] < 1) {
        edefeat = 1;
    }

    if (edefeat == 1) {
        Sleep(500);
        cout << "Slime has been defeated. You Win!" << endl;
        gainedExp = 5;
        Sleep(250);
        cout << "You gained " << gainedExp << " experience." << endl << endl;
        *exp = *exp + gainedExp;
    }

    Sleep(1000);
    cout << "Congratulations! You completed the tutorial. Now that you have an idea of how to play," << endl;
    cout << "we're gonna send you to the Hub, where you can continue your adventure!" << endl;
    cout << "Enter any key to proceed to the Hub." << endl;
    cin >> proceed;
    
}

void sSkillsBattle(int level) {
    if (level < 6) {
        Sleep(250);
        cout << "1 - Slash (MP: 3)" << endl;
    }
    else if (level < 12) {
        Sleep(250);
        cout << "1 - Slash (MP: 3)" << endl;
        Sleep(250);
        cout << "2 - Healing Strike (MP: 7)" << endl;
    }
    else if (level < 17) {
        Sleep(250);
        cout << "1 - Slash (MP: 3)" << endl;
        Sleep(250);
        cout << "2 - Healing Strike (MP: 7)" << endl;
        Sleep(250);
        cout << "3 - Sacred Swipe (MP: 10)" << endl;        
    }
    else if (level < 23) {
        Sleep(250);
        cout << "1 - Slash (MP: 3)" << endl;
        Sleep(250);
        cout << "2 - Healing Strike (MP: 7)" << endl;
        Sleep(250);
        cout << "3 - Sacred Swipe (MP: 10)" << endl;
        Sleep(250);
        cout << "4 - Triple Slash (MP: 15)" << endl; 
        }
    else {
        Sleep(250);
        cout << "1 - Slash (MP: 3)" << endl;
        Sleep(250);
        cout << "2 - Healing Strike (MP: 7)" << endl;
        Sleep(250);
        cout << "3 - Sacred Swipe (MP: 10)" << endl;
        Sleep(250);
        cout << "4 - Triple Slash (MP: 15)" << endl;
        Sleep(250); 
        cout << "5 - Counter (MP: 21)" << endl;
    }
    Sleep(250);
    cout << "0 - Back" << endl;
    cout << endl;
}

void mSkillsBattle(int level) {
    if (level < 5) {
        Sleep(250);
        cout << "1 - Flame Burst (MP: 4)" << endl;
    }
    else if (level < 12) {
        Sleep(250);
        cout << "1 - Flame Burst (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Beam Blade (MP: 12)" << endl;
    }
    else if (level < 18) {
        Sleep(250);
        cout << "1 - Flame Burst (MP: 5)" << endl;
        Sleep(250);
        cout << "2 - Beam Blade (MP: 12)" << endl;
        Sleep(250);
        cout << "3 - Freezing Shock (MP: 22)" << endl;        
    }
    else if (level < 24) {
        Sleep(250);
        cout << "1 - Flame Burst (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Beam Blade (MP: 12)" << endl;
        Sleep(250);
        cout << "3 - Freezing Shock (MP: 22)" << endl;
        Sleep(250);
        cout << "4 - Mega Flame (MP: 20)" << endl; 
        }
    else {
        Sleep(250);
        cout << "1 - Flame Burst (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Beam Blade (MP: 12)" << endl;
        Sleep(250);
        cout << "3 - Freezing Shock (MP: 22)" << endl;
        Sleep(250);
        cout << "4 - Mega Flame (MP: 20)" << endl;
        Sleep(250); 
        cout << "5 - Starburst (MP: 40)" << endl;
    }
    Sleep(250);
    cout << "0 - Back" << endl;
    cout << endl;
}

void dSkillsBattle(int level) {
    int select = -1;
    if (level < 8) {
        Sleep(250);
        cout << "1 - Defensive Call (MP: 5)" << endl;
    }
    else if (level < 13) {
        Sleep(250);
        cout << "1 - Defensive Call (MP: 5)" << endl;
        Sleep(250);
        cout << "2 - Repair (MP: 8)" << endl;
    }
    else if (level < 17) {
        Sleep(250);
        cout << "1 - Defensive Call (MP: 5)" << endl;
        Sleep(250);
        cout << "2 - Repair (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Body Bash (MP: 10)" << endl;        
    }
    else if (level < 22) {
        Sleep(250);
        cout << "1 - Defensive Call (MP: 5)" << endl;
        Sleep(250);
        cout << "2 - Repair (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Body Bash (MP: 10)" << endl;
        Sleep(250);
        cout << "4 - Smash Hit (MP: 20)" << endl; 
        }
    else {
        Sleep(250);
        cout << "1 - Defensive Call (MP: 5)" << endl;
        Sleep(250);
        cout << "2 - Repair (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Body Bash (MP: 10)" << endl;
        Sleep(250);
        cout << "4 - Smash Hit (MP: 20)" << endl;
        Sleep(250); 
        cout << "5 - Iron Guard (MP: 24)" << endl;
    }
    Sleep(250);
    cout << "0 - Back" << endl;
    cout << endl;
}

void cSkillsBattle(int level) {
    int select = -1;
    if (level < 6) {
        Sleep(250);
        cout << "1 - Cure (MP: 4)" << endl;
    }
    else if (level < 13) {
        Sleep(250);
        cout << "1 - Cure (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Draining Blast (MP: 8)" << endl;
    }
    else if (level < 19) {
        Sleep(250);
        cout << "1 - Cure (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Draining Blast (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Magic Aid (MP: 14)" << endl;        
    }
    else if (level < 23) {
        Sleep(250);
        cout << "1 - Cure (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Draining Blast (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Magic Aid (MP: 14)" << endl;
        Sleep(250);
        cout << "4 - Ultra Cure (MP: 25)" << endl; 
            
        }
    else {
        Sleep(250);
        cout << "1 - Cure (MP: 4)" << endl;
        Sleep(250);
        cout << "2 - Draining Blast (MP: 8)" << endl;
        Sleep(250);
        cout << "3 - Magic Aid (MP: 14)" << endl;
        Sleep(250);
        cout << "4 - Ultra Cure (MP: 25)" << endl;
        Sleep(250); 
        cout << "5 - Miracle Spell (MP: 32)" << endl;
    }
    Sleep(250);
    cout << "0 - Back" << endl;
    cout << endl;
}

void enemyStats(int* stats, int selection, int level) {
    fstream file("estats.txt");
    string num;
    int stat = 0;

    if (selection == 0) {
        for (int i = 0; i < 4; i++) {
            for (int i = 1; i < 26; i++) {
                file >> num;
                if (i == level) {
                    stats[stat] = stoi(num);
                    stat++;
                }
            }
        }
    }
    if (selection == 1) {
        for (int i = 0; i < 100; i++) {
            file >> num;
        }
        for (int i = 0; i < 4; i++) {
            for (int i = 1; i < 26; i++) {
                file >> num;
                if (i == level) {
                    stats[stat] = stoi(num);
                    stat++;
                }
            }
        }
    }
    if (selection == 2) {
        for (int i = 0; i < 200; i++) {
            file >> num;
        }
        for (int i = 0; i < 4; i++) {
            for (int i = 1; i < 26; i++) {
                file >> num;
                if (i == level) {
                    stats[stat] = stoi(num);
                    stat++;
                }
            }
        }
    }
}

void battle(int* stats, int &level, int* items, int difficulty, int job, int &gold, int &exp, int upStats[], int* expNeed) {
    srand(time(0));
    int eStats[] = {0, 0, 0, 0};
    int eCurrStats[4];
    int currStats[5];
    int* eStatsptr = eStats;
    int eLevel;
    int chosen = (rand() % 3);
    int beamBladeActive = 0;
    int beamBladeTurns = 0;
    int defensiveCallActive = 0;
    int defensiveCallTurns = 0;
    int counterActive = 0;
    int ironGuardActive = 0;
    int ironGuardTurns = 0;
    int repairActive = 0;
    int repairTurns = 0;
    int smashHitActive = 0;
    int smashHitTurns = 0;
    int selection;
    int userDamage;
    int enemyDamage;
    int hpRestore;
    int mpRestore;
    int userBurn = 0;
    int enemyBurn = 0;
    int enemyStun = 0;
    int burned;
    int stunned;
    int starburstHit3 = 0;
    int starburstHit4 = 0;
    int burnDamage;
    double heal;
    int goldGained;
    int expGained;
    string proceed;
    string enemyName[] = {"Slime", "Flaming Spirit", "Living Shield"};
    if (difficulty == 0) {
        eLevel = rand() % 2;
        if (level == 1) {
            eLevel = 1;
        }
        if (level > 1 && level < 26) {
            if (eLevel == 0) {
                eLevel = level - 1;
            }
            else if (eLevel == 1) {
                eLevel = level;
            }
        }
    }
    else if (difficulty == 1) {
        eLevel = rand() % 5;
        if (eLevel != 4) {
            eLevel = eLevel + 1;
        }
        else {
            eLevel = eLevel + 2;
        }
        if (eLevel > 25) {
            eLevel = 25;
        }
    }
    enemyStats(eStatsptr, chosen, eLevel);
    for (int i = 0; i < 4; i++) {
        eCurrStats[i] = eStats[i];
    }
    for (int i = 0; i < 5; i++) {
        currStats[i] = stats[i];
    }
    
    Sleep(2000);
    cout << "Battle Start!" << endl;
    Sleep(250);
    cout << "Enemy: " << enemyName[chosen] << " (Level " << eLevel << ")" << endl << endl;
    while (eCurrStats[0] > 0) {
        Sleep(500);
        cout << "Your Turn: " << endl;
        Sleep(250);
        cout << "What would you like to do?" << endl << endl;
        Sleep(500);
        cout << "1 - Attack" << endl;
        Sleep(250);
        cout << "2 - Skills" << endl;
        if (level >= 3) {
            Sleep(250);
            cout << "3 - Items" << endl;
        }
        else {
            Sleep(250);
            cout << "3 - ?????" << endl;
        }
        Sleep(250);
        cout << "4 - View Stats" << endl << endl;
        Sleep(250);
        cout << "HP: " << currStats[0] << "/" << stats[0] << endl;
        Sleep(250);
        cout << "MP: " << currStats[1] << "/" << stats[1] << endl;
        Sleep(250);
        cout << "Enemy HP: " << eCurrStats[0] << "/" << eStats[0] << endl << endl;
        Sleep(500);
        if (repairActive != 1) {
            cout << "Enter the number next to the option you would like to use." << endl;
            cin >> selection;
            cout << endl;

            while (selection < 1 || selection > 4) {
                Sleep(500);
                cout << "Please enter a number between 1-4 to select an option." << endl;
                cin >> selection;
            }
        }
        else {
            cout << "You are still undergoind repairs and can not move this turn." << endl;
            selection = 0;
        }

        if (selection == 1) {
            if (job == 2 && beamBladeActive != 0) {
                userDamage = attack(currStats[4], eCurrStats[2]);
            }
            else {
                userDamage = attack(currStats[2], eCurrStats[2]);
            }
            Sleep(1000);
            cout << "You attacked the Enemy! You dealt " << userDamage << " damage!" << endl;
            eCurrStats[0] = eCurrStats[0] - userDamage;
            if (eCurrStats[0] < 1) {
                break;
            }
        }
        else if (selection == 2) {
            Sleep(500);
            cout << "Skills: " << endl << endl;
            if (job == 1) {
                sSkillsBattle(level);
            }
            else if (job == 2) {
                mSkillsBattle(level);
            }
            else if (job == 3) {
                dSkillsBattle(level);
            }
            else if (job == 4) {
                cSkillsBattle(level);
            }
            Sleep(500);
            cout << "Which skill would you like to use? (Enter 1-5)" << endl;
            cin >> selection;
            if (selection == 0) {
                continue;
            }
            if (selection < 0 || selection > 5) {
                Sleep(500);
                cout << "Invalid Option" << endl << endl;
            }
            if (selection == 1) {
                if (job == 1) {
                    if (currStats[1] < 3) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = slash(currStats[2], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 3;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Slash! You dealt " << userDamage << " damage!" << endl << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 2) {
                    if (currStats[1] < 4) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = flameBurst(currStats[4], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 4;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Flame Burst! You dealt " << userDamage << " damage!" << endl;
                    burned = (rand() % 10);
                    if (burned == 5 && enemyBurn != 1) {
                        Sleep(250);
                        cout << "The enemy was burned!" << endl << endl;
                        enemyBurn = 1;
                    }
                    else {
                        cout << endl;
                    }
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 3) {
                    if (currStats[1] < 5) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    if (smashHitActive == 1) {
                        cout << endl;
                        Sleep(500);
                        cout << "Your armor is still damaged from a Smash Hit, so this move can not be used." << endl << endl;
                        continue;
                    }
                    if (defensiveCallActive == 1 || ironGuardActive == 1) {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Defensive Call! It had no Effect!" << endl;
                    }
                    else {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Defensive Call! Your defense has increased!" << endl;
                        currStats[3] = currStats[3] + defensiveCall(stats[3]);
                        currStats[1] = currStats[1] - 5;
                        defensiveCallActive = 1;
                    }
                }
                else if (job == 4) {
                    if (currStats[1] < 4) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    hpRestore = cure(stats[0]);
                    currStats[1] = currStats[1] - 4;
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    cout << endl;
                    Sleep(750);
                    cout << "You used Cure! You restored " << hpRestore << " HP!" << endl << endl;
                    currStats[0] = currStats[0] + hpRestore;
                }
            }
            else if (selection == 2) {
                if (job == 1) {
                    if (level < 6) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 7) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = healingStrike(currStats[2], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 7;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Healing Strike! You dealt " << userDamage << " damage!" << endl;
                    hpRestore = healingStrikeHeal(userDamage);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    currStats[0] = currStats[0] + hpRestore;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 2) {
                    if (level < 5) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 12) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    if (beamBladeActive == 1) {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Beam Blade! It had no Effect!" << endl;
                    }
                    else {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Beam Blade! Your magic stat will be used when attacking for the next few turns." << endl << endl;
                        currStats[1] = currStats[1] - 12;
                        beamBladeActive = 1; 
                    }
                }
                else if (job == 3) {
                    if (level < 8) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 8) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    if (smashHitActive == 1) {
                        cout << endl;
                        Sleep(500);
                        cout << "Your armor is still damaged from a Smash Hit, so this move can not be used." << endl << endl;
                        continue;
                    }
                    cout << endl;
                    Sleep(750);
                    cout << "You used Repair! You defend yourself as you repair your armor!" << endl << endl;
                    currStats[3] = currStats[3] + repairDef(stats[3]);
                    currStats[1] = currStats[1] - 8;
                    repairActive = 1;
                }
                else if (job == 4) {
                    if (level < 6) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 8) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = drainingBlast(currStats[4], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 8;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Draining Blast! You dealt " << userDamage << " damage!" << endl;
                    hpRestore = drainingBlastHeal(userDamage);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    currStats[0] = currStats[0] + hpRestore;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
            }
            else if (selection == 3) {
                if (job == 1) {
                    if (level < 12) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 10) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = sacredSwipe(currStats[2], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 10;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Sacred Swipe! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 2) {
                    if (level < 12) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 22) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = freezingShock(currStats[4], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 22;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Freezing Shock! You dealt " << userDamage << " damage!" << endl;
                    stunned = rand() % 5;
                    if (stunned == 2) {
                        Sleep(250);
                        cout << "The enemy was stunned!" << endl << endl;
                        enemyStun = 1;
                    }
                    else {
                        cout << endl;
                    }
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 3) {
                    if (level < 13) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 10) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = bodyBash(currStats[3], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 10;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Body Bash! You dealt " << userDamage << " damage!" << endl << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 4) {
                    if (level < 13) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 14) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    hpRestore = magicAidHeal(stats[0]);
                    mpRestore = magicAidMP(stats[1]);
                    currStats[1] = currStats[1] - 14;
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    if ((currStats[1] + mpRestore) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    cout << endl;
                    Sleep(750);
                    cout << "You used Magic Aid! You restored " << hpRestore << " HP." << endl;
                    Sleep(250);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                    currStats[0] = currStats[0] + hpRestore;
                    currStats[1] = currStats[1] + mpRestore;
                }
            }
            else if (selection == 4) {
                if (job == 1) {
                    if (level < 17) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 15) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = tripleSlashOne(currStats[2], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 15;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Triple Slash! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                    userDamage = tripleSlashTwo(currStats[2], eCurrStats[2], level);
                    Sleep(500);
                    cout << "The attack hit again! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                    userDamage = tripleSlashThree(currStats[2], eCurrStats[2], level);
                    Sleep(500);
                    cout << "The attack hit again! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 2) {
                    if (level < 18) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 20) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = megaFlame(currStats[4], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 20;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Mega Flame! You dealt " << userDamage << " damage!" << endl;
                    burned = (rand() % 5);
                    if (burned == 3 && enemyBurn != 1) {
                        Sleep(250);
                        cout << "The enemy was burned!" << endl << endl;
                    }
                    else {
                        cout << endl;
                    }
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
                else if (job == 3) {
                    if (level < 17) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 20) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    if (smashHitActive == 1) {
                        cout << endl;
                        Sleep(500);
                        cout << "Your armor is still damaged from a previous use of this move, so it can't be used." << endl << endl;
                        continue;
                    }
                    userDamage = smashHit(currStats[3], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 20;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Smash Hit! You dealt " << userDamage << " damage!" << endl;
                    Sleep(500);
                    cout << "Your armor has been damaged by the impact. Your defense has decreased." << endl << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                    if (defensiveCallActive == 1) {
                        Sleep(500);
                        cout << "The effects of your defensive call have ended." << endl << endl;
                        defensiveCallActive = 0;
                        defensiveCallTurns = 0;
                    }
                    if (ironGuardActive == 1) {
                        Sleep(500);
                        cout << "The effects of your iron guard have ended." << endl << endl;
                        ironGuardActive = 0;
                        ironGuardTurns = 0;
                    }
                    currStats[3] = currStats[3] - smashHitDefReduce(stats[3]);
                    smashHitActive = 1;
                }
                else if (job == 4) {
                    if (level < 19) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 25) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    hpRestore = ultraCure(stats[0]);
                    currStats[1] = currStats[1] - 4;
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    cout << endl;
                    Sleep(750);
                    cout << "You used Ultra Cure! You restored " << hpRestore << " HP!" << endl << endl;
                    currStats[0] = currStats[0] + hpRestore;
                }
            }
            else if (selection == 5) {
                if (job == 1) {
                    if (level < 23) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 21) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    currStats[1] = currStats[1] - 21;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Counter!" << endl << endl;
                    counterActive = 1;
                }
                else if (job == 2) {
                    if (level < 24) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 40) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    starburstHit3 = (rand() % 2);
                    starburstHit4 = (rand() % 4);
                    userDamage = starburst(currStats[4], eCurrStats[2], level);
                    currStats[1] = currStats[1] - 40;
                    cout << endl;
                    Sleep(750);
                    cout << "You used Starburst! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    hpRestore = starbustHeal(stats[0]);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(500);
                    cout << "You restored " << hpRestore << " HP." << endl;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                    userDamage = starburst(currStats[4], eCurrStats[2], level);
                    Sleep(500);
                    cout << "The attack hit again! You dealt " << userDamage << " damage!" << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    hpRestore = starbustHeal(stats[0]);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(500);
                    cout << "You restored " << hpRestore << " HP." << endl;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                    if (starburstHit3 == 1) {
                        userDamage = starburst(currStats[4], eCurrStats[2], level);
                        Sleep(500);
                        cout << "The attack hit again! You dealt " << userDamage << " damage!" << endl;
                        eCurrStats[0] = eCurrStats[0] - userDamage;
                        hpRestore = starbustHeal(stats[0]);
                        if ((currStats[0] + hpRestore) > stats[0]) {
                            hpRestore = stats[0] - currStats[0];
                        }
                        Sleep(500);
                        cout << "You restored " << hpRestore << " HP." << endl;
                        if (eCurrStats[0] < 1) {
                            break;
                        }
                        if (starburstHit4 == 2) {
                            userDamage = starburst(currStats[4], eCurrStats[2], level);
                            Sleep(500);
                            cout << "The attack hit again! You dealt " << userDamage << " damage!" << endl;
                            eCurrStats[0] = eCurrStats[0] - userDamage;
                            hpRestore = starbustHeal(stats[0]);
                            if ((currStats[0] + hpRestore) > stats[0]) {
                                hpRestore = stats[0] - currStats[0];
                            }
                            Sleep(500);
                            cout << "You restored " << hpRestore << " HP." << endl;
                            if (eCurrStats[0] < 1) {
                                break;
                            }
                        }
                    }
                }
                else if (job == 3) {
                    if (level < 22) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 24) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    if (smashHitActive == 1) {
                        cout << endl;
                        Sleep(500);
                        cout << "Your armor is still damaged from a Smash Hit, so this move can not be used." << endl << endl;
                        continue;
                    }
                    if (defensiveCallActive == 1 || ironGuardActive == 1) {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Iron Guard! It had no effect!" << endl << endl;
                    }
                    else {
                        cout << endl;
                        Sleep(750);
                        cout << "You used Iron Guard! Your defense has increased!" << endl;
                        currStats[3] = currStats[3] + stats[3];
                        currStats[1] = currStats[1] - 5;
                        defensiveCallActive = 1;
                    }
                }
                else if (job == 4) {
                    if (level < 23) {
                        cout << endl;
                        Sleep(500);
                        cout << "You are not high enough leveled to use this skill yet" << endl << endl;
                        continue;
                    }
                    if (currStats[1] < 32) {
                        cout << endl;
                        Sleep(500);
                        cout << "You do not have enough MP to use this skill." << endl << endl;
                        continue;
                    }
                    userDamage = miracleSpell(currStats[4], eCurrStats[2], level);
                    hpRestore = miracleSpellHeal(userDamage);
                    mpRestore = miracleSpellMP(userDamage);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    if ((currStats[1] + mpRestore) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    Sleep(750);
                    cout << "You used Miracle Spell! You dealt " << userDamage << " damage!" << endl;
                    Sleep(500);
                    cout << "You restored " << hpRestore << " HP." << endl;
                    Sleep(500);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                    eCurrStats[0] = eCurrStats[0] - userDamage;
                    if (eCurrStats[0] < 1) {
                        break;
                    }
                }
            }
        }
        else if (selection == 3) {
            itemDisplay(items, level);
            Sleep(250);
            cout << "0 - Back" << endl << endl;
            Sleep(250);
            cout << "Enter the number next to the item you would like to use." << endl;
            cin >> selection;
            cout << endl;
            while (selection < 0 || selection > 12) {
                Sleep(500);
                cout << "Invalid option, please enter a number between 0-12." << endl;
                cin >> selection;
                cout << endl;
            }
            if (selection == 0) {
                continue;
            }
            if (selection == 1) {
                if (items[0] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Basic HP Patch!" << endl;
                    hpRestore = 20;
                    if ((currStats[0] + 20) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                }
            }
            else if (selection == 2) {
                if (items[1] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Basic MP Patch!" << endl;
                    mpRestore = 10;
                    if ((currStats[1] + 10) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    Sleep(250);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                }
            }
            else if (selection == 3) {
                if (level < 5) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[2] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Basic HP Patch+!" << endl;
                    hpRestore = 30;
                    if ((currStats[0] + 30) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                }
            }
            else if (selection == 4) {
                if (level < 8) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[3] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Basic MP Patch+!" << endl;
                    mpRestore = 20;
                    if ((currStats[1] + 20) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    Sleep(250);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                }
            }
            else if (selection == 5) {
                if (level < 8) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[4] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Basic HP Patch+!" << endl;
                    Sleep(250);
                    cout << "The enemy has been burned!" << endl << endl;
                    enemyBurn = 1;
                }
            }
            else if (selection == 6) {
                if (level < 12) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[5] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Mega HP Patch!" << endl;
                    hpRestore = 60;
                    if ((currStats[0] + 60) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                }
            }
            else if (selection == 7) {
                if (level < 12) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[6] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Mega MP Patch!" << endl;
                    mpRestore = 30;
                    if ((currStats[1] + 30) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    Sleep(250);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                }
            }
            else if (selection == 8) {
                if (level < 16) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                Sleep(500);
                cout << "This item can not be used in battle." << endl << endl;
                continue;
            }
            else if (selection == 9) {
                if (level < 19) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[8] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used an Ultra HP Patch!" << endl;
                    hpRestore = 125;
                    if ((currStats[0] + 125) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                }
            }
            else if (selection == 10) {
                if (level < 19) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[9] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used an Ultra MP Patch!" << endl;
                    mpRestore = 60;
                    if ((currStats[1] + 60) > stats[1]) {
                        mpRestore = stats[1] - currStats[1];
                    }
                    Sleep(250);
                    cout << "You restored " << mpRestore << " MP." << endl << endl;
                }
            }
            else if (selection == 11) {
                if (level < 23) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[10] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "You used a Restoration Bottle!" << endl;
                    hpRestore = 80;
                    if ((currStats[0] + 80) > stats[0]) {
                        mpRestore = stats[0] - currStats[0];
                    }
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl;
                    if (userBurn == 1) {
                        Sleep(250);
                        cout << "Your burn has been cured." << endl << endl;
                        userBurn = 0;
                    }
                    else {
                        cout << endl;
                    }
                }
            }
            else if (selection == 12) {
                if (level < 23) {
                    Sleep(500);
                    cout << "You have not unlocked this item yet." << endl << endl;
                    continue;
                }
                if (items[11] == 0) {
                    Sleep(500);
                    cout << "You do not have any of this item." << endl << endl;
                    continue;
                }
                else {
                    Sleep(500);
                    cout << "Which stat would you like to boost?" << endl << endl;
                    Sleep(250);
                    cout << "1 - Attack" << endl;
                    Sleep(250);
                    cout << "2 - Defense" << endl;
                    Sleep(250);
                    cout << "3 - Magic" << endl;
                    cin >> selection;
                    while (selection < 1 || selection > 3) {
                        cout << endl;
                        Sleep(500);
                        cout << "Invalid Option, please enter a number from 1-3." << endl;
                        cin >> selection;
                    }
                    cout << endl;
                    if (selection == 1) {
                        currStats[2] = currStats[2] + statBoost(stats[2]);
                        Sleep(500);
                        cout << "Your Attack Stat has been boosted." << endl << endl;
                    }
                    else if (selection == 2) {
                        currStats[3] = currStats[3] + statBoost(stats[3]);
                        Sleep(500);
                        cout << "Your Defense Stat has been boosted." << endl << endl;
                    }
                    else if (selection == 3) {
                        currStats[4] = currStats[4] + statBoost(stats[4]);
                        Sleep(500);
                        cout << "Your Magic Stat has been boosted." << endl << endl;
                    }
                }
            }
        }
        else if (selection == 4) {
            Sleep(750);
            cout << "Current Stats: " << endl << endl;
            Sleep(250);
            cout << "HP: " << currStats[0] << endl;
            Sleep(250);
            cout << "MP: " << currStats[1] << endl;
            Sleep(250);
            cout << "Attack: " << currStats[2] << endl;
            Sleep(250);
            cout << "Defense: " << currStats[3] << endl;
            Sleep(250);
            cout << "Magic: " << currStats[4] << endl << endl;
            Sleep(250);
            cout << "Enter any key to continue." << endl;
            cin >> proceed;
            continue;
        }

        Sleep(1000);
        cout << "Enemy's Turn:" << endl;
        if (chosen == 0 || chosen == 2 && enemyStun != 1) {
            enemyDamage = attack(eCurrStats[1], currStats[3]) + eLevel;
            Sleep(500);
            cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl << endl;
            currStats[0] = currStats[0] - enemyDamage;
            if (counterActive == 1) {
                Sleep(500);
                userDamage = counter(enemyDamage);
                cout << "You countered the enemy's attack! You dealt " << userDamage << " damage!" << endl << endl;
                eCurrStats[0] = eCurrStats[0] - userDamage;
                if (eCurrStats[0] < 1) {
                    break;
                }
            }
        }
        else if (chosen == 1 && enemyStun != 1) {
            enemyDamage = attack(eCurrStats[3], currStats[3]);
            Sleep(500);
            cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl;
            currStats[0] = currStats[0] - enemyDamage;
            burned = (rand() % 8);
            if (burned == 4 && userBurn != 1) {
                Sleep(250);
                cout << "You have been burned!" << endl << endl;
                userBurn = 1;
            }
            else {
                cout << endl;
            }
            if (counterActive == 1) {
                Sleep(500);
                userDamage = counter(enemyDamage);
                cout << "You countered the enemy's attack! You dealt " << userDamage << " damage!" << endl << endl;
                eCurrStats[0] = eCurrStats[0] - userDamage;
                if (eCurrStats[0] < 1) {
                    break;
                }
            }
        }
        else if (chosen == 3 && enemyStun != 1) {
            enemyDamage = attack(eCurrStats[3], currStats[3]);
            Sleep(500);
            cout << "The enemy attacks! You took " << enemyDamage << " damage." << endl;
            heal = double(enemyDamage);
            heal = heal / 4;
            hpRestore = int(heal);
            Sleep(250);
            cout << "The enemy restored " << hpRestore << " HP." << endl << endl;
            if (counterActive == 1) {
                Sleep(500);
                userDamage = counter(enemyDamage);
                cout << "You countered the enemy's attack! You dealt " << userDamage << " damage!" << endl << endl;
                eCurrStats[0] = eCurrStats[0] - userDamage;
                if (eCurrStats[0] < 1) {
                    break;
                }
            }
        }
        else if (enemyStun == 1) {
            Sleep(500);
            cout << "The enemy is stunned this turn and can not move!" << endl << endl;
        }

        if (currStats[0] < 1) {
            if (level >= 16 && items[7] > 0) {
                Sleep(1000);
                cout << "You ran out of HP! Luckily, you have a Revival Tome." << endl;
                Sleep(250);
                cout << "Would you like to use a Revival Tome to continue this battle?" << endl;
                Sleep(250);
                cout << "Enter 'y' to use, otherwise enter any other character to end the battle." << endl;
                cin >> proceed;
                if (proceed == "y") {
                    cout << endl;
                    Sleep(500);
                    cout << "You used a Revival Tome! Your HP has been restored!" << endl << endl; 
                    currStats[0] = stats[0] / 2;
                    continue;
                }
                else {
                    cout << endl;
                    Sleep(500);
                    cout << "You were defeated! Better luck next time!" << endl;
                    Sleep(250);
                    cout << "You earned 10G." << endl;
                    gold = gold + 10;
                    Sleep(250);
                    cout << "Enter any character to proceed to the hub." << endl;
                    cin >> proceed;
                    return;
                }
            }
            else {
               cout << endl;
                Sleep(500);
                cout << "You were defeated! Better luck next time!" << endl;
                Sleep(250);
                cout << "You earned 10G." << endl;
                gold = gold + 10;
                Sleep(250);
                cout << "Enter any character to proceed to the hub." << endl;
                cin >> proceed;
                return; 
            }
        }
        else {
            if (defensiveCallActive == 1) {
                defensiveCallTurns++;
                if (defensiveCallTurns == 3) {
                    Sleep(500);
                    cout << "The effects of your defensive call have ended." << endl << endl;
                    currStats[3] = stats[3];
                    defensiveCallTurns = 0;
                    defensiveCallActive = 0;
                }
            }
            if (ironGuardActive == 1) {
                ironGuardTurns++;
                if (ironGuardTurns == 3) {
                    Sleep(500);
                    cout << "The effects of your iron guard have ended." << endl << endl;
                    currStats[3] = stats[3];
                    ironGuardTurns = 0;
                    ironGuardActive = 0;
                }
            }
            if (beamBladeActive == 1) {
                beamBladeTurns++;
                if (beamBladeTurns == 3) {
                    Sleep(500);
                    cout << "The effects of your beam blade have ended." << endl << endl;
                    beamBladeTurns = 0;
                    beamBladeActive = 0;
                }
            }
            if (repairActive == 1) {
                repairTurns++;
                if (repairTurns == 2) {
                    Sleep(500);
                    cout << "Your armor has been repaired!" << endl;
                    hpRestore = 3 * (stats[0] / 4);
                    if ((currStats[0] + hpRestore) > stats[0]) {
                        hpRestore = stats[0] - currStats[0];
                    }
                    currStats[3] = stats[3];
                    Sleep(250);
                    cout << "You restored " << hpRestore << " HP." << endl << endl;
                    repairTurns = 0;
                    repairActive = 0;
                }
            }
            if (smashHitActive == 1) {
                smashHitTurns++;
                if (smashHitTurns == 3) {
                    Sleep(500);
                    cout << "Your armor has been fixed from your Smash Hit!" << endl << endl;
                    currStats[3] = stats[3];
                    smashHitTurns = 0;
                    smashHitActive = 0;
                }
            }
            if (enemyBurn == 1) {
                burnDamage = burn(eStats[0]);
                Sleep(500);
                cout << "The enemy took " << burnDamage << " damage due to its burn." << endl << endl;
                eCurrStats[0] = eCurrStats[0] - burnDamage;
                if (eCurrStats[0] < 1) {
                    break;
                }
            }
            if (userBurn == 1) {
                burnDamage = burn(stats[0]);
                Sleep(500);
                if ((currStats[0] - burnDamage) < 1) {
                    burnDamage = currStats[0] - 1;
                }
                cout << "You took " << burnDamage << " damage due to your burn." << endl << endl;
                currStats[0] = currStats[0] - burnDamage;
            }
        }
    }
    Sleep(1000);
    cout << "The enemy has been defeated. You Win!" << endl;
    goldGained = goldGain(level);
    expGained = expGain(level); 
    if (difficulty == 1) {
        goldGained = goldGained + (goldGained / 5);
        expGained = expGained + (expGained / 5);
    }
    Sleep(500);
    cout << "Rewards: " << endl << endl;
    Sleep(250);
    cout << "Gold: " << goldGained << "G" << endl;
    Sleep(250);
    cout << "Experience: " << expGained << "EXP" << endl << endl;
    gold = gold + goldGained;
    exp = exp + expGained;
    levelUp(exp, level, expNeed, stats, upStats);
    Sleep(500);
    cout << "Enter any key to proceed to the hub." << endl;
    cin >> proceed;
}

int main() {
    enum Job {Blank, Swordsman, Mage, Defender, Cleric};
    int sStats[] = {20, 6, 12, 10, 5};
    int mStats[] = {13, 12, 6, 7, 14};
    int dStats[] = {23, 7, 9, 17, 8};
    int cStats[] = {17, 14, 7, 9, 12};
    int addHP = 0;
    int addMP = 0;
    int addAtk = 0;
    int addDef = 0;
    int addMag = 0;
    int select;
    string selection;
    int userGold = 500;
    int userLevel = 1;
    int userExp = 0;
    int* expptr = &userExp;
    int userStats[5];
    int* userStatsptr = userStats;
    int statProgress[] = {0, 0, 0, 0, 0};
    int* statProgptr = statProgress;
    int statAdd[] = {0, 0, 0, 0, 0};
    int* statAddptr = statAdd;
    int userItems[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int* userItemsptr = userItems;
    int levelUp = 0; //Temp Variable for testing.
    int goldUp = 0; //Temp
    char confirm;
    int difficulty;
    int addSword[120];
    int addMage[120];
    int addDefense[120];
    int addCler[120];
    fstream expFile("exp.txt");
    fstream statsFile("stats.txt");
    int expNeeded[24];
    string fileRead;
    for (int i = 0; i < 24; i++) {
        expFile >> fileRead;
        expNeeded[i] = stoi(fileRead);
    }
    for (int i = 0; i < 120; i++) {
        statsFile >> fileRead;
        addSword[i] = stoi(fileRead);
    }
    for (int i = 0; i < 120; i++) {
        statsFile >> fileRead;
        addMage[i] = stoi(fileRead);
    }
    for (int i = 0; i < 120; i++) {
        statsFile >> fileRead;
        addDefense[i] = stoi(fileRead);
    }
    for (int i = 0; i < 120; i++) {
        statsFile >> fileRead;
        addCler[i] = stoi(fileRead);
    }
    int* expNeededptr = expNeeded;
    Job userJob;
    openMenu();
    cin >> select;

    while (select < 1 || select > 4) {
        cout << endl;
        cout << "Invalid selection, please input a number between 1-4." << endl;
        cin >> select;
    }

    userJob = static_cast<Job>(select);
    cout << endl;
    while (confirm != 'c') {
        if (userJob == Swordsman) {
            Sleep(1000);
            cout << "You Selected: Swordsman. Below are the stats and beginning skill." << endl << endl;
            Sleep(1000);
            cout << "HP: " << sStats[0] << endl;
            Sleep(250);
            cout << "MP: " << sStats[1] << endl;
            Sleep(250);
            cout << "Attack: " << sStats[2] << endl;
            Sleep(250);
            cout << "Defense: " << sStats[3] << endl;
            Sleep(250);
            cout << "Magic: " << sStats[4] << endl << endl;
            Sleep(1000);
            cout << "Level 1 Skill - Slash (MP: 3)" << endl;
            Sleep(500);
            cout << "Description: Perform a Slash on the Enemy with your Sword."; 
            cout << " This attack has an increased chance to land a critical hit." << endl;
            Sleep(500);
            cout << "Would you like to proceed with this class?"; 
            cout << " Type 'c' to confirm, or any other character to return to class selection." << endl;
            cin >> confirm; 
        }
        else if (userJob == Mage) {
            Sleep(1000);
            cout << "You Selected: Mage. Below are the stats and beginning skill." << endl << endl;
            Sleep(1000);
            cout << "HP: " << mStats[0] << endl;
            Sleep(250);
            cout << "MP: " << mStats[1] << endl;
            Sleep(250);
            cout << "Attack: " << mStats[2] << endl;
            Sleep(250);
            cout << "Defense: " << mStats[3] << endl;
            Sleep(250);
            cout << "Magic: " << mStats[4] << endl << endl;
            Sleep(1000);
            cout << "Level 1 Skill - Flame Burst (MP: 4)" << endl;
            Sleep(500);
            cout << "Description: Shoot a Small Burst of Flame at the enemy."; 
            cout << " This attack has a small chance to inflict a burn." << endl;
            Sleep(500);
            cout << "Would you like to proceed with this class?"; 
            cout << " Type 'c' to confirm, or any other character to return to class selection." << endl;            
            cin >> confirm; 
        }
        else if (userJob == Defender) {
            Sleep(1000);
            cout << "You Selected: Defender. Below are the stats and beginning skill." << endl << endl;
            Sleep(1000);
            cout << "HP: " << dStats[0] << endl;
            Sleep(250);
            cout << "MP: " << dStats[1] << endl;
            Sleep(250);
            cout << "Attack: " << dStats[2] << endl;
            Sleep(250);
            cout << "Defense: " << dStats[3] << endl;
            Sleep(250);
            cout << "Magic: " << dStats[4] << endl << endl;
            Sleep(1000);
            cout << "Level 1 Skill - Defensive Call (MP: 5)" << endl;
            Sleep(500);
            cout << "Description: Increase the user's defense by 35%."; 
            cout << " This defense boost will last for 3 turns." << endl;
            Sleep(500);
            cout << "Would you like to proceed with this class?"; 
            cout << " Type 'c' to confirm, or any other character to return to class selection." << endl;
            cin >> confirm; 
        }
        else if (userJob == Cleric) {
            Sleep(1000);
            cout << "You Selected: Cleric. Below are the stats and beginning skill." << endl << endl;
            Sleep(1000);
            cout << "HP: " << cStats[0] << endl;
            Sleep(250);
            cout << "MP: " << cStats[1] << endl;
            Sleep(250);
            cout << "Attack: " << cStats[2] << endl;
            Sleep(250);
            cout << "Defense: " << cStats[3] << endl;
            Sleep(250);
            cout << "Magic: " << cStats[4] << endl << endl;
            Sleep(1000);
            cout << "Level 1 Skill - Cure (MP: 4)" << endl;
            Sleep(500);
            cout << "Description: Heal the user by 30% of their Maximum HP."; 
            cout << " This has a small chance to critically heal, which heals for 50% Max HP." << endl;
            Sleep(500);
            cout << "Would you like to proceed with this class?"; 
            cout << " Type 'c' to confirm, or any other character to return to class selection." << endl;
            cin >> confirm; 
        }

        if (confirm != 'c') {
            cout << endl;
            openMenu();
            cin >> select;
            userJob = static_cast<Job>(select);
            cout << endl;
        }
    }

    if (userJob == Swordsman) {
        for (int i = 0; i < 5; i++) {
            userStats[i] = sStats[i];
        }
    }
    else if (userJob == Mage) {
        for (int i = 0; i < 5; i++) {
            userStats[i] = mStats[i];
        }
    }
    else if (userJob == Defender) {
        for (int i = 0; i < 5; i++) {
            userStats[i] = dStats[i];
        }
    }
    else if (userJob == Cleric) {
        for (int i = 0; i < 5; i++) {
            userStats[i] = cStats[i];
        }
    }

    
    Sleep(500);
    cout << "If you would like to partake in the tutorial, type '0'. Otherwise, type any other character." << endl;
    cin >> selection;
    if (selection == "0") {
        tutorialText(select, userStatsptr, expptr);
    }
    else {
        cout << endl;
        userExp += 5;
    }
    
    

    while (selection != "8") {
        cout << endl;
        displayHub(userLevel);
        cin >> selection;
        cout << endl;
        if (selection == "1") {
            displayStats(userStats, userGold, userExp, userLevel, userItemsptr, expNeededptr);
        }
        else if (selection == "2") {
            if (userLevel >= 3) {
                displayShop(userLevel, userGold, userItemsptr);
            }
            else {
                Sleep(500);
                cout << "This has not yet been unlocked." << endl;
            }
        }
        else if (selection == "3") {
            if (userLevel >= 7) {
                displaySkillTrain(userStatsptr, userGold, statProgptr, statAddptr);
            }
            else {
                Sleep(500);
                cout << "This has not yet been unlocked." << endl; 
            }
        }
        else if (selection == "4") {
            if (userJob == Swordsman) {
                displaySSkills(userLevel);
            }
            if (userJob == Mage) {
                displayMSkills(userLevel);
            }
            if (userJob == Defender) {
                displayDSkills(userLevel);
            }
            if (userJob == Cleric) {
                displayCSkills(userLevel);
            }
        }
        else if (selection == "5") {
            Sleep(500);
            cout << "Which difficulty would you like to battle in?" << endl << endl;
            Sleep(250);
            cout << "0 - Normal" << endl;
            Sleep(250);
            if (userLevel >= 10) {
                cout << "1 - Hard" << endl;
            }
            else {
                cout << "1 - ??????" << endl;
            }
            Sleep(250);
            cout << "2 - Back" << endl;
            cin >> difficulty;
            if (difficulty == 1 && userLevel < 10) {
                Sleep(500);
                cout << "You can not partake in that difficulty of battle yet." << endl;
                continue;
            }
            if (difficulty == 2) {
                continue;
            }
            if (userJob == 1) {
                battle(userStatsptr, userLevel, userItemsptr, difficulty, userJob, userGold, userExp, addSword, expNeededptr);
            }
            else if (userJob == 2) {
                battle(userStatsptr, userLevel, userItemsptr, difficulty, userJob, userGold, userExp, addMage, expNeededptr);
            }
            else if (userJob == 3) {
                battle(userStatsptr, userLevel, userItemsptr, difficulty, userJob, userGold, userExp, addDefense, expNeededptr);
            }
            else if (userJob == 4) {
                battle(userStatsptr, userLevel, userItemsptr, difficulty, userJob, userGold, userExp, addCler, expNeededptr);
            }
            
        }
        else if (selection == "6") {
            cout << "Increase Level By How Much?" << endl;
            cin >> levelUp;
            userLevel = userLevel + levelUp;
        }
        else if (selection == "7") {
            cout << "Increase Gold By How Much?" << endl;
            cin >> goldUp;
            userGold = userGold + goldUp;
        }
        else {
            Sleep(500);
            cout << "Invalid Option, please enter a different selection." << endl;
        }

    }

    return 0;
}
