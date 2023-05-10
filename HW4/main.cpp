#include <iostream>

using namespace std;

int if_win(int player[9]) {
    for(int i=0;i<9;i+=3) {
        if(player[i]==1&&player[i+1]==1&&player[i+2]==1) {
            return 1;
        }
    }
    for(int i=0;i<3;i++) {
        if(player[i]==1&&player[i+3]==1&&player[i+6]==1) {
            return 1;
        }
    }
    if(player[0]==1&&player[4]==1&&player[8]==1) {
            return 1;
    }
    if(player[2]==1&&player[4]==1&&player[6]==1) {
            return 1;
    }
    
}

void print_jiugongge (char record[9]){
    cout<<"-- Tic Tac Toe -- CSIE@CGU"<<endl;
    cout<<"player 1 (N) - player 2 (Y)"<<endl<<endl;
    for(int i=0;i<9;i+=3) {
        cout<<"   ▉   ▉   "<<endl;
        cout<<" "<<record[i]<<" ▉ "<<record[i+1]<<" ▉ "<<record[i+2]<<" "<<endl;
        cout<<"   ▉   ▉   "<<endl;
        if(i<6) {
            cout<<"▉▉▉▉▉▉▉▉▉▉▉"<<endl;
        }
    }
}

class TicTacToe {
    public:
    int player1[9] = { 0 };
    int player2[9] = { 0 };
    char record[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int importer=1;
    int gridnumber;
    int run () {
        while(1) {
            print_jiugongge(record);
            if(importer==1) {
                cout<<"player 1,請輸入 1-9 的數字 : "<<endl;
                cin>>gridnumber;
                player1[gridnumber-1]=1;
                record[gridnumber-1]='N';
                importer=2;
            }else if(importer==2) {
                cout<<"player 2,請輸入 1-9 的數字 : "<<endl;
                cin>>gridnumber;
                player2[gridnumber-1]=1;
                record[gridnumber-1]='Y';
                importer=1;
            }
            if(if_win(player1)==1) {
                print_jiugongge(record);
                cout<<"player1 win";
                break;
            }
            if(if_win(player2)==1) {
                print_jiugongge(record);
                cout<<"player2 win";
                break;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.run ();

    return 0;
}
