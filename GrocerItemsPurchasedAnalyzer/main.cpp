#include "ProduceItem.h"
#include "ItemMenu.h"

int main() {
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string backupFileName = "frequency.dat";
    ItemMenu itemMenu;

    try
    {
        cout << "Reading in file..." << endl;
        itemMenu.GetFileItems(inputFileName);
        cout << "Creating backup file..." << endl;
        itemMenu.CreateBackupDatFile(backupFileName);
    }
    catch (const std::exception&)
    {
        system("pause");
        return ERROR_FILE_NOT_FOUND;
    }
    
    itemMenu.GetUserMenuInput();

    //This is about console coloring
    //Source: https://learn.microsoft.com/en-us/windows/console/setconsoletextattribute?redirectedfrom=MSDN
    //Source: https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text
    //int red = 4;
    //int default = 15;
    
    return EXIT_SUCCESS;
}