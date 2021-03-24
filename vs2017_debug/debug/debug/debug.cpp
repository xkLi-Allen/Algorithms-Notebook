# include<iostream>
# include<queue>
using namespace std;
int main() {
	queue<int> queue_example;
	// 1. 入队 .push()
	queue_example.push(2);
	queue_example.push(9);
	queue_example.push(1);

	// 2. 获取队列中的元素个数 .size()
	cout << "queue num: " << queue_example.size() << endl;

	// 3. 访问队列头元素 .front()
	cout << "queue head: " << queue_example.front() << endl;
	
	// 4. 访问队列最后一个元素 .back()
	cout << "queue back: " << queue_example.back() << endl;
	
	// 5. 删除队列中的第一个元素 .front()
	queue_example.pop();
	cout << "queue now head: " << queue_example.front() << endl;
	
	// 6. 判断队列是否为空 .empty()
	cout << "queue is empty: " << queue_example.empty() << endl;

	
}