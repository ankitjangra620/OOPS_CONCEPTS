#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Node
{
public:
    int value;
    int key;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }

    // This const will be used to call the function by set.
    void display() const
    {
        cout << "Val  =  " << value << "    " << key << endl;
    }

    // Equality operator for comparing nodes
    bool operator==(const Node &other) const
    {
        return key == other.key && value == other.value;
    }

    // Less-than operator for ordering nodes
    bool operator<(const Node &other) const
    {
        return key < other.key;
    }
};

template <typename T>
void renderContainers(T x)
{
    typename T::iterator it;

    cout << "The list data values are as follows = ";

    it = x.begin();
    while (it != x.end())
    {
        it->display();
        ++it;
    }
    cout << endl;
}

int main()
{
    // This is a doubly linked list
    list<Node> linkList;

    for (auto i : {0, 1})
    {
        cout << "Provide the key and value = " << endl;
        int x, y;
        cin >> x >> y;

        linkList.push_back(Node(x, y));
    }

    renderContainers(linkList);

    set<Node> setData;

    for (auto i : {0, 1, 2, 3})
    {
        cout << "Provide the value = ";
        int x, y;
        cin >> x >> y;

        setData.insert(Node(x,y));
    }

    renderContainers(setData);

    multiset<Node> multiSetData;

    for (auto i : {0, 1})
    {
        cout << "Provide the value = ";
        int x, y;
        cin >> x >> y;

        multiSetData.insert(Node(x, y));
    }

    renderContainers(multiSetData);

    pair<int, int> val;
    val.first = 10;
    val.second = 20;

    cout << "THe Pair is as shown below : " << val.first << "  " << val.second << endl;

    map<Node, int> mapData;

    for (auto i : {0, 1})
    {
        cout << "Provide the value = ";
        int x, y;
        cin >> x >> y;

        mapData.insert(pair<Node, int>(Node(x, y), i));
    }

    map<Node, int>::iterator it = mapData.begin();

    while (it != mapData.end())
    {
        cout << "  " << it->second << "  ";
        it->first.display();
        ++it;
    }

    // Ṭhe multimap just sorts down the list
    multimap<int, Node> multimapData;

    for (auto i : {1, 0})
    {
        cout << "Provide the value = ";
        int x, y;
        cin >> x >> y;

        multimapData.insert(pair<int, Node>(i, Node(x, y)));
    }

    multimap<int, Node>::iterator itr = multimapData.begin();

    while (itr != multimapData.end())
    {
        cout << "  " << itr->first << "  ";
        itr->second.display();
        ++itr;
    }

    // renderContainers(mapData);

    return 0;
}
