#include "minion.h"

class ApprenticeSummoner : public Minion {
    public: 
        ApprenticeSummoner(): Minion{"Apprentice Summoner", "Minion", "apprenticesummoner.txt", 1, 1, 1} {};
        void activate() override {};
};