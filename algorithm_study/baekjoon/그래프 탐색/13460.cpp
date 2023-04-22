//
//  13460.cpp
//  baekjoon
//
//  Created by 신상용 on 2023/01/12.
//

#include <bits/stdc++.h>
#define MAX 10

class Stack
{
private:
    typedef struct _node {
        int *data;
        struct _node* link;
    }node;
    int m_size;
    node* stack;
public:
    Stack()
    {
        m_size = 0;
        stack = NULL;
    }

    int empty() {
        return (stack == NULL);
    }

    void push(int *data) {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = data;
        temp->link = NULL;
        if (empty()) {
            stack = temp;
        }
        else {
            temp->link = stack;
            stack = temp;
        }
        m_size++;
    }

    int* pop() {
        node* temp = NULL;
        if (empty()) {
        }
        else {
            temp = stack;
            stack = temp->link;
            m_size--;
        }
        int* popdata = temp->data;
        free(temp);
        return popdata;
    }

    int* top() {
        node* temp = stack;
        if (empty()) {
            return NULL;
        }
        else {
            return temp->data;
        }
    }

    int size() {
        return m_size;
    }
};

int bead_excape(int, int);

int main(int argc, char const *argv[])
{
    int width, height, count;
    scanf("%d %d", &height, &width);
    count = bead_excape(height, width);
    printf("%d\n", count);
    return 0;
}


int move(char[MAX][MAX], int[4], int[2], int[MAX][MAX][MAX][MAX], int, int, Stack*);

int bead_excape(int height, int width)
{
    char maps[MAX][MAX], line[MAX+1];
    int rb[MAX][MAX][MAX][MAX]; // red, blue position
    int goal[2];
    Stack S1, S2;
    int* save;
    save = (int*)malloc(4*sizeof(int));// start position data;
    for(int i = 0; i < height; i++)
    {
        scanf("%s", line);
        for(int j = 0; j < width; j++)
        {
            maps[i][j] = line[j];
            if(line[j] == 'R') // first red bead's position
            {
                save[0] = i;
                save[1] = j;
            }
            if(line[j] == 'B') // first blue bead's position
            {
                save[2] = i;
                save[3] = j;
            }
            if(line[j] == 'O') // goal position
            {
                goal[0] = i;
                goal[1] = j;
            }
            for (int k = 0; k < height; ++k) // all reset for 0
            {
                for (int l = 0; l < width; l++)
                {
                    rb[i][j][k][l] = 0;
                }
            }
        }
    }
    rb[save[0]][save[1]][save[2]][save[3]] = 1;
    S1.push(save);


    int maxcount = 10;
    for(int count = 0; count < maxcount; count++)
    {
        while( (!(count%2) && !S1.empty()) || (count%2 && !S2.empty()) )
        {
            if(count%2 && !S2.empty()) // count%2 == 1 then pop S2 and push S1
            {
                save = (int*)S2.top();
                S2.pop();
            }

            if(!(count%2) && !S1.empty()) // count%2 == 0 then pop S1 and push S2
            {
                save = (int*)S1.top();
                S1.pop();
            }

            //rightmove
            if(move(maps, save, goal, rb, 0, 1, count%2?&S1:&S2))
                return count+1;
            //leftmove
            if(move(maps, save, goal, rb, 0, -1, count%2?&S1:&S2))
                return count+1;
            //upmove
            if(move(maps, save, goal, rb, -1, 0, count%2?&S1:&S2))
                return count+1;
            //downmove
            if(move(maps, save, goal, rb, 1, 0, count%2?&S1:&S2))
                return count+1;
            free(save);
        }
    }
    return -1;
}

int move(char maps[MAX][MAX], int nowrb[4], int goal[2], int rbdata[MAX][MAX][MAX][MAX], int udmove, int lrmove, Stack *pushS)
{
    int r[2], b[2];
    r[0] = nowrb[0];
    r[1] = nowrb[1];
    b[0] = nowrb[2];
    b[1] = nowrb[3];
    int *finishrb;

    while(maps[r[0]+udmove][r[1]+lrmove] != '#' || maps[b[0]+udmove][b[1]+lrmove] != '#')
    {
        if(maps[r[0]+udmove][r[1]+lrmove] != '#' && maps[b[0]+udmove][b[1]+lrmove] != '#')
        {
            r[0] += udmove;
            r[1] += lrmove;
            b[0] += udmove;
            b[1] += lrmove;
        }
        else if(maps[r[0]+udmove][r[1]+lrmove] != '#') // blue bead can't move
        {
            if(r[0]+udmove == b[0] && r[1]+lrmove == b[1]) // if meet blue bead then can't move red bead
                break;
            r[0] += udmove;
            r[1] += lrmove;
        }
        else // maps[b[0]+udmove][b[1]+lrmove] != '#'
        {
            if(b[0]+udmove == r[0] && b[1]+lrmove == r[1]) // if meet red bead then can't move blue bead
                break;
            b[0] += udmove;
            b[1] += lrmove;
        }

        if (b[0] == goal[0] && b[1] == goal[1]) // blue goal is fail
            return 0;

        if (r[0] == goal[0] && r[1] == goal[1])
        {
            while(maps[b[0]+udmove][b[1]+lrmove] != '#') // if red goal but blue also goal
            {
                b[0] += udmove;
                b[1] += lrmove;
                if (b[0] == goal[0] && b[1] == goal[1])
                    return 0;
            }
            return 1;
        }
    }
    if (rbdata[r[0]][r[1]][b[0]][b[1]] == 0) // new red, blue bead's position
        {
            rbdata[r[0]][r[1]][b[0]][b[1]] = 1; // save new position data
            finishrb = (int*)malloc(4*sizeof(int));
            finishrb[0] = r[0];
            finishrb[1] = r[1];
            finishrb[2] = b[0];
            finishrb[3] = b[1];
            pushS->push(finishrb);
        }
    return 0;
}
