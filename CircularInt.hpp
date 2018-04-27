#include <iostream>

using namespace std;

class CircularInt {
    
    int start, end;
    int curHour;
    
    public:
    
    CircularInt(int start, int end);
    CircularInt(int start, int end, int curHour);
    
    int getStart();
    int getEnd();
    int getCurHour();
    void getInRange();
    void setCurHour(int hour);
    
    friend ostream& operator<<(ostream& os, const CircularInt& circ);  //CircularInt to cout
    friend istream& operator>>(istream& is, CircularInt& circ);  //CircularInt to cout
    
    CircularInt& operator+= (int add);
    CircularInt& operator+= (CircularInt& circ);
    CircularInt& operator++ ();
    CircularInt operator++ (int);
    int operator+ (CircularInt& circ);
    int operator+ (int a);
    
    CircularInt& operator-= (int sub);
    CircularInt& operator-= (CircularInt& circ);
    CircularInt& operator-- ();
    CircularInt operator-- (int);
    int operator- ();
    int operator- (CircularInt& circ);
    int operator- (int a);
    
    CircularInt& operator*= (int mult);
    CircularInt& operator*= (CircularInt& circ);
    int operator* (CircularInt& circ);
    int operator* (int mult);
    
    CircularInt& operator/= (int divi);
    int operator/ (int divi);
    int operator/ (CircularInt& circ);
    
    CircularInt& operator= (CircularInt& circ);
    CircularInt& operator= (int hour);
    bool operator== (CircularInt& circ);
    bool operator== (int a);
    
    int operator% (CircularInt& circ);
    int operator% (int a);
    CircularInt& operator%= (CircularInt& circ);
    CircularInt& operator%= (int a);
    
    bool operator!= (CircularInt& circ);
    bool operator!= (int a);
    bool operator! ();
    
    bool operator> (CircularInt& circ);
    bool operator> (int a);
    bool operator>= (CircularInt& circ);
    bool operator>= (int a);
    bool operator< (CircularInt& circ);
    bool operator< (int a);
    bool operator<= (CircularInt& circ);
    bool operator<= (int a);
    
    bool operator&& (CircularInt& circ);
    bool operator&& (int a);
    
    bool operator|| (CircularInt& circ);
    bool operator|| (int a);
    
    int operator~ ();
    
    int operator& (CircularInt& circ);
    int operator& (int a);
    CircularInt& operator&= (CircularInt& circ);
    CircularInt& operator&= (int a);
    
    int operator| (CircularInt& circ);
    int operator| (int a);
    CircularInt& operator|= (CircularInt& circ);
    CircularInt& operator|= (int a);
    
    int operator^ (CircularInt& circ);
    int operator^ (int a);
    CircularInt& operator^= (CircularInt& circ);
    CircularInt& operator^= (int a);
    
    int operator<< (CircularInt& circ);
    int operator<< (int shift);
    CircularInt& operator<<= (CircularInt& circ);
    CircularInt& operator<<= (int a);
    
    int operator>> (CircularInt& circ);
    int operator>> (int shift);
    CircularInt& operator>>= (CircularInt& circ);
    CircularInt& operator>>= (int a);
};

CircularInt& operator- (int base, CircularInt& circ);
CircularInt& operator+ (int base, CircularInt& circ);
CircularInt& operator* (int base, CircularInt& circ);
CircularInt& operator/ (int base, CircularInt& circ);
bool operator> (int base, CircularInt& circ);
bool operator< (int base, CircularInt& circ);
bool operator>= (int base, CircularInt& circ);
bool operator<= (int base, CircularInt& circ);
bool operator== (int base, CircularInt& circ);
bool operator!= (int base, CircularInt& circ);
