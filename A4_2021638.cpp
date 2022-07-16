#include <iostream>
using namespace std;

class MyString
{

private:
    char *charArr;
    int size;

public:

    MyString()                                              
    {
        size = 50;
        charArr = new char[size];

        for (int i = 0; i < size; i++)
        {
            charArr[i] = ' ';
        }
    }

    MyString(int sz)                                        
    {
        size = sz;
        charArr = new char[size];

        for (int i = 0; i < size; i++)
        {
            charArr[i] = ' ';
        }
    }

    MyString(char *characterArray)                          
    {
        int len = 0;
        size = 50;
        charArr = new char[size];

        for (int i = 0; i < size; i++)
        {
            if (characterArray[i] == '\0')
                break;

            else
            {
                charArr[i] = characterArray[i];
                len++;
            }
        }

        size = len;

        char *updatedCharArr;
        updatedCharArr = new char[size];

        for (int i = 0; i < size; i++)
        {
            updatedCharArr[i] = charArr[i];
        }

        charArr = updatedCharArr;
    }

    int sizeOfCharArr()                                     
    {
        int len = 0;

        for (int i = 0; charArr[i] != '\0'; i++)
        {
            len++;
        }

        return len;
    }

    friend ostream &operator<<(ostream &out, MyString &s);  

    friend istream &operator>>(istream &in, MyString &s);   

    void operator=(MyString s)                              
    {
        for (int i = 0; i < s.size; i++)
        {
            this->charArr[i] = s.charArr[i];
        }

        this->charArr[s.size] = '\0';

        size = s.size;
    }

    MyString operator+(MyString s)                          
    {
        MyString result;

        int i = 0;

        while (this->charArr[i] != '\0')
        {
            result.charArr[i] = this->charArr[i];
            i++;
        }

        int k = i;

        result.size = k;

        i = 0;

        while (s.charArr[i] != '\0')
        {
            result.charArr[k] = s.charArr[i];
            i++;
            k++;
        }

        result.size += i;

        return result;
    }

    void operator+=(MyString s)                             
    {
        int i = 0;

        while (this->charArr[i] != '\0')
        {
            i++;
        }

        int k = i;

        this->size = k;

        i = 0;

        while (s.charArr[i] != '\0')
        {
            this->charArr[k] = s.charArr[i];
            i++;
            k++;
        }

        this->size += i;
    }

