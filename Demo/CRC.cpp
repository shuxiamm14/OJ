#include <iostream>

using namespace std;

string crc(string & a, const string & b, int flag){
	string res = a;
	string temp;
	
	if(flag == 0){
		for(int k = 0; k < b.size() - 1; ++k){
			res +='0';
		}	
	}
	
	int i = 0;
	int j = 0;
	//处理编码解码
	while(res.size() >= b.size()){
		
		//判断异或性质
		if(res[i] == b[j]){
			if(temp.size() > 0) temp +='0';
		}
		else {
			temp += '1';
		}
		++i;
		++j;
		//如果到达尾部，进行处理，将缓存的余数用作被除数，进行迭代
		if(j == b.size()){			
			for(int k = i; k < res.size(); ++k){
				temp += res[k];
			}
			res = temp;
			temp = "";
			i = 0;
			j = 0;
		}
	}
	
	//余数不够需要在前面补0
	if(res.size() != b.size() - 1){
		for(int k = 0; k < b.size() - 1 - res.size(); ++ k){
			res.insert(res.begin(), '0');
		}
	}
	
	
	//用于编码与解码的返回值，先设定0时是编码，其他为解码
	if(flag == 0)	return a+res;
	else {
		
		int index = 0;
		for(int k = 0; k < res.size(); k++){
			if(res[index] == '0')	++ index;
		}
		
		if(index == res.size()){
			//当余数为0，说明无差错，进行输出
			res = "";
			for(int i = 0; i < a.size() - b.size() + 1; ++i){
				res += a[i];
			}
			return res;
		}
		else{
			//当余数为1，说明有差错，将错误进行输出
			return "Error->"+res;
		}
		
	}

}



int main(int argc, char *argv[]) {
	
	
	
	while(1){
		string a;
		string b;
		string output;
		
		cout << "输入传输的编码：";
		cin >> a;
		cout << "输入多项式：";
		cin >> b;
		
		output = crc(a, b, 0);
		cout << "编码后：" << output << endl;
		
		
		cout << "输入待校验的编码：";
		cin >> a;
		cout << "输入多项式：";
		cin >> b;
		
		output = crc(a,b,1);
		cout << "解码后：";
		cout << output << endl;
	}

	
	
}