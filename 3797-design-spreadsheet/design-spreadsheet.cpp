class Spreadsheet {
public:
    
    vector<vector<int>> excel;

    Spreadsheet(int rows) {
        excel.resize(26, vector<int>(rows+1, 0));
    }
    
    void setCell(string cell, int value) {
        int col=cell[0]-'A';
        int row=stoi(cell.substr(1));
        excel[col][row]=value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
      if(formula[0]!='=') return stoi(formula);
      int i=1;
      int sum=0;
      int n=formula.size();

      while(i<n){
        string taken="";

        while(i<n && formula[i]!='+'){
            taken+=formula[i];
            i++;
        }
        i++;
        if(isalpha(taken[0])){
            int col=taken[0]-'A';
            int row=stoi(taken.substr(1));
            sum+=excel[col][row];
        }else sum+=stoi(taken);
      }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */