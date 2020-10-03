# BST (Binary Search Tree)

### 검색

삽입과 삭제를 통해서, 트리의 속성을 항상 유지할 수 있다. 선형 자료구조에서는 이런 속성을 유지하기 위해서 O(n)의 작업이 필요하다면, 더 짧게

### 삽입

### 삭제

https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

-   leaf 노드라면, 그냥 지운다.
-   child 가 1개라면, child를 node에 복사하고, child를 지운다.
-   child 이 2개 이상이라면
    -   node의 inoder successor를 node에 복사하고
    -   inorder successor를 삭제한다.

? Inorder successor of a node: the next node in Inorder traversal
-> 간단히 말해서, 중위순회에서 현재 노드 다음에 위치한 노드, 중위 순회에서 다음 노드가 없다면? 트리에서 제일 우측 노드라는 뜻(어차피 이는 leaf 노드일 것이다.)
