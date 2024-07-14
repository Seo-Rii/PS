#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person
{
    int age;
    string name;

    bool operator<(const Person& p) const
    {
        return age < p.age;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<Person> v(n);
    for (auto& i : v) cin >> i.age >> i.name;
    stable_sort(v.begin(), v.end());
    for (auto& i : v) cout << i.age << ' ' << i.name << '\n';
}
