/* Author: Alexander Martin
 * Date: 7/21/2020
 * Assignment Number: 2
 * CS 3358 Summer 2020
 * Instructor: Dan Tamir
 *
 * This program is a string format checker, it proves if a string follows
 * a sequence of consecutive (unless empty) A's followed by
 * n*2 consecutive B's followed by
 * n/2 consecutive A's. Accepts any arbitrary string of length 1 < k,
 * and determines if it meets previously stated requirement.
*/

#include<iostream>
#include<fstream>

using namespace std;

class Queue
{
private:
    char * q;
    int qlimit,
        count,
        qfront,
        qrear;
public:
    Queue();

    void dynSize();
    void enQue(char s);
    char deQue();
    char First();
    bool Empty();
    bool Full();
};
//constructor
Queue::Queue()
{
    qlimit = 20;
    q = new char[qlimit];
    qfront= qrear=-1;
    count=0;
}



/********************************************
 enQue: add char to the end of queue

 parameters: char s - holds value of character from "exp.txt"

 returns: void
*********************************************/
void Queue::enQue(char s)
{
    if(Full())
        dynSize();
    qrear = (qrear + 1) % qlimit;
    q[qrear] = s;
    count++;
}




/********************************************
 deQue: return and remove the 1st char of the queue

 parameters: none

 returns: first element of queue
*********************************************/
char Queue::deQue()
{
    if(Empty())
        return ' ';
    qfront = (qfront + 1) % qlimit;
    count--;
    return q[qfront];
}




/********************************************
 First: get the front element of the queue

 parameters: none

 returns: first element in queue
*********************************************/
char Queue::First()
{
    if(Empty())
        return ' ';
    int tfront = (qfront + 1) % qlimit;
    return q[tfront];
}




/********************************************
 dynSize: Dynamically alter the size of the character limit

 parameters: none

 returns: void
*********************************************/
void Queue::dynSize()
{
    int k = qlimit;
    qlimit = qlimit * 2;
    char *tmp = new char[qlimit];
    for(int i=0; i < k; i++)
    {
        tmp[i] = q[i];
    }
    delete []q;
    q = tmp;
    delete []tmp;
}




/********************************************
 Empty: called if queue is empty

 parameters: none

 returns: 0
*********************************************/
bool Queue::Empty()
{
    return count==0;
}




/********************************************
 Full: called if queue is qlimit is reached

 parameters: none

 returns: qlimit
*********************************************/
bool Queue::Full()
{
    return count == qlimit;
}




/********************************************
 strValid: read and determine if arbitrary string is formatted correctly or not

 parameters: string s, Queue q

 returns: true or false
*********************************************/
bool strValid(string s, Queue q)
{
    for(int i=0; i<s.size(); i++){
        q.enQue(s[i]);
    }

    int n = 0;

    while(!q.Empty() && q.First() == 'A')
    {
        q.deQue();
        n++;
    }

    if(q.Empty())
        cout << "File is Empty \n" << "Program Terminating...";

    int m = 0;

    while(!q.Empty() && q.First() == 'B')
    {
        q.deQue();
        m++;
    }

    if(q.Empty() || m != n*2) return false;

     int k = 0;
    while(!q.Empty() && q.First() == 'A')
    {
        q.deQue();
        k++;
    }

    if(q.Empty() && k == n/2) return true;

    return false;
}





//main function
int main() {

    ifstream fin;
    fin.open("exp.txt");

    if (!fin.is_open()) {
        cout << "File not exist! " << endl;
        return 1;
    }

    ofstream fout;
    fout.open("out.txt");

    Queue q;
    string str;

    while (fin) {

        fin >> str;

        if (strValid(str, q) == true)
            fout << str << " == Format is OK" << endl;
        else
            fout << str << " == Format not acceptable" << endl;


        if (fin.eof()) break;

    }
    fin.close();
    fout.close();

    return 0;
}