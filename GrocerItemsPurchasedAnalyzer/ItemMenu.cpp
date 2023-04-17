#include "ItemMenu.h"

void ItemMenu::GetFileItems(string& t_fileName)
{
    string item;
    fstream inFileStream;

    //Open the data file
    inFileStream.open(t_fileName, ios::in);

    //Make sure file opens properly
    if (!inFileStream.is_open()) {
        cout << "Error opening file: " << t_fileName << endl;
        throw runtime_error("Error opening file: " + t_fileName);
    }

    while (getline(inFileStream, item)) {
        CreateListOfProduceItem(item);
    }
}

void ItemMenu::CreateBackupDatFile(string &t_fileName)
{
    //Create a back up file for accumulated data
    fstream outFileStream;

    //Make sure file opens properly
    outFileStream.open(t_fileName, ios::out);
    if (!outFileStream.is_open()) {
        cout << "Error opening file: " << t_fileName << endl;
        throw runtime_error("Error opening file: " + t_fileName);
    }

    //Add produce item name, count, and histogram to the back up file
    for (auto& item : m_ProduceItems) {
        outFileStream << "Name:       " << item.GetName() << endl;
        outFileStream << "Count:      " << item.GetCount() << endl;
        outFileStream << "Histogram:  " << Utility::repeatCharNTimes(item.GetCount(), '*') << endl;
    }

    //Close the back up file
    outFileStream.close();
}

void ItemMenu::GetUserMenuInput()
{
    cin.exceptions(ios::failbit);
    int userInput = 1;

    while (userInput != 4)
    {
        //User input validation to make sure an integer 1-4 is entered
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

        //Switch statement for the four menu options
        switch (userInput) {
        case 1:
            printRequestedItemCount();
            break;
        case 2:
            listItemsWithCount();
            break;
        case 3:
            listItemsWithHistogram();
            break;
        default:
            break;
        }
    }
}