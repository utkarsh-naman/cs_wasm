#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, std::string> dict = {
        {"a", "apple"},
        {"b", "mango"},
        {"ac", "grapes"}
    };

    // Print the dictionary contents
    for (const auto& pair : dict) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // Access a value
    std::cout << "Value for key 'b': " << dict["b"] << std::endl;

    return 0;
}



#include <iostream>
#include <unordered_map>
#include <string>

// Define the class that will be stored as values
class State_Properties {
public:
    std::string name;
    int population;
    double area;          // in square kilometers
    std::string capital;

    // Constructor for easy initialization
    State_Properties(const std::string& n = "", int pop = 0,
                     double a = 0.0, const std::string& cap = "")
        : name(n), population(pop), area(a), capital(cap) {}

    // Optional: a method to print the properties nicely
    void print() const {
        std::cout << "Name    : " << name << "\n"
                  << "Capital : " << capital << "\n"
                  << "Population: " << population << "\n"
                  << "Area    : " << area << " sq km\n";
    }
};

int main() {
    // The dictionary: key = string, value = State_Properties object
    std::unordered_map<std::string, State_Properties> stateDict;

    // Insert entries (similar to Python dict literal)
    stateDict["California"] = State_Properties("California", 39512223, 423967, "Sacramento");
    stateDict["Texas"]      = State_Properties("Texas",      29145505, 695662, "Austin");
    stateDict["Florida"]    = State_Properties("Florida",    21477737, 170312, "Tallahassee");

    // Alternative: use emplace or insert for more efficiency
    stateDict.emplace("New York", State_Properties("New York", 19453561, 141297, "Albany"));

    // Access and print a specific state
    std::cout << "=== Florida ===\n";
    stateDict["Florida"].print();

    std::cout << "\n=== All states in the dictionary ===\n";
    for (const auto& pair : stateDict) {
        std::cout << "Key: " << pair.first << "\n";
        pair.second.print();
        std::cout << "--------------------\n";
    }

    // Check if a key exists
    if (stateDict.find("Nevada") == stateDict.end()) {
        std::cout << "Nevada is not in the dictionary.\n";
    }

    // Modify an existing entry
    stateDict["Texas"].population = 30000000;  // updated population

    return 0;
}



#include <iostream>
#include <tuple>
#include <string>

int main() {
    // Define the type alias for clarity (optional but recommended)
    using Point = std::tuple<int, int>;
    using MyStructure = std::tuple<Point, Point, int>;

    // Create an instance
    MyStructure structure = {
        std::make_tuple(1, 2),     // first point: (1, 2)
        std::make_tuple(10, 20),   // second point: (10, 20)
        42                         // the integer value
    };

    // Access elements using std::get<index>
    auto& start_point = std::get<0>(structure);
    auto& end_point   = std::get<1>(structure);
    int   value       = std::get<2>(structure);

    std::cout << "Start: (" << std::get<0>(start_point) << ", " << std::get<1>(start_point) << ")\n";
    std::cout << "End:   (" << std::get<0>(end_point)   << ", " << std::get<1>(end_point)   << ")\n";
    std::cout << "Value: " << value << "\n";

    // Alternative: structured binding (C++17 and later) - much cleaner!
    auto [start, end, val] = structure;
    auto [x1, y1] = start;
    auto [x2, y2] = end;

    std::cout << "\nUsing structured bindings:\n";
    std::cout << "Start: (" << x1 << ", " << y1 << ")\n";
    std::cout << "End:   (" << x2 << ", " << y2 << ")\n";
    std::cout << "Value: " << val << "\n";

    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

class State_Properties
{
public:
    float score = 0.0;
    vector<string> next_states;
    char color[4];
};

int main()
{
    cout<<sizeof(State_Properties)<<endl;

    struct State_Properties_struct
    {
        float score = 0.0;
        vector<string> next_states;
        char color[4];
    };

    cout<<sizeof(State_Properties_struct)<<endl;

    struct Player_restricted
    {
        unsigned int l: 3;
        unsigned int r: 3;
    };

    struct State_restriced
    {
        Player_restricted r;
        Player_restricted u;
        bool next_player;
    };

    cout<<sizeof(State_restriced)<<endl;


    tuple< tuple<short, short>, tuple<short, short>, bool> state;
    cout<<"size of state_short_tuple: "<<sizeof(state)<<endl;
    tuple< tuple<int, int>, tuple<int, int>, bool> state2;
    cout<<"size of state_int_tuple: "<<sizeof(state2)<<endl;

    char c[4] = {'b', 'l', 'u', 'e'};
    cout<<c<<":: size :"<<sizeof(c)<<endl;
    int a = 3;
    return 0;
}