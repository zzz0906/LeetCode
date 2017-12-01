#include<bits/stdc++.h>
using namespace std;
int main()
{
  
  //通过位运算实现数字的反转（操作的对象必须是整数）

  unsigned  int original =123;
  unsigned  int result  =0;
  unsigned  int mask =0xF;   //掩码

  
  result |=original&mask;

  original>>=4;
  result<<=4;
  result |=original&mask;

  original>>=4;
  result<<=4;
  result|=original & mask;

  printf("%X\n",result);
  return 0;
}
