#include <string>

class Lottery{
    public:
    double lottoMoney;
    bool win; //winning?
    double pot;
    std::string frequency; //how frequent the ticket purchase
    int tickets;
    int minPot;

    Lottery();
};

void initialize(Lottery &L, int argc, char* argv[]); //initialization
bool play(const Lottery &L, int month); //whether or not lottery is beign played
double simulateLotto(Lottery &L, int month); //lottery simulation