#include "StringCheck.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delayText(std::string inputText) {
    int wait = 0;
    for (int i = 0; i < inputText.size(); i++) {
        std::cout << inputText.at(i) << std::flush;
        if ((inputText.at(i) == '?' ) || (inputText.at(i) == '!' ) || (inputText.at(i) == '.' ) || (inputText.at(i) == ',' ) || (i == (inputText.size() - 1))) {
            Sleep(20);
        } else {
            Sleep(5);
        }
    }
}

int charLength(char input[]) {
    int l = 0;
    while (input[l] != '\0') {
        ++l;
    }
    return l;
}

std::vector<std::string> alphabetize(std::vector<std::string> toBeAlpha) {
    std::vector<std::string> output = toBeAlpha;
    int i = 0;
    int l = 0;
    int last = toBeAlpha.size() - 1;
    bool swap = 0;
    //std::cout << "alphabetization begun. last = " << last << "i = " << i << std::endl;
    while ((i + 1 <= last) && !swap) {
        //std::cout << "while loop entered." << std::endl;
        l = 0;
        while ((l < toBeAlpha.at(i).size()) && (l < toBeAlpha.at(i + 1).size())) {
            if (toBeAlpha.at(i)[l] == toBeAlpha.at(i + 1)[l]) {
                ++l;
                continue;
            } else if (toBeAlpha.at(i)[l] > toBeAlpha.at(i + 1)[l]) {
                //std::cout << "swap found for" << toBeAlpha.at(i + 1) << " and " << toBeAlpha.at(i) << "... ";
                output.erase(output.begin() + i + 1);
                output.insert(output.begin() + i, toBeAlpha.at(i + 1));
                swap = true;
                //std::cout << "swap made." << std::endl;
            }
            break;
        }
        i++;
    }
    //std::cout << "finished swap" << std::endl;
    if (swap) {
        return alphabetize(output);
    }
    return output;
}

bool iterDigit(char input[]) {
    int i = 0;
    bool good = true;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            good = false;
        }
        ++i;
    }
    return good;
}

bool iterDecDigit(char input[]) {
    int i = 0;
    int count = 0;
    bool good = true;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            if ((count > 1) || (input[i] != '.')) {
                good = false;
            }
            else {
                count += 1;
            }
        }
        ++i;
    }
    return good;
}

bool iterAlpha(char input[]) {
    int i = 0;
    bool good = true;
    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            ++i;
        }
        else {
            good = false;
        }
    }
    
    return good;
}


int GetIntNum(int min, int max) {
    bool deliver = false;
    int fInput = 0;
    char Cinput[1000];
    do {
        std::cin >> Cinput;
        if (iterDigit(Cinput)) {
            fInput = atoi(Cinput);
            if ((min <= fInput) && (fInput <= max)) {
                deliver = true;
            }
        }
        if (deliver == false) {
                std::cout << "Provide a valid integer between " << min << " and " << max << std::endl;
        }
    } while (deliver == false);
    return fInput;
}

double GetAnyDec(int min, int max) {
    bool deliver = false;
    double fInput = 0;
    char Cinput[100];
    do {
        std::cin >> Cinput;
        if (iterDecDigit(Cinput)) {
            fInput = atof(Cinput);
            if (min <= fInput <= max) {
                deliver = true;
            }
        }
        if (deliver == false) {
                std::cout << "Provide a valid decimal number between " << min << " and infinity." << std::endl;
            }
    } while (deliver == false);
    
    return fInput;
}
