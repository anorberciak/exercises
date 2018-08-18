#include <iostream>
#include <functional>
#include <algorithm>

int main()
{
        std::function<int(int)> multi = [](int i){ return std::multiplies<int>()(i, 5);};
            std::cout << multi(11) << std::endl;
                return 0;
}
