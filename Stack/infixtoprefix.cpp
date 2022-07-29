// To convert an infix to postfix expression refer to this article Stack | Set 2 (Infix to Postfix). We use the same to convert Infix to Prefix.

// Step 1: Reverse the infix expression i.e A+B*C will become C*B+A. Note while reversing each ‘(‘ will become ‘)’ and each ‘)’ becomes ‘(‘.
// Step 2: Obtain the postfix expression of the modified expression i.e CB*A+.
// Step 3: Reverse the postfix expression. Hence in our example prefix is +A*BC.
// Below is the C++ implementation of the algorithm.

// CPP program to convert infix to prefix 
#include <bits/stdc++.h> 
using namespace std; 
  
bool isOperator(char c) 
{ 
    return (!isalpha(c) && !isdigit(c)); 
} 
  
int getPriority(char C) 
{ 
    if (C == '-' || C == '+') 
        return 1; 
    else if (C == '*' || C == '/') 
        return 2; 
    else if (C == '^') 
        return 3; 
    return 0; 
} 
  
string infixToPostfix(string infix) 
{ 
    infix = '(' + infix + ')'; 
    int l = infix.size(); 
    stack<char> char_stack; 
    string output; 
  
    for (int i = 0; i < l; i++) { 
  
        if (isalpha(infix[i]) || isdigit(infix[i])) 
            output += infix[i]; 
  
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if (infix[i] == '(') 
            char_stack.push('('); 
  
        // If the scanned character is an ‘)’, pop and output from the stack  
        // until an ‘(‘ is encountered. 
        else if (infix[i] == ')') { 
  
            while (char_stack.top() != '(') { 
                output += char_stack.top(); 
                char_stack.pop(); 
            } 
            char_stack.pop();   // Remove '(' from the stack 
        } 
        else { 
            if (isOperator(char_stack.top())) { 
                while (getPriority(infix[i]) <= getPriority(char_stack.top())) { 
                    output += char_stack.top(); 
                    char_stack.pop(); 
                } 
                // Push current Operator on stack 
                char_stack.push(infix[i]); 
            } 
        } 
    } 
    return output; 
} 

string infixToPrefix(string infix) 
{ 
    /* Reverse String 
     * Replace ( with ) and vice versa 
     * Get Postfix 
     * Reverse Postfix  *  */
    int l = infix.size(); 
  
    // Reverse infix 
    reverse(infix.begin(), infix.end()); 
  
    // Replace ( with ) and vice versa 
    for (int i = 0; i < l; i++) { 
  
        if (infix[i] == '(') { 
            infix[i] = ')'; 
            i++; 
        } 
        else if (infix[i] == ')') { 
            infix[i] = '('; 
            i++; 
        } 
    } 
  
    string prefix = infixToPostfix(infix); 
  
    // Reverse postfix 
    reverse(prefix.begin(), prefix.end()); 
  
    return prefix; 
} 

int main() 
{ 
    // string s = ("(a-b/c)*(a/k-l)"); 
    string s = "a+b";
    cout << infixToPrefix(s) << std::endl; 
    return 0; 
} 

// Complexity:
// Stack operations like push() and pop() 
// are performed in constant time. Since we scan 
// all the characters in the expression once the complexity 
// is linear in time i.e   mathcal{O}(n).