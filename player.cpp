//Menna Osama Elminshawy 
// Radwa Belal AbdAllah  
#include <iostream>
#include <fstream>
#include  <bits/stdc++.h>

//number of player in array
int nPlayers;

using namespace std;
class Player
{
private:
    string Name;
    int Year_of_Birth;
    int Height;
    int International_Goals;
    string Nationality;
public:
//default constructor
    Player()
    {
        Name="unknown";
        Year_of_Birth=0;
        Height=0;
        International_Goals=0;
        Nationality="unknown";
    }
    //parameterized constructor
    Player(string n,int Y,int H,int I ,string N)
    {
        Name=std::move(n);
        Year_of_Birth=Y;
        Height=H;
        International_Goals=I;
        Nationality=std::move(N);
    }
    void setName(string name){
        Name=name;
    }
    void setYearOfBirth(int year){
        Year_of_Birth=year;
    }
    void setHeight(int height){
        Height=height;
    }
    void setInternationalGoals(int goals){
        International_Goals=goals;
    }
    void setNationality(string nationality){
        Nationality=nationality;

    }
    string get_Name() const
    {
        return Name;
    }
    int get_Year_of_Birth() const
    {
        return Year_of_Birth;
    }
    int get_Height() const
    {
        return Height;
    }
    int get_International_Goals() const
    {
        return International_Goals;
    }
    string get_Nationality() const
    {
        return Nationality;
    }

    friend istream  & operator>>(istream & is,  Player &p);
    friend ostream  & operator<<(ostream & os,  const Player& N);

};
//operator overloading
istream  & operator>>(istream & is, Player &p)
{
    cout<<"name : \n";
    is>>p.Name;
    cout<<"Height : \n";
    is>>p.Height;
    cout<<"Year of Birth : \n";
    is>>p.Year_of_Birth;
    cout<<"International Goals : \n";
    is>>p.International_Goals;
    cout<<"Nationality : \n";
    is>>p.Nationality;
    return is;
}
ostream  & operator<<(ostream & os,  const Player& N)
{


    cout << "name : \n";
    os << N.get_Name() << endl;
    cout << "Height : \n";
    os << N.get_Height() << endl;
    cout << "Year of Birth : \n";
    os << N.get_Year_of_Birth() << endl;
    cout << "International Goals : \n";
    os << N.get_International_Goals() << endl;
    cout << "Nationality : \n";
    os << N.get_Nationality() << endl;


    return os;

}
//this function is supposed to take a string then convert it to an uppercase to avoid case-sensitive

string upper(string s)
{       string ch;
    for(int i=0;i<s.size();i++ ){
        ch+=toupper(s[i]) ;
    }

    return ch;

}
class NationalTeam{
private:
    Player players[18];
    bool active[18];
    string country;
public:
    NationalTeam()
    {
        for (int i=0 ;i<18;i++) {
            active[i]=false;
            players[i].setName(" ");
            players[i].setHeight(0);
            players[i].setInternationalGoals(0);
            players[i].setNationality(" ");
            players[i].setYearOfBirth(0);
            country=" ";
        }

    }

    void setCountry(const string& c){
        country=c;
        players->setNationality(c);

    }
    Player get_player(int i)
    {
        return players[i];
    }

    bool get_active(int i)
    {
        return active[i];
    }
    string getCountry()const{
        return country;
    }
    //getting the number of the players

    int getNumberOfPlayers()
    {
        int count=0;
        for(int i=0 ;i<18;i++) {
            if(active[i])
            {
                count ++;
            }
        }
        return count;
    }
//this function will add a player in the team the user want

    bool addPlayer(const Player & p)
    {
        //if there is any the user should enter the player he wants
        for (int i=0 ;i<18;i++)
        {
            //we will use the upper function to avoid case-sensitive
            if(!active[i])
            {
                players[i] = p;
                active[i]= true;
                return true;
            }
        }
        return false;
    }
    // upper line 130
    //the user will enter the name of the player he wants to delete then if the condition is true it will be deleted
    bool removePlayer(const string& name)
    {
        //the user will enter the name of the player he wants to delete then if the condition is true it will be deleted
        for(int i=0; true; i++)
        {
            if(upper(name)==upper(players[i].get_Name()))
            {
                active[i]=false;
                return false;
            } else  { return true;}
        }

    }
    //this function gets the average of players' heights
    int AvgHeight( )
    {
        int Ave=0;
        for (int i=0 ;i<18;i++) {
            if(active[i])
            {
                Ave=players[i].get_Height() + Ave;
            }
        }
        Ave=(Ave/getNumberOfPlayers());
        return Ave;
    }
    //this function returns the youngest player

    Player YoungestPlayer()
    {
        int y=0;
        int c=0;
        for(int i=0 ;i<18 ;i++)
        {
            if(y<players[i].get_Year_of_Birth())
            {
                y=players[i].get_Year_of_Birth();
                c=i;
            }
        }

        return players[c];
    }
    //this function is to return the oldest player

    Player OldestPlayer()
    {
        Player Oldest;
        int max=0;
        for (int i=1 ;i<18;i++)
        {
            if (active[i]&& max<2022-players[i].get_Year_of_Birth())
            {
                max=2022-players[i].get_Year_of_Birth();
                Oldest=players[i];
            }
        }

        return Oldest;

    }
//this function is to return the player with the highest international number of goals

