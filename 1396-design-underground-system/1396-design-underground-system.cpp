class UndergroundSystem {
public:
    // id->{station name,time}
    unordered_map<int,pair<string,int>>checkinst;
    
    // route->{total time,count}
    unordered_map<string,pair<int,int>>checkoutst;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinst[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string s1=checkinst[id].first;
        string route=s1+"->"+stationName;
            
        checkoutst[route].first+=t-checkinst[id].second;
        checkoutst[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"->"+endStation;
        
        return (double)checkoutst[route].first/checkoutst[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */