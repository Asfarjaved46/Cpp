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
            cout << "Enter name " << i + 1 << ": ";
            cin >> temp;
            name.push_back(temp);
        }
    }

    void read_ages() {
        double temp_age;

        for (int i = 0; i < name.size(); i++) {
            cout << "Enter age for " << name[i] << ": ";
            cin >> temp_age;
            age.push_back(temp_age);
        }
    }

    void sort_pairs() {
        for (int i = 0; i < name.size() - 1; i++) {
            for (int j = 0; j < name.size() - i - 1; j++) {
                if (name[j] > name[j + 1]) {
                    // Swap names
                    string temp_name = name[j];
                    name[j] = name[j + 1];
                    name[j + 1] = temp_name;

                    // Swap corresponding ages
                    double temp_age = age[j];
                    age[j] = age[j + 1];
                    age[j + 1] = temp_age;
                }
            }
        }
    }

    void print() {
        cout << "\nName-Age Pairs:\n";

        for (int i = 0; i < name.size(); i++) {
            cout << "(" << name[i] << ", " << age[i] << ")" << endl;
        }
    }
};

int main() {
    Name_pairs np;

    np.read_names();
    np.read_ages();

    cout << "\nBefore Sorting:\n";
    np.print();

    np.sort_pairs();

    cout << "\nAfter Sorting:\n";
    np.print();

    return 0;
}