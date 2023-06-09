#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include "ProduceItem.h"
#include "Utility.h"
#include <Windows.h>

using namespace std;

class ItemMenu
{
public:
    ItemMenu() {};
    //Get produce items from input file
    void GetFileItems(string& t_fileName);
    //Create a formatted back up file for acculuated data
    void CreateBackupDatFile(string& t_fileName);
    //Get user input
	void GetUserMenuInput();

private:
    //Create a vector of produce item
	vector<ProduceItem> m_ProduceItems;

    //Method to create a vector of produce item
    //If item is not on the vector, add item to the vector
    //If item is on the vector, increment item by one
    void CreateListOfProduceItem(string& t_item) {
        //Source: https://stackoverflow.com/a/15518039
        auto it = find_if(m_ProduceItems.begin(), m_ProduceItems.end(), [&t_item](ProduceItem& obj) {return obj.GetName() == t_item;});

        if (it != m_ProduceItems.end())
        {
            it._Ptr->AddOneToCount();
        }
        else {
            m_ProduceItems.emplace_back(ProduceItem(t_item));
        }
    }

    //Method to create the main menu for the user
    static void displayMenu() {
        string menuItemOne = "1. Item Search";
        string menuItemTwo = "2. List Items Count";
        string menuItemThree = "3. List Items Histogram Count";
        string menuItemFour = "4. Exit";
        string hintText = "*    Please type a number from menu items     *";
        /*
                    **************   Corner Grocer   **************
                    ***********   Item Analyzer Menu   ************
                    ***********************************************
                    *                                             *
                    * 1. Item Search                              *
                    * 2. List Items Count                         *
                    * 3. List Items Histogram Count               *
                    * 4. Exit                                     *
                    *                                             *
                    ***********************************************
                    *    Please type a number from menu items     *
                    ***********************************************
        */
        cout << Utility::Utility::repeatCharNTimes(14, '*') << "   Corner Grocer   " << Utility::repeatCharNTimes(14, '*') << endl;
        cout << Utility::repeatCharNTimes(11, '*') << "   Item Analyzer Menu   " << Utility::repeatCharNTimes(12, '*') << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << '*' << Utility::repeatCharNTimes(45, ' ') << '*' << endl;
        cout << "* " << menuItemOne << Utility::repeatCharNTimes(30, ' ') << '*' << endl;
        cout << "* " << menuItemTwo << Utility::repeatCharNTimes(25, ' ') << '*' << endl;
        cout << "* " << menuItemThree << Utility::repeatCharNTimes(15, ' ') << '*' << endl;
        cout << "* " << menuItemFour << Utility::repeatCharNTimes(37, ' ') << '*' << endl;
        cout << '*' << Utility::repeatCharNTimes(45, ' ') << '*' << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << hintText << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << endl;
    }

    //Method to create the Item Search screen
    void printRequestedItemCount() {
        string userInput;
        /*
                        ***********************************************
                        **********        Item Search        **********
                        ***********************************************
                        
                        Enter Item:
        */
        system("cls");
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << Utility::repeatCharNTimes(10, '*') << Utility::repeatCharNTimes(8, ' ') << "Item Search" << Utility::repeatCharNTimes(8, ' ') << Utility::repeatCharNTimes(10, '*') << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << endl;
        cout << "Enter Item: ";
        cin >> userInput;
        cout << endl;

        //Source: https://stackoverflow.com/a/15518039
        auto it = find_if(m_ProduceItems.begin(), m_ProduceItems.end(), [&userInput](ProduceItem& obj) {return Utility::toLowerString(obj.GetName()) == Utility::toLowerString(userInput);});

        if (it != m_ProduceItems.end()) {
            cout << it._Ptr->GetName() << ": " << it._Ptr->GetCount() << endl;
            cout << endl;
        }
        //User input validation if the item is not in the vector
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "There are no items that match the word ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << userInput << endl;
            cout << endl;
        }

        system("pause");
    }

    //Method to create the Item Counts screen
    void listItemsWithCount() {
        /*
                        ***********************************************
                        **********        Item Counts        **********
                        ***********************************************

                        Press any key to continue . . .
        */
        system("cls");
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << Utility::repeatCharNTimes(10, '*') << Utility::repeatCharNTimes(8, ' ') << "Item Counts" << Utility::repeatCharNTimes(8, ' ') << Utility::repeatCharNTimes(10, '*') << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << endl;

        //Get largest string size for formatting
        int largestStringSize = 0;
        for (auto& item : m_ProduceItems) {
            int stringSize = item.GetName().size();
            if (stringSize > largestStringSize) {
                largestStringSize = stringSize;
            }
        }

        for (auto& item : m_ProduceItems) {
            int amountOfSpace = (largestStringSize - item.GetName().size()) + 2;

            cout << item.GetName() << Utility::repeatCharNTimes(amountOfSpace, '.') << item.GetCount() << endl;
        }

        cout << endl;
        system("pause");
    }

    //Method to create the Item Histogram screen
    void listItemsWithHistogram() {
        /*
                        ***********************************************
                        *********       Item Histogram       **********
                        ***********************************************

                        Press any key to continue . . .
        */
        system("cls");
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << Utility::repeatCharNTimes(9, '*') << Utility::repeatCharNTimes(7, ' ') << "Item Histogram" << Utility::repeatCharNTimes(7, ' ') << Utility::repeatCharNTimes(10, '*') << endl;
        cout << Utility::repeatCharNTimes(47, '*') << endl;
        cout << endl;

        //Get largest string size for formatting
        int largestStringSize = 0;
        for (auto& item : m_ProduceItems) {
            int stringSize = item.GetName().size();
            if (stringSize > largestStringSize) {
                largestStringSize = stringSize;
            }
        }

        for (auto& item : m_ProduceItems) {
            int amountOfSpace = (largestStringSize - item.GetName().size());
            cout << Utility::repeatCharNTimes(amountOfSpace, ' ') << item.GetName() << " ";

            //Color code the histogram asterisks based on frequency
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), item.GetCount());
            cout << Utility::repeatCharNTimes(item.GetCount(), '*') << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }

        cout << endl;
        system("pause");
    }
};