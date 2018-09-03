#include <vector>
#include <string>
using namespace std;
class stockType
{
    vector<string> stock_symbol;
    vector<float> open_price,close_price,high_price,low_price;
    vector<float> previous_price, percent_gain_loss;
    vector<int> shares;
    float activ;

public:
    stockType(float);
    void info_set(string,float,float,float,float,float,int);
    void info_print();
    void show_price();
    void print_percent_g_l();
    void show_share();
};
