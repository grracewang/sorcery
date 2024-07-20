#include "minion.h"

string name, string type, string description, int cost,
class ApprenticeSummoner : public Minion {
    public: 
        ApprenticeSummoner(): Minion{"Apprentice Summoner", "Minion", "Summon a 1/1 air elemental", 1, 1, 1} {};
        void activate() override {};
};