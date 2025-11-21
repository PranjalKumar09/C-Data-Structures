#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> priorities(4);

bool cal_val(pair<int, int> x, pair<int, int> y){
    bool result = (x.first == y.first && priorities[x.second-1] > priorities[y.second-1]);
    cout << "  Comparing: (" << x.first << "," << x.second << ") vs (" << y.first << "," << y.second << ") -> " 
         << (result ? "CAPTURE" : "NO CAPTURE") << endl;
    return result;
}

void shuffle(vector<pair<int, int>> &deck, queue<pair<int, int>> &C){
    cout << "  SHUFFLING " << deck.size() << " cards to queue" << endl;
    cout << "  Before shuffle - deck: ";
    for(auto card : deck) cout << "(" << card.first << "," << card.second << ") ";
    cout << endl;
    
    sort(begin(deck), end(deck));
    for (auto it: deck) {
        C.push(it);
        cout << "    Adding to queue: (" << it.first << "," << it.second << ")" << endl;
    }
    deck = {};
    cout << "  After shuffle - deck cleared, queue size: " << C.size() << endl;
}

string cardToString(pair<int, int> card) {
    string result;
    result = to_string(card.first);
    result += "-" + to_string(card.second);
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> deck;
    queue<pair<int, int>> C1, C2;
    
    int n; 
    cin >> n;
    cout << "=== INITIAL SETUP ===" << endl;
    cout << "Number of rounds: " << n << endl;
    
    int round_num = 0;
    while (n--){
        char c1, s1, c2, s2;
        cin >> c1 >> s1 >> c2 >> s2;
        cout << "Round " << ++round_num << ": C1 gets " << c1 << s1 << ", C2 gets " << c2 << s2 << endl;
            
        // Parse C1's card
        if (c1 == 'A')
            C1.push({1, s1 - '0'});
        else if (c1 =='J')
            C1.push({13, s1 - '0'});
        else if (c1 =='Q')
            C1.push({12, s1 - '0'});
        else if (c1 =='K')
            C1.push({11, s1 - '0'});
        else 
            C1.push({c1-'0', s1 - '0'}); // Fixed: was '1' should be '0'
         
        // Parse C2's card  
        if (c2 == 'A')
            C2.push({1, s2 - '0'});
        else if (c2 =='J')
            C2.push({13, s2 - '0'});
        else if (c2 =='Q')
            C2.push({12, s2 - '0'});
        else if (c2 =='K')
            C2.push({11, s2 - '0'});
        else 
            C2.push({c2-'0', s2 - '0'}); // Fixed: was '1' should be '0'
    }
    
    cin >> priorities[0] >> priorities[1] >> priorities[2] >> priorities[3];
    cout << "Priorities: " << priorities[0] << " " << priorities[1] << " " << priorities[2] << " " << priorities[3] << endl;
    cout << "Initial C1 size: " << C1.size() << ", C2 size: " << C2.size() << endl;

    // Start the game
    if(!C1.empty()) {
        auto firstCard = C1.front();
        cout << "Initial deck card from C1: " << cardToString(firstCard) << endl;
        deck.push_back(firstCard);
        C1.pop();
    }

    int turn = 0;
    while (!C1.empty() && !C2.empty()){
        turn++;
        cout << "\n--- Turn " << turn << " ---" << endl;
        cout << "C1 cards: " << C1.size() << ", C2 cards: " << C2.size() << ", Deck size: " << deck.size() << endl;
        
        if(!deck.empty()) {
            cout << "Top of deck: " << cardToString(deck.back()) << endl;
        }

        // Player 2's turn
        if(!C2.empty()) {
            auto curr = C2.front();
            C2.pop();
            cout << "C2 plays: " << cardToString(curr) << endl;
            
            auto top = deck.back();
            if (cal_val(curr, top)) {
                cout << "C2 CAPTURES the deck!" << endl;
                shuffle(deck, C2);
            }
            deck.push_back(curr);
            cout << "Deck after C2 play: ";
            for(auto card : deck) cout << cardToString(card) << " ";
            cout << endl;
        }

        // Check if game ended after C2's turn
        if (C1.empty() || C2.empty()) break;

        // Player 1's turn  
        if(!C1.empty()) {
            auto curr = C1.front();
            C1.pop();
            cout << "C1 plays: " << cardToString(curr) << endl;
            
            auto top = deck.back();
            if (cal_val(curr, top)) {
                cout << "C1 CAPTURES the deck!" << endl;
                shuffle(deck, C1);
            }
            deck.push_back(curr);
            cout << "Deck after C1 play: ";
            for(auto card : deck) cout << cardToString(card) << " ";
            cout << endl;
        }

        // Safety check to prevent infinite loop
        if(turn > 100) {
            cout << "SAFETY BREAK - Too many turns!" << endl;
            break;
        }
    }

    cout << "\n=== GAME OVER ===" << endl;
    cout << "Final - C1 cards: " << C1.size() << ", C2 cards: " << C2.size() << endl;
    
    if (!C1.empty()) {
        cout << "WINNER - Player 1 wins!" << endl;
    } else if (!C2.empty()) {
        cout << "LOSER - Player 2 wins!" << endl;
    } else {
        cout << "TIE - It's a draw!" << endl;
    }

    return 0;
}

/* 
7.3.3 completed .
13


*/