#include <iomanip>
#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <cstring>
#include <cmath>

#include <cstdlib>
#include <stdlib.h>
#include "StringCheck.h"
#include "Cons.h"

using namespace std;
// to run: g++ -o test Cons.cpp WishSim.cpp StringCheck.cpp

int allWishes = 0;

void newPull(string n, bool t, bool s, vector<Cons>& account) {
    bool isCon = false;
    for (int i = 0; i < account.size(); i++) {
        if (n == account.at(i).getName()) {
            account.at(i).addCons();
            isCon = true;
        }
    }
    if (!isCon) {
        Cons item(n, t, s);
        account.push_back(item);
    }
}

float getMoney(vector<Cons> account, int wishTotal) {
    float money = 0.00;
    int starGlitter = 0;
    int primo = 0;
    for (int i = 0; i < account.size(); i++) {
        if (account.at(i).getStars()) {
            starGlitter += (account.at(i).getCons() * 10) + (account.at(i).getOverCons() * 25);
        }
    }
    for (int i = 0; i < account.size(); i++) {
        if (!account.at(i).getStars() && account.at(i).getType()) {
            starGlitter += (account.at(i).getCons() * 2) + (account.at(i).getOverCons() * 5);
        }
    }
    for (int i = 0; i < account.size(); i++) {
        if ((!account.at(i).getStars() && !account.at(i).getType())) {
            starGlitter += (account.at(i).getCons() * 2) + (account.at(i).getOverCons() * 2);
        }
    }
    primo = 160 * (wishTotal - (starGlitter / 5));
    //cout << endl << "wish total: " << wishTotal << endl << "primo total: " << primo << endl << "starglitter total: " << starGlitter << endl;
    money += ((primo / 6480) * 99.99);
    money += (((primo % 6480) / 3280) * 49.99);
    money += ((((primo % 6480) % 3280) / 1980) * 29.99);
    money += (((((primo % 6480) % 3280) % 1980) / 980) * 14.99);
    money += ((((((primo % 6480) % 3280) % 1980) % 980) / 300) * 4.99);
    money += (((((((primo % 6480) % 3280) % 1980) % 980) % 300) / 60) * 0.99);
    return money;
}

