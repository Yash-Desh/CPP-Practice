// a function that takes an unsigned integer and returns the sum of its decimal digits. 
// e.g., with input 123, it returns 1+2+3 = 6
// part 2: do the same but for binary digits, e.g, if the input is 13, the returns 1+1+0+1 = 3


//part 3: value 19(inp) in base 5 is 34 therefore 3+4 = 7




int sum(unsigned int inp) {   
   int sum_dec = 0;
  
   while (inp != 0) {
       sum_dec += (inp % 10);
       inp = inp / 10;
   }
  
   return sum_dec;
}


// 1101
// 0001
int sum_binary(unsigned int inp) {   
   int sum_dec = 0;
  
   while (inp != 0) {
       sum_dec += (inp & 1);
       inp = inp >> 1;
   }
  
   return sum_dec;
}


static unsigned int rem(unsigned int inp, int base) {
   return inp % base;
}


static unsigned int rshift(unsigned int inp, int base) {
   return inp / base;
}


int sum_basen(unsigned int inp, int base) {
   int sum_dec = 0;
  
   while (inp != 0) {
       sum_dec += rem(inp, base);
       inp = rshift(inp, base);
   }
  
   return sum_dec;
}




typedef struct Node_ {
   Node* left;
   Node *right;
   int val;
} Node;




bool search(Node* root, int value) {
   if (!root)
       return false;
  
   if (root->val == value)
       return true;
  
   if (root->val > value) {
       return search(root->left, value);
   }
   else {
       return search(root->right, value);
   }
}


bool search_non_recursive(Node *root, int value) {
   Node* q;
   q = root;
  
   while (q) {
       if (q->val == value)
           return true;
      
       if (q->val > value)
           q = root->left;
       else
           q = root->right;
   }
  
  return false;
}
