#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

struct ListNode
{
    string letter;
    string num;
    ListNode *next;
};

void append(ListNode *&h, string l, string n);
void addInOrder(ListNode *&h, string l, string n);
void printList(ListNode *h, int &lengthOfFile);
void deleteNode(ListNode *&h, string l, string n);
void deleteList(ListNode *&h);

int main()
{
    string letter;
    string num;
    string lines;
    int lengthOfFile = 0;
    const string FILENAME = "file link";
    ifstream inFile(FILENAME);

    /*if (inFile)
    {
        while (getline( inFile, lines ))
        {
            lengthOfFile++;
            cout << "Hello...1" << endl;
        }
    }*/
    ListNode *head = nullptr;

    if (inFile)
    {
        string line;
        for (int lineNum = 1; getline(inFile, line); lineNum++)
        {
            stringstream ss(line);
            string word;

            for (int wordNum = 1; ss >> word; wordNum++)
            {

                if (wordNum == 1)
                {
                    char c = word[0];

                    if (isalpha(c))
                    {
                        cout << "letter: " << c << endl;
                        letter = c;
                    }
                    else if (word == "!" or word == ".")
                    {
                        cout << "letter: " << word << endl;
                        letter = word;
                    }
                    else if (word != "!" or word != ".")
                    {
                        cout << "letter: " << "  " << endl;
                        cout << "number: " << word << endl;
                        letter = "  ";
                        num = word;
                        lengthOfFile++;
                    }
                }
                if (wordNum == 2)
                {
                    cout << "number: " << word;
                    num = word;
                    lengthOfFile++;
                }
                if (wordNum == 2)
                {
                    cout << endl;
                    append(head, letter, num);
                    //cout << "letter: " << letter << "   and   num: " << num << endl;
                    cout << endl;
                    addInOrder(head, letter, num);
                    //cout << "letter: " << letter << "   and   num: " << num << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                }
            }
            cout << endl;
        }
    inFile.close();
    }

    cout << "lengthOfFile++;: " << lengthOfFile << endl;

    printList(head, lengthOfFile);
}

void append(ListNode *&h, string l, string n)
{
    // create a new ListNode and set data and next
    ListNode *newNode;
    newNode = new ListNode;
    newNode->letter = l;
    //cout << "l: " << l << endl;
    newNode->num = n;
    //cout << "n: " << n << endl;
    newNode->next = nullptr;
}

void addInOrder(ListNode *&h, string l, string n)
{
    // create a new ListNode and set data
    ListNode *newNode;
    newNode = new ListNode;
    newNode->letter = l;
    //cout << "l: " << l << endl;
    newNode->num = n;
    //cout << "n: " << n << endl;
    newNode->next = nullptr;

    // if list is empty, assign head to new ListNode; otherwise,
    // find where to add in (non-descending) order
    if (h == nullptr)
    {
        h = newNode;
        newNode->next = nullptr;
    }
    else
    {
        ListNode *prev = nullptr;
        ListNode *curr = h;

        // find location to add
        while (curr != nullptr && curr->num < n)
        {
            prev = curr;
            curr = curr->next;
        }

        // if prev is nullptr, then we're adding to the beginning
        // of the list; else, adding to end or between two nodes
        if (prev == nullptr)
        {
            h = newNode;
            newNode->next = curr;
        }
        else
        {
            prev->next = newNode;
            newNode->next = curr;
        }
    }
}

void printList(ListNode *h, int &lengthOfFile)
{
    ListNode * ptr = h;

    // loop through and print data
    for(int i = 0; i < lengthOfFile; i++)
    {
        cout << ptr->letter << " ";
        cout << ptr->num << " ";
        cout << endl;
        ptr = ptr->next;
    }
}
