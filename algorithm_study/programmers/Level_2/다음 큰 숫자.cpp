//
//  다음 큰 숫자.cpp
//  algorithm_study
//
//  Created by 신상용 on 6/29/24.
//

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int getCntNum1(int n)
{
  int nCnt = 0;
  for (int i=0; i<31; i++)
  {
    if (n & 1 << i)
      nCnt++;
  }
  return nCnt;
}

int solution(int n)
{
  int nNum1Cnt = getCntNum1(n);

  while(1)
  {
    n++;
    if (nNum1Cnt == getCntNum1(n))
      return n;
  }
}
