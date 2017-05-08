#include <iostream>
#include <math.h>

void plagboad(char *text, bool isReflected) {
    if (isReflected == false) {
            //std::cout << *text << " to " ;
            switch (*text) {
                case 'a':
                    *text = 'a';
                    break;
                case 'b':
                    *text = 'b';
                    break;
                case 'c':
                    *text = 'd';
                    break;
                case 'd':
                    *text = 'c';
                    break;
                default:
                    *text = '0';
                    break;
            }
            //std::cout << *text << std::endl;
        } else {
            //std::cout << *text << " to ";
            switch (*text) {
                case 'a':
                    *text = 'a';
                    break;
                case 'b':
                    *text = 'b';
                    break;
                case 'c':
                    *text = 'd';
                    break;
                case 'd':
                    *text = 'c';
                    break;
                default:
                    *text = '0';
                    break;
            }
        //std::cout << *text << std::endl;
    }
}


void rotor(char *text, int i, int times, bool isReflected) {
    int caseFalse[4] = {2, -1, 1, -2};
    int caseTrue[4] = {1, 2, -2, -1};
    i = i / pow(4, times);

    if (isReflected == false) {
        //std::cout << "i = " << i << std::endl;


        //std::cout << *text << " to ";
        switch (*text) {
            case 'a':
                *text += caseFalse[(0 + i) % 4];
                break;
            case 'b':
                *text += caseFalse[(1 + i) % 4];
                break;
            case 'c':
                *text += caseFalse[(2 + i) % 4];
                break;
            case 'd':
                *text += caseFalse[(3 + i) % 4];
                break;
            default:
                *text = '0';
                break;
        }
        //std::cout << *text << std::endl;

        if (*text < 'a') {
            *text = 'd' - (('a' - 1) - *text);
        } else if (*text > 'd') {
            *text = 'a' + (*text - ('d' + 1));

        }
        //std::cout << *text << std::endl;
    } else {
        //std::cout << "i = " << i << std::endl;
        //std::cout << *text << " to ";
        switch (*text) {
            case 'a':
                *text += caseTrue[(0 + i) % 4];
                break;
            case 'b':
                *text += caseTrue[(1 + i) % 4];
                break;
            case 'c':
                *text += caseTrue[(2 + i) % 4];
                break;
            case 'd':
                *text += caseTrue[(3 + i) % 4];
                break;
            default:
                *text = '0';
                break;
        }
        if (*text < 'a') {
            *text = 'd' - (('a' - 1) - *text);
        } else if (*text > 'd') {
            *text = 'a' + (*text - ('d' + 1));
        }
        //std::cout << *text << std::endl;
    }

}


void reflector(char *text, bool* isReflected) {
    if (*isReflected == false) {
        //std::cout << *text << " to " ;
        switch (*text) {
            case 'a':
                *text = 'd';
                break;
            case 'b':
                *text = 'c';
                break;
            case 'c':
                *text = 'b';
                break;
            case 'd':
                *text = 'a';
                break;
            default:
                *text = '0';
                break;
        }
        //std::cout << *text << std::endl;
        *isReflected = true;
    }
}

char enigma(char text, int i) {
    bool isReflected = false;
    plagboad(&text, isReflected);
    rotor(&text, i, 0, isReflected);
    rotor(&text, i, 1, isReflected);
    rotor(&text, i, 2, isReflected);
    reflector(&text, &isReflected);
    rotor(&text, i, 2, isReflected);
    rotor(&text, i, 1, isReflected);
    rotor(&text, i, 0, isReflected);
    plagboad(&text, isReflected);
    return text;
}

int main() {
    char plain = '0';
    char cipher = '0';
    int i = 0;
    while (1) {
        std::cin >> plain;
        cipher = enigma(plain, i);
        std::cout << cipher << std::endl;
        //std::cout << i << std::endl;
        i++;
    }
    return 0;
}
