#include <iostream>

using namespace std;

const int MaxBranchNumber = 123;

// Trie Tree 结点定义
class TrieNode {
public:
    // 单词完整标志位
    bool isWord;
    // 结点储存的字符
    char word;
    // 有多少个单词通过这个结点，即由根至该结点组成的字符串模式出现的次数
    int count;
    // next数组储存所有的子结点
    TrieNode *next[MaxBranchNumber];
public:
    // 结点初始化
    TrieNode(char word) {
        this->word = word;
        isWord = false;
        count = 1;
        memset(next, 0, sizeof(next));  // 子结点初始化
    }
};

TrieNode *pRoot;

// Trie Tree 结构定义
class TrieTree {
public:
    TrieTree() {
        pRoot = new TrieNode(NULL);
    }

    ~TrieTree() {
        Destory(pRoot);
    }

    // 销毁函数
    void Destory(TrieNode *pRoot);

    // 插入函数
    void insert(string str);

    // 删除函数
    bool remove(string str);

    // 查询函数
    bool search_str(string str);

    // 前缀搜索
    bool priSearch_str(string str);

    // 前缀次数搜索
    int getPriNum(string str);

    // 辅助函数
    // 删除操作使用 -- 获取第k个位置所在的结点
    TrieNode *getchNode(string str, int k);
};

void insert(string str) {
    if (str.length() == 0 || search_str(str)) {
        return;
    }
    TrieNode *curNode = pRoot;
    // 遍历待插入单词的各个字符，并进行插入
    for (auto str_ch : str) {
        if (curNode->next[str_ch] != nullptr) {
            // 树中存在该字符
            curNode = curNode->next[str_ch];
            curNode->count++;
        } else {
            // 树中不存在该字符
            TrieNode *newNode = new TrieNode(str_ch);
            curNode->next[str_ch] = newNode;
            curNode = curNode->next[str_ch];
        }
    } 
    // 插入完成后，该结点完整位置为true
    curNode->isWord = true;
}

// O(n), n为单词长度
// 从根结点开始，遍历指定单词的所有字符
// 遍历结束后，若当前结点不为空且单词完整标志为true
bool search_str(string str) {
    if (str.length() == 0) {
        return false;
    }
    TrieNode *curNode = pRoot;
    for (auto str_ch : str) {
        if (curNode != nullptr) {
            curNode = curNode->next[str_ch];
        }
    }

    return (curNode != nullptr && curNode->isWord);
}

// 大体思路和查询是差不多的
// 唯一不同的在于返回判断条件
// 在遍历完指定前缀的所有字符后，若当前结点不为空，则表示前缀存在
// 而不是采用当前单词完整位判断是否为true
// 时间复杂度 O(n)
bool priSearch_str(string str) {
    if (str.length() == 0) {
        return false;
    }
    TrieNode *curNode = pRoot;
    for (char str_ch : str) {
        if (curNode) {
            curNode = curNode->next[str_ch];
        }
    }
    return curNode != nullptr;
}

// 在查询中，我们并不是去统计指定前缀的单词个数
// 而是直接返回当前结点的count
// 时间复杂度 O(n)
int getPriNum(string str) {
    if (str.length() == 0) {
        return 0;
    }
    if (!priSearch_str(str)) {
        return 0;
    }
    TrieNode *curNode = pRoot;
    
    for (char str_ch : str) {
        if (curNode) {
            curNode = curNode->next[str_ch];
        }
    }

    if (curNode) {
        return curNode->count;
    }

    return 0;
}


// 删除函数的辅助函数
// 返回待删除结点的第k个字符所在位置
TrieNode *getchNode(string str, int k) {
    TrieNode *curNode = pRoot;
    for (char str_ch : str) {
        if (k == 0) {
            break;
        }
        k--;
        if (curNode) {
            curNode = curNode->next[str_ch];
        }
    }
    return curNode;
}

// 自底向上进行
// 删除单词有以下几种情况
// 1. 删除的元素不仅是单词，还是其他单词的前缀，比如删除butter，但同时还有butterfly
//      这种情况我们并不需要真正的删除它，而是将该单词的完整位改为false，同时向上回溯，将经过的每个结点的count减一
// 2. 删除的元素不是其他单词的前缀，但是它的部分是其他单词的前缀，比如删除删除butterfly，但是还有flutter
//      这种情况也不能直接将结点删除，而是向上回溯，直到从某个结点开始它的count不为1
//      此时继续向上回溯，将遍历的结点的count减一
//      注意这里的删除方法是将该结点置为nullptr
// 3. 这里有一种特殊情况，即该单词路径无分支
//      这种情况，在删除完所有的结点后，需要将根结点指向删除结点元素首字符的next，并将next置空
bool remove(string str) {
    if (str.length() == 0 || !search_str(str)) {
        return false;
    }

    /*
     * 如果以str为前缀的单词个数超过1，那么我们并不是真正的删除
     * 该结点，而是将该单词的最后一个字符的isword置为false，
     * 表示它不再表示一个完整的单词
     * 但是其他单词还是存在的
     * 剩下的操作就是向上遍历，将每个成员的count-1
    */
    if (getPriNum(str) > 1) {
       int k = str.size();
       TrieNode *lastNode = getchNode(str, k);
       lastNode->isWord = false;
       while (lastNode != pRoot) {
           lastNode->count--;
           k--;
           lastNode = getchNode(str, k);
       }
       return true;
    }

    // 更新根结点标志位 
    bool updataRoot = false;

    /*
     * 如果该字符的前缀不影响其他元素，且str[0]的前缀count为1，
     * 表示待删除结点的单词路径没有其他分支，
     * 则将该单词的所有结点删除
     * 最后更新首字母的next
    */
    if (getPriNum(str.substr(0, 1)) == 1) {
       updataRoot = true;
    }

    TrieNode *curNode = pRoot;
    int k = str.size();
    auto it = str.rbegin();
    while (it != str.rend()) {
       char str_ch = *it;
       TrieNode *deleteNode = getchNode (str, k);
       k--;

        /*
        * count为1，且当前结点不是根结点，当删除该结点时
        * 不能使用delete删除，
        * 而是将该结点置为nullptr
        */ 
       if (deleteNode->count == 1 && deleteNode != pRoot) {
           if (updataRoot) {
               free(deleteNode);
           }
           deleteNode = nullptr;
        } else {
            // 若count不为1
            // 这向上遍历，更新所有前缀结点的count
            deleteNode->count--;
        }
        it++;
    }

    if (updataRoot) {
        pRoot->next[str[0]] = nullptr;
    }
    
    return true;
}

void Destory(TrieNode *pRoot) {
    if (!pRoot) {
        return;
    }
    for (int i = 0; i < MaxBranchNumber; i++) {
        if (pRoot->next[i]) {
            Destory(pRoot->next[i]);
        }
    }
    delete(pRoot);
    pRoot = nullptr;
    return;
}