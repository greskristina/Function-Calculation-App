#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <conio.h> 
#include <cstdlib> 

using namespace std;

//Check of Input

void checkValidPressOne(int value) {
    if (cin.fail() || value != 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input correct data!";
    }
}

void checkInputOfN(int n) {
    if (cin.fail() || n <= 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input correct data!";
    }
}

void checkInputOfA(double a) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input correct data!";
    }
}

void checkInputOfB(double a, double b) {
    if (cin.fail() || b <= a) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input correct data! (b > a)";
    }
}

void checkInputOfStep(double step) {
    if (cin.fail() || step <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw "Input correct data";
    }
}

double functionCalculations(int n, double step, double a, double b) {
    double x, y;
    string results;
    for (x = a; x <= b; x += step) {
        double mlt = 1, sum = 0;

        if (x < -2) {
            for (int i = 0; i <= n + 3; i++) {
                for (int j = 0; j <= n; j++) {
                    sum += pow(i + x - j, 2);
                }
            }
            y = sum;
        }
        else {
            for (int j = 1; j <= n; j++) {
                mlt *= (7 * x - j);
            }
            for (int j = 1; j <= n; j++) {
                sum += ((j + 2) / pow(j, 2));
            }
            y = (mlt - 6 * x * sum);
        }


        cout << "x = " << x << ";  y = " << y << ";\n";
        results += "x = " + to_string(x) + ";  y = " + to_string(y) + ";\n";
    }
    return y;
}


int saveResultsMenu(const string options[], int size) {
    int choice = 0;
    while (true) {
        system("cls");

        cout << "---------------------------------------------\n";
        cout << "             Save results menu               \n";
        cout << "---------------------------------------------\n";
        cout << "Do you want to save results in the file?\n";

        for (int i = 0; i < size; i++) {
            if (i == choice)
                cout << "[x] " << options[i] << endl;
            else
                cout << "[ ] " << options[i] << endl;
        }
        cout << "Select and press ENTER to continue.\n";

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && choice > 0) choice--;
            else if (key == 80 && choice < size - 1) choice++;
        }
        else if (key == 13) {
            return choice;
        }
    }
}

int finalMenu(const string options[], int size) {
    int choice = 0;
    while (true) {
        system("cls");

        cout << "---------------------------------------------\n";
        cout << "                 Final Menu                  \n";
        cout << "---------------------------------------------\n";
        cout << "Do you want to delete data and start again?\n";

        for (int i = 0; i < size; i++) {
            if (i == choice)
                cout << "[x] " << options[i] << endl;
            else
                cout << "[ ] " << options[i] << endl;
        }
        cout << "Select and press ENTER to continue.\n";

        int key = _getch();
        if (key == 224) {
            key = _getch();
            if (key == 72 && choice > 0) choice--;
            else if (key == 80 && choice < size - 1) choice++;
        }
        else if (key == 13) {
            return choice;
        }
    }
}


int calculateFunction() {
    int n;
    double a, b, y, x, step;
    string results;

    // Welcome screen

    try {
        int press;

        cout << "\n---------------------------------------------\n";
        cout << "         Function Calculation App             \n";
        cout << "---------------------------------------------\n";
        cout << "Welcome to the function calculation application.\n";
        cout << "Press 1 to start input of data.\n";

        cout << "\nYour answer: ";
        cin >> press;
        checkValidPressOne(press);

        cin.ignore();
        system("cls");

        //Input screen

        cout << "---------------------------------------------\n";
        cout << "                Input of Data                 \n";
        cout << "---------------------------------------------\n";

        cout << "\nInput n > 1, n = ";
        cin >> n;
        checkInputOfN(n);

        cout << "\nInput a, a = ";
        cin >> a;
        checkInputOfA(a);

        cout << "\nInput b > a, b = ";
        cin >> b;
        checkInputOfB(a, b);

        cout << "\nInput step > 0, step = ";
        cin >> step;
        checkInputOfStep(step);
    

        cin.ignore();
        cout << "\nWe got your input. Press ENTER to see results...";
        cin.get();

        // Results

        system("cls");

        cout << "---------------------------------------------\n";
        cout << "          Results of the Function             \n";
        cout << "---------------------------------------------\n";

        functionCalculations(n, step, a, b);

    }
    catch (const char* ex) {
        cout << ex << endl;
        return -1;
    }
    catch (...) {
        cout << "Unknown error" << endl;
        return -2;
    }

    cout << "\nPress ENTER to continue...";
    cin.get();

    // Save results menu

    string saveOptions[] = { "Yes", "No" };
    int saveChoice = saveResultsMenu(saveOptions, 2);

    if (saveChoice == 0) {
        char* userProfile = nullptr;
        size_t len = 0;
        _dupenv_s(&userProfile, &len, "USERPROFILE");
        string desktopPath = string(userProfile) + "\\Desktop\\results.txt";
        ofstream fout(desktopPath);
        fout << results << endl;
        fout.close();
        free(userProfile);

        cout << "\nYour results are successfully saved.\n";
        cout << "Press ENTER to continue...";
        cin.get();
    }

    // Final menu

    string finalOptions2[] = { "Yes", "No" };
    int restartChoice = finalMenu(finalOptions2, 2);

    if (restartChoice == 0) {
        cin.get();
        calculateFunction();
    }
    else {
        cout << "\nExiting program...\nGoodbye!\n";
        system("exit");
    }

    return 0;
}

int main() {
    calculateFunction();
    return 0;
}
