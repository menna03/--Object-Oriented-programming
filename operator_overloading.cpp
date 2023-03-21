#include <iostream>
using namespace std;
class time
{
private:
    int hours,min,sec;
    static int numofoprators;
public:

    time()
    {
        hours=0;
        min=0;
        sec=0;
    }
    time(int h,int m,int s)
    {
        hours =h;
        min=m;
        sec=s;
    }
    time(const time & t)
    {
        hours=t.hours ;
        min=t.min ;
        sec=t.sec ;
    }
    void simpl()
    {
        if (sec>=60)
        {
            sec-=60;
            min++;
        }
        if(min>=60)
        {
            min-=60;
            hours++;
        }
    }
    bool operator >(const time &t) const
    {
        numofoprators++;
        if(t.hours>hours&&t.min>min&&t.sec>sec)
        {
            return true;
        }
        else return false;
    }
    bool operator <(const time &t) const
    {
        numofoprators++;
        if(t.hours<hours&&t.min<min&&t.sec<sec)
        {
            return true;
        }
        else return false;
    }
    time operator =( const time& t)
    {
        numofoprators++;
        hours=t.hours ;
        min=t.min ;
        sec=t.sec ;
        return t;
    }
    bool operator !=(const time &t) const
    {
        numofoprators++;
        if(t.hours==hours&&t.min==min&&t.sec==sec)
        {
            return false;
        }
        else return true;
    }
    bool operator ==(const time &t) const
    {
        numofoprators++;
        if(t.hours==hours&&t.min==min&&t.sec==sec)
        {
            return true;
        }
        else return false;
    }
    time operator +(const time &t) const
    {
        numofoprators++;
        int s=0,m=0,h=0;
        time t3(h,m,s);
        t3.sec=sec+t.sec ;
        t3.min=min+t.min;
        t3.hours=t.hours+hours;
        t3.simpl();

        return t3;
    }
    time operator -(const time &t) const
    {
        numofoprators++;
        int s=0,m=0,h=0;
        time t3(h,m,s);
        if(hours>t.hours)
        {
            t3.hours= hours-t.hours;
        }
        else
        {
            t3.hours=t.hours-hours;
        }
        if (min>t.min)
        {
            t3.min=min-t.min;
        }
        else
        {
            t3.min=t.min-min;
        }
        if(sec>t.sec)
        {
            t3.sec=sec-t.sec ;
        }
        else
        {
            t3.sec=t.sec-sec;
        }
        t3.simpl();

        return t3;
    }
    time operator ++()
    {        numofoprators++;

        sec++;
        simpl();
        return *this;
    }
    time operator ++(int )
    {
        numofoprators++;

        time t(hours,min,sec);
        ++sec;
        simpl();
        return t;
    }
    time operator --()
    {
        numofoprators++;

        sec--;
        simpl();
        return *this;
    }
    time operator --(int )
    {
        numofoprators++;
        time t(hours,min,sec);
        --sec;
        simpl();
        return t;
    }
    static int getnumofoprators()
    {return numofoprators;};

    friend ostream& operator<< (ostream &os, const time& t);
    friend istream& operator>> (istream &is,  time& t);

};
int time :: numofoprators=0;
ostream& operator<< (ostream& os,const class time& t)
{
    os<< " hours "<<t.hours<<" mints "<<t.min<<" seconds "<<t.sec<<endl;
    return os;
}
istream& operator>> (istream &is,  class time& t)
{
    cout<<"plz enter time hours mints seconds \n";
    is >>t.hours>>t.min>>t.sec;
    return is;
}
int main(){
    class time t1;
    cin>>t1;
    cout<<t1;
    class time t2;
    cin>>t2;
    cout<<t2;
    cout<<"_________\n";
    cout<<"the + of 2 is "<<t1+t2<<endl;
    cout<<"the - of 2 is "<<t1-t2<<endl;
    cout<<"the ++ of t1 is "<<t1++<<endl;
    cout<<"the ++ of t1 is "<<++t1<<endl;
    cout<<"the -- of t1 is "<<t2--<<endl;
    cout<<"the -- of t1 is "<<--t2<<endl;
    if(t1>t2)
    {
        cout<<"t1>t2 "<<endl;
    }
    else
    {
        cout<<"t1>t2=====xxxx\n";
    }
    if(t1<t2)
    {
        cout<<"t1<t2 "<<endl;
    }
    else
    {
        cout<<"t1<t2=====xxxx\n";
    }
    if(t1==t2)
    {
        cout<<"t1==t2 "<<endl;
    }
    else
    {
        cout<<"t1=t2=====xxxx\n";
    }
    if(t1!=t2)
    {
        cout<<"t1!=t2 "<<endl;
    }

    t1=t2;
    cout<<"t1= "<<t1<<" t2= "<<t2;
    cout<<t1.getnumofoprators()<<endl;
    cout<<t2.getnumofoprators()<<endl;
}