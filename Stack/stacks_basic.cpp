/* 
                +++++++++++++++++
                +               +
                +    STACKS     +
                +    ------     +
                +    ======     +
                +               +
                +++++++++++++++++

    *LIFO or FILO   (container adapator)
    *LIFO: Last In First Out
    *#include <stack>
        stack <data_type> name;


push(6)     |  7  | (removed at pop)
push(3)     |  3  |
push(7)     |__6__|
top = 7     
pop()       |  3  |
top=3       |__6__|
size=2

    * A stack is a linar data structure in which the insertion of new element & removal of an existing element takes place at same end represnted as top of stack


Stacks 
    * Fixed Size
    * Dynamic Size



Operation 
    * push() O(1)       (push an element into stack)
    * pop() O(1)        (remove topmost element)
    * top() O(1)        (top at start => -1) 
    * isEmpty() O(1)    (boolean value)
    * size() O(1)      
    
Stack Implementation 
    * Array
    * Linked List
    * Queues

When we push stack then when we fetch it/ pop it then answer will always reverse


 */