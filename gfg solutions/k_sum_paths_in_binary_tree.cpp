/*
    Time complexity: O(N ^ 2)
    Space complexity: O(N)

    Where N is the total number of nodes in the binary tree.
*/

void kPathSumHelper(BinaryTreeNode<int> *root, vector<int> &path, vector<vector<int>> &answer, int k) {
    if (!root) {
        return;
    }
    path.push_back(root->data);

    // Recur for left subtree.
    kPathSumHelper(root->left, path, answer, k);

    // Recur for right subtree.
    kPathSumHelper(root->right, path, answer, k);

    int sum = 0;

    // Stores the path.
    for (int i = path.size() - 1; i >= 0; i--) {
        vector<int> temp;
        sum += path[i];

        // If path sum is equal to required sum.
        if (sum == k) {
            for (int j = i; j < path.size(); j++) {
                temp.push_back(path[j]);
            }
            answer.push_back(temp);
        }
    }

    // Pop to backtrack.
    path.pop_back();
}
vector<vector<int>> kPathSum(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    vector<vector<int>> answer;
    kPathSumHelper(root, path, answer, k);
    return answer;
}
