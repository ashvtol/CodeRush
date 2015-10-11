#include<iostream>
#include<string>
using namespace std;


/*Prefix function - Step 1
At every postion of the string sequence it finds the longest suffix length which is
same as the prefix.

For example:
COCACOLA, if this is the string then it's suffix array would be

POS:    0 1 2 3 4 5 6 7
STR:    C O C A C O L A
PRE:    0 0 1 0 1 2 0 0

At position 1 in the prefix array the value is 1, it means that the longest proper
suffix length uptil now is 1 (corresponding to "C" in the sub-string "COC") which
also is the prefix.

Similary at position 5 the is 2, it means that the longest proper suffix length uptil
now is 2 (corresponding to "CO" in the substring "COCACO") which is aslo the prefix
of the string.

You can refer to this video for more clarity:https://www.youtube.com/watch?v=GTJr8OvyEVQ
*/

void prefix(string &s, int *pre)
{
    int i,j;
    i = 0;
    j = 1;
    int l = s.length();
    pre[0] = 0;
    while(j<l)
    {
        //cout << "j = " << j << "\n";
        if(s[i]==s[j])
        {
            pre[j] = i+1;
            i++;
            j++;
        }
        else
        {
            if(i>0) i--;
            //cout << "Else i = " << i << "\n";
            while(i!=0 && s[i]!=s[j])
            {
                if(pre[i]>0)
                    i = pre[i];
                else
                {
                    i--;
                }

            }
            if(s[i]==s[j])
            {
                pre[j++] = i+1;
                i++;
            }
            else
                pre[j++] = i;
        }
    }
}


/*
Knuth–Morris–Pratt (KMP)-- Step 2

When checking a string with a given pattern there are two possibilities,
1. You find the pattern in the string
2. You don't find the pattern.

Let's say you had a string "hackhackhackhackithackerearth" and a pattern "hackhackit"
Then initialy the first 8 characters match with the pattern in the string but after
that "h != i" so instead of checking from the begining of the pattern we make use of
the pattern array to find the max index away from the begining.

*/
void kmp(string &s, string &p, int *pre)
{
    int l = s.length();
    int lof = p.length();
    int i=0;
    int j=0;
    while(i<l)
        {
            if(s[i]==p[j])
            {
                if(p[lof-1]==s[i])
                    cout << "Match found at i = " << i-lof+1 << "\n";
                j++;
                i++;
            }
            else
            {

                if(j>0) j--;
                j = pre[j];

                i++;
                j++;
            }


    }
}

int main()
{
    string sequence = "hackhackhackhackithackerearth";
    string pattern = "hackhackit";
    int l = sequence.length();
    int pre[l];
    prefix(sequence, pre);
    for(int i=0; i<l; i++)
    {
        cout << pre[i] << " ";
    }
    cout << "\n";
    kmp(sequence, pattern, pre);
}
