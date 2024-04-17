#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;
std::unordered_map<std::string, int> um{ {"1st", 1}, {"2nd", 2}, {"3rd", 3}, };
int main()
{
  unordered_set<int> a{ 1, 2, 3, };
  a.insert(9);
  a.erase(9);
  cout<<a.count(9);;//オーダーの1だよ
  unordered_map<string,int> ab{ {"a",1}, {"b",2},};
  cout<<ab["a"];
  return 0;
}