# include<iostream>
using namespace std;
// https://leetcode-cn.com/problems/implement-trie-prefix-tree
class Trie
{
private:
	bool is_string = false;
	Trie* next[26] = { nullptr };   // 每个节点有26个链接
public:
	Trie() {}
    // 主要是边的标识
	void insert(const string& word)//插入单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
	}

	bool search(const string& word)//查找单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(const string& prefix)//查找前缀
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}
};

int main(){
    Trie trie;
    trie.insert("apple");
    cout << "trie.search(apple): " << trie.search("apple") << endl;   // 返回 true
    cout << "trie.search(app): " << trie.search("app") << endl;     // 返回 false
    cout << "trie.search(app): " << trie.startsWith("app") << endl; // 返回 true
    trie.insert("app");   
    cout << "trie.search(app): " << trie.search("app") << endl;     // 返回 true
}