    Player highestIntGoal()
    {

        Player HIGoals;
        int I = players[0].get_International_Goals();
        for (int i=1 ;i<18;i++)
        {
            if (I<players[i].get_International_Goals())
            {
                I=players[i].get_International_Goals();
                HIGoals=players[i];
            }
        }
        return HIGoals;
    }
    //this function sums the international goals then get the average

    int AvgIntGoals(){
        int average,sum=0;
        for(int i=0;i<18;i++){
            if(active[i]){
                sum=sum+players[i].get_International_Goals();
            }

        }
        average=sum/getNumberOfPlayers();


        return average;
    }
//this function is to write the entered players in a file

    void writeStatistics(ofstream&  write )
    {
        write<<"Number of players are : "<< getNumberOfPlayers()<<endl;
        write <<"Average height of players : "<<AvgHeight()<<endl;
        write <<"Name of oldest player: "<<OldestPlayer().get_Name()<<"     year of birth:"<<OldestPlayer().get_Year_of_Birth()<<endl;
        write << "Name of youngest player: "<<YoungestPlayer().get_Name()<<"      year of birth:"<<YoungestPlayer().get_Year_of_Birth()<<endl;
        write <<"Average number of international goals of players: "<<AvgIntGoals()<<endl;
        write<<"Player with the highest goals: "<<highestIntGoal().get_Name()<<"    Goals:"<<highestIntGoal().get_International_Goals()<<endl;

    }
    friend ostream  & operator<<(ostream & os,  NationalTeam & N);

};
//this function reads the information of players from player.txt file

Player* readPlayersFromFile(ifstream& R) {
    R >> nPlayers;
    Player* players = new Player[nPlayers];
    R.ignore();
    for (int i = 0; i < nPlayers; i++) {
        //name of player

        string name;
        getline(R, name);
        players[i].setName(name);
        //year of birth
        int year;
        R >> year;
        players[i].setYearOfBirth(year);
        //height of player
        int height;
        R >> height;
        players[i].setHeight(height);
        //InternationalGoals of player
        int InternationalGoals;
        R >> InternationalGoals;
        players[i].setInternationalGoals(InternationalGoals);
        // his nationality
        string nationality;
        R.ignore();
        getline(R, nationality);
        players[i].setNationality(nationality);
    }
    return players;
}
ostream  & operator<<(ostream & os,  NationalTeam & N) {
    for (int i = 0; i < N.getNumberOfPlayers(); i++) {
        if (N.get_active(i))
        {
            os << "\nPlayer number " << i + 1 << " Information \n";
            os << "Name : " << N.get_player(i).get_Name() << endl;
            os << "Height : "<< N.get_player(i).get_Height() << endl;
            os << "Year of Birth : "<< N.get_player(i).get_Year_of_Birth() << endl;
            os << "International Goals : " << N.get_player(i).get_International_Goals() << endl;
            os << "Nationality : "<< N.get_player(i).get_Nationality() << endl;

        }
    }
    return os;
}

int main() {
    NationalTeam * N;
    int numberOfNationalTeams;
    cout << "\n Please enter a number of national teams: ";
    cin >> numberOfNationalTeams;
    N=new   NationalTeam [numberOfNationalTeams ];
    string c;

    for(int i=0;i<numberOfNationalTeams;i++)
    {
        cout << "Please enter the nationality you want in team "<<i+1<<':';
        cin>>c;
        N[i].setCountry(c);
    }
//opening the file

    ifstream file("players.txt");

    Player *p = readPlayersFromFile(file);
//displaying the info of players read from the file

    for(int i=0;i<nPlayers;i++)
    {
        //we made an overloading operator to player  in line 92

        cout << p[i] << endl << endl;
    }

    bool flag= true;
    while (flag)
    {
        cout << "1.If you want to add player  \n"
                "2. if you want to remove player enter \n"
                "3.If you want to end press   ";
        int num ;
        cin>>num;
        switch (num) {
            case 1:
            {
                int index, index2;
                cout<<"Please enter your index of player :\n";
                cin >> index;
                cout << "Enter national team number:\n";
                cin >> index2;
                if(N[index2-1].addPlayer(p[index-1]))
                    cout << "Player added\n";
                break;
            }
            case 2:
            {
                string index;
                int index2;
                cout<<"Please enter player name :\n";
                cin >> index;
                cout << "Enter national team number:\n";
                cin >> index2;
                if(N[index2-1].removePlayer(index))
                    cout << "Player removed\n";
            }
            case 3:
            {
                flag= false;
                break;
            }
        }

    }
    for(int i=0;i<numberOfNationalTeams;i++)
    {
        //displaying the players added by the user

        cout<<"Team "<<i+1<<endl;
        if(N[i].get_active(i)){
            cout<< N[i];}
    }
    //calling the function that write to the file

    ofstream  out("statistics.txt");

    for(int i=0;i<18;i++)
    {
        out<<"Team "<<N[i].getCountry()<<endl;
        N[i].writeStatistics(out);
        out<<endl;
    }
    return 0;
}
