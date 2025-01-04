class Solution {
public:
    int romanToInt(string s) {
    unordered_map<string, int> mp;
    mp["M"]=1000;
    mp["CM"]=900;
    mp["D"]=500;
    mp["CD"]=400;
    mp["C"]=100;
    mp["XC"]=90;
    mp["L"]=50;
    mp["XL"]=40;
    mp["X"]=10;
    mp["IX"]=9;
    mp["V"]=5;
    mp["IV"]=4;
    mp["I"]=1;
    int sum=0;
    int n=s.size(),i=0;
    while(i<n){
    string temp="";
    while(i<n && mp.find(temp+s[i])!=mp.end()){
    temp += s[i];
    i++;
    }
    sum += mp[temp];
    }

    return sum;
    }
};