template <typename T>
void wish(vector<T> banner, vector<T> FourStars, vector<T> FourWepons, vector<T> ThreeWepons, vector<T> FiveOff, vector<Cons>& account, int& fourPity, int& fivePity) {
    srand (time(0));
    vector<string> results;
    int wishes = 0;
    int sesWishes = 0;
    int wishProb;
    bool fiveFifty = 0;
    bool fourFifty = 0;
    while (true) {
        cout << endl << "Please enter the amount of wishes you would like to do. You can perform up to 90 pulls at ` time. To exit, enter 0." << endl;
        wishes = GetIntNum(0, 90);
        if (wishes == 0) {
            break;
        }
        for (int i = 0; i < wishes; i++) {
            wishProb = rand() % 1000;
            if ((fivePity < 75) && (fourPity < 9)) {
                 //cout << "   here 0 ";
                if (wishProb < 6) {
                    if ((fiveFifty == 1) || (rand() % 2) == 1) {
                        results.push_back(banner.at(0));
                        fiveFifty = 0;
                    } else {
                        results.push_back(FiveOff.at(rand() % FiveOff.size()));
                        fiveFifty = 1;
                    }
                    newPull(results.at(results.size() - 1),1,1,account);
                    fivePity = 0;
                    fourPity++;
                } else if (wishProb < 51) {
                    if ((fourFifty == 1) || (rand() % 2) == 1) {
                        results.push_back(banner.at((rand() % 3) + 1));
                        newPull(results.at(results.size() - 1),1,0,account);
                        fourFifty = 0;
                    } else {
                        if ((rand() % 2) == 1) {
                            results.push_back(FourWepons.at(rand() % FourWepons.size()));
                            newPull(results.at(results.size() - 1),0,0,account);
                        } else {
                            string fourOff; 
                            do {
                                fourOff = FourStars.at(rand() % (FourStars.size() - 1));
                            } while ((fourOff == banner.at(1)) || (fourOff == banner.at(2)) || (fourOff == banner.at(3)));
                            results.push_back(fourOff);
                            newPull(fourOff,1,0,account);
                            fourFifty = 1;
                        }
                    fourFifty = 1;
                    }
                    fourPity = 0;
                    fivePity++;
                } else {
                    results.push_back(".");//ThreeWepons.at(rand() % ThreeWepons.size());
                    fourPity++;
                    fivePity++;
                }
            } else if ((fivePity < 89) && (fourPity < 9)) { //Soft Pity
                //cout << "   here 1 ";
                if (wishProb < 206) {
                    if ((fiveFifty == 1) || (rand() % 2) == 1) {
                        results.push_back(banner.at(0));
                        fiveFifty = 0;
                    } else {
                        results.push_back(FiveOff.at(rand() % FiveOff.size()));
                        fiveFifty = 1;
                    }
                    newPull(results.at(results.size() - 1),1,1,account);
                    // cout << "   here 0";
                    fivePity = 0;
                    fourPity++;
                } else if (wishProb < 51) {
                    
                    if ((fourFifty == 1) || (rand() % 2) == 1) {
                        results.push_back(banner.at((rand() % 3) + 1));
                        newPull(results.at(results.size() - 1),1,0,account);
                        // cout << "   here 1";
                        fourFifty = 0;
                    } else {
                        if ((rand() % 2) == 1) {
                            results.push_back(FourWepons.at(rand() % FourWepons.size()));
                            newPull(results.at(results.size() - 1),0,0,account);
                            // cout << "   here 2";
                        } else {
                            string fourOff; 
                            do {
                                fourOff = FourStars.at(rand() % (FourStars.size() - 1));
                            } while ((fourOff == banner.at(1)) || (fourOff == banner.at(2)) || (fourOff == banner.at(3)));
                            results.push_back(fourOff);
                            newPull(fourOff,1,0,account);
                            // cout << "   here 3";
                            fourFifty = 1;
                        }
                    fourFifty = 1;
                    }
                    fourPity = 0;
                    fivePity++;
                } else {
                    results.push_back(".");//ThreeWepons.at(rand() % ThreeWepons.size());
                    fourPity++;
                    fivePity++;
                }
            } else if (fivePity == 89){ //Hard pity
                //cout << "   here 3 ";
                if ((fiveFifty == 1) || (rand() % 2) == 1) {
                    results.push_back(banner.at(0));
                    fiveFifty = 0;
                } else {
                    results.push_back(FiveOff.at(rand() % FiveOff.size()));
                    fiveFifty = 1;
                }
                newPull(results.at(results.size() - 1),1,1,account);
                fivePity = 0;
                fourPity++;
            } else {
                //cout << "   here 4 ";
                if ((fourFifty == 1) || (rand() % 2) == 1) {
                    results.push_back(banner.at((rand() % 3) + 1));
                    fourFifty = 0;
                    newPull(results.at(results.size() - 1),1,0,account);

                } else {
                    if ((rand() % 2) == 1) {
                        results.push_back(FourWepons.at(rand() % FourWepons.size()));
                        newPull(results.at(results.size() - 1),0,0,account);

                    } else {
                        string fourOff; 
                        do {
                            fourOff = FourStars.at(rand() % (FourStars.size() - 1));
                        } while ((fourOff == banner.at(1)) || (fourOff == banner.at(2)) || (fourOff == banner.at(3)));
                        results.push_back(fourOff);
                        newPull(fourOff,1,0,account);

                    }
                    fourFifty = 1;
                }
                fourPity = 0;
                fivePity++;
            }
            cout << (i + sesWishes + 1);
            delayText(" - " + results.at(results.size() - 1));
            cout << "     " << fourPity << " " << fivePity << " " << endl;
        }
        results = {};
        sesWishes += wishes;
        allWishes += wishes;
        delayText("\n5-Star Rate-Up: " + banner.at(0) + "\n" + "4-Star Rate-Ups: " + banner.at(1) + ", " + banner.at(2) + ", " + banner.at(3) + "\n\n");
        delayText("You have spent at least $");
        cout << getMoney(account, allWishes);
        delayText(" and your account contains:\n\n");
        for (int j = 6; j >= 0; j--) {
            for (int i = 0; i < account.size(); i++) {
                if ((account.at(i).getStars()) && (account.at(i).getCons() == j)) {
                    cout << "C" << account.at(i).getCons() << " " << account.at(i).getName() << endl;
                }
            }
        }
        cout << endl;
        for (int j = 6; j >= 0; j--) {
            for (int i = 0; i < account.size(); i++) {
                if (!account.at(i).getStars() && account.at(i).getType() && (account.at(i).getCons() == j)) {
                    cout << "C" << account.at(i).getCons() << " " << account.at(i).getName() << endl;
                }
            }
        }
        cout << endl;
        for (int j = 5; j >= 0; j--) {
            for (int i = 0; i < account.size(); i++) {
                if (!account.at(i).getStars() && !account.at(i).getType() && (account.at(i).getCons() == j)) {
                    cout << "R" << account.at(i).getCons() + 1 << " " << account.at(i).getName() << endl;
                }
            }
        }
    }
}

template <typename T> 
void makeBanner(vector<T> FourStars, vector<T> FiveStars, vector<T>& userBanner) {
    srand (time(NULL));
    
    string userInput;
    int userFourStar = -1;
    
    cout << "Would you like to design your own banner?" << endl << endl;
    while ((userInput != "y") && (userInput != "n")) {
        cout << "Please answer y/n" << endl;
        cin >> userInput;
    }
    
    if (userInput == "y") {
        cout << endl << "Please give the number of the 5 star character you want on your banner." << endl << endl;
        for (int i = 0; i < FiveStars.size(); i++) {
            cout << (i + 1) << " - " << FiveStars.at(i) << endl;
        }
        userBanner.push_back(FiveStars.at(GetIntNum(1, FiveStars.size()) - 1));
        cout << "You have created a new " << userBanner.at(0) << " rate-up banner! " << endl << endl;
        
        while (userBanner.size() < 4) {
            cout << "Please select the number of a four star character you want on your banner." << endl << endl;
            for (int i = 0; i < FourStars.size(); i++) {
                    cout << (i + 1) << " - " << FourStars.at(i) << endl;
            }
            userFourStar = GetIntNum(1, FourStars.size());
            userBanner.push_back(FourStars.at(userFourStar - 1));
            FourStars.erase (FourStars.begin() + (userFourStar - 1));
        }
    } else {
        cout << endl;
        userBanner.push_back(FiveStars.at((rand() % FiveStars.size() - 1)));
        cout << endl;
        int num;
        cout << endl;
        while (userBanner.size() < 4) {
            num = (rand() % (FourStars.size() - 1));
            userBanner.push_back(FourStars.at(num));
            FourStars.erase (FourStars.begin() + num);
        }
    }
    cout << "Your banner is complete!" << endl << endl;
    delayText("5-Star Rate-Up: " + userBanner.at(0) + "\n" + "4-Star Rate-Ups: " + userBanner.at(1) + ", " + userBanner.at(2) + ", " + userBanner.at(3) + "\n");
    
}

int main() {
    int userInput;
    int fourStarPity = 0;
    int fiveStarPity = 0;
    vector<string> ThreeStarWepons = {"Black Tassel", "Bloodtainted Greatsword", "Cool Steal", "Thrilling Tales of Dragon Slayers", "Debate Club", "Magic Guide", "Harbinger of Dawn", "Slingshot", "Raven Bow", "Halberd", "Ferrous Shadow", "Skyrider Sword", "Emerald Orb", "Sharpshooter's Oath"};
    vector<string> FourStarWepoons = {"Rainslasher", "The Widsith", "The Bell", "The Flute", "The Stringless", "Sacrificial Sword", "Sacrificial Greatsword", "Sacrificial Fragments", "Sacrificial Bow", "Rust", "Favonius Codex", "Favonius Lance", "Favonius Warbow", "Favonius Greatsword", "Eye of Perception", "Dragon's Bane", "Lion's Roar"};
    vector<string> FourStarChar = alphabetize({"Kaveh", "Yaoyao", "Layla", "Faruzan", "Mika", "Candace", "Barbara", "Beidou", "Bennet", "Chongyun", "Collei", "Diona", "Dori", "Fischl", "Gorou", "Kujou Sara", "Kuki Shinobu", "Ningguang", "Noelle", "Razor", "Rosaria", "Sayu", "Shikanoin Heizou", "Sucrose", "Thoma", "Xiangling", "Xingqiu", "Xinyan", "Yanfei", "Yun Jin"});
    vector<string> FiveStarChar = alphabetize({"Baizhu", "Cyno", "Nilou", "Nahida", "Wanderer", "Alhaithem", "Albedo", "Arataki Itto", "Eula", "Ganyu", "Hu Tao", "Kaedehara Kazuha", "Kamisato Ayaka", "Kamisato Ayato", "Klee", "Raiden Shogun", "Sangonomiya Kokomi", "Shenhe", "Tartaglia", "Venti", "Yelan", "Yoimiya", "Yae Miko", "Xiao", "Zhongli"});
    vector<string> FiveStarCharOff = alphabetize({"Keqing", "Mona", "Qiqi", "Diluc", "Jean", "Tighnari", "Dehya"});
    
    vector<string> userBanner;
    vector<Cons> userAccount;
    
    makeBanner(FourStarChar, FiveStarChar, userBanner);
    while (true) {
        cout << endl << "Would you like to wish now, or make a different banner?\n1:Wish.\n2:Make different banner.\n3:Reset account.\n4:Exit wish simulator." << endl;
        userInput = GetIntNum(1,4);
        if (userInput == 2) {
            userBanner.erase (userBanner.begin(),userBanner.begin() + userBanner.size());
            makeBanner(FourStarChar, FiveStarChar, userBanner);
        } else if (userInput == 1) {
            wish(userBanner, FourStarChar, FourStarWepoons, ThreeStarWepons, FiveStarCharOff, userAccount, fourStarPity, fiveStarPity);
        } else if (userInput == 3) {
            userAccount.erase(userAccount.begin(),userAccount.begin() + (userAccount.size()));
            fourStarPity = 0;
            fiveStarPity = 0;
            allWishes = 0;
        } else {
            break;
        }
    }
    

    
    return 0;
}