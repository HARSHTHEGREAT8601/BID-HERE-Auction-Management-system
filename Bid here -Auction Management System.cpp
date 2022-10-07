#include<bits/stdc++.h>
using namespace std;
int main()
{
    Auction auct;
    Item it[10];
    int noi_const[10],not_const[10];
    int cnt =1;
    int sell_price[10][10];
    Attributes attr[10];
    buyers bteam[10];
    vector<string> attri [10];
    int ch;
    do {
        cout << "1:ENTER THE DATE OF THE AUCTION:" << endl;
        cout << "2:ENTER THE ATTRIBUTES THAT IS REQUIRED FOR EACH ITEM:" << endl;
        cout << "3:ENTER THE ITEMs BEING SOLD" << endl;
        cout << "4:ENTER THE BUYER DETAILS:" << endl;
        cout << "5:ENTER THE SELLING PRICE OF THE ITEM AND BOUGHT BY:" << endl;
        cout << "6:AUCTION SUMMARY:"<<endl;
        cout << "7:TO EXIT:"<<endl;

        cin >> ch;
        switch (ch) {
            case 1: { //for entering the dates of auction and checking for date clash

                int  day,month, year;
                string auction_name;
                cout << "ENTER THE DAY MONTH AND YEAR RESPECTIVELY:"<<endl;
                cin >> day>> month >> year;
                cout<<"ENTER THE AUCTION NAME:"<<endl;
                cin>>auction_name;
                auct.set_auction_info(day, month, year, auction_name);
                break;
            }
            case 2: {   //entering name of auctions to be held
                string name;
                int Auct_num;
                cout << "Enter Auction Name" << endl;
                cin >> name;
                Auct_num = auct.findauction_num(name);
                if (Auct_num==0)
                {
                    cout<<"Invalid Auction Name"<<endl;
                }
                else
                {
                    int noa ;
                    cout<<"Enter Number of Attribute:\n";
                    cin>>noa;
                    attri[Auct_num]=attr[Auct_num].set_attributes(noa);
                }
                break;
            }
            case 3:
            {
                int flag=1;
                string name;
                int Auct_num;
                cout <<"Enter Auction Name"<< endl;
                cin >> name;
                Auct_num = auct.findauction_num(name);

                if (Auct_num==0)
                {
                    cout<<"Invalid Auction Name"<<endl;
                }
                else {
                    int noi;
                    cout << "Enter Number of Items being Auctioned:\n";
                    cin >> noi;

                    noi_const[Auct_num]=noi;
                    while (noi--) {
                        it[Auct_num].Set_Item(flag, attri[Auct_num]);
                        flag++;
                    }
                }
                break;
            }
            case 4: {

                string name;
                int Auct_num;
                cout << "Enter Auction Name" << endl;
                cin >> name;
                Auct_num = auct.findauction_num(name);
                if (Auct_num == 0) {
                    cout << "Invalid Auction Name" << endl;
                } else {
                    int bud, no;
                    cout << "Enter Number of Teams: \n";
                    cin >> no;
                    not_const[Auct_num] = no;
                    cout << "Enter Budget:\n";
                    cin >> bud;
                    bteam[Auct_num].set_budget(bud,no);
                    for (int i = 1; i <= no; i++) {
                        string tname;
                        cout << "Enter Team Name:\n";
                        cin >> tname;
                        bteam[Auct_num].set_team(tname);
                    }
                }
                break;
            }
            case 5: {
                string name;
                int flag=1;
                int Auct_num;
                cout << "Enter Auction Name" << endl;
                cin >> name;
                Auct_num = auct.findauction_num(name);
                if (Auct_num == 0) {
                    cout << "Invalid Auction Name" << endl;
                } else {
                    while (noi_const[Auct_num]--) {
                        int sp;
                        string name;
                        cout << "Enter Selling Price of ";
                        it[Auct_num].display_itemname(flag,it[Auct_num]);
                        cin >>sp;
                        it[Auct_num].selling_price[flag]= sp;
                        sell_price[Auct_num][flag] = sp;
                        int soldp;
                        soldp = it[Auct_num].get_selling_price(flag,it[Auct_num]);
                        if(soldp>0)
                        {
                            cout << "Sold To ";
                            cin >> name;
                            bteam[Auct_num].bought(it[Auct_num], name, flag);
                        }
                        flag++;
                    }
                }
                break;
            }
            case 6: {
                int k;
                do {
                    cout << "1:Display amount spent by the team and items bought by them: "<<endl;
                    cout << "2:Display amount spent by the all teams above a certain limit: "<<endl;
                    cout << "3:TOTAL MONEY SPENT IN AUCTION: "<<endl;
                    cout << "4:EXIT"<<endl;
                    cin>>k;
                    switch(k)
                    {
                    case 1:
                        {
                            string name;
                            int flag=1;
                            int Auct_num;
                            cout << "Enter Auction Name" << endl;
                            cin >> name;
                            Auct_num = auct.findauction_num(name);
                            if (Auct_num == 0) {
                                cout << "Invalid Auction Name" << endl;
                            } else
                            {
                                cout<<"ENTER THE TEAM NAME:";
                                string name;
                                cin>>name;
                                int amt_spend;
                                amt_spend = bteam[Auct_num].amount_spent_team(name);
                                cout<<endl<<"THE AMOUNT SPENT BY THEM IS:"<<amt_spend;
                                cout<<endl<<"THE BUYS ARE AS FOLLOWS:"<<endl;
                                bteam[Auct_num].display_buys(name,it[Auct_num]);
                            }
                            cout<<endl;
                            break;
                        }
                        case 2:
                        {
                            string name;
                            int flag=1;
                            int Auct_num;
                            cout << "Enter Auction Name" << endl;
                            cin >> name;
                            Auct_num = auct.findauction_num(name);
                            if (Auct_num == 0) {
                                cout << "Invalid Auction Name" << endl;
                            } else
                            {
                                int slab;
                                cout<<"ENTER THE SLAB PRICE FOR THE TEAM: ";
                                cin>>slab;
                                bteam[Auct_num].amount_spent_above(slab,bteam[Auct_num]);

                            }
                            break;
                        }
                        case 3:
                        {
                            string name;
                            int flag=1;
                            int Auct_num;
                            cout << "Enter Auction Name" << endl;
                            cin >> name;
                            Auct_num = auct.findauction_num(name);
                            if (Auct_num == 0) {
                                cout << "Invalid Auction Name" << endl;
                            } else
                            {
                                cout<<endl<<"THE TOTAL AMOUNT SPENT IN THE AUCTION:";
                                int tot_amt;
                                tot_amt = bteam[Auct_num].total_amount_spent(not_const[Auct_num]);
                                cout<<tot_amt<<endl;
                                int max;
                                max = it[Auct_num].highest_price(it[Auct_num],noi_const[Auct_num]);
                                cout<<"THE  HIGHEST PURCHASE OF THE AUCTION WAS: ";
                                it[Auct_num].display_at_price(max,it[Auct_num],noi_const[Auct_num]);
                            }
                            break;
                        }


                    }
                }while(k!=4);
                break;
            }
        }
    }while(ch!=7);
#include"header.h"
struct date
{ int month ;
    int day;
    int year;
};
class Auction
{ // for auction date and name management

private:
    date auction_date[10];

public:
    int auction_num=0;
    string auction_name[10];
    void set_auction_info(int day,int month,int year, string name)
    {
        auction_num++;
        int flag =auction_num;
        if(auction_num>1)
        {
            for(int i=1;i<auction_num;i++) {
                if (auction_date[i].day == day && auction_date[i].month == month && auction_date[i].year == year) {
                    cout << "DATE CLASH WITH "<<auction_name[i]<<" ON "<<day<<"-"<<month<<"-"<<year<<endl;
                    auction_num--;
                }
            }
            if(auction_num==flag)
            {
                auction_name[auction_num]=name;
                auction_date[auction_num].day=day;
                auction_date[auction_num].month = month;
                auction_date[auction_num].year = year;

            }
        }
        else
        {
            auction_name[auction_num]=name;
            auction_date[auction_num].day=day;
            auction_date[auction_num].month = month;
            auction_date[auction_num].year = year;

        }


    }

    int findauction_num(string name) //storing the auction name
    {
        for (int i=1;i<=auction_num;i++)
        {
            if (name==auction_name[i])
                return i;

        }
        return 0;
    }
};


class Attributes   //attributes name
{
public:
    vector<string> attributes;
    vector<string> set_attributes(int n)
    {
        string a;
        for(int i=0;i<n;i++) {   //entering attribute name
            cout<<"Enter Atrribute Name:\n";
            cin>>a;

            attributes.push_back(a);
        }
        return attributes;
    }
};
class Item {
public:
    string item_info[10][10];   //[auction_no][item_no]
    int count=0;
//    int b=0;
    int selling_price[10]; //for unsold players the selling price would be zero...
    void Set_Item(int noi, vector<string> attrib) {    //storing item name and value
        for (int i = 0; i < attrib.size(); i++) {
            cout << "ENTER " << attrib[i] << " ";
            cin >> item_info[noi][i];
        }
    }
    void display_itemname(int noi,Item object)
    {
        cout<< object.item_info[noi][0]<<" ";
    }
    void set_sellingprice(int sp)
    {
        count++;
        selling_price[count]=sp;
    }
    int get_selling_price(int noi,Item obj)
    {
        return obj.selling_price[noi];

    };

    bool check_if_unsold(Item obj,int noi)
    {
        if(obj.selling_price[noi]==0)
            return true;
        return false;
    }
    void display_selling_price(Item obj,int noi)
    {
        if(check_if_unsold(obj,noi))
            cout<<"UNSOLD";
        else
            cout<<obj.selling_price[noi];
    }
    void slab_price(Item obj, int slab,int noi)
    {
        int cnt=0;
        for(int i = 1;i<=noi;i++)
        {
            if (obj.selling_price[i] >= slab) {
                cout << obj.item_info[i][0]<<" ";
                cnt++;
            }
        }
        if(cnt==0)
            cout<<"NO SUCH DATA:"<<endl;
        else
            cout<<"/n There are"<<cnt<<"Item sold at this price or more:";


    }
    int highest_price(Item obj,int noi)
    {
        int max=0;
        sort(obj.selling_price,obj.selling_price+noi);
        return obj.selling_price[noi];
    }

    void display_at_price(int price, Item obj,int noi)
    {
        int cnt=0;
        for(int i=0;i<=noi;i++)
        {
            if(price==obj.selling_price[i])
            {
                cout<<obj.item_info[i][0]<<" ";
                cnt++;
            }
        }
        if(cnt==0)
            cout<<"NO SUCH DATA:";
        else
            cout<<"/n There are"<<cnt<<"Item sold at this price:";
    }
};
class buyers : public Item
{
public:
    long int budget[10];
    string team_name[10];
    long int team_purchase [10][10];
    string team_purchase_name[10][10];
    int number_of_teams=0;
    int counter[10];
    void set_team(string name)
    {
        number_of_teams++;
        team_name[number_of_teams]=name;

    }
    void set_budget (int bud,int no)
    {
        if(bud!=0) {
            for (int i = 1; i <= no; i++) {
                counter[i] = 0;
                budget[i] = bud;
            }
        }
        else
            for (int i = 1; i <= no; i++) {
                counter[i] = 0;
                budget[i] = LONG_MAX;
            }
    }
    void bought (Item obj,string team,int noi)
    {
        int cnt = 0;
        for (int i = 1; i <= number_of_teams; i++) {
            if (team == team_name[i]) {
                cnt = i;
                break;
            }
        }

        if ((budget[cnt] - obj.selling_price[noi]) >= 0) {
            counter[cnt]++;
            team_purchase[cnt][counter[cnt]] = obj.selling_price[noi];
            team_purchase_name[cnt][counter[cnt]] = obj.item_info[noi][0];
            budget[cnt] -= obj.selling_price[noi];
        } else {
            cout << "Budget Exceeded\n";
        }
    }
    int max_purchase(string team)
    {
        int cnt = 0;
        for (int i = 1; i <= number_of_teams; i++) {
            if (team == team_name[i]) {
                cnt = i;
                break;
            }
        }
        sort(team_purchase[cnt],team_purchase[cnt]+counter[cnt]);
        return team_purchase[cnt][counter[cnt]];
    }
    int min_purchase(string team)
    {
        int cnt = 0;
        for (int i = 1; i <= number_of_teams; i++) {
            if (team == team_name[i]) {
                cnt = i;
                break;
            }
        }
        sort(team_purchase[cnt],team_purchase[cnt]+counter[cnt]);
        return team_purchase[cnt][1];
    }
    void display_buys(string team,Item obj)
    {
        int cnt = 0;
        for (int i = 1; i <= number_of_teams; i++) {
            if (team == team_name[i]) {
                cnt = i;
                break;
            }
        }
        for(int i =1;i<=counter[cnt];i++)
        {
            cout<<team_purchase[cnt][i]<<" FOR "<<team_purchase_name[cnt][i]<<" ";
        }
    }
    int amount_spent_team(string team)
    {
        int sum=0 ;
        int cnt = 0;
        for (int i = 1; i <= number_of_teams; i++) {
            if (team == team_name[i]) {
                cnt = i;
                break;
            }
        }
        for(int i=1;i<=counter[cnt];i++)
        {
            sum = sum + team_purchase[cnt][i];
        }
        return sum;
    }
    void max_amt_spent_by(buyers b)
    {
        vector <string> allname;
        int cmp=0;
        int flag;
        for(int i=1;i<=b.number_of_teams;i++)
        {
            flag = b.amount_spent_team(b.team_name[i]);
            if(cmp<flag)
                cmp = flag;
        }
        for(int i=1;i<=b.number_of_teams;i++)
        {
            flag = b.amount_spent_team(b.team_name[i]);
            if(cmp==flag)
                allname.push_back(b.team_name[i]);
        }
        for(int i=0;i<allname.size();i++)
            cout<<"THE AMOUNT MOST SPENT IS: "<< cmp<<" BY "<<allname[i]<<" ";
    }
    int total_amount_spent(int notp)
    {
        int sum=0 ;
        for(int cnt=1;cnt<=number_of_teams;cnt++)
            for(int i=1;i<=counter[cnt];i++)
            {
                sum = sum + team_purchase[cnt][i];
            }
        return sum;
    }
    void amount_spent_above(int slab,buyers buy)
    {
        int total=0;
        for(int cnt=1;cnt<=number_of_teams;cnt++)
        {
            total=0;
            for (int i = 1; i <= counter[cnt]; i++)
            {
                total = total + buy.team_purchase[cnt][i];
            }
            if(total>slab)
            {
                cout<<buy.team_name[cnt]<<" HAS SPENT "<<total<<endl;
            }
        }

    }
};
    return 0;
}