#include <bits/stdc++.h>
using namespace std;

/*  

|--------------------------|
|   Basics of Hash Maps    |
|   ===================    |
|--------------------------|


    * D.S.
    * InBuilt

    TC => good, incrusion, deletion

    Nothing but combination of steps, pre-storing & fetching

    
    map           -> log n (ordered)
    unordered_map -> O(1) (unordered)

    (key , value)

                name.first  name.second
    unordered_map <int    ,    string> name; // syntax
                    key        value   map_name




    To insert in map
        .insert()  name.inset({key, value}) or name[key] = value

        name[key] = name.at(key) // also used for update value
        both same return value

        It is preferable to use at() as it throws an exception if the key doesn't exist, while [] pairs the key with a garbage value. Accessing an unknown key with at() is safer.

        name.erase(key) -> remove value
        name.count(key) -> return 0 if not exist, else 1 
        name.find(key) -> return iterator to key, if not exist return end()


    To acess all element 
        for (auto i: mp)
            ----
    Key are unique    


    Iterator 
    unordered_map <--,--> :: iterator it = m.begin();
    where (it != m.end()) {
        //code
        it++;index
    }

    * ordered map depend on BSt


    counting Frequiencies     TC = O(N)    SC = O(N)
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for (auto x : mp) cout << x.first;




    Bucket Array 
    ============

    to save <key, value>
             _________________________________
        arr  |  V0  | V1  | V2 | --- | V(n-1) |
              ---------------------------------
                0     1     2       

                
        map_name.bucket(key); -> returns an unsigned int
                         k1  -> 1
        (index)         


    Hash Table is data structure which stores data in associative manners in hash table data stored in an array format where each data value has its own unique index value. Access of data becomes very fast if we know  index of desired data

    

    Hash Function
    =============

    Hash Code : comparsion to int  (gives output int)
        identy fn
            i/p   23       -> H.C. -> 23
                  pranjal  -> H.C. -> 23
        (H.C. -> Secret Code)

    Compression functions: int hascode bring in range this function, output is shorter than input


    keys        hash          buckets
                function
--------------------------------------------------
    ===  ----|-- \  /->|   |0| |-----------|
    ===  ----|--\ \/   |   |1| |           |
             |   \ \-->|   |2| |-----------|
    ===  ----|--/ \    |   |3| |           |
             |     \-->|   |4| |-----------|
             |________ |   |5| |           |
                           |6| |           |
                            '  |           |
                            '  |           |
                            '  |           |
 
    

    Why Hash Code ?
        Conversion to int
        Uniform distrubtion: to distribute uniformly not in in one place 
                When same value intersect : collison
                Two values same indexes when more than one value , to be hashed by particular hash function

                *   *   *   Like this
                ***         Not Like this



    Collisons Handling:
        Open Hashing: keep in there place
        Closed Adressing:   V1 - V2 - V3 - V4 --- V7(head)
                            A     
                            B     
        head of linked list  V7 ->  A  ->  B

        Hash code made very well (seprate chaining) such that nothing unique repeat. They are made efficincienntyly no chance of repeat. Hash code ouput mostly prime no which neglect chance of repeat

        Open adressing      put element in next blank space decicded by    
                Fx => Hi(a) = h(a) + Fi(a)
        
        Linear proping => F(i) = i,  Quadtione property   f(i) = i^2
                                        7 + 4  =  11\\





    Complexity Anaylsis
    ===================

    k -> word length
    n -> totl words
                    n  >> k
    TC = > O(k) ==>    O(1)
    SC = > O(n) ==>    O(n)
        n -> no of extrusion map
        b -> no of boxes availabale

        no  of entries in a box -> n/b
        reality -> n/b < 0.7

            ex -> 70 entries at least for 100 boxes

    It is very safe to assume -> O(1)
    If n(increase) then b should also increase
        Rehashing -> * increasae backet size
                     * n/b -> half


    If insetion , same for concept for deletion and searching
    

    Insertoin -> TC = O(1) -> Searching
                Deletion
 */
