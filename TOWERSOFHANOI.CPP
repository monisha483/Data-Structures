#include<iostream.h>
#include<conio.h>
//S-source  D-destination A- Auxilliary
void hanoi(int n, char S, char D, char A)
{if(n==1)
 {cout<<"\nmove "<<n<<" from "<<S<<" to "<<D;
  return;}
 hanoi(n-1,S,A,D);
 cout<<"\nmove "<<n<<" from "<<S<<" to "<<D;
 hanoi(n-1,A,D,S);
}
void main()
{clrscr();
 //let the 1st, 2nd, 3rd pegs be a, b, c resp
 //a-source peg, b-destination peg, c-auxilliary peg
 hanoi(3,'a','b','c');
 getch();
}
