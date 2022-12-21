#pragma once
#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

/*
 * Node Declaration
 */
struct Pnode
{
    int freq;
    char info;
    struct Pnode* link;
};
/*
 * Class Priority Queue
 */
class PriorityQ
{
public:
    Pnode* front;
    int count=0;
public:
    PriorityQ()
    {
        front = NULL;
    }
    Pnode* peek() {
        if (!empty())
            return front;
    }
    void insert(char item, int priority)
    {
        Pnode* tmp, * q;
        tmp = new Pnode;
        tmp->info = item;
        tmp->freq = priority;
        //checking priority and inserting priority wise 
        if (front == NULL || priority < front->freq)
        {
            tmp->link = front;
            front = tmp;
            count++;
        }
        else
        {
            q = front;
            while (q->link != NULL && q->link->freq <= priority)
                q = q->link;
            tmp->link = q->link;
            q->link = tmp;
            count++;
        }
    }
    //poping function
    void del()
    {
        Pnode* tmp;
        if (front == NULL)
            return;
        else
        {
            tmp = front;

            front = front->link;
            free(tmp);
            count--;
        }
    }


    //frequency function finding frequency of string and storing in queue 
    void FindFreq(string str) {

        int freq[28] = { 0 };
        int i = 0, var;
        while (str[i] != '\0') {


            var = str[i] - 'a';
            if (str[i] == ' ')
                var = 26;
            if (str[i] == '\n')
                var = 27;
            freq[var]++;
            i++;
        }
        for (i = 0; i < 28; i++) {
            if (freq[i] != 0) {

                if (i == 26)
                    insert((' '), (freq[i]));
                if (i == 27)
                    insert(('\n'), (freq[i]));

                insert((i + 'a'), (freq[i]));
            }
        }
    }
    void display()
    {
        Pnode* ptr;
        ptr = front;
        if (front == NULL)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue is :\n";
            cout << "Priority       Item\n";
            while (ptr != NULL)
            {
                cout << ptr->freq << "                 " << ptr->info << endl;
                ptr = ptr->link;
            }
        }
    }

    bool empty() {
        return(front == NULL);
    }
};


