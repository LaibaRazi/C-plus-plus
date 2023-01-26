// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;
class item
{

    private:
    //item no. ,item name ,item price:
    int itemNumber,itemPrice,discPercent;
    string itemName;
    public:
    void set()
    {
        int i=0;
        do
        {cout<<"\nEnter Item Number : ";
        cin>>itemNumber;
        i++;
        }
        while (i==0);
        cout<<"\nEnter Item Name : ";
        cin>>itemName;
        
        cout<<"\nEnter Item Price : ";
        cin>>itemPrice;
        
        cout<<"\nEnter Item Discount Percentage : ";
        cin>>discPercent;
    };
    void get()
    {
       cout<<"\nNumber of items : "<<itemNumber<<endl;
       cout<<"Item Name listed : "<<itemName<<endl;
       cout<<"Item Price Listed : "<<itemPrice<<endl;
       cout<<"Discounted Percentage : "<<discPercent<<endl;
       int priceAftdisc=itemPrice-(itemPrice*discPercent/100);
       cout<<"Discounted Price : "<<priceAftdisc<<endl;
       
    };
    void total()
    {
        int total+=itemPrice;
        cout<<total<<endl;
    }
    
};

int main()
{
    int id;
    cout<<"how many items do you want to enter?";
    cin>>id;
    item* stored[id];
    for(int i=1; i<=id;i++)
{
    stored[i]=new item;
    stored[i] -> set();
    cout<<"\n-------------------------";
}
for(int j=1;j<=id;j++)
{
    stored[j]->get();

}

 item s[1];
 s->total;

       cout<<"Total"<<total<<endl;
    return 0;
}