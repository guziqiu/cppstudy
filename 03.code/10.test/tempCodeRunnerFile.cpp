Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) { 
        int flag = 0;//1：右旋，2：左旋
        root->color = 0;//原根节点改红
        if (root->lchild->color == 0) { 
            root->rchild->color -= 1;
            root = right(root);
            flag = 1;
        }
        else { 
            root->lchild->color -= 1;
            root = left(root);
            flag = 2;
        }
        root->color = 1;//新根节点改黑
        if (flag == 1) root->rchild = erase_maintain(root->rchild);// 
        else root->lchild = erase_maintain(root->lchild);// 
        return root;
    }
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild)) ) {
         
            root->lchild->color -= 1; 
            root->rchild->color -= 1;                                                       
            root->color += 1;                                                                      
            return root;                                                                    
    }   
    
    if (root->lchild->color == 2) { 
        if (root->rchild->rchild->color != 0) { 
            //------------不是红色
            root->rchild->color = 0;
            root->rchild = right(root->rchild);
            root->rchild->color = 1;
        }
        root = le