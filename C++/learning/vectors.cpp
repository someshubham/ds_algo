#include <iostream>
#include <vector>

using namespace std;

// Vector is a dynamic array
// can grow and shrink in size based on req.

int main()
{

    // How to create and init a vector
    vector<int> a;

    vector<int> b(5, 10); // five int with value 10

    vector<int> c(b.begin(), b.end());

    vector<int> d{1, 2, 3, 10, 14};

    // Iterating over a vector

    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }

    cout << endl;

    for (auto it = b.begin(); it != b.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;

    for (int x : d)
    {
        cout << x << " ";
    }

    cout << endl;

    // Functions for vectors

    vector<int> v;
    int n;
    cin >> n;
    // push_back
    // 1 . Insert the element at the back
    // 2 . Expand the memory of the vector
    // Note : Doubling of memory is expensive
    // Avoid doubling of memory
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }

    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Memory lvl difference

    cout << v.size() << endl;
    cout << v.capacity() << endl; // size of the underlying array
    cout << v.max_size() << endl; // max no of elements a vector can store in the worst case

    // Removes the last element O(1)
    d.pop_back();

    // Insert in the middle of the vector

    d.insert(d.begin() + 3, 100); // Add one 100 at index 3

    d.insert(d.begin() + 3, 4, 200); // Add 4 200s at index 3

    // Erase

    d.erase(d.begin() + 3);                // Will remove one 200
    d.erase(d.begin() + 3, d.begin() + 5); // Remove a range

    //We avoid the shrink opn
    d.resize(8);

    // Remove all the elements , does not free up the memory though
    d.clear();

    if (d.empty())
    {
        cout << "Empty" << endl;
    }

    cout << v.front() << endl; // Return the first element
    cout << v.back() << endl;  // Return the last element

    // Reserve
    int n;
    cin >> n;

    vector<int> v;

    // This will prevent the doubling and copying process
    // Until it reaches 1000
    v.reserve(1000);

    return 0;
}