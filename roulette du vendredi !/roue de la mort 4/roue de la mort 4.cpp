#include <iostream>


std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
    std::string _result = _str;
    size_t _pos = 0;
    while ((_pos = _result.find(_old, _pos)) != std::string::npos)
    {
        _result.replace(_pos, _old.size(), _new);
        _pos += _new.size();
    }
    return _result;
}

int Decroissant(const std::string _str)
{
    const std::string _number = Replace(_str, " ", "");
    int* _tab = new int[_number.size()+1];

    for (int i = 0; i <= _number.size(); i++)
        _tab[i] = 0;

    for (int i = 0; i <= _number.size();i++)
    {
        _tab[_number[i] - '0']++;        
    }
    int _result = 0, multiplier = 1;
    for (int i = 0; i <= _number.size();i++)
    {
        while (_tab[i] > 0)
        {

            _result += (i * multiplier);
            _tab[i]--;
            multiplier *= 10;
        }
    }
    return _result;
}





int main()
{
    std::cout<<Decroissant("1234589");
}


