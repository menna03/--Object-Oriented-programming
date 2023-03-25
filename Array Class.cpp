
#include <iostream>
using namespace std;
class MyArray
        : public error_code, public error_condition {
private:


public:
    int* array;
    int size;
    MyArray()
    {
        size=0;
        array=NULL;
    }
    MyArray(int s) {
        size = s;
        //dynamic allocation for the array .
        array = new int(size);
        //set all the values of the array's elements =0.
        for(int i=0;i<size;i++)
            array[i]=0;

    }
    MyArray(const MyArray & arr)
    {
        size=arr.size;
        for (int i=0;i<size;i++)
        {
            arr.array[i] = array[i];

        }

    }
    void setSize(int siz)
    {
        size=siz ;
        array=new int[siz];
        for(int i=0 ;i<siz ; i++)
            array[i]=0;
    }

    int getSize() const
    {
        return size;
    };
    //this function checks if the index entered is within the interval of the array or not.
    int &  operator[](const int num ) const
    {
        if (num<0 || num>= size)
        {
            cout<<"\nERROR :SUBSCRIPT OUT OF RANGE \n";
            exit(0);
        }

        return array[num];
    }
//this overloading function assigns the values of the first array to the second one (assign the values of one object to another).
    MyArray &operator =( const MyArray& arr)
    {
        size=arr.size;
        array=new int [size];
        for (int i=0;i<arr.size;i++)
        {
            array[i]=arr.array[i];
        }
        return *this;
    }
    friend ostream & operator<<(ostream & os,const MyArray & obj );
    friend istream & operator>>(istream & is,const MyArray & obj );

    //this overloading function merges the two arrays together.
    MyArray  operator +(const MyArray  & arr2) const
    {
        //creating a new array with the sum of two arrays' sizes to hold all the elements .
        MyArray arr3(size+arr2.size);
        int count =0;

        for (int i=0;i<(size+arr2.size);i++)
            //this step is to get the values of the first array into the third one if the index is less than the first size.
            if(i<size)
                arr3[i]=array[i];
                //otherwise it gets the second array's elements into the third one.
            else
            {
                arr3[i]=arr2.array[count];
                count++;
            }
        return  arr3;
    }
//this overloading function is to find if there is common values in both arrays if yes it deletes this value from the new array
    MyArray operator-(const MyArray &arr2) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            bool found = false;
            for (int j = 0; j < arr2.size; j++)
            {//check if there's common values in the two arrays .
                if (array[i] == arr2.array[j])
                {
                    found = true;
                }
                //if there's not any common we increase the count .
                if (!found)
                {
                    count++;
                }
            }
        }
        int correct = 0;
        MyArray Arr3(count);
        for (int i = 0; i < size; i++)
        {
            bool found = false;
            for (int j = 0;j< arr2.size; j++)
            {
                if (array[i] == arr2.array[j])
                {
                    found = true;
                }
            }//if there's not any common values we put the elements of array2 in the new array.
            if (!found)
            {
                Arr3.array[correct] = (arr2.array)[i];
                Arr3.array[correct+1]=array[i];
                correct++;
            }
        }
        return Arr3 ;}
//this overloading function takes a scalar from the user and multiply it by the elements of the array then return the array.
    MyArray  operator *(const int x) const
    {
        MyArray arr(size);
        for (int i=0;i<size;i++)
        {
            arr.array[i]=array[i]*x;
        }
        return arr;
    }
//this function takes a new size from the user then gets the old values of the array and puts 0 in the empty indexes.
    bool resize(int s)
    { //checks if the new size is bigger than or less than the old one .
        if (s < size)
        {
            return false;
        }
        else {
            int *arr = new int [s];
            for (int i = 0; i < size; i++) {
                arr[i] = array[i];
            }
            //putting 0 in the empty indexes of the array with the new size.
            for (int j = size; j < (s); j++) {
                arr[j] = 0;
            }
            delete [] array ;
            size = s;
            array = arr;
            return true;
        }
    }
    ~MyArray()
    {
        delete array;
    }

};
//this overloading function enables us to display the elements of the array  .
ostream & operator<<(ostream & os,const MyArray & obj )
{
    for (int i=0;i<obj.size;i++)
    {
        os<<obj.array[i]<<'\t';
    }
    return os;
}
//this function enables us to enter the elements of the array.
istream & operator>>(istream & is,const MyArray & obj )
{
    for (int i=0;i<obj.size;i++)
    {
        is>>obj.array[i];
    }
    return is;
}

