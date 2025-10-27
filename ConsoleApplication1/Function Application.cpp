#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    int n, a, b, step;
    double y, x;

    string results;

    cout << "Input n > 1, n = ";
    cin >> n;
    cout << "Input a, a = ";
    cin >> a;
    cout << "Input b > a, b = ";
    cin >> b;
    cout << "Input step > 0, step = ";
    cin >> step;

    for (x = a; x <= b; x += step) {
        double mlt = 1, sum = 0;
        if (x < -2) {
            for (int i = 0; i <= n + 3; i++) {
                for (int j = 0; j <= n; j++) {
                    sum += pow(i + x - j, 2);
                };
            };

            y = sum;
        }
        else if (x >= -2) {
            for (int j = 1; j <= n; j++) {
                mlt *= (7 * x - j);
            }
            for (int j = 1; j <= n; j++) {
                sum += ((j + 2) / pow(j, 2));
            }
            y = (mlt - 6 * x * sum);
        };

        cout << "x = " << x << ";  " << "y = " << y << ";" << endl;

        results += "x = " + to_string(x) + ";  y = " + to_string(y) + ";\n";

    };

    string answer;

    cout << "Do you need to save the result in the file? (Yes, no) " << endl << "Your answer: ";
    cin >> answer;

    if (answer == "yes" || answer == "Yes") {
        char* userProfile = nullptr;
        size_t len = 0;

        if (_dupenv_s(&userProfile, &len, "USERPROFILE") != 0 || userProfile == nullptr) {
            cerr << "Could not get USERPROFILE environment variable!" << endl;
            return 1;
        }

        string desktopPath = string(userProfile) + "\\Desktop\\results.txt";

        ofstream fout(desktopPath);
        if (!fout) {
            cerr << "Error: could not open file!" << endl;
            return 1;
        }

        fout << results << endl;
        fout.close();

        cout << "Results successfully saved to " << desktopPath << endl;

        free(userProfile);
    }

    string repeat;
    cout << "Do you want to run the program again? (yes/no): ";
    cin >> repeat;

    if (repeat == "yes" || repeat == "Yes") {
        main();
    }
    else {
        system("exit");
    }

    return 0;
}

