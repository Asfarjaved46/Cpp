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

                    // Swap ages
                    double temp_age = age[j];
                    age[j] = age[j + 1];
                    age[j + 1] = temp_age;
                }
            }
        }
    }

    friend ostream& operator<<(ostream& os,
                               const Name_pairs& np);

    friend bool operator==(const Name_pairs& a,
                           const Name_pairs& b);

    friend bool operator!=(const Name_pairs& a,
                           const Name_pairs& b);
};

ostream& operator<<(ostream& os,
                    const Name_pairs& np)
{
    for (int i = 0; i < np.name.size(); i++) {
        os << "("
           << np.name[i]
           << ", "
           << np.age[i]
           << ")\n";
    }

    return os;
}

bool operator==(const Name_pairs& a,
                const Name_pairs& b)
{
    return a.name == b.name &&
           a.age == b.age;
}

bool operator!=(const Name_pairs& a,
                const Name_pairs& b)
{
    return !(a == b);
}

int main() {
    Name_pairs p1, p2;

    cout << "Enter data for first object:\n";
    p1.read_names();
    p1.read_ages();
    p1.sort_pairs();

    cout << "\nEnter data for second object:\n";
    p2.read_names();
    p2.read_ages();
    p2.sort_pairs();

    cout << "\nFirst Object:\n";
    cout << p1;

    cout << "\nSecond Object:\n";
    cout << p2;

    if (p1 == p2)
        cout << "\nThe objects are equal.\n";
    else
        cout << "\nThe objects are not equal.\n";

    if (p1 != p2)
        cout << "operator!= returns true.\n";
    else
        cout << "operator!= returns false.\n";

    return 0;
}