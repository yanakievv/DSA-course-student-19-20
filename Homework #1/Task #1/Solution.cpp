#include <iostream>
#include <string>
std::string encode(std::string str)
{
    std::string pass;
    for (int i = 0; i < str.length();)
    {
        int ctr = 0;
        int temp = str[i];
        while (temp == str[i])
        {
            ctr++;
            i++;
        } 

        pass += std::to_string(ctr);
        pass.push_back(temp);
    }

    return pass;
}

int main()
{
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < 65 || str[i] > 90)
        {
            std::cout << "Passworm must be UPPERcase only!" << std::endl;
            return 0;
        }
    }

    std::cout << encode(str);

}
