#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

GroceryTracker::GroceryTracker()
{
}

void GroceryTracker::LoadFile(const string& fileName)
{
    ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open the input file: "
            << fileName << endl;
        return;
    }

    string item;

    while (inputFile >> item)
    {
        groceryItems[item]++;
    }

    inputFile.close();
}

void GroceryTracker::BackupFile(const string& fileName)
{
    ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to create the backup file: "
            << fileName << endl;
        return;
    }

    for (const auto& item : groceryItems)
    {
        outputFile << item.first << " "
            << item.second << endl;
    }

    outputFile.close();
}

int GroceryTracker::GetItemFrequency(const string& itemName) const
{
    auto item = groceryItems.find(itemName);

    if (item != groceryItems.end())
    {
        return item->second;
    }

    return 0;
}

void GroceryTracker::PrintAllItems() const
{
    cout << endl;
    cout << "Item Frequencies" << endl;
    cout << "----------------" << endl;

    if (groceryItems.empty())
    {
        cout << "No grocery items were found." << endl;
        return;
    }

    for (const auto& item : groceryItems)
    {
        cout << left << setw(15)
            << item.first
            << item.second
            << endl;
    }

    cout << endl;
}

void GroceryTracker::PrintHistogram() const
{
    cout << endl;
    cout << "Item Frequency Histogram" << endl;
    cout << "------------------------" << endl;

    if (groceryItems.empty())
    {
        cout << "No grocery items were found." << endl;
        return;
    }

    for (const auto& item : groceryItems)
    {
        cout << left << setw(15)
            << item.first;

        for (int i = 0; i < item.second; ++i)
        {
            cout << "*";
        }

        cout << endl;
    }

    cout << endl;
}