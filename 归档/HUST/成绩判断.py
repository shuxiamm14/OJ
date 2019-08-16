
while(1):
	score = int(input('输入成绩:'));
	score_file = open("/Users/xq/score_file.txt","a")
	score_file.write(str(score)+' ')
	score_file.close()
	if score >100 or score<0 :print("非法数据")
	elif score >= 95: print("优秀")
	elif score>=85: print("良好")
	elif score>=75: print("一般")
	elif score>=60: print("及格")
	elif score<60: print('不及格')