class UndergroundSystem {
public:
    int id, t;
    string stationname;
    unordered_map<int, pair<int, string> > map;
    unordered_map<string, pair<int, int>> routemap;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<int, string> temp;
        temp.first = t;
        temp.second = stationName;
        map[id] = temp;
    }
    
    void checkOut(int id, string stationName, int t) {
        string stat = map[id].second + "-" + stationName;
        
        routemap[stat].second += 1;
        routemap[stat].first += t - map[id].first;
        map.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tempstr = startStation + "-" + endStation;
        return (double)routemap[tempstr].first / routemap[tempstr].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */