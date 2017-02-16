//
//  main.cpp
//  honeycombwalk
//
//  Created by Sara Lindström on 2017-02-14.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Coords
{
    int x;
    int y;
};

//Possibe steps from each cell
Coords alt1 = {-1, -1};
Coords alt2 = {-1, 0};
Coords alt3 = {0, -1};
Coords alt4 = {0, 1};
Coords alt5 = {1, 0};
Coords alt6 = {1, 1};

vector<Coords> possibleSteps = {alt1, alt2, alt3, alt4, alt5, alt6};

vector<Coords> generateSteps(int n)
{
    vector <Coords> v;
    if ( n == 1 )
    {
        for (int i = 0; i < possibleSteps.size(); ++i)
        {
            v.push_back({possibleSteps[i].x, possibleSteps[i].y});
        }
    }
    else
    {
        vector<Coords> w = generateSteps(n - 1);
        
        for ( int i = 0; i < w.size(); i++ )
        {
            for (int j = 0; j < possibleSteps.size(); ++j)
            {
                v.push_back({w[i].x + possibleSteps[j].x, w[i].y + possibleSteps[j].y});
            }
        }
    }
    return v;
}

int countSuccessfulWalks (const vector<Coords>& v, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].x == x && v[i].y == y)
        {
            ++sum;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    
    vector<string> lines;
    string line;
    
    while (cin >> line)
    {
        lines.push_back(line);
    }
    
    int cases = stoi(lines[0]);

    for (int i = 1; i <= cases; ++i)
    {
        vector <Coords> g = generateSteps(stoi(lines[i]));
        cout << countSuccessfulWalks(g, 0, 0) << endl;
    }
    
    return 0;
}