int main()
{
    int menu;
    int size ;
    size=0;
    MyArray A ;
    do
    {
        cout<<"plz choose a number "<<endl;
        cout<<"1- Create an array A"<<endl;
        cout<<"2- Enter array elements of A"<<endl;
        cout<<"3- Copy array A into a new array and display the new array"<<endl;
        cout<<"4- Display an element in array A by index"<<endl;
        cout<<"5- Set an element in array A by index"<<endl;
        cout<<"6- Display array A"<<endl;
        cout<<"7- Concatenate 2 arrays into array A"<<endl;
        cout<<"8- Subtract 2 arrays into array A"<<endl;
        cout<<"9- Multiply array elements of A by an integer"<<endl;
        cout<<"10- Expand array A"<<endl;
        cout<<"11- Get size of array A"<<endl;
        cout<<"12- Exit" << endl;
        cin>>menu;
        //user chooses the option he wants .
        switch(menu)
        {
            case 1:
            {
                cout<<"plz enter the size of the array "<<endl ;
                cin>>size;
                A.setSize(size) ;
            }break;
            case 2:
            {
                cout<<"plz enter the array elements "<<endl ;
                for(int i=0 ;i<size ;i++)
                {
                    cin>>A.array[i] ;
                }
            }
                break;

            case 3:
            {
                MyArray newA;
                newA=A;
                cout<<newA;
            }break ;
            case 4:
            {
                int n ;
                cout<<"plz enter the index "<<endl ;
                cin>>n ;
                cout<<"number of index number "<<n<<" is "<<A.array[n-1]<<endl;
            }break ;
            case 5:
            {
                int y=0 ;
                cout<<"plz enter the index "<<endl ;
                cin>>y ;
                cout<<"plz enter the number that yo wanna assign to that index "<<endl ;
                cin>>A.array[y-1];
            } break ;
            case 6:
            {
                cout<<A;
            }break;
            case 7:
            {
                int q,r ;
                cout<<"plz enter the number of the first array elements "<<endl ;
                cin>>q ;
                MyArray X(q);
                cout<<"plz enter the array elements "<<endl ;
                for(int i=0 ;i<q ;i++)
                {
                    cin>>X.array[i] ;
                }
                cout<<"plz enter the number of the second array elements "<<endl ;
                cin>>r ;
                MyArray Y(r);
                cout<<"plz enter the array elements "<<endl ;
                for(int i=0 ;i<r ;i++)
                {
                    cin>>Y.array[i] ;
                }
                A=X+Y ;
            }break ;
            case 8:
            {
                int s1,s2;
                cout<<"plz enter the number of the first array elements "<<endl ;
                cin>>s1 ;
                MyArray arr1(s1);
                cout<<"plz enter the array elements "<<endl ;
                for(int i=0 ;i<s1 ;i++)
                {
                    cin>>arr1.array[i] ;
                }
                cout<<"plz enter the number of the second array elements "<<endl ;
                cin>>s2 ;
                MyArray arr2(s2);
                cout<<"plz enter the array elements "<<endl ;
                for(int i=0 ;i<s2 ;i++)
                {
                    cin>>arr2.array[i] ;
                }
                if(s1<s2)
                    A=arr2-arr1 ;
                else
                    A=arr1-arr2 ;
            }break;
            case 9:
            {
                int multiply;
                cout<<"plz enter the number "<<endl ;
                cin>>multiply;
                MyArray multiA;
                multiA=A*multiply;
                A=multiA;
            }break;
            case 10:
            {
                int newsize;
                cout<<"plz enter the new size of the array "<<endl ;
                cin>>newsize;
                A.resize(newsize);
            }break ;
            case 11:
            {
                cout<<A.getSize();
            }break ;
        }
    }while(menu!=12);
    cout<<"END OF PROGRAM THANK U ";

    return 0;}
