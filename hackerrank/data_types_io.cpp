#include <iostream>
#include <cstdio>
#include<iomanip>
using namespace std;

int main() {
    // Complete the code.
    int n;
    cin>>n;
    long l;
    cin>>l;
    char c;
    cin>>c;
    float f;
    cin>>f;
    double d;
    cin>>d;
    cout<<n<<endl;
    cout<<l<<endl;
    cout<<c<<endl;
    printf("%.3f", f);
    cout<<endl;
    printf("%.9f",d);
    cout<<endl;
    return 0;
}


// char ch = 'd';
// double d = 234.432;
// printf("%c %lf", ch, d);


// char ch;
// double d;
// scanf("%c %lf", &ch, &d);


//printf and scanf are better for performing large io operations.


//learn about pointers and references
// void update(int *a,int *b) {
//     // Complete this function
//     int temp=*a;
//     *a=*a+*b;
//     *b=abs(temp-*b);
// }