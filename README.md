## parse CEAddressString


下载 [win_flex and win_bison3](https://sourceforge.net/projects/winflexbison/)

在`Release`和`x64`模式下，启动test项目

## Example 
```cpp
#include <iostream>
#include <CEAddress.h>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
  MessageBoxA(0, "a", "b", 0);
  try
  {
    map<string, LPVOID> symbols;
    symbols["a"] = (LPVOID)2;
    cout << ces::getAddress("1 + a", symbols) << endl;
    cout << ces::getAddress("messageboxa", symbols) << endl;
    cout << ces::getAddress("user32.messageboxa", symbols) << endl;
    cout << ces::getAddress("user32.MessageBoxA", symbols) << endl;
  }
  catch (const std::exception& e)
  {
    cout << e.what() << endl;
  }
  cin.get();
}
```


```sh
0000000000000003
00007FFD182FBCA0
00007FFD182FBCA0
00007FFD182FBCA0
```