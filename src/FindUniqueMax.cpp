#include "FindUniqueMax.h"

// stdlib includes
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

// external includes
#include "boost/algorithm/string.hpp"
#include "boost/lexical_cast.hpp"

std::vector<std::string> FindUniqueMaxN(std::istream &stream, int N)
{
    // Use a priority_queue to store N ids with the largest values.
    auto compare = [](const std::pair<std::string, int> &right, const std::pair<std::string, int> &left) {
        return right.second > left.second;
    };
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(compare)> q(compare);

    std::string line;
    while (std::getline(stream, line))
    {
        // split the line to an id and value pair
        std::vector<std::string> p;
        boost::split(p, line, boost::is_any_of(std::vector<char>{',', '\t', ' '}));
        int value = 0;
        // check to see if you have a good line
        if (p.size() < 2)
        {
            throw std::invalid_argument("Invalid {ID,value} pair in stream.");
        }
        try
        {
            value = boost::lexical_cast<int>(p[1]);
        }
        catch (std::exception &e)
        {
            throw;
        }

        q.push(std::make_pair(p[0], value));
        // Remove one if the count is larger
        if (q.size() > N)
        {
            q.pop();
        }
    }

    std::vector<std::string> v;
    v.reserve(q.size());
    while (!q.empty())
    {
        v.push_back(q.top().first);
        q.pop();
    }

    return v;
}

std::vector<std::string> FindUniqueMaxN2(std::istream &stream, int N)
{
    std::stack<std::pair<std::string, int>> s;

    std::string line;
    while (std::getline(stream, line))
    {
        // split the line to an id and value pair
        std::vector<std::string> p;
        boost::split(p, line, boost::is_any_of(std::vector<char>{',', '\t', ' '}));
        int value = 0;
        // check to see if you have a good line
        if (p.size() < 2)
        {
            throw std::invalid_argument("Invalid {ID,value} pair in stream.");
        }
        try
        {
            value = boost::lexical_cast<int>(p[1]);
        }
        catch (std::exception &e)
        {
            throw;
        }

        const auto newp = std::make_pair(p[0], value);
        // use a second data structure
        std::stack<std::pair<std::string, int>> stemp;
        while(!s.empty() && newp.second > s.top().second){
            stemp.push(s.top());
            s.pop();
        }
        // found where the new item belongs in the stack.
        stemp.push(newp);
        // push back the items in the queue
        while(s.size() < N && !stemp.empty()){
            s.push(stemp.top());
            stemp.pop();
        }

    }

    std::vector<std::string> v;
    v.reserve(s.size());
    while (!s.empty())
    {
        v.push_back(s.top().first);
        s.pop();
    }

    return v;
}