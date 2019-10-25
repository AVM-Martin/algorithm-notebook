# lib: math cmath queue heapq collections.deque

class Data:
	def __init__(self, _name, _num):
		self.name, self.num = _name, _num

	def __lt__(self, rhs):
		return self.num < rhs.num;

data.sort(reverse=True);
