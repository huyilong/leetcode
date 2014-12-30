//在c++和java里面都有  ternary operator  也就是三元算子
//如果用好的话会省去很多多余代码


int num1 = ( (i < len) ? (nums1[i] : 0) );
int num2 = i < len ? nums2[i] : 0;

//LCA problem
return L ? L : R;
//L is null -> false  
//L is not null -> true
//similar to if(L)

return result = a > b ? true : false;

/*


Node *LCA(Node *root, Node *p, Node *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  Node *L = LCA(root->left, p, q);
  Node *R = LCA(root->right, p, q);
  if (L && R) return root;  // if p and q are on both sides

  //the following statement means that
  //if L is true then return L, i.e. contains the side
  //else return R
  //也就是说如果？前面的语句为真则取：前面的  否则取：后面的
  return L ? L : R;  // either one of p,q is on one side OR p,q is not in L&R subtrees


  //同理有点类似于for(auto i : name of container) in c++
  //in java (Object i : map.keySet() )
  //：后面必须为set等container的名字 前面则为Object/auto通用类型取出
}

*/

/*
这个还可以与赋值语句结合起来  非常好用

int atoi (const char * str);

Convert string to integer
this method is regarding to c-string instead of c++ string
Parses the C-string str interpreting its content as an integral number, 
which is returned as a value of type int.


char * strtok ( char * str, const char * delimiters );

//On a first call, the function expects a C string as argument for str, 
whose first character is used as the starting location to scan for tokens. 
In subsequent calls, the function expects a null pointer and uses the position
right after the end of the last token as the new starting location for scanning.

Split string into tokens
A sequence of calls to this function split str into tokens, which are sequences of contiguous 
characters separated by any of the characters that are part of delimiters.

strcpy(cstr, str.c_str());

convert the c++ string to c-string

str.c_str();

*/



