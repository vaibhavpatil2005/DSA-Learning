int maze(int sr,int sc, int er, int ec){
    if(sr>er || sc>ec ) return 0;
    if(sr==er || sc==ec) return 1; // destination reached
    int rightWays = maze(sr,sc+1,er,ec);
    int downWays = maze(sr+1,sc,er,ec);
    return rightWays + downWays;
}