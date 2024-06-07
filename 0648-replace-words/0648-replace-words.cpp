class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root_.reset(new Node());
        string res = "", temp = "";
        for(const string & pattern: dict){
            insert(pattern);
        }
        istringstream is(sentence);
        while(is >> temp){
            if(!res.empty()) res += " ";
            res += findClosest(temp);
        }
        return res;
    }
private:
    struct Node{
        vector<Node*> childs;
        bool isLeaf;
        Node(): isLeaf(false), childs(26, nullptr){};
        ~Node(){
            for(auto node: childs){
                delete node;
            }
        }
    };
    std::unique_ptr<Node> root_;
    void insert(const string & word){
        Node* temp = root_.get();
        for(const char & c: word){
            if(!temp->childs[c - 'a']){
                temp->childs[c - 'a'] = new Node();
            }
            temp = temp->childs[c - 'a'];
        }
        temp->isLeaf = true;
    }
    string findClosest(const string & word){
        Node* temp = root_.get(); 
        string cur = "";
        for(const char c: word){
            cur += c;
            if(temp->childs[c - 'a']){
                if(temp->childs[c - 'a']->isLeaf)
                    return cur;
                else temp = temp->childs[c - 'a'];
            }else return word;
        }
        return word;
    }
};