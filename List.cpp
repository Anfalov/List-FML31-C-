#include<iostream>

using namespace std;

struct Node{
    int Value;
    Node* Left;
    Node* Right;
    Node(int value, Node* left, Node* right)
    {
        Value = value;
        Left = left;
        Right = right;
    }
    Node()
    {
        Value = 0;
        Left = Right = NULL;
    }
};

struct List {
    int size;
    Node* Begin;
    Node* End;
    Node* RBegin;
    Node* REnd;

    List()
    {
        size = 0;
        End = new Node;
        End -> Left = End;
        End -> Right = End;
        Begin = RBegin = REnd = End;
    }

    void Insert(Node* it, int value)
    {
        Node* cur = new Node(value, it->Left, it);
        it->Left->Right = cur;
        it->Left = cur;
        if (it == Begin)
            Begin = cur;
        if (it == End)
            RBegin = cur;
        size++;
    }

    Node* Erase(Node* it)
    {
        if (it == End)
            throw exception();
        it->Left->Right = it->Right;
        it->Right->Left = it->Left;
        if (it == Begin)
            Begin = it->Right;
        if (it == RBegin)
            RBegin = it->Left;
        Node* nxt = it->Right;
        delete it;
        size--;
        return nxt;
    }

    int Size()
    {
        return size;
    }

    Node* Find(int value)
    {
        for (auto it = Begin; it != End; it = it->Right)
            if (it->Value == value)
                return it;
        return End;
    }

    ~List()
    {
        Node* nxt = Begin->Right;
        for (auto it = Begin; it != End; it = nxt)
        {
            nxt = it -> Right;
            delete it;
        }
    }
};

int main()
{
    List li;
    li.Insert(li.Begin, 12);
    li.Insert(li.Begin, 13);
    li.Insert(li.End, 14);
    li.Insert(li.RBegin, 15);
    li.Insert(li.Begin->Right, 16);
    for (auto it = li.Begin; it != li.End; it = it->Right)
        cout << it->Value << " ";
    cout << endl;
    li.Erase(li.Begin->Right);
    li.Erase(li.Begin);
    for (auto it = li.Begin; it != li.End; it = it->Right)
        cout << it->Value << " ";
    cout << endl;
    if (li.Find(15) != li.End)
        cout << "Yes";
    else
        cout << "No";
}





