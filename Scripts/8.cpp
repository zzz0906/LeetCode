#include<bits/stdc++.h>
using namespace std;
int main()
{
  
  //ͨ��λ����ʵ�����ֵķ�ת�������Ķ��������������

  unsigned  int original =123;
  unsigned  int result  =0;
  unsigned  int mask =0xF;   //����

  
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
