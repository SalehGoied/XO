#include <iostream>

using namespace std;

void print (int a[][3]) //print the game
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 1)
            {
                cout <<" X ";
            }
            else if (a[i][j] == -1)
            {
                cout << " O ";
            }
            else
            {
                cout <<" - ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int check_win(int a[][3])     //check are there any winner
{
    for (int r = 0; r < 3; r++) //check row and column
    {
        int sum_c = 0;
        int sum_r = 0;
        for (int c = 0; c < 3 ;c++)
        {
            sum_c += a[c][r];
            sum_r += a[r][c];
        }
        if (sum_c == 3|| sum_r == 3)
            return 1;
        else if (sum_c == -3|| sum_r == -3)
            return -1;
    }
    int d1 = 0, d2 = 0; //diagonal
    for (int i = 0; i < 3; i++)
    {
        d1 += a[i][i];
        d2 += a[i][2-i];
    }
    if (d1 == 3|| d2 == 3)
        return 1;
    else if (d1 == -3|| d2 == -3)
        return -1;
    else
        return 0;
}
void player(int a[][3],string name1, string name2,int &z)
{
    print(a);
    int r = 0, c = 0;
    bool x = true;
    int win = 0;
    int k = 0;
    while (k <= 9)
    {
        cout<<name1<<"'s turn \n"<<"------------"<<endl;
        do
        {
            cout<<"enter two number of row then column: ";
            cin>>r>>c;
            if (r > 3 ||c > 3)
            {
                cout<<"that value is not valid\n";
                cout<<"numbers should be less than 3\n";
                x = true;
                continue;
            }
            if (a[r-1][c-1] != 0)
            {
                cout<<"that place is not empty\n";
                cout<<"chose another numbers\n";
                x = true;
                continue;
            }
            x = false;
            a[r-1][c-1] = 1;
            print(a);
            win  = check_win(a);
            k++;
        }while (x);
        if (win == 1)
        {
            z = 1;
            cout<<name1<<" win (-.-)\a"<<endl;
            break;
        }
        if (k == 9)
                break;

        cout<<name2<<"'s turn \n"<<"------------"<<endl;
        do
        {
            cout<<"enter two number one for row then column: ";
            cin>>r>>c;
            if (r > 3 ||c > 3)
            {
                cout<<"that value is not valid\n";
                cout<<"numbers should be less than 3\n";
                x = true;
                continue;
            }
            if (a[r-1][c-1] != 0)
            {
                cout<<"that place is not empty\n";
                cout<<"chose another numbers\n";
                x = true;
                continue;
            }
            x = false;
            a[r-1][c-1] = -1;
            print(a);
            win  = check_win(a);
            k++;

        }while (x);
        if (win == -1)
        {
            z = 1;
            cout<<name2<<" win (-.-)\a"<<endl;
            break;
        }
         if (k == 9)
                break;

    }
}

int main()
{
    cout<<"XO GAME\n===========\n\n";
    string name1,name2;
    cout<<"name of player 1: ";
    cin>>name1;
    cout<<"name of player 2: ";
    cin>>name2;
    cout<<"\nX for "<<name1<<" and O for "<<name2<<endl<<endl;
    int a[3][3]={0};
    int z = 0;
    player(a,name1,name2,z);
    if (z == 0)
    {
        cout<<"draw"<<endl;
    }
    return 0;
}
