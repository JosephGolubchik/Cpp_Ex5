#include <iostream>
#include "CircularInt.hpp"
#include <string>

using namespace std;

CircularInt::CircularInt(int start, int end){
    this->start = start;
    this->end = end;
    curHour = start;
}

CircularInt::CircularInt(int start, int end, int curHour){
    this->start = start;
    this->end = end;
    this->curHour = curHour;
    this->getInRange();
}


int CircularInt::getStart(){
    return start;
}

int CircularInt::getEnd(){
    return end;
}

int CircularInt::getCurHour(){
    return curHour;
}

void CircularInt::getInRange(){
    while(curHour < start || curHour > end){
        if(curHour > end){
            curHour -= (end-(start-1));
        }
        else if(curHour < start){
            curHour += (end-(start-1));
        }
    }
}

void CircularInt::setCurHour(int hour){
    curHour = hour;
}

CircularInt& CircularInt::operator+= (int add){ 
    curHour = curHour + add;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator+= (CircularInt& circ){ 
    curHour = curHour + circ.getCurHour();
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator++ (){ 
    curHour++;
    this->getInRange();
    return *this;
}

CircularInt CircularInt::operator++ (int){ 
    CircularInt temp {start, end, curHour};
    curHour++;
    this->getInRange();
    return temp;
}

int CircularInt::operator+ (CircularInt& circ){
    CircularInt temp {start, end, curHour};
    int ans = curHour + circ.getCurHour();
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

int CircularInt::operator+ (int a){
    CircularInt temp {start, end, curHour};
    int ans = curHour + a;
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

CircularInt& CircularInt::operator-= (int sub){ 
    curHour = curHour - sub;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator-= (CircularInt& circ){ 
    curHour = curHour - circ.getCurHour();
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator-- (){ 
    curHour--;
    this->getInRange();
    return *this;
}

CircularInt CircularInt::operator-- (int){ 
    CircularInt temp {start, end, curHour};
    curHour--;
    this->getInRange();
    return temp;
}

int CircularInt::operator- (){
    CircularInt temp {start, end, curHour};
    int ans = -curHour;
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

int CircularInt::operator- (CircularInt& circ){
    CircularInt temp {start, end, curHour};
    int ans = curHour - circ.getCurHour();
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

int CircularInt::operator- (int a){
    CircularInt temp {start, end, curHour};
    int ans = curHour - a;
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

CircularInt& CircularInt::operator*= (int mult){ 
    curHour = curHour * mult;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator*= (CircularInt& circ){ 
    curHour = curHour * circ.getCurHour();
    this->getInRange();
    return *this;
}

int CircularInt::operator* (int mult){
    CircularInt temp {start, end, curHour};
    int ans = curHour * mult;
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

int CircularInt::operator* (CircularInt& circ){
    CircularInt temp {start, end, curHour};
    int ans = curHour * circ.getCurHour();
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

CircularInt& CircularInt::operator/= (int divi){ 
    if(curHour % divi != 0){
        string message = "There is no number x in {" + to_string(start) + "," 
                       + to_string(end) +"} such that x*" + to_string(divi) + "=" + to_string(curHour);
        throw message;
    }
    else{
        curHour = curHour / divi;
        this->getInRange();
        return *this;
    }
}

int CircularInt::operator/ (CircularInt& circ){
    
    if(curHour % circ.getCurHour() != 0){
        string message = "There is no number x in {" + to_string(start) + "," 
                       + to_string(end) +"} such that x*" + to_string(circ.getCurHour()) + "=" + to_string(curHour);
        throw message;
    }
    else{
        CircularInt temp {start, end, curHour};
        int ans = curHour / circ.getCurHour();
        temp.setCurHour(ans);
        temp.getInRange();
        ans = temp.getCurHour();
        return ans;
    }
}

int CircularInt::operator/ (int divi){ 
    if(curHour % divi != 0){
        string message = "There is no number x in {" + to_string(start) + "," 
                       + to_string(end) +"} such that x*" + to_string(divi) + "=" + to_string(curHour);
        throw message;
    }
    else{
        CircularInt temp {start, end, curHour};
        int ans = curHour / divi;
        temp.setCurHour(ans);
        temp.getInRange();
        ans = temp.getCurHour();
        return ans;
    }
}

CircularInt& CircularInt::operator= (CircularInt& circ){
    curHour = circ.curHour;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator= (int hour){
    curHour = hour;
    this->getInRange();
    return *this;
}

bool CircularInt::operator== (CircularInt& circ){
    return curHour == circ.getCurHour();
}

bool CircularInt::operator== (int a){
    return curHour == a;
}

int CircularInt::operator% (CircularInt& circ){
    CircularInt temp {start, end, curHour};
    int ans = (curHour) % (circ.getCurHour());
    temp.setCurHour(ans);
    temp.getInRange();
    ans = temp.getCurHour();
    return ans;
}

int CircularInt::operator% (int a){
    return curHour % a;
}

CircularInt& CircularInt::operator%= (int a){ 
    curHour = curHour % a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator%= (CircularInt& circ){ 
    curHour = curHour % circ.getCurHour();
    this->getInRange();
    return *this;
}

bool CircularInt::operator!= (CircularInt& circ){
    return curHour != circ.getCurHour();
}

bool CircularInt::operator!= (int a){
    return curHour != a;
}

bool CircularInt::operator! (){
    return !curHour;
}

bool CircularInt::operator> (CircularInt& circ){
    return curHour > circ.getCurHour();
}

bool CircularInt::operator> (int a){
    return curHour > a;
}

bool CircularInt::operator>= (CircularInt& circ){
    return curHour >= circ.getCurHour();
}

bool CircularInt::operator>= (int a){
    return curHour >= a;
}

bool CircularInt::operator< (CircularInt& circ){
    return curHour < circ.getCurHour();
}

bool CircularInt::operator< (int a){
    return curHour < a;
}

bool CircularInt::operator<= (CircularInt& circ){
    return curHour <= circ.getCurHour();
}

bool CircularInt::operator<= (int a){
    return curHour <= a;
}

bool CircularInt::operator&& (CircularInt& circ){
    return curHour && circ.getCurHour();
}

bool CircularInt::operator&& (int a){
    return curHour && a;
}

bool CircularInt::operator|| (CircularInt& circ){
    return curHour || circ.getCurHour();
}

bool CircularInt::operator|| (int a){
    return curHour || a;
}

int CircularInt::operator~ (){
    return ~curHour;
}

int CircularInt::operator& (CircularInt& circ){
    return curHour & circ.getCurHour();
}

int CircularInt::operator& (int a){
    return curHour & a;
}

CircularInt& CircularInt::operator&= (int a){ 
    curHour = curHour & a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator&= (CircularInt& circ){ 
    curHour = curHour & circ.getCurHour();
    this->getInRange();
    return *this;
}

int CircularInt::operator| (CircularInt& circ){
    return curHour | circ.getCurHour();
}

int CircularInt::operator| (int a){
    return curHour | a;
}

CircularInt& CircularInt::operator|= (int a){ 
    curHour = curHour | a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator|= (CircularInt& circ){ 
    curHour = curHour | circ.getCurHour();
    this->getInRange();
    return *this;
}

int CircularInt::operator^ (CircularInt& circ){
    return curHour ^ circ.getCurHour();
}

int CircularInt::operator^ (int a){
    return curHour ^ a;
}

CircularInt& CircularInt::operator^= (int a){ 
    curHour = curHour ^ a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator^= (CircularInt& circ){ 
    curHour = curHour ^ circ.getCurHour();
    this->getInRange();
    return *this;
}

int CircularInt::operator<< (CircularInt& circ){
    return curHour << circ.getCurHour();
}

int CircularInt::operator<< (int shift){
    return curHour << shift;
}

CircularInt& CircularInt::operator<<= (int a){ 
    curHour = curHour << a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator<<= (CircularInt& circ){ 
    curHour = curHour << circ.getCurHour();
    this->getInRange();
    return *this;
}

int CircularInt::operator>> (CircularInt& circ){
    return curHour >> circ.getCurHour();
}

int CircularInt::operator>> (int shift){
    return curHour >> shift;
}

CircularInt& CircularInt::operator>>= (int a){ 
    curHour = curHour >> a;
    this->getInRange();
    return *this;
}

CircularInt& CircularInt::operator>>= (CircularInt& circ){ 
    curHour = curHour >> circ.getCurHour();
    this->getInRange();
    return *this;
}



/////////////////////////////////////////////
////NEED TO ADD MORE FUNCTIONS LIKE THESE FOR OTHER OPERATORS:
//////Ex: 1 + hour, 1 - hour, 1 * hour, 1 << hour ....

ostream& operator<<(ostream& out, CircularInt& circ){  
    out << circ.getCurHour() << endl;
    return out;  
}

istream& operator>>(istream& input, CircularInt& circ){  
    input >> circ.curHour;
    circ.getInRange();
    return input;  
}

CircularInt& operator- (int base, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = base - curHour;
    circ.setCurHour(ans);
    circ.getInRange();
    return circ;
}

CircularInt& operator+ (int base, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = base + curHour;
    circ.setCurHour(ans);
    circ.getInRange();
    return circ;
}

CircularInt& operator* (int base, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = base * curHour;
    circ.setCurHour(ans);
    circ.getInRange();
    return circ;
}

CircularInt& operator/ (int base, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = base / curHour;
    circ.setCurHour(ans);
    circ.getInRange();
    return circ;
}

CircularInt& operator% (int base, CircularInt& circ){ 
    int curHour = circ.getCurHour();
    int end = circ.getEnd();
    int ans = base % curHour;
    circ.setCurHour(ans);
    circ.getInRange();
    return circ;
} ///need to find way for modulo to work

bool operator> (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base > circ.getCurHour();
    return ans;
}

bool operator< (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base < circ.getCurHour();
    return ans;
}

bool operator>= (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base >= circ.getCurHour();
    return ans;
}

bool operator<= (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base >= circ.getCurHour();
    return ans;
}

bool operator== (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base == circ.getCurHour();
    return ans;
}

bool operator!= (int base, CircularInt& circ){ 
    CircularInt temp {circ.getStart(), circ.getEnd(), circ.getCurHour()};
    bool ans = base != circ.getCurHour();
    return ans;
}
