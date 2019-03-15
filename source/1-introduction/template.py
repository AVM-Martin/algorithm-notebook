# lib: math cmath queue heapq collections.deque
class Data:
	def __init__(self, _name, _num):
		self.name, self.num = _name, _num;
	def __lt__(self, rhs): return self.num < rhs.num;
def main():
	temp = input().split();
	n,s,data = int(temp[0]), int(temp[1]), [];
	# input
	for i in range(n):
		temp = input().split();
		data.append( Data(temp[0], int(temp[1])) );
	# do
	data.sort(reverse=True);
	res = [];
	for i in range(n):
		if(s < data[i].num): continue;
		s -= data[i].num;
		res.append(i);
	if(s != 0): res = [];
	# print
	print(len(res));
	for x in res: print(data[x].name);
main();