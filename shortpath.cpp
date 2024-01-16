#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int r1, r2, r3, r4, r5;
class microm
{
public:
    void turnleft()
    {
        // turn left using motor
        cout << "turning left" << endl;
    }
    void turnright()
    {
        cout << "turning right" << endl;
        // turn right
    }
    void gostraight()
    {
        cout << "going ahead straight" << endl;
        // go straight
    }
    void uturn()
    {
        cout << "i am turning u" << endl;
        // uturn
    }
    void stop()
    {
        cout << "i have finished the race" << endl;
        // stop
    }
    void moveinch()
    {
        cout << "i have moved a inch" << endl;
        cout << "enter r1,r2,r3,r4,r5" << endl;
        cin >> r1 >> r2 >> r3 >> r4 >> r5;
    }
};
int check(string take)
{
    for (int x = 0; x < take.length(); x++)
    {
        if (take[x] == 'U')
        {
            return 1;
        }
    }
void robo(string in)
{
    while (check(in)==1)
    {
        for (int i = 0; i < in.length(); i++)
        {
            if (in[i] == 'S' && in[i + 1] == 'U' && in[i + 2] == 'L')
            {
                in.erase(i, 3);
                in.insert(i, "R");
               // break;
            }
            else if (in[i] == 'L' && in[i + 1] == 'U' && in[i + 2] == 'L')
            {
                in.erase(i, 3);
                in.insert(i, "S");
               // break;
            }
            else if (in[i] == 'L' && in[i + 1] == 'U' && in[i + 2] == 'S')
            {
                in.erase(i, 3);
                in.insert(i, "R");
               // break;
            }

            else if (in[i] == 'S' && in[i + 1] == 'U' && in[i + 2] == 'R')
            {
                in.erase(i, 3);
                in.insert(i, "L");
               // break;
            }
            else if (in[i] == 'R' && in[i + 1] == 'U' && in[i + 2] == 'R')
            {
                in.erase(i, 3);
                in.insert(i, "S");
               // break;
            }

            else
            {
                break;
            }
        }
    }
    cout <<"the shortest path is: "<<in;
}
int main()
{
    ofstream obj("abc.txt");//file openeed in write mode

    for (int i = 0; i >= 0; i++)
    {

        cout << "enter r1,r2,r3,r4,r5" << endl;
        cin >> r1 >> r2 >> r3 >> r4 >> r5;
        microm aa;
        // read the sensor reading
        if (r1 == 1 && r2 == 1 && r3 == 1 && r4 == 0 && r5 == 0) // left
        {
            // move inch function
            // gets readinng
            aa.moveinch();
            if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && r5 == 0)
            {
                aa.turnleft();

                obj << "L";
            }
            else if (r1 == 0 && r2 == 0 && r3 == 1 && r4 == 0 && r5 == 0)
            {
                aa.gostraight();
                obj << "S";
            }
            else
            {
                continue;
            }
        }
        else if (r1 == 0 && r2 == 0 && r3 == 1 && r4 == 1 && r5 == 1) // right
        {
            // move inch function
            // gets reading
            aa.moveinch();
            if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && r5 == 0)
            {
                aa.turnright();
                obj << "R";
            }
            else if (r1 == 0 && r2 == 0 && r3 == 1 && r4 == 0 && r5 == 0)
            {
                aa.turnright();
                obj << "R";
            }
            else
            {
                continue;
            }
        }
        else if (r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1) // left and right
        {
            // move inch function
            // gets reading
            aa.moveinch();
            if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && r5 == 0)
            {
                aa.turnright();
                obj << "R";
            }
            else if (r1 == 0 && r2 == 0 && r3 == 1 && r4 == 0 && r5 == 0)
            {
                aa.turnright();
                obj << "R";
            }
            else if (r1 == 1 && r2 == 1 && r3 == 1 && r4 == 1 && r5 == 1)
            {
                aa.stop();
                break;
            }
            else
            {
                continue;
            }
        }

        else if (r1 == 0 && r2 == 0 && r3 == 1 && r4 == 0 && r5 == 0) // uturn
        {
            // move inch function
            // gets reading
            aa.moveinch();
            if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0 && r5 == 0)
            {
                aa.uturn();
                obj << "U";
            }
            else
            {
                continue;
            }
        }

        else
        {
            aa.gostraight();
            obj << "S";
        }}
        obj.close();//write mode closed
        string str;
        char re;
        cout << "do you want to restart[y/n]"<<endl;
        cin >> re;
        
        if (re == 'y')
        {
            ifstream read("abc.txt");//file opened in read mode
            read >> str;
            robo(str);
            read.close();
            
        }
        else if (re == 'n')
        {
            goto label;
        }
label:
        return 0;
    }
