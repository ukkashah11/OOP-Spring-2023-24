
#include <iostream>
using namespace std;
float inline bat_avg(int runs, int outs){
    return runs/outs;
}
float inline str_rate(int total_runs, int balls){
    return (float)total_runs/balls;
}
class Batsman{
    public:
    int total_runs, balls, outs;
    Batsman(int runs, int b, int o): total_runs(runs), balls(b), outs(o){}
};
int main(){
  Batsman BobsyTheKing(100, 120, 2);
  cout<<"Total runs scored: "<<BobsyTheKing.total_runs<<endl;
  cout<<"Balls faced: "<<BobsyTheKing.balls<<endl;
  cout<<"Batting Average: "<< bat_avg(BobsyTheKing.total_runs,BobsyTheKing.outs)<<endl;
  cout<<"Strike Rate: "<< str_rate(BobsyTheKing.total_runs,BobsyTheKing.balls)<<endl;
  return 0;
}