    bool operator==(MyString s)                             
    {
        int sumS1 = 0, sumS2 = 0;

        for (int i = 0; i < this->size; i++)
        {
            sumS1 += int(this->charArr[i]);
        }

        for (int i = 0; i < s.size; i++)
        {
            sumS2 += int(s.charArr[i]);
        }

        if (sumS1 == sumS2)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    bool operator!=(MyString s)                             
    {
        int sumS1 = 0, sumS2 = 0;

        for (int i = 0; i < this->size; i++)
        {
            sumS1 += int(this->charArr[i]);
        }

        for (int i = 0; i < s.size; i++)
        {
            sumS2 += int(s.charArr[i]);
        }

        if (sumS1 != sumS2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>(MyString s)                              
    {
        int sumS1 = 0, sumS2 = 0;

        for (int i = 0; i < this->size; i++)
        {
            sumS1 += int(this->charArr[i]);
        }

        for (int i = 0; i < s.size; i++)
        {
            sumS2 += int(s.charArr[i]);
        }

        if (sumS1 > sumS2)
        {
            return true;
        }

        else
        {
            return false;
        }

    }

    bool operator<(MyString s)                              
    {
        int sumS1 = 0, sumS2 = 0;

        for (int i = 0; i < size; i++)
        {
            sumS1 += int(this->charArr[i]);
        }

        for (int i = 0; i < s.size; i++)
        {
            sumS2 += int(s.charArr[i]);
        }

        if (sumS1 < sumS2)
        {
            return true;
        }

        else
        {
            return false;
        }

    }

    MyString operator()(int startIndex, int endIndex)       
    {
        MyString result;
        int j = 0;

        for (int i = startIndex; i <= endIndex; i++)
        {
            result.charArr[j] = this->charArr[i];
            j++;
        }
        
        return result;
    }

    MyString operator<<(int numOfChar)                      
    {
        MyString result;

        for (int i = 0; i < numOfChar; i++)
        {
            result.charArr[i] = this->charArr[i];
        }

        char* updatedCharArr = new char[size];
        int j = 0;

        for (int i = numOfChar; i < size; i++)
        {
            updatedCharArr[j] = this->charArr[i]; 
            j++;
        }
        
        charArr = updatedCharArr;

        return result;
        
    }

    MyString operator>>(int numOfChar)                      
    {
        MyString result;

        for (int i = 0; i < numOfChar; i++)
        {
            result.charArr[i] = this->charArr[size-1-i];
        }

        char* updatedCharArr = new char[size];

        for (int i = 0; i < (size-numOfChar); i++)
        {
            updatedCharArr[i] = this->charArr[i];
        }
        
        charArr = updatedCharArr;
        size -= numOfChar;

        return result;
    }

    char operator[](int index) const                        
    {
        return this->charArr[index];
    }

    char &operator[](int index)                             
    {
        return this->charArr[index];
    }

    ~MyString()                                             
    {      
        delete[] charArr;
        charArr = nullptr;
    }
};

istream &operator>>(istream &in, MyString &s)
{
    in >> s.charArr;

    return in;
}

ostream &operator<<(ostream &out, MyString &s)
{
    out << s.charArr;

    return out;
}

bool exit()
{
    char in;
    cout << "\nPress Y/y to Exit or Any other key to continue: ";
    cin >> in;

    if(in == 'Y' || in == 'y')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{

    char in1[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char in2[10] = {'1', '2', '3', '4', '5', '6', '7'};
    MyString s1(in1), s2(in2), s3, st1, st2;
    
    char menu;
    bool running = true;
    
    while (running)
    {
       cout << "\n********** Menu For Testing MyString Class **********\n\n";
       cout << "Enter 1 to Return the Size of a String" << endl;
       cout << "Enter 2 to Concatenate Two Strings(+)" << endl;
       cout << "Enter 3 to Concatenate Two Strings(+=)" << endl;
       cout << "Enter 4 to Get a Character" << endl;
       cout << "Enter 5 to Set a Character" << endl;
       cout << "Enter 6 to Check if Two Strings are Equal" << endl;             
       cout << "Enter 7 to Check if Two Strings are Not Equal" << endl;         
       cout << "Enter 8 to Check which String is Greater" << endl;
       cout << "Enter 9 to Check which String is Smaller" << endl;
       cout << "Enter A to Get Substring" << endl;
       cout << "Enter B to Left Shift a String" << endl;
       cout << "Enter C to Right Shift a String" << endl;
       cout << "Enter D to Check Assignment Operator" << endl;
       cout << "Enter E to Exit" << endl;
       cout << "\n\nEnter Option: ";
       cin >> menu;
    
       switch (menu)
       {
            case '1':
                cout << "Input: ";
                cin >> st1;
                cout << st1.sizeOfCharArr();
                running = exit();
                break;
    
            case '2':
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                s3 = st1 + st2;
                cout << endl << s3 << endl;
                running = exit();
                break;
    
            case '3':
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                st1 += st2;
                cout << endl << st1 << endl;
                running = exit();
                break;
    
            case '4':
                char a;
                int i;
                cout << endl << s1 << endl << "Return Character at Positon: ";
                cin >> i;
                a = s1[i-1];                            // Position != Index here i.e starts from 1
                cout << a;
                running = exit();
                break;

            case '5':
                char b;
                int j;
                cout << endl << s1 << endl << endl << "Set Character: ";
                cin >> b;
                cout << "Set " << b << " at Position: ";
                cin >> j;          
                s1[j-1] = b;                            // Position != Index here i.e starts from 1
                cout << endl << s1 << endl;
                running = exit();
                break;

            case '6':                                   
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                if (st1 == st2)
                {
                    cout << endl << "Same String" << endl;
                }
                else
                {
                    cout << endl << "Different String" << endl;
                }
                running = exit();
                break;

            case '7':
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                if (st1 != st2)
                {
                    cout << endl << "Different String" << endl;
                }
                else
                {
                    cout << endl << "Same String" << endl;
                }
                running = exit();
                break;

            case '8':
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                if(st1 > st2)
                {
                    cout << endl << st1 << " is Greater" << endl;
                }
                else{
                    cout << endl << st2 << " is Greater" << endl;
                }
                running = exit();
                break;

            case '9':
                cout << "\nFirst String: ";
                cin >> st1;
                cout << "Second String: ";
                cin >> st2;
                if(st1 < st2)
                {
                    cout << endl << st1 << " is Smaller" << endl;
                }
                else{
                    cout << endl << st2 << " is Smaller" << endl;
                }
                running = exit();
                break;

            case 'A': 
                int startingIndex, endingIndex;
                cout << endl << s1 << endl << endl << "Start from Index: ";
                cin >> startingIndex;
                cout << "End at Index: ";
                cin >> endingIndex;
                s3 = s1(startingIndex, endingIndex);
                cout << endl << s3 << endl;
                running = exit();
                break;

            case 'B':
                int lShiftBy;
                cout << "\nEnter String: ";
                cin >> st1;
                cout << "Left Shift by: ";
                cin >> lShiftBy;
                s3 = st1 << lShiftBy;
                cout << endl << s3 << endl << st1 << endl;
                running = exit();
                break;

            case 'C':
                int rShiftBy;
                cout << endl << s1 << endl << endl << "Right Shift by: ";
                cin >> rShiftBy;
                s3 = s1 >> rShiftBy;                                       
                cout << endl << s3 << endl << s1 << endl;
                running = exit();
                break;

            case 'D':
                cout << endl << "s1: " << s1 << endl << "s2: " << s2 << endl;
                s2 = s1;
                cout << "s2: " << s2 << endl;
                running = exit();
                break;

            case 'E':
                running = false;
                break;
    
            default:
                cout << "\nWrong Input\n";
                break;
        }
    }
    
    return 0;
}