#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;
int main()
{

    ofstream wrt;
    ifstream read;
    wrt.open("Output.txt", ios::app);
    read.open("input.txt", ios::in);
    int n;
    read >> n;

    while (n--)
    {
        // geting input file ready
        vector<int> takeOutOrders;
        vector<int> dineInOrders;
        vector<int> servedOrders;

        for (int i = 0; i < 3; i++)
        {
            vector<int> temp;
            string str;
            int t = 0;
            getline(read, str, ']');
            for (int j = 0; j < str.size(); j++)
            {
                if (str[j] - '0' != -38 && str[j] != ' ' && str[j] != ',' && str[j] != '[' && str[j] != ']')
                {
                    t = t * 10 + (str[j] - '0');
                    if (str[j + 1] == ',')
                    {
                        temp.push_back(t);
                        t = 0;
                    }
                }
            }
            temp.push_back(t);
            if (i == 0)
            {
                takeOutOrders = temp;
            }
            else if (i == 1)
            { // dineINOrders.push_back(temp);
                dineInOrders = temp;
            }
            else
            {
                servedOrders = temp;
            }
            temp.clear();
        }

        // input loaded

        int i = 0, j = 0, k = 0; // Pointers
        int count = 0;
        int flag = 0;
        int counti = 0;
        int countj = 0;
        int temp = 0;
        while (i <= takeOutOrders.size() - 1 && j <= dineInOrders.size() - 1 && k <= servedOrders.size() - 1)
        {
            if (count < 0)
            {
                wrt << "Invalid" << endl;
                flag = 1;
                break;
            }
            if (servedOrders[k] == takeOutOrders[i])
            {

                counti++;
                countj = 0;
                k++;
                i++;
                temp = i;
            }
            else if (servedOrders[k] == dineInOrders[j])
            {
                countj++;
                counti = 0;
                k++;
                j++;
                temp = j;
            }
            else
            {
                wrt << "Invalid\n";
                flag = 1;
                break;
            }
        }
        while (i < takeOutOrders.size() - 1 && flag == 0)
        {
            if (servedOrders[k] == takeOutOrders[i])
            {
                k++;
                i++;
            }
            else
            {
                wrt << "Invalid" << endl;
                flag = 1;
                break;
            }
        }
        while (j < dineInOrders.size() - 1 && flag == 0)
        {
            if (servedOrders[k] == dineInOrders[j])
            {
                k++;
                j++;
            }
            else
            {
                wrt << "Invalid" << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            wrt << "Valid\n";
        }
    }
    return 0;
}