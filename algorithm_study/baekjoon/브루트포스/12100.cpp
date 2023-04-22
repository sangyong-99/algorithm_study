//
//  12100.cpp
//  baekjoon
//
//  Created by 신상용 on 2023/01/05.
//

#include<bits/stdc++.h>
 
#define endl "\n"
#define MAX 20
using namespace std;
 
int N, Answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
int Select[5];
bool Visit[MAX][MAX];
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
void Copy_MAP()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C_MAP[i][j] = MAP[i][j];
        }
    }
}
 
void Move_Left()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (C_MAP[i][j] == C_MAP[i][j + 1])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i][j + 1] = 0;
            }
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}
 
void Move_Right()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            if (C_MAP[i][j] == C_MAP[i][j - 1])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i][j - 1] = 0;
            }
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > 0; j--)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = j - 1;
                while (k >= 0)
                {
                    if (C_MAP[i][k] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}
 
void Move_Up()
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }
 
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
 
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i][j] == C_MAP[i + 1][j])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i + 1][j] = 0;
            }
        }
    }
 
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i + 1;
                while (k <= N - 1)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k++;
                }
 
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
}
 
void Move_Down()
{
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
 
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i - 1][j] == C_MAP[i][j])
            {
                C_MAP[i][j] = C_MAP[i][j] * 2;
                C_MAP[i - 1][j] = 0;
            }
        }
    }
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            bool Check = false;
            if (C_MAP[i][j] == 0)
            {
                int k = i - 1;
                while (k >= 0)
                {
                    if (C_MAP[k][j] != 0)
                    {
                        Check = true;
                        break;
                    }
                    k--;
                }
                if (Check == true)
                {
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
 
}
 
int Find_Max()
{
    int Max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (C_MAP[i][j] > Max)
            {
                Max = C_MAP[i][j];
            }
        }
    }
    return Max;
}
 
void Play_The_Game()
{
    for (int i = 0; i < 5; i++)
    {
        int Dir = Select[i];
        if (Dir == 0) Move_Right();
        else if (Dir == 1) Move_Left();
        else if (Dir == 2) Move_Down();
        else if (Dir == 3) Move_Up();
    }
 
    Answer = Bigger(Answer, Find_Max());
}
 
void Select_Direction(int Idx, int Cnt)
{
    if (Cnt == 5)
    {
        Copy_MAP();
        Play_The_Game();
        return;
    }
 
    for (int i = 0; i < 4; i++)
    {
        Select[Cnt] = i;
        Select_Direction(i, Cnt + 1);
    }
}
 
void Solution()
{
    Select_Direction(0, 0);
    cout << Answer << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

