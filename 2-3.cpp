#include <iostream>
#include <math.h>


using namespace std;

#define n 8
int Board[n][n] = {0};
int tile = 0;

/*
  @params: tr   棋盘左上角方格的行号
  @params: tc   棋盘左上角方格的列号
  @params: dr   特殊方格所在的行号
  @params: dc   特殊方格所在的列号
  @params: size =2^k, 棋盘规格为 2^k x 2^k
*/
void ChessBoard(int tr, int tc, int dr, int dc, int size){
    if (size == 1) {
        return;
    }
    int s = size/2; // 分割棋盘
    int t = ++tile;


    // 先覆盖棋盘左上角
    if (dr < tr+s && dc < tc + s) {  // 特殊方格在左上角子棋盘
        ChessBoard(tr,tc,dr,dc,s); 
    }
    else{ // 特殊方格不在左上角子棋盘中
        Board[tr+s-1][tc+s-1] = t;                    // 用 t 号 L型骨牌覆盖 左上角子棋盘的右下角
        ChessBoard(tr, tc, tr+s-1, tc+s-1, s);    // 覆盖左上角子棋盘内其余方格 （tr+s-1, tc+s）就是上一行覆盖的那块
    }
    
    // 再覆盖棋盘右上角
    if(dr < tr+s && dc >= tc+s) {   // 特殊方格在右上角子棋盘
        ChessBoard(tr, tc+s, dr, dc, s);
    }
    else{ // 特殊棋盘也不在右上角子棋盘中
        Board[tr+s-1][tc+s] = t;                // 用 t 号 L型骨牌覆盖 右上角子棋盘的左下角
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);  // 覆盖右上角子棋盘内其余方格 
    }
    
    // 再覆盖棋盘左下角
    if(dr >= tr+s && dc < tc+s) {   // 特殊方格在左下角子棋盘
        ChessBoard(tr+s, tc, dr, dc, s);
    }
    else {
        Board[tr+s][tc+s-1] = t;                // 用 t 号 L型骨牌覆盖 左下角子棋盘的右上角
        ChessBoard(tr+s, tc, tr+s, tc+s-1, s);  // 覆盖左下角子棋盘内的其余方格
    }

    // 最后覆盖棋盘右下角
    if(dr >= tr+s && dc >= tc+s){  // 特殊方格在右下角子棋盘
        ChessBoard(tr+s, tc+s, dr, dc, s);   
    }
    else {
        Board[tr+s][tc+s] = t;                  // 用 t 号 L型骨牌覆盖 右下角子棋盘的左上角
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);  // 覆盖右下角子棋盘内的其余方格
    }
}

int main() {
    int dr = 0, dc = 0;
    
    cout << "please give me the position (x,y) of special point: " << endl;
    cin >> dr >> dc;

    // 标出特殊点
    Board[dr][dc] = 0;

    ChessBoard(0, 0, dr, dc, n);

    // 然后输出 覆盖完成后的骨牌来看看。
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout << Board[i][j] << "\t";
        }
        cout << endl;
    }
    

    return 0;
}