#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

using namespace std;

class GroceryTracker
{
public:
    GroceryTracker();

    void LoadFile(const string& fileName);

    void BackupFile(const string& fileName);

    int GetItemFrequency(const string& itemName) const;

    void PrintAllItems() const;

    void PrintHistogram() const;

private:
    map<string, int> groceryItems;
};

#endif
