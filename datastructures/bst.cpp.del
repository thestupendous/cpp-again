// bst
#include<iostream>

using namespace std;

struct treet {
    int val;
    treet* left;
    treet* right;
};
void inputVal(int& val) {
    cin >> val;
}
void addToTree(treet* head, const int& val) {
    treet* newOne = new treet{ val,nullptr,nullptr };
    if (head == nullptr) {
        head = newOne;
        return;
    }
}

int main()
{
    treet* head = nullptr;
    int val;
    inputVal(val);

    addToTree(head, val);

    cout << head->val << '\n';

    /*
    for (int i{0};i<6;i++) {
        inputVal(val);
        addToTree(head,val);
    }
    */
    return 0;
}
