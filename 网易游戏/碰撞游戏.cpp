#include <iostream>
#include <vector>
using namespace std;


int fun(vector<vector<int> > & m, int x, int y, int w, int t){
	
	int count = 0;//计数最高到t
	m[x][y] = 2;//小球位置初始化
	int ret = 0;//返回值，颜色变化次数
	int dir = w;//记录方向
	
	for(int i = 0; i < t; ++i){
		
		//检测碰撞
		int temp = 0;
		if(dir == 0){
			temp = m[x-1][y] + m[x][y-1];
		}
		else if(dir == 1){
			temp = m[x-1][y] + m[x][y+1];
		}
		else if(dir == 2){
			temp = m[x+1][y] + m[x][y+1];
		}
		else if(dir == 3){
			temp = m[x+1][y] + m[x][y-1];
		}
		//出现碰撞
		if(temp != 0){
			m[x][y]++;
			ret ++;
				if(dir == 0){				
					if(m[x-1][y] == 1 && m[x][y-1] == 0) {
						
						dir = 3;
					}
					else if(m[x-1][y] == 0 && m[x][y-1] == 1) {
						
						dir = 1;
					}
					else{
						
						dir = 2;
						if(i < t-1){
							m[x][y]++;
							ret ++;
						}
						
					}
					
				}
				else if(dir == 1){
					if(m[x-1][y] == 1 && m[x][y+1] == 0) {
						
						dir = 2;
					}
					else if(m[x-1][y] == 0 && m[x][y+1] == 1) {
						
						dir = 0;			
					}
					else{
						
						dir = 3;
						if(i < t-1){
							m[x][y]++;
							ret ++;
						}
					}
					
					
				}	
				else if(dir == 2){
					if(m[x][y+1] == 1 && m[x+1][y] == 0) {
						
						dir = 3;
					}
					else if(m[x][y+1] == 0 && m[x+1][y] == 1) {
						
						dir = 1;
					}
					else{
						
						dir = 0;
						if(i < t-1){
							m[x][y]++;
							ret ++;
						}
					}
										
				}
				else if(dir == 3){
					if(m[x+1][y] == 1 && m[x][y-1] == 0) {
						
						dir = 0;
					}
					else if(m[x+1][y] == 0 && m[x][y-1] == 1) {
						
						dir = 2;
					}
					else{
						
						dir = 1;
						if(i < t-1){
							m[x][y]++;
							ret ++;
						}
					}
				}
				

		}
		
		
			//移动点的位置
			if(dir == 0){
				//左上
				m[x-1][y-1] = m[x][y];
				m[x][y] = 0;
				x -= 1;
				y -= 1;
			}
			else if(dir == 1){
				//右上
				m[x-1][y+1] = m[x][y];
				m[x][y] = 0;
				x -= 1;
				y += 1;
			}
			else if(dir == 2){
				//右下
				m[x+1][y+1] = m[x][y];
				m[x][y] = 0;
				x += 1;
				y += 1;
			}
			else if(dir == 3){
				//左下
				m[x+1][y-1] = m[x][y];
				m[x][y] = 0;
				x += 1;
				y -= 1;
			}
			
			
		for(int i = 0; i < m.size(); ++i){
						
			for(int j = 0; j < m[i].size(); ++j){
							
				cout << m[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "-----------" << endl;

		
		
			
		
	}
	
	
	
	
	return ret;
}



int main(int argc, char *argv[]) {
	
	int Q = 0;//测试点个数
	
	while(cin >> Q){
		
		for(int k = 0; k < Q; ++k){
			int N = 0;
			int M = 0;
			cin >> N >> M;
			vector<vector<int> > res;
			//第一步生成矩阵
			for(int i = 0; i < N; ++i){
				vector<int> temp;
				for(int j = 0; j < M; ++j){
					
					if(i == 0 || j == 0 || i == N - 1 || j == M - 1){
						
						temp.push_back(1);
					} else {
						temp.push_back(0);
					}
				}
				res.push_back(temp);
			}
			
			//cout << endl;
			//输出矩阵
			/*for(int i = 0; i < N; ++i){
				
				for(int j = 0; j < M; ++j){
					
					cout << res[i][j] << ' ';
				}
				cout << endl;
			}*/
			
			//输入
			int X = 0;
			int Y = 0;
			int W = 0;
			int T = 0;
			cin >> X >> Y >> W >> T;
			
			
			//进行转换
			int ret = 0;
			ret = fun(res, X, Y, W, T);
			
			
			cout << ret << endl;
			
			
		}
		
		
		
		
		
		
	}
	
	
	
}