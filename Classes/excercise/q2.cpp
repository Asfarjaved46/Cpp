#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Name_pairs {
private:
    vector<string> name;
    vector<double> age;

public:
    void read_names() {
        int n;
        cout << "How many names? ";
        cin >> n;

        string temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            name.push_back(temp);
        }
    }

    void read_ages() {
        double a;

        for (int i = 0; i < name.size(); i++) {
            cout << "Age of " << name[i] << ": ";
            cin >> a;
            age.push_back(a);
        }
    }

    void sort_pairs() {
        for (int i = 0; i < name.size() - 1; i++) {
            for (int j = 0; j < name.size() - i - 1; j++) {
                if (name[j] > name[j + 1]) {

                    string tempName = name[j];
                    name[j] = name[j + 1];
                    name[j + 1] = tempName;

                    double tempAge = age[j];
                    age[j] = age[j + 1];
                    age[j + 1] = tempAge;
                }
            }
        }
    }

    friend ostream& operator<<(ostream& os, const Name_pairs& np);

    friend bool operator==(const Name_pairs& a,
                           const Name_pairs& b);

    friend bool operator!=(const Name_pairs& a,
                           const Name_pairs& b);
};