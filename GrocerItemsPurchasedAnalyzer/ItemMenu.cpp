#include "ItemMenu.h"

void ItemMenu::GetFileItems(string &fileName)
{
    string item;
    fstream inFileStream;

    inFileStream.open(fileName, ios::in);

    if (!inFileStream.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        throw runtime_error("Error opening file: " + fileName);
    }

    while (getline(inFileStream, item)) {
        CreateListOfProduceItem(item);
    }
}

void ItemMenu::CreateBackupDatFile(string &fileName)
{
    fstream outFileStream;

    outFileStream.open(fileName, ios::out);
    if (!outFileStream.is_open()) {
        cout << "Error opening file: " << fileName << endl;
        throw runtime_error("Error opening file: " + fileName);
    }

    for (auto& item : m_ProduceItems) {
        outFileStream << "Name:       " << item.GetName() << endl;
        outFileStream << "Count:      " << item.GetCount() << endl;
        outFileStream << "Histogram:  " << Utility::repeatCharNTimes(item.GetCount(), '*') << endl;
    }

    outFileStream.close();
}

void ItemMenu::GetUserMenuInput()
{
    cin.exceptions(ios::failbit);
    int userInput = 1;

    while (userInput != 4)
    {
        if (userInput < 4 && userInput > 0)
        {
            system("cls");
            displayMenu();
        }
        else {
            system("cls");
            displayMenu();
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Incorrect selection made. Please try again." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << endl;
        }

        cout << "Menu Selection: ";
        try
        {
            cin >> userInput;
        }
        catch (ios_base::failure)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            userInput = -1;
        }

        switch (userInput) {
        case 1:
            /*cout << "You selected: " << userInput << endl;*/
            //system("pause");
            printRequestedItemCount();
            break;
        case 2:
            /*cout << "You selected: " << userInput << endl;
            system("pause");*/
            listItemsWithCount();
            break;
        case 3:
            /*cout << "You selected: " << userInput << endl;
            system("pause");*/
            listItemsWithHistogram();
            break;
        default:
            break;
        }
    }
}