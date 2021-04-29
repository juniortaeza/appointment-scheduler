/*
* Author : Heginio Jr Taeza
* GitHub @ juniortaeza
*/

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int Data;
    string S;
    Node* Left;
    Node* Right;

    Node(int data, string str) { Data = data; S = str; Left = nullptr; Right = nullptr; }
    Node(int data, string str, Node* l, Node* r) { Data = data; S = str; Left = l; Right = r; }
};

class BT {
protected:
    Node* Root = NULL;
public:
    void insert(int data, string s) {
        insert(data, s, Root);
    }

    Node* remove(int data, string s) {
        return remove(data, s, Root);
    }

    bool contains(int data, string s) {
        return contains(data, s, Root);
    }

    void printTree() {
        printTree(Root);
    }

private:
    void insert(int data, string s, Node*& n) {
        if (Root == NULL)
            Root = new Node(data, s);
        else if (data < n->Data) {
            if (n->Left != NULL)
                insert(data, s, n->Left);
            else
                n->Left = new Node(data, s);
        }
        else if (data > n->Data) {
            if (n->Right != NULL)
                insert(data, s, n->Right);
            else
                n->Right = new Node(data, s);
        }      
    }

    Node* remove(int data, string s, Node*& n) {
        if (n == NULL)
            return n;
        else if (data < n->Data)
            n->Left = remove(data, s, n->Left);
        else if (data > n->Data)
            n->Right = remove(data, s, n->Right);
        else if (n->Left != NULL && n->Right != NULL) {
            n->Data = findMin(n->Right);
            remove(n->Data, n->S, n->Right);
        }
        else {
            if (n->Left != NULL)
                n = n->Left;
            else
                n = n->Right;
        }
        return n;
    }

    bool contains(int data, string s, Node*& n) {
        if (n == NULL)
            return false;
        else if (data < n->Data)
            return contains(data, s, n->Left);
        else if (data > n->Data)
            return contains(data, s, n->Right);
        else
            return true;
    }

    int findMin(Node*& n) {
        if (n->Left == NULL)
            return n->Data;
        else
            return findMin(n->Left);
    }

    void printTree(Node*& n) {
        if (n != NULL) {
            cout << n->Data << " - " << n->S << endl;
            printTree(n->Left);
            printTree(n->Right);
        }
    }
};

class Menu {
public:
    void menu() {
        cout << "A) Insert to Calendar" << endl;
        cout << "B) Show Calendar" << endl;
        cout << "C) Remove from Calendar" << endl;
        cout << "D) Search Calendar" << endl;
        cout << "Q) Exit Program" << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    BT bt;
    Menu p;
    bool program_running = true;
    int d;
    string str;
    char menu_choice;

    while (program_running) {
        p.menu();
        cin >> menu_choice;
        if (menu_choice - 32 == 'A' || menu_choice == 'A') {
            cout << "Enter Both Urgency Level and Appointment Name" << endl;
            cin >> d >> str;
            
            bt.insert(d, str);
        }
        else if (menu_choice - 32 == 'B' || menu_choice == 'B') {
            bt.printTree();
        }
        else if (menu_choice - 32 == 'C' || menu_choice == 'C') {
            cout << "Enter Both Urgency Level and Appointment Name" << endl;
            cin >> d >> str;
            if (bt.contains(d, str))
                bt.remove(d, str);
            else
                cout << "Non-existing Appointment" << endl;
        }
        else if (menu_choice - 32 == 'D' || menu_choice == 'D') {
            cout << "Enter Both Urgency Level and Appointment Name" << endl;
            cin >> d >> str;
            if (bt.contains(d, str) == true) {
                cout << "Appointment Found!" << endl;
                cout << d << " - " << str << endl;
            }
            else
                cout << "Appointment Not Found" << endl;
        }
        else if (menu_choice - 32 == 'Q' || menu_choice == 'Q') {
            program_running = false;
        }
    }
    cout << "Program exited successfully" << endl;

    return 0;
}