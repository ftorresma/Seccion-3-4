#include <iostream>
#include "P E 10-a.h"
stockType::stockType(float act)
{
    activ=act;
}
void stockType::info_set(string sim_stk,float op,float clos,float high,float low,float prev,int shar)
{
    stock_symbol.push_back(sim_stk);
    open_price.push_back(op);
    close_price.push_back(clos);
    high_price.push_back(high);
    low_price.push_back(low);
    previous_price.push_back(prev);
    percent_gain_loss.push_back((clos*shar*100)/(op*shar)-100);
    shares.push_back(shar);
    activ=activ+((clos-op)*shar)-shar;
}
void stockType::info_print()
{
    cout<<"_____________________________________________________________________"<<endl;
    cout<<"*********              First Investor's Haven              **********"<<endl;
    cout<<"*********                 Financial Report                 **********"<<endl;
    cout<<"Stock           Today                 Previous Percent              "<<endl;
    cout<<"Symbol  Open    Close   High    Low     Close   Gain          Volume "<<endl;
    cout<<"------  ----    -----   ----    ---     -----   ----          ------ "<<endl;
    for(int i=0;i<low_price.size();i++){
    cout<<stock_symbol[i]<<"\t"<<open_price[i]<<"\t"<<close_price[i]<<"\t"<<high_price[i]<<"\t"<<low_price[i]<<"\t"<<previous_price[i]<<"\t"<<percent_gain_loss[i]<<"% \t"<<shares[i]<<endl;
    }
    cout<<"Closing Assets: $"<<activ<<endl;
    cout<<"_____________________________________________________________________"<<endl;
}
void stockType::show_price()
{
    for(int i=0;i<open_price.size();i++)
        cout<<open_price[i]<<"\t"<<close_price[i]<<"\t"<<high_price[i]<<"\t"<<low_price[i]<<"\t"<<previous_price[i]<<endl;
}
void stockType::print_percent_g_l()
{
    for(int i=0;i<open_price.size();i++)
        cout<<percent_gain_loss[i]<<endl;
}
void stockType::show_share()
{
    for(int i=0;i<open_price.size();i++)
        cout<<shares[i]<<endl;
}

int main()
{
    stockType goku(10000.00);
    goku.info_set("CTGM",123.45,130.95,132.01,125.01,120.50,10000);
    goku.info_print();
    goku.info_set("HDAU",1875.68,875.95,13.91,89.9,10.5,143);
    goku.info_print();
    goku.info_set("AJSF",213.5,990.9,813.6,12.71,10.5,665);
    goku.info_print();
    goku.print_percent_g_l();
    goku.show_price();
    goku.show_share();
}