/*  
|--------------------------|
|   Basics of Hash Maps    |
|   ===================    |
|--------------------------|

    * D.S.
    * InBuilt

    TC => good, insertion, deletion

    Nothing but a combination of steps, pre-storing & fetching

    map           -> O(log n) (ordered)
    unordered_map -> O(1) (unordered)

    (key , value)

    unordered_map <int, string> name; // syntax
                     key     value   map_name

    To insert in map:
        .insert()  name.insert({key, value}) or name[key] = value

        name[key] = name.at(key) // also used for updating value
        Both return the value

        It is preferable to use at() as it throws an exception if the key doesn't exist, while [] pairs the key with a garbage value. Accessing an unknown key with at() is safer.

        name.erase(key) -> remove value
        name.count(key) -> returns 0 if not exist, else 1 
        name.find(key) -> returns an iterator to key, if not exist returns end()

    To access all elements:
        for (auto i: mp)
            ----

    Keys are unique.

    Iterator:
    unordered_map <int, string>::iterator it = m.begin();
    while (it != m.end()) {
        // code
        it++; // increment
    }

    * ordered map depends on BST (Binary Search Tree)

    Counting Frequencies:     TC = O(N)    SC = O(N)
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for (auto x : mp) cout << x.first << " ";

    Bucket Array:
    =============

    To save <key, value>
             _________________________________
        arr  |  V0  | V1  | V2 | --- | V(n-1) |
              ---------------------------------
                0     1     2       

    map_name.bucket(key); -> returns an unsigned int index

    Hash Table is a data structure that stores data in associative manners. In a hash table, data is stored in an array format where each data value has its own unique index value. Access to data becomes very fast if we know the index of the desired data.

    Hash Function:
    =============

    Hash Code: converts to int (gives output int)
        Identity function:
            i/p   23       -> H.C. -> 23
                  pranjal  -> H.C. -> 23
        (H.C. -> Secret Code)

    Compression functions: int hashcode bring in range, this function's output is shorter than input.

    keys        hash          buckets
                function
--------------------------------------------------
    ===  ----|-- \  /->|   |0| |-----------|
    ===  ----|--\ \/   |   |1| |           |
             |   \ \-->|   |2| |-----------|
    ===  ----|--/ \    |   |3| |           |
             |     \-->|   |4| |-----------|
             |________ |   |5| |           |
                           |6| |           |
                            '  |           |
                            '  |           |
                            '  |           |
 
    Why Hash Code?
        Conversion to int
        Uniform distribution: to distribute uniformly, not in one place.
                When the same value intersects: collision.
                Two values same indexes when more than one value is hashed by a particular hash function.

    Collisions Handling:
        Open Hashing: keep in their place.
        Closed Addressing:   V1 - V2 - V3 - V4 --- V7(head)
                            A     
                            B     
        head of linked list  V7 ->  A  ->  B

        Hash code is made very well (separate chaining) such that nothing unique repeats. They are made efficiently with no chance of repeat. Hash code output is mostly a prime number which negates the chance of repeat.

        Open addressing: put element in the next blank space decided by    
                Fx => Hi(a) = h(a) + Fi(a)
        
        Linear probing => F(i) = i,  Quadratic probing   f(i) = i^2
                                        7 + 4  =  11

    Complexity Analysis:
    ===================

    k -> word length
    n -> total words
                    n  >> k
    TC => O(k) ==>    O(1)
    SC => O(n) ==>    O(n)
        n -> no of extractions map
        b -> no of boxes available

        Number of entries in a box -> n/b
        In reality -> n/b < 0.7

            ex -> 70 entries at least for 100 boxes

    It is very safe to assume -> O(1)
    If n increases, then b should also increase.
        Rehashing -> * increase bucket size
                     * n/b -> half

    If insertion, same concept for deletion and searching.

    Insertion -> TC = O(1) -> Searching
                 Deletion
*/

int main() {
    // Example usage of unordered_map
    unordered_map<int, string> name;
    name[1] = "Alice";
    name[2] = "Bob";
    name[3] = "Charlie";

    // Accessing elements
    cout << "Name with key 1: " << name[1] << endl;
    cout << "Name with key 2: " << name.at(2) << endl;

    // Checking if a key exists
    if (name.count(3)) 
        cout << "Key 3 exists." << endl;
    

    // Erasing an element
    name.erase(3);

    // Iterating over the map
    for (auto i : name) {
        cout << "Key: " << i.first << ", Value: " << i.second << endl;
    }

    return 0;
}